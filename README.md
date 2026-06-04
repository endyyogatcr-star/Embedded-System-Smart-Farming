# Embedded-System-Smart-Farming

--
## Perankat yang digunakan:
ESP8266 (NodeMCU/Wemos D1 Mini)
Sensor DHT22 (suhu dan kelembaban)
Sensor Gas (MQ-2)
Motor Servo MG90S
LED

## Fungsi Sistem:
Membaca suhu dan kelembaban dari DHT22.
Membaca kadar gas dari sensor gas.
Menyalakan LED jika kadar gas melebihi batas.
Membuka ventilasi (servo 90°) jika:
Suhu terlalu tinggi (> 30°C), atau
Gas melebihi ambang batas.
Menutup ventilasi (servo 0°) jika kondisi normal.
Menampilkan data pada Serial Monitor.

## Library yang Dibutuhkan
Install melalui Arduino IDE:
DHT sensor library
Adafruit Unified Sensor
Servo

## Wiring Diagram
| Komponen | ESP8266 |
|-----------|----------|
| DHT22 VCC | 3.3V |
| DHT22 GND | GND |
| DHT22 DATA | D4 (GPIO2) |
| Sensor Gas AO | A0 |
| Sensor Gas VCC | 5V |
| Sensor Gas GND | GND |
| LED (+) | D5 (GPIO14) |
| LED (-) | GND melalui resistor |
| Servo Signal | D6 (GPIO12) |
| Servo VCC | 5V Eksternal |
| Servo GND | GND |
