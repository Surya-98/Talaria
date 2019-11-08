#include "mbed.h"
#include <ros.h>
#include <std_msgs/String.h>
#include "devices/imu/bmi_160.h"

#include "devices/base/analog_device.h"

using namespace ros;

I2CBus BodyBus(0, PC_9, PA_8);
I2CBus KneeBus(1, PF_0, PF_1);
I2CBus AnkleBus(2, PD_13, PD_12);
I2CBus FootBus(3, PB_9, PB_8);

I2CBus Busses[4] = { BodyBus, KneeBus, AnkleBus, FootBus };
I2CBus* I2CBusses = Busses;

BMI_160 Imu(0x68, 3, 0);

NodeHandle nh;

std_msgs::String network_msg;
Publisher network_pub("network_strings", &network_msg);

AnalogDevice ReadStrain(0, PC_0, 1);

char hello_msg[50] = "";

int main()
{
  nh.initNode();
  nh.advertise(network_pub);

  while (1)
  {

    char hello[14] = "Hello World!\n";

    if (Imu.ping())
    {
      sprintf(hello_msg, "Chip Id is: %x\n", Imu.getChipId());
    }
    else
    {
      sprintf(hello_msg, "Error");
    }
  
    
    //if (ReadStrain.ping())
    // {
    //   sprintf(hello_msg, "Strain = %f \n", ReadStrain.readAnalogData(5.0));
    // }
    // else
    // {
    //   sprintf(hello_msg, "Error");
    // }

  
    //printf("Read status = %d \n", ReadStrain.ping());
    //printf(hello);
    //wait_ms(1000);

    network_msg.data = hello_msg;
    network_pub.publish(&network_msg);

    nh.spinOnce();
    wait_ms(1000);
  }

  return 0;
}
