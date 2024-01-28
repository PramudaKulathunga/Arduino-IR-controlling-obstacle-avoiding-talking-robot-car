
void forward() {
  digitalWrite(A2, LOW);//break light off
  parkingOff();
  digitalWrite(A1, LOW); //reverse light off
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(8, LOW);
}

void back() {
  digitalWrite(A2, LOW);//break light off
  parkingOff();
  digitalWrite(A1, HIGH); //reverse light on
  tmrpcm.play("back.wav");
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(8, HIGH);
}

void left() {
  digitalWrite(A2, LOW);//break light off
  parkingOff();
  digitalWrite(A1, LOW); //reverse light off
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(8, LOW);
}

void right() {
  digitalWrite(A2, LOW);//break light off
  parkingOff();
  digitalWrite(A1, LOW); //reverse light off
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(6, LOW);
  digitalWrite(8, HIGH);
}

void Stop() {
  digitalWrite(A1, LOW); //reverse light off
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(6, LOW);
  digitalWrite(8, LOW);
  digitalWrite(A2, HIGH);// break light on
}
