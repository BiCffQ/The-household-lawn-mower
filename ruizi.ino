/*
  D13			D12			右2
  3V3			D11			右1
  REF			D10			左2
  A0			D9			左1
  A1			D8			继电器
  A2			D7
  A3			D6			D
  A4			D5			C
  A5			D4			B
  A6			D3			A
  A7			D2			公共
  5V			GND
  RST			RST
  GND			RXD
  VIN			TXD

*/
int state = 0;
//void(* resetFunc) (void) = 0;
void attachInterrupt_fun_2() {
  if (digitalRead(5) == HIGH) {
    control();
  } else if (digitalRead(3) == HIGH) {
    left();
  } else if (digitalRead(4) == HIGH) {
    right();
  } else {
    go();
  }
}

void control() {
  state = !state;
  digitalWrite(8, state);
}

void right() {
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
}

void left() {
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
}
void go() {
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);

}
void stop() {
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH );
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);

}
void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(8, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  stop();
}

void loop() {
  attachInterrupt(digitalPinToInterrupt(2), attachInterrupt_fun_2, RISING);
  if (digitalRead(6) == 1) {
    go();
  } else {
    stop();
  }
}
