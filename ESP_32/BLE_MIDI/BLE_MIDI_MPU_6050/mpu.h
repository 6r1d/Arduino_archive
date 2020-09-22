// I2C address of the MPU-6050
const uint16_t MPU_addr = 0x68;
int16_t A_X, A_Y, A_Z, G_X, G_Y, G_Z;
float ax, ay, az, gx, gy, gz;

// Enables MPU-6050 accelerometer / gyroscope
void start_accelerometer() {
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  // Select PWR_MGMT_1 register
  Wire.write(0x6B);
  // Set PWR_MGMT_1 to zero to wake up the MPU-6050
  Wire.write(0);
  Wire.endTransmission(true);
}

void read_mpu() {
  // Start transmission with accelerometer
  Wire.beginTransmission(MPU_addr);
  // Starting with register 0x3B (ACCEL_XOUT_H)
  Wire.write(0x3B);
  Wire.endTransmission(false);
  // Request a total of 14 registers
  Wire.requestFrom(MPU_addr, 14, true);
  // Read accelerometer and gyroscope
  A_X = Wire.read() << 8 | Wire.read(); // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
  A_Y = Wire.read() << 8 | Wire.read(); // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  A_Z = Wire.read() << 8 | Wire.read(); // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  G_X = Wire.read() << 8 | Wire.read(); // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  G_Y = Wire.read() << 8 | Wire.read(); // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  G_Z = Wire.read() << 8 | Wire.read(); // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
  ax = A_X / 32767.0; ay = A_Y / 32767.0; az = A_Z / 32767.0;
  gx = G_X / 32767.0; gy = G_Y / 32767.0; gz = G_Z / 32767.0;
}
