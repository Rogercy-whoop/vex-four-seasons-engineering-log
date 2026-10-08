#include "vex.h"
#include "autons.h"
#include "user.h"
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Inertial             inertial      15              
// left1                motor         13              
// left2                motor         12              
// left3                motor         11              
// right1               motor         18              
// right2               motor         19              
// right3               motor         20              
// wing                 digital_out   A               
// climb1               digital_out   F               
// climb2               digital_out   H               
// shooter              motor         16              
// collectR             motor         14              
// collectL             motor         17              
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;
competition Competition;
int thread1=0;

int fff=0;

int display()//显示角度
{
  while(1)
  {
    Controller1.Screen.setCursor(1,1);
    Controller1.Screen.print("GYROz%.2f",Gyro.rotation());//陀螺仪
    Controller1.Screen.setCursor(1,12);
    Controller1.Screen.print("r%.2f",r.angle());
  }
}
task a = task(display);


Drive chassis(

ZERO_TRACKER_ODOM,

motor_group(leftA, leftB, leftC),

motor_group(rightA, rightB, rightC),

PORT7,//惯性传感器端口 *************

4.125,//输入轮子的直径
//4.125
//3.25
//2.75

0.5,//输入齿轮/输出齿轮算出齿轮比

360,//陀螺仪比例
//左轮前后端口     右轮前后端口
PORT10,     -PORT3,

PORT9,     -PORT2,
//下面默认就可以了
3,

2.75,

-2,

1,

-2.75,

5.5

);

int current_auton_selection = 0;
bool auto_started = false;

/**
 * Function before autonomous. It prints the current auton number on the screen
 * and tapping the screen cycles the selected auton by 1. Add anything else you
 * may need, like resetting pneumatic components. You can rename these autons to
 * be more descriptive, if you like.
 */
 void arm() {
  timer Tarm;
  double pre_angle = fabs(r.angle());
  double p = 0.8;
  double error_a;
  double speed = 0;
  double t_angle = 37;

  while (thread1 == 1) {
    if (Controller1.ButtonUp.pressing()) {
      climb.spin(forward, 100, pct);
    } else if (Controller1.ButtonDown.pressing()) {
      climb.spin(forward, -90, pct);
    } else {
      climb.stop(hold);
    }

    if (Controller1.ButtonLeft.pressing()) 
    {
      while ( r.angle() < t_angle || r.angle() > 350) 
      {
        if(r.angle()>0 && r.angle()<t_angle)
         {  
            pre_angle = r.angle();
            error_a = t_angle - pre_angle;
            speed = 20+error_a*p;
            climb.spin(fwd,speed,pct);
            
        if(Tarm > 700)
        {
          Tarm.clear();
          pre_angle = r.angle();
        }
        if(fabs(pre_angle -t_angle) < 2.5 and Tarm > 350)
        {
          break;
        }
        wait(10,msec);
        }

        else{
          climb.spin(fwd,30,pct);
         }
      }

      while (r.angle(degrees) > t_angle && r.angle() < 355) 
      {
            pre_angle = r.angle();
            error_a = t_angle - pre_angle;
            speed = error_a*0.8;
            climb.spin(fwd,speed,pct);
         if(Tarm > 700)
        {
          Tarm.clear();
          pre_angle = r.angle();
        }
        if(fabs(pre_angle -t_angle) < 3.5 and Tarm > 350)
        {
          break;
        }
        wait(10,msec);
      }
    }
  }
} 

//   void arm()
// {
//   climb.resetPosition();
//   while(1)
//   {
//      if(Controller1.ButtonX.pressing())
//     {
//       climb.spin(forward,100,pct); 
//     }
//     else if(Controller1.ButtonB.pressing())
//     {
//       climb.spin(reverse,90,pct);
//     }
//     else
//     {
//       climb.stop(hold);
//     }

//       if(Controller1.ButtonY.pressing())
//     {
//       while(climb.position(degrees)<115 )
//       {
//         climb.spin(fwd,50,pct);
//       }
//       climb.stop(hold);
//     }  

//   }

// }

thread t1(arm);

void pre_auton(void) {
  vexcodeInit();
  default_constants();
  //选择程序
  while(!auto_started){
    Brain.Screen.clearScreen();
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setFillColor(purple);
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("GYRO:%.2f",Gyro.rotation());
    switch(current_auton_selection){
      case 0:
        Brain.Screen.setFillColor(red);
        Brain.Screen.printAt(10, 120, "red you ");
        break;
      case 1:
        Brain.Screen.setFillColor(blue);
        Brain.Screen.printAt(10, 120, "blue zuo ");  
        break;
      case 2:
        Brain.Screen.setFillColor(red);
        Brain.Screen.printAt(10, 120, "red zuo ");
        break;
      case 3:
        Brain.Screen.setFillColor(blue);
        Brain.Screen.printAt(10, 120, "blue you");
        break;
    }
    if(Brain.Screen.pressing()){
      while(Brain.Screen.pressing()) {}
      current_auton_selection ++;
    } else if (current_auton_selection == 4){
      current_auton_selection = 0;
    }
    task::sleep(10);
  } 
 
}

void autonomous(void) {
  //根据选择程序进入自动程序
  thread1=0;//多线程手臂不启用
  // current_auton_selection = 2;
  switch(current_auton_selection){ 
    case 0:
      hyou_test();
      break;
    case 1:         
      lzuo_a2();
      break;
    case 2:
      test523();
      //hzuo_test();
      break;
    case 3:
      lyou();
      break; 
    }
  just_stop(0);
}

void usercontrol(void) {
   thread1=1;//启用多线程手臂
   just_stop(0);
   thread t1(arm);

  while (1) {
    chassis.control_tank();
    UserCollect();
    handle();

      if(Controller1.ButtonA.pressing())
     {
       t1.interrupt();
       //hzuo_test();
       test523();
     } 
    //按键测试，比赛开始前需要注销掉
/*      if(Controller1.ButtonRight.pressing() && fff==0)
    { thread1=0;
     
     switch(current_auton_selection){ 
    case 0:
      hyou();
      break;
    case 1:         
      lzuo();
      break;
    case 2:
      hzuo();
      break;
    case 3:
      hzuo2();
      break; 
    case 4:
      lyou();
      break;
    case 5:
      lyou2();
      break;
    }

     fff=1;thread1=1;
    }  */
}
}


int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  while (true) {
    wait(100, msec);
  }
  return 0;
}
