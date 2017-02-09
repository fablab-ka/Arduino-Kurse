//Pin 2: Knopf
//Pin 3: LED

void setup() {
  Serial.begin(9600);
  Serial.println("Starte das Programm!");
  pinMode(2, INPUT);
  digitalWrite(2, HIGH);

  pinMode(3, OUTPUT);
  digitalWrite(3, LOW);
}

long reaktionszeit = 500;

void loop() {
  delay(random(1000,3000));    //Warte zwischen 1 und 3 Sekunden
  long aktion = millis(); //Speichere die Zeit in ms
  digitalWrite(3, HIGH);       //Schalte die LED ein
  while(digitalRead(2) != 0) { //Warte bis der Knopf gedrückt wird
    delay(1);
  }
  long reaktion = millis();

  
  if(reaktion - aktion <= reaktionszeit) {
    Serial.println("Geschafft");
    reaktionszeit = reaktionszeit * 0.9;
    for(int i = 0; i < 10; i++) {
      digitalWrite(3, HIGH);
      delay(100);
      digitalWrite(3, LOW);
      delay(100);
    }
  } else {
    Serial.println("Nicht geschafft!");
    digitalWrite(3, LOW);
  }
  delay(1000);
}
