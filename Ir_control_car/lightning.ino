int signal_Light_pin;

void rightSignal() {
  tmrpcm.play("signal.wav");
  signal_Light_pin = A4;
  displaySignal();
}

void leftSignal() {
  tmrpcm.play("signal.wav");
  signal_Light_pin = A3;
  displaySignal();
}

void displaySignal() {
  for (int y = 0; y < 5; y++) {
    digitalWrite(signal_Light_pin, HIGH);
    delay(300);
    digitalWrite(signal_Light_pin, LOW);
    delay(300);
  }
}

void parking() {
  tmrpcm.play("parking.wav");
  digitalWrite(A3, HIGH);
  digitalWrite(A4, HIGH);
  delay(300);
  digitalWrite(A3, LOW);
  digitalWrite(A4, LOW);
  delay(300);
  digitalWrite(A3, HIGH);
  digitalWrite(A4, HIGH);
  delay(300);
}

void parkingOff() {
  digitalWrite(A3, LOW);
  digitalWrite(A4, LOW);
}

void headOff() {
  digitalWrite(5,HIGH);
  for (int x = 255; x > -1; x--) {
    analogWrite(5, x );
    delay(8);
  }
}

void headLight() {
  for (int x = 0; x < 256; x++) {
    analogWrite(5, x );
    delay(8);
  }
}

void dimLight() {
  for (int x = 0; x < 131; x++) {
    analogWrite(5, x );
    delay(8);
  }
}
