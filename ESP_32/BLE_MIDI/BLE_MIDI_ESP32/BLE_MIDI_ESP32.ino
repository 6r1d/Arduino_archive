/*
 * This demo registers as "Bluetooth Keyboard" BLE device.
 * It plays a middle C note / MIDI 60 / 261.625565 Hz.
 */

#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLE2902.h>
#include "midi_signal.h"

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
  BLEDevice::init("Bluetooth MIDI Keyboard");

  // Create the BLE Server
  BLEServer *pServer = BLEDevice::createServer();

  callbacks_instance = new MyCallbacks();

  pServer->setCallbacks(callbacks_instance);

  // Create the BLE Service
  BLEService *pService = pServer->createService(SERVICE_UUID);

  // Create a BLE Characteristic
  pCharacteristic = pService->createCharacteristic(CHARACTERISTIC_UUID,
                    BLECharacteristic::PROPERTY_READ |
                    BLECharacteristic::PROPERTY_NOTIFY |
                    BLECharacteristic::PROPERTY_WRITE_NR);

  pCharacteristic->setCallbacks(new MyCharacteristicCallback());

  // Create a BLE Descriptor
  pCharacteristic->addDescriptor(new BLE2902());

  // Start the service
  pService->start();

  // Start advertising
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(pService->getUUID());
  pAdvertising->start();

  pAdvertising->setScanResponse(true);

  // Apparently, this timing helps
  // with some iPhone connection issue
  pAdvertising->setMinPreferred(0x06);
  pAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();

  BLESecurity *pSecurity = new BLESecurity();
  pSecurity->setAuthenticationMode(ESP_LE_AUTH_REQ_SC_BOND);
}

void loop() {
  if (callbacks_instance->deviceConnected) {
    // "Press" a midddle C key using MIDI
    send_note_on(pCharacteristic, 60);
    delay(100);
    // Release a middle C key using MIDI
    send_note_off(pCharacteristic, 60);
    delay(100);
  }
}
