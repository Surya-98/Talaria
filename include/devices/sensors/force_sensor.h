/**
 * @file force_sensor.h
 * @author Hao Yang (hyang6@wpi.edu)
 * @brief
 * @version 0.1
 * @date 2019-10-18
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef FORECE_SENSOR_H
#define FORECE_SENSOR_H

#include "devices/base/analog_device.h"

class force_sensor : public AnalogDevice
{
private:
//   enum REGISTER_ADDRESS
//   {
//     CHIP_ID = 0x68,

//     POLLING_ID = 0x12
//   } reg_addr;

protected:
public:
  // CONSTRUCTORS

  force_sensor(uint8_t id, PinName a0, uint8_t dev_index = 0)
    : AnalogDevice(id, a0, dev_index)
  {
  }

  // DESTRUCTORS
  virtual ~force_sensor()
  {
  }

  // GETTERS

  // SETTERS

  // METHODS
};

#endif  // FORECE_SENSOR_H
