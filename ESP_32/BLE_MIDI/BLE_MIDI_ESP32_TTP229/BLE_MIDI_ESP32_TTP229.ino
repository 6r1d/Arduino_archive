#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLE2902.h>
#include "midi_signal.h"

/**/
#include <Wire.h>
#include <TTP229.h>
TTP229 ttp229;
int keys[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
bool key_pressed;
/**/

#include "esp32-hal-adc.h"

#define SERVICE_UUID "03b80e5a-ede8-4b33-a751-6ce34ec4c700"
#define CHARACTERISTIC_UUID "7772e5db-3868-4112-a1a9-f2669d106bf3"

BLECharacteristic *pCharacteristic;

class MyCharacteristicCallback : public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic *pChar) {
      //uint8_t value[5] = {0};
      //memcpy(value, pChar->getValue().c_str(), 5);
      //ESP_LOGW(LOG_TAG, "command: %d, note: %d, data: %d, %d, %d", value[2], value[3], value[0], value[1], value[4]);
    }
};

class MyCallbacks : public BLEServerCallbacks
{
  public: bool deviceConnected = false;
    void onConnect(BLEServer* pServer, esp_ble_gatts_cb_param_t *param) {
      pServer->updateConnParams(param->connect.remote_bda, 0x01, 0x90, 0, 800);
      deviceConnected = true;
    }

    void onDisconnect(BLEServer *pServer) {
      deviceConnected = false;
    }
};
MyCallbacks *callbacks_instance;

void setup() {
  Serial.begin(115200);
  Wire.begin();

  BLEDevice::init("Bluetooth Keyboard");
  BLEServer *pServer = BLEDevice::createServer();

  callbacks_instance = new MyCallbacks();

  pServer->setCallbacks(callbacks_instance);

  BLEService *pService = pServer->createService(SERVICE_UUID);
  pCharacteristic = pService->createCharacteristic(CHARACTERISTIC_UUID,
                    BLECharacteristic::PROPERTY_READ |
                    BLECharacteristic::PROPERTY_NOTIFY |
                    BLECharacteristic::PROPERTY_WRITE_NR);

  pCharacteristic->setCallbacks(new MyCharacteristicCallback());

  pCharacteristic->addDescriptor(new BLE2902());
  pService->start();

  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(pService->getUUID());
  pAdvertising->start();

  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x12);
  pAdvertising->setMaxPreferred(0x16);
  BLEDevice::startAdvertising();

  BLESecurity *pSecurity = new BLESecurity();
  pSecurity->setAuthenticationMode(ESP_LE_AUTH_REQ_SC_BOND);
}

void loop() {
  ttp229.readKeys();

  if (callbacks_instance->deviceConnected) {
    for (int i = 0; i < 16; ++i) {
      key_pressed = ttp229.isKeyPress(i);
      if (key_pressed != keys[i]) {
        if (keys[i]) {
          send_note_off(pCharacteristic, i + 60);
        }
        else {
          send_note_on(pCharacteristic, i + 60);
        }
      }
      keys[i] = key_pressed;
    }
  }
}
