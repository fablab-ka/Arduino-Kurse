void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  digitalWrite(13,LOW);

  pinMode(3, INPUT);
  digitalWrite(3, HIGH);
}

bool letzter_zustand = false;

void loop() {
  bool zustand = digitalRead(3);
  if(zustand == true && letzter_zustand == false) {
    bool led_zustand = digitalRead(13); 
    digitalWrite(13, !led_zustand);
  }
  letzter_zustand = zustand;
}
