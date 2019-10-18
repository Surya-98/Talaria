/**
 * @file bmi_160.h
 * @author Dhruv Kool Rajamani (dkoolrajamani@wpi.edu)
 * @brief
 * @version 0.1
 * @date 2019-10-02
 *
 * @copyright Copyright (c) 2019
 *
 */


/**
 * @file potentiometer.h
 * @author Hao Yang (hyang6@wpi.edu)
 * @brief
 * @version 0.1
 * @date 2019-10-18
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

#include "devices/base/analog_device.h"

class potentiometer : public AnalogDevice
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

  potentiometer(uint8_t id, PinName a0, uint8_t dev_index = 0)
    : AnalogDevice(id, a0, dev_index)
  {
  }

  // DESTRUCTORS
  virtual ~potentiometer()
  {
  }

  // GETTERS

  // SETTERS

  // METHODS
};

#endif  // POTENTIOMETER_H