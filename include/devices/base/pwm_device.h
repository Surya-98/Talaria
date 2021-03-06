/**
 * @file analog_device.h
 * @author Raunak Hosangadi (rphosangadi@wpi.edu)
 * @brief
 * @version 0.1
 * @date 2019-10-05
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef PWM_DEVICE_H
#define PWM_DEVICE_H

#include "devices/base/device.h"
#include "devices/hardware.h"

#ifndef PIO_FRAMEWORK_ARDUINO_PRESENT
#include "mbed.h"
#else
#include "Arduino.h"
#endif

#ifndef PIO_FRAMEWORK_ARDUINO_PRESENT
class PwmDevice : public PwmOut
{
private:
  PinName _pwm_pin;

public:
  /** CONSTRUCTORS */
  PwmDevice(PinName pwm_pin) : PwmOut(pwm_pin), _pwm_pin(pwm_pin)
  {
  }

  /** DESTRUCTORS */

  /**
   * @brief Destroy the PwmDevice object
   *
   */
  virtual ~PwmDevice()
  {
  }

  /** METHODS */
  virtual void writePWMData(float dutyCycle = .50, float pulsePeriod = 0.1)
  {
    float pwmData = dutyCycle;
    // this->period_ms(pulsePeriod);
    if (pwmData >= 1.)
      pwmData = 0.99;
    this->write(pwmData);
  }
};
#else
class PwmDevice
{
private:
  int _pwm_pin;

public:
  /** CONSTRUCTORS */
  PwmDevice(int pwm_pin) : _pwm_pin(pwm_pin)
  {
    pinMode(_pwm_pin, OUTPUT);
  }

  /** DESTRUCTORS */

  /**
   * @brief Destroy the PwmDevice object
   *
   */
  virtual ~PwmDevice()
  {
  }

  /** METHODS */
  virtual void writePWMData(float dutyCycle = 1)
  {
    int pwmData = map(dutyCycle * 1000, 0, 3300, 0, 255);

    analogWrite(_pwm_pin, pwmData);
  }
};
#endif

#endif  // ANALOG_DEVICE_H