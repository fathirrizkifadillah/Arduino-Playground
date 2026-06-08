#define TRIG_PIN 9
#define ECHO_PIN 10

#define LED_HIJAU 2
#define LED_KUNING 3
#define LED_MERAH 4

#define BUZZER_PIN 8

void setup() {
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(LED_HIJAU, OUTPUT);
  pinMode(LED_KUNING, OUTPUT);
  pinMode(LED_MERAH, OUTPUT);

  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);

  float distance = duration * 0.034 / 2;

  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Matikan semua LED dulu
  digitalWrite(LED_HIJAU, LOW);
  digitalWrite(LED_KUNING, LOW);
  digitalWrite(LED_MERAH, LOW);

  // Aman
  if (distance > 50) {
    digitalWrite(LED_HIJAU, HIGH);

    tone(BUZZER_PIN, 1000) ;
    delay(1000);
    noTone(BUZZER_PIN);
    delay(1000);
  }

  // Waspada
  else if (distance > 20) {
    digitalWrite(LED_KUNING, HIGH);

    tone(BUZZER_PIN, 1000);
    delay(300);
    noTone(BUZZER_PIN);
    delay(300);
  }

  // Bahaya
  else if (distance > 10) {
    digitalWrite(LED_MERAH, HIGH);

    tone(BUZZER_PIN, 1500);
    delay(100);
    noTone(BUZZER_PIN);
    delay(100);
  }

  // Sangat dekat
  else {
    digitalWrite(LED_MERAH, HIGH);
    tone(BUZZER_PIN, 2000);
  }
}