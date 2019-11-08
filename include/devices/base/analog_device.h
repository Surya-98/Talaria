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
<<<<<<< HEAD
  bool _init_status;
=======
>>>>>>> a3bd8829ed70c97131a9f4f5f41356713e7d4c82
  bool readReady = false;

  uint8_t _id;
  PinName _a0;

<<<<<<< HEAD
public:
  /** CONSTRUCTORS */

=======
  float _Vin = 3.3;

public:
  /** CONSTRUCTORS */

#ifndef DISABLE_ROS
  AnalogDevice(uint8_t id, PinName a0, ros::NodeHandle& nh,
               uint8_t dev_index = 0, const char* dev_name = NULL,
               const char* topic_name = NULL)
    : AnalogIn(a0)
    , Device(dev_index, nh, dev_name, topic_name)
    , _id(id)
    , _a0(a0)
  {
    setIndex(dev_index);
    setHealthStatus(true);
    setEnabledStatus(true);
  }
#else
>>>>>>> a3bd8829ed70c97131a9f4f5f41356713e7d4c82
  /**
   * @brief Construct a new AnalogDevice object
   *
   * @param id
   * @param a0
   */
  AnalogDevice(uint8_t id, PinName a0, uint8_t dev_index = 0)
    : AnalogIn(a0), Device(dev_index), _id(id), _a0(a0)
  {
<<<<<<< HEAD
    _init_status = true;
  }
=======
    setIndex(dev_index);
    setHealthStatus(true);
    setEnabledStatus(true);
  }
#endif
>>>>>>> a3bd8829ed70c97131a9f4f5f41356713e7d4c82

  /** DESTRUCTORS */

  /**
   * @brief Destroy the AnalogDevice object
   *
   */
  virtual ~AnalogDevice()
  {
  }

  /** METHODS */

<<<<<<< HEAD
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
=======
  // /**
  //  * @brief Ping the device to check if connection can be established
  //  *
  //  * @param chip_id_reg_address
  //  * @return true
  //  * @return false
  //  */
  // virtual bool ping(uint8_t chip_id_reg_address = 0x00)
  // {
  //   if (readReady == true)
  //   {
  //     setHealthStatus(true);
  //     setConfiguredStatus(true);
  //     setEnabledStatus(true);
  //     readReady = false;
  //     return true;
  //   }
  //   else
  //     return false;
  // }

  virtual float readAnalogData(uint16_t delay_ms = 100)
  {
    float analogData;
    analogData = this->read() * _Vin;
    readReady = true;
    // wait_ms(delay_ms);

    return analogData;
  }

  /** GETTERS */

  /**
   * @brief Get the Vin object
   *
   * @return float
   */
  float getVin()
  {
    return _Vin;
>>>>>>> a3bd8829ed70c97131a9f4f5f41356713e7d4c82
  }
};

#endif  // ANALOG_DEVICE_H