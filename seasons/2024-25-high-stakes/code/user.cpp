#include "vex.h"
#include "user.h"

int f1= 0;
int f2= 0;
int f3 = 0;
int f4 = 0;
int sudu = 100;

//底盘操控方式
void Drive::control_tank(){
  float throttle = deadband(controller(primary).Axis3.value(), 5);
  float turn = deadband(controller(primary).Axis1.value(), 5);
  DriveL.spin(fwd, to_volt(throttle+turn), volt);
  DriveR.spin(fwd, to_volt(throttle-turn), volt);
}

// void Drive::control_tank(){
//   float throttle = deadband(controller(primary).Axis2.value(), 5);
//   float turn = deadband(controller(primary).Axis1.value(), 5);
//   DriveL.spin(fwd, to_volt(throttle+turn), volt);
//   DriveR.spin(fwd, to_volt(throttle-turn), volt);
// }

void UserCollect()
{
    if(Controller1.ButtonL1.pressing())
    {
      xi.spin(forward,-100,pct);
      xi2.spin(forward,-100,pct);
    }
    else if(Controller1.ButtonL2.pressing())
    {
      xi.spin(forward,100,pct);
      xi2.spin(forward,100,pct);
    }
    else
    {
      xi.stop();
      xi2.stop();
    }

}


void handle()
{

if(Controller1.ButtonR1.pressing() && f1==0)
  {
    zhua.set(1);
    f1 = 1;
    while(Controller1.ButtonR1.pressing())
    {
      wait(10,msec);
    }
  }

  if(Controller1.ButtonR1.pressing() && f1==1)
  {
    zhua.set(0);
    f1 = 0;
    while(Controller1.ButtonR1.pressing())
    {
      wait(10,msec);
    }
  }

  if(Controller1.ButtonR2.pressing() && f3==0)
  {
    zhua2.set(1);
    f3 = 1;
    while(Controller1.ButtonR2.pressing())
    {
      wait(10,msec);
    }
  }

  if(Controller1.ButtonR2.pressing() && f3==1)
  {
    zhua2.set(0);
    f3 = 0;
    while(Controller1.ButtonR2.pressing())
    {
      wait(10,msec);
    }
  }


}


   


 