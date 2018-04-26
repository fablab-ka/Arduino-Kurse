int pin_btn = 3;               //Pin 3: Knopf
int pin_led = 12;               //Pin 3: LED

void setup() {
  Serial.begin(9600);          //Verbindung zum PC initialisieren
  Serial.println("Starte das Programm!"); //Nachricht schicken
  
  pinMode(pin_btn, INPUT);     //Den Taster-Pin auf "nicht-Ausgabe" stellen
  digitalWrite(pin_btn, HIGH); //Den Taster-Pin über 10kOhm mit 5V verbinden
  pinMode(pin_led, OUTPUT);    //Den LED-Pin auf "Ausgabe" stellen
  digitalWrite(pin_led, LOW);  //An den LED-Pin Masse anlegen
}

long reaktionszeit = 500;      //Der Startwert für unseren Reaktionszeit-Tester

void loop() {
  delay(random(1000,3000));    //Warte zwischen 1 und 3 Sekunden
  long aktion = millis();      //Speichere die Zeit in ms
  digitalWrite(pin_led, HIGH); //Schalte die LED ein
  while(digitalRead(pin_btn) != 0) { //Prüfe ob der Knopf gedrückt wurde
    delay(1);                  //Warte 1ms zwischen Prüfungen
  }
  long reaktion = millis();    //Speichere die Zeit in ms
  
  if(reaktion - aktion <= reaktionszeit) {
    //Der Teilnehmer hat den Test bestanden!
    Serial.println("Geschafft");
    reaktionszeit = reaktionszeit * 0.9; //Weniger Zeit beim nächsten Mal!
    for(int i = 0; i < 10; i++) { //Lasse die LED blinken
      digitalWrite(pin_led, HIGH);
      delay(100);
      digitalWrite(pin_led, LOW);
      delay(100);
    }
  } else {
    //Der Teilnehmer war zu langsam!
    Serial.println("Nicht geschafft!");
    delay(1000); 
    digitalWrite(pin_led, LOW);
    
  }
  delay(1000);
}
