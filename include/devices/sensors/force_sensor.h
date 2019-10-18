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
  enum REGISTER_ADDRESS
  {
    CHIP_ID = 0x68,

    POLLING_ID = 0x12
  } reg_addr;

protected:
public:
  // CONSTRUCTORS

  BMI_160(int address, uint8_t bus_Id, uint8_t dev_index)
    : I2CDevice(address, bus_Id, dev_index)
  {
  }

  // DESTRUCTORS
  virtual ~BMI_160()
  {
  }

  // GETTERS

  // SETTERS

  // METHODS
};

#endif  // BMI_160_H

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