#include <SoftwareSerial.h>
#include <ModbusRTUMaster.h>

const uint8_t txpin = 6;
const uint8_t rxpin = 5;

// Untuk kebutuhan simulasi
// dari Arduino mengirim value ke PC
// pada software pilih baudrate 38400

SoftwareSerial ss(rxpin, txpin);
ModbusRTUMaster ModMaster(ss);

String incomingData;

uint16_t holdingRegister[4];
bool coilStatus[4];


void setup() {
  Serial.begin(9600);
  ModMaster.begin(38400);
}

void loop() {

  if(Serial.available()){
    incomingData = Serial.readStringUntil("\n");
    incomingData.trim();
    incomingData.replace("\n", "");

    Serial.println(incomingData);

    ModMaster.writeSingleHoldingRegister(1, 0, incomingData.toInt());
  }

  ModMaster.writeSingleCoil(1, 4, true);
  delay(500);
  ModMaster.writeSingleCoil(1, 4, false);
  delay(500);

}
