int t = 300;
int t2 = 200;

void lineLight() {
  none();
  digitalWrite(A0, HIGH);
}

void trangleLight() {
  none();
  digitalWrite(5, HIGH);
}

void none() {
  digitalWrite(A0, LOW);
  digitalWrite(5, LOW);
}

void vip() {
  none();
  tmrpcm.play("vip.wav");

  for (int a = 0; a < 24; a++) {
    digitalWrite(A0, HIGH);
    delay(t);
    digitalWrite(A0, LOW);
    delay(t);
  }
  none();
}

void Blink1() {
  none();

  for (int b = 0; b < 5; b++) {
    digitalWrite(A0, HIGH);
    digitalWrite(5, HIGH);
    delay(t);
    digitalWrite(A0, LOW);
    digitalWrite(5, LOW);
    delay(t);
  }
  none();
}

void Blink2() {
  none();

  for (int b = 0; b < 5; b++) {
    digitalWrite(A0, HIGH);
    digitalWrite(5, LOW);
    delay(t);
    digitalWrite(A0, LOW);
    digitalWrite(5, HIGH);
    delay(t);
  }
  none();
}

void Round() {
  for (int b = 0; b < 2; b++) {
    digitalWrite(A0, HIGH);
    delay(t2);
    digitalWrite(5, HIGH);
    delay(t2);
    digitalWrite(A3, HIGH);
    delay(t2);
    digitalWrite(A2, HIGH);
    delay(t2);
    digitalWrite(A1, HIGH);
    delay(t2);
    digitalWrite(A4, HIGH);
    delay(t2);
    digitalWrite(A0, LOW);
    delay(t2);
    digitalWrite(5, LOW);
    delay(t2);
    digitalWrite(A3, LOW);
    delay(t2);
    digitalWrite(A2, LOW);
    delay(t2);
    digitalWrite(A1, LOW);
    delay(t2);
    digitalWrite(A4, LOW);
    delay(t2);
  }
}

void doubleSide() {
  for (int x = 0; x < 2; x++) {
    digitalWrite(A0, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(A1, HIGH);
    digitalWrite(A2, HIGH);
    delay(t);
    digitalWrite(A0, LOW);
    digitalWrite(5, LOW);
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
    delay(t);
    digitalWrite(A0, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(A1, HIGH);
    digitalWrite(A2, HIGH);
    delay(t);
    digitalWrite(A0, LOW);
    digitalWrite(5, LOW);
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
    delay(t);
    digitalWrite(A3, HIGH);
    digitalWrite(A4, HIGH);
    delay(t);
    digitalWrite(A3, LOW);
    digitalWrite(A4, LOW);
    delay(t);
    digitalWrite(A3, HIGH);
    digitalWrite(A4, HIGH);
    delay(t);
    digitalWrite(A3, LOW);
    digitalWrite(A4, LOW);
    delay(t);
  }
}

void allInOne() {
  for (int x = 0; x < 3; x++) {
    digitalWrite(A0, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(A1, HIGH);
    digitalWrite(A2, HIGH);
    digitalWrite(A3, HIGH);
    digitalWrite(A4, HIGH);
    delay(t);
    digitalWrite(A0, LOW);
    digitalWrite(5, LOW);
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(A3, LOW);
    digitalWrite(A4, LOW);
    delay(t);
  }
}
