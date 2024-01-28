/*esp32 cam URL 192.168.4.1*/
/*I connectes esp32 cam module seperately. It's not compulsary*/

#include <IRremote.h>
#include <Ultrasonic.h>
#include "SD.h"
#include "TMRpcm.h"
#include "SPI.h"

#define irPin 7
#define SD_ChipSelectPin 4
IRrecv irrecv(irPin);

decode_results results;
Ultrasonic ultra = Ultrasonic(10, A5);
int cm;
TMRpcm tmrpcm;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);

  Serial.begin(9600);
  irrecv.enableIRIn(); // enable IR reciever
  tmrpcm.speakerPin = 9;
  tmrpcm.setVolume(5);
  if (!SD.begin(SD_ChipSelectPin)) {
    Serial.println("SD fail");
    return;
  }
}

void loop() {

  cm = ultra.read();
  Serial.println(cm);

  if (cm < 15) {
    if (digitalRead(2) == HIGH && digitalRead(6) == HIGH) {
      tmrpcm.play("distance.wav");
      Stop();
    }
  }

  if (irrecv.decode(&results)) {
    Serial.println(results.value);

    if (results.value == 1074791717) {//forward
      if (cm > 15) {
        forward();
        Serial.println("forward");
      }
      else if (cm < 15) {
        tmrpcm.play("side.wav");
        Stop();
      }
    }

    else if (results.value == 1074792231) {//left
      left();
      Serial.println("left");
    }

    else if (results.value == 1074794287) {//right
      right();
      Serial.println("right");
    }

    else if (results.value == 1074793773) {//reverse
      back();
      Serial.println("reverse");
    }

    else if (results.value == 1074792745) {//stop
      Stop();
      Serial.println("stop");
    }

    else if (results.value == 1074793419) {//on music
      tmrpcm.play("1.wav");
    }
    else if (results.value == 1075383636) {//hi music
      tmrpcm.play("2.wav");
    }
    else if (results.value == 1075052740) {//how are you music
      tmrpcm.play("3.wav");
    }
    else if (results.value == 1074792970) {//lets go music
      tmrpcm.play("4.wav");
    }
    else if (results.value == 1074791588) {//i'm fine music
      tmrpcm.play("5.wav");
    }
    else if (results.value == 1074790560) {//i'm here music
      tmrpcm.play("6.wav");
    }
    else if (results.value == 1074793676) {//yo are not my boss music
      tmrpcm.play("7.wav");
    }
    else if (results.value == 1074794255) {//about music
      tmrpcm.play("8.wav");
    }
    else if (results.value == 1074790624) {//hone1
      tmrpcm.play("hone1.wav");
    }
    else if (results.value == 1074792680) {//hone2
      tmrpcm.play("hone2.wav");
    }
    else if (results.value == 1074791652) {//hone3
      tmrpcm.play("hone3.wav");
    }
    else if (results.value == 1074793708) {//hone4
      tmrpcm.play("hone4.wav");
    }
    else if (results.value == 1074792905 || results.value == 1075383895) {//left signal
      leftSignal();
    }
    else if (results.value == 1074793660 || results.value == 1074791090) {//right signal
      rightSignal();
    }
    else if (results.value == 1074923445) {//head light
      headLight();
    }
    else if (results.value == 1074791620) {//dim light
      dimLight();
    }
    else if (results.value == 1074791106) {//head light off
      headOff();
    }
    else if (results.value == 1074793162) {//break light off
      digitalWrite(A2, LOW);
    }
    else if (results.value == 1074790464) {//parcking
      parking();
    }
    else if (results.value == 1074792520) {//parking off
      parkingOff();
    }
    else if (results.value == 1074790528) {//line light
      lineLight();
    }
    else if (results.value == 1074792584) {//trangle light
      trangleLight();
    }
    else if (results.value == 1074791556) {//none
      none();
    }
    else if (results.value == 1074793612) {//vip light
      vip();
    }
    else if (results.value == 1074791042) {//blink1
      Blink1();
    }
    else if (results.value == 1074793098) {//blink2
      Blink2();
    }
    else if (results.value == 1074792070) {//round light
      Round();
    }
    else if (results.value == 1074794126) {//double side light
      doubleSide();
    }
    else if (results.value == 1074790785) {//all in one blink light
      allInOne();
    }
    else if (results.value == 1074793580) {//song1
      tmrpcm.play("song1.wav");
    }
    else if (results.value == 1074792841) {//song2
      tmrpcm.play("song2.wav");
    }
    else if (results.value == 1074794190) {//song3
      tmrpcm.play("song3.wav");
    }
  }

  irrecv.resume();
}
