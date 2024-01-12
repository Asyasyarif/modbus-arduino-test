#include <SoftwareSerial.h>
#include <ModbusRTUSlave.h>


// Untuk kebutuhan simulasi
// dari PC (Software Modbus Poll) mengirim value ke Arduino
// pada software pilih baudrate 38400

const uint8_t txpin = 6;
const uint8_t rxpin = 5;

SoftwareSerial ss(rxpin, txpin);
ModbusRTUSlave ModSlave(ss);

String incomingData;

uint16_t holdingRegister[4];
bool coilStatus[4];


void setup() {
  ModSlave.configureCoils(coilStatus, 4);
  ModSlave.configureHoldingRegisters(holdingRegister, 4);
  Serial.begin(9600);
  ModSlave.begin(3, 38400);
}

void loop() {
  ModSlave.poll();

  Serial.println("========================");
  Serial.println("Holding Register 0 - " + String(holdingRegister[0]));
  Serial.println("Holding Register 1 - " + String(holdingRegister[1]));
  Serial.println("Holding Register 2 - " + String(holdingRegister[2]));
  Serial.println("Holding Register 3 - " + String(holdingRegister[3]));
  Serial.println("Coil Status 0 - " + String(coilStatus[0]));
  Serial.println("Coil Status 1 - " + String(coilStatus[1]));
  Serial.println("Coil Status 2 - "+ String(coilStatus[2]));
  Serial.println("Coil Status 3 - "+ String(coilStatus[3]));
  Serial.println("========================");
  delay(200);
}
