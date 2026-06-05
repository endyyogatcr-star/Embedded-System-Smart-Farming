#include <DHT.h>
#include <Servo.h>

// =======================
// Konfigurasi Pin
// =======================
#define DHTPIN D4
#define DHTTYPE DHT22

#define GAS_PIN A0
#define LED_PIN D5
#define SERVO_PIN D6

// =======================
// Objek
// =======================
DHT dht(DHTPIN, DHTTYPE);
Servo ventilasi;

// =======================
// Variabel
// =======================
float suhu;
float kelembaban;
int gasValue;

// Ambang batas
const float BATAS_SUHU_PANAS = 30.0;
const float BATAS_SUHU_DINGIN = 15.0;
const int BATAS_GAS = 500;

void setup() {
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);

  dht.begin();

  ventilasi.attach(SERVO_PIN);
  ventilasi.write(0);

  Serial.println("=== SMART FARMING SYSTEM ===");
}

void loop() {

  // Membaca DHT22
  suhu = dht.readTemperature();
  kelembaban = dht.readHumidity();

  // Membaca sensor gas
  gasValue = analogRead(GAS_PIN);

  // Cek apakah pembacaan DHT gagal
  if (isnan(suhu) || isnan(kelembaban)) {
    Serial.println("Gagal membaca DHT22!");
    delay(2000);
    return;
  }

  // ======================
  // Tampilkan Data
  // ======================
  Serial.println("---------------");
  Serial.print("Suhu       : ");
  Serial.print(suhu);
  Serial.println(" °C");

  Serial.print("Kelembaban : ");
  Serial.print(kelembaban);
  Serial.println(" %");

  Serial.print("Gas        : ");
  Serial.println(gasValue);

  // ======================
  // Kontrol LED
  // ======================
  if (suhu > BATAS_SUHU_DINGIN) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("PERINGATAN: Suhu terlalu dingin, mengaktifkan led");
  }
  else {
    digitalWrite(LED_PIN, LOW);
  }

  // ======================
  // Kontrol Servo
  // ======================
  if (suhu > BATAS_SUHU_PANAS || gasValue > BATAS_GAS) {

    ventilasi.write(90);

    Serial.println("Ventilasi TERBUKA");
  }
  else {

    ventilasi.write(0);

    Serial.println("Ventilasi TERTUTUP");
  }

  delay(2000);
}
