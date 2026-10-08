#include "vex.h"
#include "user.h"
timer T1;

void arm(int jiaodu,int speed,bool f)
{
  climb.spinFor(fwd,jiaodu,degrees,speed,velocityUnits::pct,f);
}

void collectspin(int deg,int speed)//宣传滚筒（参数：角度）
{
  xi2.resetPosition();//重置编码器
  while(fabs(xi2.position(degrees))<=abs(deg))
  {
    xi2.spin(forward,-speed,percent);
    vex::task::sleep(10);
  }
  xi2.stop();
}

void intake(int speed)
{
  if(speed==0)
  {
    xi.stop();
    xi2.stop();
  }
  else{
    xi.spin(fwd,-speed,pct);
    xi2.spin(fwd,-speed,pct);
  }
  
}

void intaketime(int speed, float time)
{
  if(speed==0 || time <= 0)
  {
    xi.stop();
    xi2.stop();
  }
  else{
    xi.spin(fwd,-speed,pct);
    xi2.spin(fwd,-speed,pct);
    wait(time, sec);
    xi.stop();
    xi2.stop();
  }

}

void just_stop(int stopmod)
{
    if(stopmod==1)
    {
        leftA.stop(vex::brakeType::brake);
        leftB.stop(vex::brakeType::brake);
        leftC.stop(vex::brakeType::brake);
        rightA.stop(vex::brakeType::brake);
        rightB.stop(vex::brakeType::brake);
        rightC.stop(vex::brakeType::brake);
    }
    else if(stopmod==0)
    {
        leftA.stop(vex::brakeType::coast);
        leftB.stop(vex::brakeType::coast);
        leftC.stop(vex::brakeType::coast);
        rightA.stop(vex::brakeType::coast);
        rightB.stop(vex::brakeType::coast); 
        rightC.stop(vex::brakeType::coast); 
    }
    else if(stopmod==3)
    {
        leftA.stop(vex::brakeType::hold);
        leftB.stop(vex::brakeType::hold);
        leftC.stop(vex::brakeType::hold);
        rightA.stop(vex::brakeType::hold);
        rightB.stop(vex::brakeType::hold); 
        rightC.stop(vex::brakeType::hold);
    }
        leftA.stop();
        leftB.stop();
        leftC.stop();
        rightA.stop();
        rightB.stop(); 
        rightC.stop();
}

//直行（按着角度执行）
void just_run_straight(double output,double newgyro)//按照一定的速度，陀螺仪的角度去走
{
    double angle_err=Gyro.rotation(vex::rotationUnits::deg)-newgyro;
    double Kp=0.7;
    angle_err*=Kp;
    leftA.spin(fwd,output,pct);
    leftB.spin(fwd,output,pct);
    leftC.spin(fwd,output,pct);
    rightA.spin(fwd,output+angle_err,pct);
    rightB.spin(fwd,output+angle_err,pct);
    rightC.spin(fwd,output+angle_err,pct);
}


void timed_run(double time,int v)
{
    time = time*1000;
    T1.clear();
    double angle=Gyro.rotation(vex::rotationUnits::deg);
    while(T1.time()<time)
    {
        just_run_straight(v,angle);
    }
    just_stop(1);
}