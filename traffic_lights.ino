#include <Arduino.h>

int Buzzer = 7;
int Lampu_Merah  = 8;
int Lampu_Kuning = 9;
int Lampu_Hijau  = 10;

void beep() {
    tone(Buzzer, 3000);  // frekuensi 3000 Hz
    delay(500);          // bunyi 0.5 detik
    noTone(Buzzer);      // matikan buzzer
}

void setup() {
    pinMode(Buzzer, OUTPUT);

    pinMode(Lampu_Merah, OUTPUT);
    pinMode(Lampu_Kuning, OUTPUT);
    pinMode(Lampu_Hijau, OUTPUT);
}

void loop() {

    // Merah nyala
    digitalWrite(Lampu_Merah, HIGH);
    digitalWrite(Lampu_Kuning, LOW);
    digitalWrite(Lampu_Hijau, LOW);
    delay(5000);

    beep();

    // Kuning nyala
    digitalWrite(Lampu_Merah, LOW);
    digitalWrite(Lampu_Kuning, HIGH);
    digitalWrite(Lampu_Hijau, LOW);
    delay(1000);

    beep();

    // Hijau nyala
    digitalWrite(Lampu_Merah, LOW);
    digitalWrite(Lampu_Kuning, LOW);
    digitalWrite(Lampu_Hijau, HIGH);
    delay(5000);

    beep();

    // Kuning nyala
    digitalWrite(Lampu_Merah, LOW);
    digitalWrite(Lampu_Kuning, HIGH);
    digitalWrite(Lampu_Hijau, LOW);
    delay(1000);

    beep();
}