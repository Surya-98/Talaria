/**
 * @file analog_device.h
 * @author Hao Yang (hyang6@wpi.edu)
 * @brief
 * @version 0.1
 * @date 2019-10-10
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef ANALOG_DEVICE_H
#define ANALOG_DEVICE_H

#include "mbed.h"
#include "device.h"

class AnalogDevice : public AnalogIn, public Device
{
private:
  bool _init_status;
  bool readReady = false;

  uint8_t _id;
  PinName _a0;

public:
  /** CONSTRUCTORS */

  /**
   * @brief Construct a new AnalogDevice object
   *
   * @param id
   * @param a0
   */
  AnalogDevice(uint8_t id, PinName a0, uint8_t dev_index = 0)
    : AnalogIn(a0), Device(dev_index), _id(id), _a0(a0)
  {
    _init_status = true;
  }

  /** DESTRUCTORS */

  /**
   * @brief Destroy the AnalogDevice object
   *
   */
  virtual ~AnalogDevice()
  {
  }

  /** METHODS */

  /**
   * @brief Ping the device to check if connection can be established
   *
   * @param chip_id_reg_address
   * @return true
   * @return false
   */
  virtual bool ping(uint8_t chip_id_reg_address = 0x00)
  {
    if (readReady == true)
    {
      setHealthStatus(true);
      setConfiguredStatus(true);
      setEnabledStatus(true);
      readReady = false;
      return true;
    }
    else
      return false;
  }

  virtual float readAnalogData(float Vin)
  {
    float analogData;
    uint16_t delay_ms = 100;
    analogData = this->read();
    float GF = 2;
    float strain;
    strain = analogData / Vin;
    readReady = true;
    // wait_ms(delay_ms);

    return strain;
  }
};

#endif  // ANALOG_DEVICE_H