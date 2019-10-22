/**
 * @file device_manager.h
 * @author Dhruv Kool Rajamani (dkoolrajamani@wpi.edu)
 * @brief
 * @version 0.1
 * @date 2019-10-07
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef DEVICE_MANAGER_H
#define DEVICE_MANAGER_H

#include "mbed.h"
#include "devices/hardware.h"

#include "devices/base/device.h"

#include "devices/imu/bmi_160.h"

class DeviceManager
{
private:
  static const int BYTE_STREAM_PUB_SIZE = 100;
  static const int BYTE_STREAM_SUB_SIZE = 20;
  Device* _devices[NUM_DEVICES];

  uint8_t _byte_stream_pub[BYTE_STREAM_PUB_SIZE];
  uint8_t _byte_stream_sub[BYTE_STREAM_SUB_SIZE];

protected:
public:
  /** VARIABLES */
  enum DEV_INDEX
  {
    IMU = 0,
    ENCODER = 1
  };

  /** CONSTRUCTORS */

  DeviceManager();

  /** DESTRUCTOR */
  virtual ~DeviceManager()
  {
  }

  /** GETTERS */

  /** SETTERS */

  /** METHODS */

  bool initialize();

  bool addDevice(Device* device, int index);

  bool readByteStream(/* Add callback ptr*/);

  void writeByteStream();

  void initializeDevices();

  void updateDevices();
};

extern DeviceManager device_manager;

#endif  // DEVICE_MANAGER_H