#include "vex.h"
#include "user.h"


void default_constants() {
  //调试PID参数，分别是（最大电压，KP,KI,KD,statI参数）
  chassis.set_drive_constants(10, 1.2, 0, 5, 0);
  chassis.set_heading_constants(6, 0.1, 0, 1, 0);
  chassis.set_turn_constants(10, 0.3, 0.001, 0.8, 0);
  chassis.set_swing_constants(10, .3, .001, 2, 15);

  //设置程序跳出条件（误差，时间，时间截止）都是以ms为单位的
  chassis.set_drive_exit_conditions(1.5, 180, 900);
  chassis.set_turn_exit_conditions(1, 180, 900);
  chassis.set_swing_exit_conditions(1, 180, 900);
}

void lzuo_a2()
{
  default_constants();
  chassis.drive_timeout=700;
  chassis.drive_distance(18/2.54,0,6,6);
  climb.spin(fwd,60,pct);
  wait(1,sec);
  climb.stop();
  wait(0.3,sec);
  chassis.drive_timeout=900;
  chassis.drive_distance(-35/2.54,0,6,6);
  chassis.turn_to_angle(-57,8);
  intake(100);
  chassis.drive_distance(22/2.54,-57,7,7);
  wait(0.5,sec);
  intake(0);
  //xi.spin(forward,100,pct);
  arm(-300,60, 0);

  chassis.drive_distance(-10/2.54,-57,7,7);
  chassis.turn_to_angle(5,7);
   chassis.drive_timeout=1100;
  chassis.drive_distance(-30,5,7,7);
  zhua.set(1);
  intaketime(90,1);
  
  chassis.turn_to_angle(122,8);
  intake(100);
  chassis.drive_distance(56/2.54,122,6.5,6.5);
  wait(1,sec);
  chassis.drive_distance(-56/2.54);
  wait(0.5,sec);
  intake(0);
  
  chassis.turn_to_angle(264,8);
  intake(90);
  chassis.drive_distance(24/2.54,264,7,7);
  arm(245,60,0);
  just_stop(0);
}

void test523()
{
  default_constants();
  climb.spin(fwd,60,pct);
  wait(0.8,sec);
  climb.stop();
  chassis.drive_distance(-20/2.54,0,6,6);
  chassis.turn_to_angle(-2,7);
  chassis.drive_timeout=1700;//默认timeout900
  chassis.drive_distance(-115/2.54,-2,6,6);
  zhua.set(1);
  wait(0.5,sec);
  chassis.turn_to_angle(40,7);
  intake(100);
  chassis.drive_distance(60/2.54,40,7,7);
  wait(0.5,sec);
  chassis.turn_to_angle(-97,7);
  chassis.drive_distance(78/2.54,-97,7,7);
  wait(0.5,sec);
  chassis.turn_to_angle(-170,7);
  chassis.drive_distance(60/2.54,-170,6,6);
  wait(0.5,sec);
  chassis.turn_to_angle(-20,7);
  chassis.drive_distance(60/2.54,-60,8,8);
  intake(0);
}

void test_van()
{
  default_constants();
  climb.spin(fwd,60,pct);
  wait(0.8,sec);
  climb.stop();

  chassis.drive_distance(-30/2.54,0,6,6);
  chassis.turn_to_angle(-90,8);
  chassis.drive_distance(-60/2.54,-90,6,6);
  zhua.set(1);
  chassis.turn_to_angle(180,8);
  intake(100);
  chassis.drive_distance(62/2.54,180,7,7);
  chassis.turn_to_angle(90,8);
  chassis.drive_distance(60/2.54,90,7,7);
  wait(0.5,sec);
  chassis.turn_to_angle(155,8);
  chassis.drive_distance(43/2.54,155,7,7);
  wait(0.5,sec);
  chassis.turn_to_angle(-4,8);
  chassis.drive_distance(130/2.54,-4,7,7);
  wait(0.5,sec);
  chassis.turn_to_angle(0,8);
  chassis.drive_distance(45/2.54,0,7,7);
  wait(0.5,sec);
  chassis.drive_distance(-35/2.54,0,7,7);
  chassis.turn_to_angle(90,8);
  chassis.drive_distance(30/2.54,90,7,7);
  chassis.turn_to_angle(200,8);
  chassis.drive_distance(-55/2.54,195,7,7);
  zhua.set(0);
}

void hyou_a2()
{
  default_constants();
  chassis.drive_timeout=700;
  chassis.drive_distance(20/2.54,0,6,6);
  climb.spin(fwd,60,pct);
  wait(1,sec);
  climb.stop();
  wait(0.3,sec);
  chassis.drive_timeout=900;
  chassis.drive_distance(-35/2.54,0,6,6);
  chassis.turn_to_angle(57,8);
  xi.spin(fwd,-100,pct);//第一层电机
  xi2.spin(fwd,-100,pct);//第二层电机
  chassis.drive_distance(22/2.54,57,7,7);
  wait(0.5,sec);
  intake(0);
  // xi.spin(forward,100,pct);
  arm(-350,60, 0);

  chassis.drive_distance(-10/2.54,57,7,7);
  chassis.turn_to_angle(-5,7);
  chassis.drive_timeout=1100;
  chassis.drive_distance(-30,-5,7,7);
  zhua.set(1);
  intaketime(90,1);
  
  chassis.turn_to_angle(-122,8);
  intake(100);
  chassis.drive_distance(50/2.54,-122,6.5,6.5);
  wait(1,sec);
  chassis.drive_distance(-50/2.54);
  intake(0);//取消intake
  
  chassis.turn_to_angle(-264,8);
  chassis.drive_distance(23/2.54,-264,8,8);
  arm(220,60,0);
  just_stop(0);
}

void hyou_testnew()
{
  default_constants();
  chassis.drive_timeout=700;
  climb.spin(fwd,60,pct);
  wait(0.8,sec);
  climb.stop();
  wait(0.3,sec);
  chassis.drive_timeout=900;
  chassis.drive_distance(-20/2.54,0,8,8);
  chassis.turn_to_angle(60,8);
  chassis.drive_distance(35/2.54,57,8,8);
  xi.spin(fwd,-100,pct);
  wait(0.7,sec);
  intake(0);
  arm(-350,60, 0);

  chassis.turn_to_angle(-25,8);
  chassis.drive_timeout=1700;
  chassis.drive_distance(-75/2.54,-25,8,8);
  zhua.set(1);
  wait(0.5, sec);
  chassis.turn_to_angle(-155,8);
  intake(100);
  chassis.drive_distance(65/2.54,-155,9,9);
  chassis.turn_to_angle(-85,8);
  zhua2.set(1);
  chassis.drive_distance(80/2.54,-85,8,8);
  chassis.turn_to_angle(-173,10);
  zhua2.set(0);
  chassis.drive_distance(20/2.54,-173,10,10);
  chassis.drive_distance(-20/2.54,-173,10,10);
  chassis.turn_to_angle(-263,8);
  chassis.drive_distance(140/2.54,-263,10,10);
  just_stop(0);
}

void hyou_test()
{
  default_constants();
  //chassis.drive_timeout=700;
  //chassis.drive_distance(20/2.54,0,6,6);
  climb.spin(fwd,60,pct);//什么意思？？？
  wait(0.5,sec);
  climb.stop();
  wait(0.3,sec);
  chassis.drive_timeout=900;
  chassis.drive_distance(-35/2.54,0,8,8);
  chassis.turn_to_angle(57,8);
  xi.spin(fwd,-100,pct);//第一层电机？？
  xi2.spin(fwd,-100,pct);//第二层电机？？
  chassis.drive_distance(22/2.54,57,8,8);
  wait(0.5,sec);
  intake(0);
  // xi.spin(forward,100,pct);
  arm(-350,60,0);

  chassis.drive_distance(-10/2.54,57,8,8);
  chassis.turn_to_angle(-5,8);
  chassis.drive_timeout=1100;
  chassis.drive_distance(-30,-5,8,8);
  zhua.set(1);
  intaketime(90,0.5);
  
  chassis.turn_to_angle(-122,8);
  intake(100);
  chassis.drive_distance(53/2.54,-122,8,8);
  wait(0.3,sec);
  
  //加转向去清角
  //chassis.drive_distance(-50/2.54);
  intake(0);//取消intake
  
  chassis.turn_to_angle(-264,8);
  chassis.drive_distance(23/2.54,-264,8,8);
  arm(220,60,0);
  just_stop(0);
}

void test228()
{
  //车45cm，一格垫子60cm
  default_constants();
  chassis.drive_distance(-55/2.54,0,7,7);//滚轮一侧是头
  zhua.set(1);
  wait(1,sec);
  chassis.drive_distance(-10/2.54,0,7,7);
  chassis.turn_to_angle(90,8);
  intake(100);
  chassis.drive_distance(62/2.54,90,8,8);
  wait(2,sec);//让吸持续
  //just_stop(0);
}
void test1(){

  chassis.drive_distance(40/2.54,0,10,10);
  chassis.turn_to_angle(90,10);
  wait (1,sec);
  chassis.drive_distance(40/2.54,90,10,10);
  chassis.turn_to_angle(180,10);
  wait (1,sec);
  chassis.drive_distance(40/2.54,180,10,10);
  chassis.turn_to_angle(270,10);
  wait (1,sec);
  chassis.drive_distance(40/2.54,270,10,10);
  chassis.turn_to_angle(0,10);
} 
void test2(){
 default_constants();
  arm(450,90,1);
  chassis.drive_distance(26/2.54,0,8,8);
  
   arm(90,90,1);
  
  chassis.drive_distance(-75/2.54,10,7,7);
  zhua.set(1);
  chassis.turn_to_angle(-14,10);
  arm(-540, 90, 0);
  chassis.drive_distance(80/2.54,-14,10,10);
  intake(100);
  wait(1, sec);
  intake(0);
}
void lzuo_a()//看有什么用
{
  default_constants();
  wait(0.5,sec);
  //转弯放联队杆程序,中间小赶
  chassis.left_swing_to_angle(63);
  climb.spin(fwd,50,pct);//手臂电机单独旋转
  wait(1.5,sec);
  climb.stop(brake);

  //抓第一个塔
  chassis.drive_timeout=1200;
  chassis.drive_distance(-22/2.54,62,9,9);
  chassis.drive_distance(-85/2.54,62,5,5);
  zhua.set(1);
  wait(0.5,sec);
  chassis.turn_to_angle(180);
  
  //抬手臂
  arm(-300,90,0);
  //吸取环
  intake(100);
  chassis.drive_distance(85/2.54,190,7,7);
  wait(0.5,sec);

  chassis.drive_distance(-50/2.54,190,6,6);
  wait(0.5,sec);
  
   
  chassis.turn_to_angle(330);
  arm(-300,100,0);
  intake(0);
  chassis.drive_distance(65/2.54,330,8,8);
  
  just_stop(0);

}

void hyou_a()
{
  default_constants();
  wait(0.5,sec);
  //转弯放联队杆程序
  chassis.right_swing_to_angle(-58);
  climb.spin(fwd,50,pct);
  wait(1.5,sec);
  climb.stop(brake);

  //抓第一个塔
  chassis.drive_timeout=1200;
  chassis.drive_distance(-22/2.54,-62,9,9);
  chassis.drive_distance(-88/2.54,-62,5,5);
  zhua.set(1);
  wait(0.5,sec);
  chassis.turn_to_angle(-180);
  
  //抬手臂
  arm(-300,90,0);
  //吸取环
  intake(100);
  chassis.drive_distance(85/2.54,-190,7,7);
  wait(0.5,sec);

  chassis.drive_distance(-50/2.54,-190,6,6);
  intake(0);

  chassis.turn_to_angle(-330);
  arm(-300,100,0);
  chassis.drive_distance(65/2.54,-330,8,8);
  
  just_stop(0);

}


//红方右边的程序，2塔，2环
void hyou()
{
  default_constants();
  //调节底盘参数为激进状态
  chassis.turn_timeout=500;
  chassis.drive_timeout=700;
  
  //抓中线上的塔
  chassis.drive_distance(-83/2.54,0,10,10);
  chassis.turn_to_angle(-35,10);
  chassis.drive_distance(-32/2.54,-35,9,9);
  zhua.set(1);
  wait(0.3,sec);
  chassis.drive_distance(33/2.54,-35,9,9);
  intaketime(90,1);//套环

  //把底盘参数调回正常数值
  chassis.turn_timeout=900;
  chassis.drive_timeout=900;
  zhua.set(0);
  wait(0.3,sec);
  
  //后退一点距离
  chassis.drive_distance(-25/2.54,-30,9,9);
  chassis.turn_to_angle(45,8);//转向吸环的位置
  xi2.spin(fwd,100,pct);
  chassis.drive_distance(40/2.54,45,8,8);

  //转弯瞄向第二个塔抓取
  chassis.turn_to_angle(-84,10);
  xi.stop();
  //wait(0.3,sec);
  chassis.drive_distance(-20,-84,6,6);
  zhua.set(1);
  intake(100);
  wait(0.3,sec);
  intake(0);
  wait(0.3,sec);
  intake(100);
  
  //转弯瞄向角落
  chassis.drive_distance(50/2.54,-55,10,10);
  wait(0.5,sec);
  chassis.turn_to_angle(-270,9);
  zhua.set(0);
  chassis.turn_to_angle(-240);
  chassis.drive_distance(27,-240,9,7);
  intake(0);
  just_stop(0);
}

//蓝方左边的程序
void lzuo()
{
  default_constants();
  //调节底盘参数为激进状态
  chassis.turn_timeout=500;
  chassis.drive_timeout=700;
  
  //抓中线上的塔
  chassis.drive_distance(-82/2.54,0,10,10);
  chassis.turn_to_angle(33,10);
  chassis.drive_distance(-33/2.54,33,9,9);
  zhua.set(1);
  wait(0.3,sec);
  chassis.drive_distance(33/2.54,30,9,9);
  intaketime(90,1);//套环

  //把底盘参数调回正常数值
  chassis.turn_timeout=900;
  chassis.drive_timeout=900;
  zhua.set(0);
  wait(0.3,sec);
  
  //后退一点距离
  chassis.drive_distance(-25/2.54,30,9,9);
  chassis.turn_to_angle(-45,8);//转向吸环的位置
  xi2.spin(fwd,100,pct);
  chassis.drive_distance(40/2.54,-45,8,8);

  //转弯瞄向第二个塔抓取
  chassis.turn_to_angle(84,10);
  xi.stop();
  //wait(0.3,sec);
  chassis.drive_distance(-20,84,6,6);
  zhua.set(1);
  intake(100);
  wait(0.3,sec);
  intake(0);
  wait(0.3,sec);
  intake(100);
  
  //转弯瞄向角落
  chassis.drive_distance(50/2.54,55,10,10);
  wait(0.5,sec);
  chassis.turn_to_angle(270,9);
  zhua.set(0);
  chassis.turn_to_angle(240);
  chassis.drive_distance(30,240,9,7);
  intake(0);
  just_stop(0);
}

//4环
void hzuo()
{
  default_constants();
  chassis.drive_timeout=1200;
  chassis.turn_to_angle(-18,7);
  chassis.drive_distance(-59/2.54,-18,6,6);
  zhua.set(1);//吸预装加第一个环
  wait(0.5,sec);

  chassis.turn_to_angle(137,7);
  intake(95);
  chassis.drive_distance(71/2.54,137,6.5,6.5);//吸第二个环
  wait(0.5,sec);
  
  chassis.drive_distance(-61/2.54,140,9,9);
  intake(0);
  chassis.turn_to_angle(95,10);
  intake(90);
  chassis.drive_distance(58/2.54,95,6,6);
  wait(0.5,sec);
  chassis.drive_distance(-7/2.54,95,6,6);
  wait(0.5,sec);
  intake(0);
  chassis.turn_to_angle(168,10);
  intake(98);
  chassis.drive_distance(41/2.54,160,6.5,6.5);
  wait(0.5,sec);
  chassis.drive_distance(-58/2.54,155,9,9);

  chassis.turn_to_angle(237,9);
  chassis.drive_timeout = 1300;
  chassis.drive_distance(70/2.54,233,10,10);
  arm(340,100,0);
  just_stop(0);

  /* chassis.turn_to_angle(40,9);
  zhua2.set(1);
  chassis.drive_distance(90/2.54,40,8,9);
  just_stop(0); */
}

void hzuo_test()
{
  default_constants();
  chassis.turn_to_angle(-17.5,9);
  chassis.drive_timeout=1100;
  chassis.drive_distance(-59/2.54,-17.5,8,8);
  zhua.set(1);//吸预装加第一个环
  wait(0.2,sec);

  chassis.turn_to_angle(137,9);
  intake(100);
  chassis.drive_distance(80/2.54,137,9,9);//吸第二个环
  chassis.turn_to_angle(100,9);
  chassis.drive_distance(47/2.54,90,9,9);//90
  wait(0.4,sec);
  
  chassis.drive_distance(-90/2.54,130,9,9);
  chassis.turn_to_angle(78,9);
  chassis.drive_distance(52/2.54,80,9,9);
  chassis.drive_distance(-43/2.54,80,9,9);

  chassis.turn_to_angle(40,9);
  zhua2.set(1);
  chassis.drive_distance(123/2.54,40,9,9);
  chassis.turn_to_angle(-35,9);
  zhua2.set(0);
  chassis.drive_distance(30/2.54,-35,9,9);
  chassis.drive_distance(-15/2.54,-35,9,9);
  chassis.turn_to_angle(240,9);
  chassis.drive_distance(180/2.54,200,9,9);
  arm(340,100,0);
  just_stop(0);
}

void lyou()//4环
{
  default_constants();
  chassis.drive_timeout=1200;
  chassis.turn_to_angle(20,7);
  chassis.drive_distance(-64/2.54,20,6,6);
  zhua.set(1);//吸预装加第一个环
  wait(0.5,sec);

  chassis.turn_to_angle(-137,8);
  intake(90);
  chassis.drive_distance(70/2.54,-137,6,6);//吸第二个环
  wait(0.5,sec);
  
  chassis.drive_distance(-59/2.54,-140,9,9);
  intake(0);
  chassis.turn_to_angle(-95,10);
  intake(100);
  chassis.drive_distance(60/2.54,-95,8,8);
  wait(0.5,sec);
  chassis.drive_distance(-7/2.54,-95,7,7);
  wait(0.5,sec);
  chassis.turn_to_angle(-160,10);
  chassis.drive_distance(40/2.54,-160,6.5,6.5);
  wait(0.5,sec);
  chassis.drive_distance(-61/2.54,-155,9,9);

  chassis.turn_to_angle(-240,9);
  chassis.drive_distance(75/2.54,-250,9,9);
  arm(485,60,0);
  just_stop(0);
}
void lyou_test()
{
  default_constants();
  chassis.drive_timeout=1100;
  chassis.turn_to_angle(17.5,7);
  chassis.drive_distance(-59/2.54,20,6,6);
  zhua.set(1);//吸预装加第一个环
  wait(0.3,sec);

  chassis.turn_to_angle(-137,8);
  intake(100);
  chassis.drive_distance(76/2.54,-137,9,9);//吸第二个环
  chassis.turn_to_angle(-105,8);
  chassis.drive_distance(48/2.54,-105,6,6);
  wait(0.4,sec);
  chassis.drive_distance(-59/2.54,-140,9,9);
  intake(0);
  chassis.turn_to_angle(-95,10);
  intake(100);
  chassis.drive_distance(60/2.54,-95,8,8);
  wait(0.5,sec);
  chassis.drive_distance(-7/2.54,-95,7,7);
  wait(0.5,sec);
  chassis.turn_to_angle(-160,10);
  chassis.drive_distance(40/2.54,-160,6.5,6.5);
  wait(0.5,sec);
  chassis.drive_distance(-61/2.54,-155,9,9);

  chassis.turn_to_angle(-240,9);
  chassis.drive_distance(75/2.54,-250,9,9);
  arm(485,60,0);
  just_stop(0);
}

/* void drive_test(){
  chassis.drive_distance(20,10);
  chassis.drive_distance(12);
  chassis.drive_distance(-18,0);
}

void turn_test(){
  default_constants();
  chassis.turn_to_angle(90);
  chassis.turn_to_angle(-100);
} */

/*
chassis.turn_to_angle(角度,最大速度（最大12.8）,稳定误差,稳定时间,整个运行时间);
chassis.drive_distance(距离,角度,最大速度（最大12.8）,最大速度,稳定误差, 稳定时间,整个运行时间);
chassis.left_swing_to_angle(角度);
chassis.right_swing_to_angle(角度);

//可调节参数
chassis.turn_max_voltage = 3;//可以设置改变pid底盘的任意一个参数
float angle, float turn_max_voltage, float turn_settle_error, float turn_settle_time, float turn_timeout, float turn_kp, float turn_ki, float turn_kd, float turn_starti
  chassis.drive_distance(-90/2.54,12);
  chassis.turn_to_angle(40,10,1, 180, 500);
  chassis.drive_distance(-28/2.54,35,5,5);
  zhua.set(true);
*/


/* 
const float one_unit = 60 / 2.54;
void qualify_attack() {
  timer *t1 = new timer();
  collectmove(-100);
  wait(500, msec);
  collectmove(0);
  chassis.drive_distance(one_unit * 1.7);
  chassis.turn_to_angle(83, 12.8, 0, 0, 500);
  collectmove(50);
  driveForward(180, -30, t1);
  driveForward(800, 80, t1);
  collectmove(0);
  wait(500, msec);
  driveForward(200, -50, t1);
  chassis.turn_to_angle(-115, 12.8*0.8, 0, 0, 1000);
  collectmove(-100);
  chassis.drive_distance(one_unit*1.2);
  collectmove(0);
  chassis.turn_to_angle(65, 12.8*0.8, 0, 0, 1000);
  collectmove(100);
  wait(500, msec);
  chassis.turn_to_angle(-26, 12.8*0.8, 0, 0, 500);
  collectmove(-100);
  chassis.drive_distance(one_unit*0.95);
  chassis.turn_to_angle(90, 12.8*0.8, 0, 0, 500);
  wing.set(true);
  collectmove(0);
  driveForward(1000, 80, t1);
  chassis.drive_distance(-one_unit*0.65);
  wing.set(false);
  set_coast();
}
void qualify_defense()
{
  collectmove(-100);
  wait(800, msec);
  chassis.drive_distance(-one_unit*0.3,135);
  wing.set(true);
  wait(0.3, sec);
  chassis.turn_to_angle(45, 12.8*0.8, 0, 0, 500);
  wing.set(false);
  chassis.turn_to_angle(135, 12.8*0.8, 0, 0, 500);
  chassis.drive_distance(one_unit*0.9);
  chassis.turn_to_angle(90, 12.8*0.8, 0, 0, 500);
  collectmove(0);
  collectmove(80);
  chassis.drive_distance(one_unit * 1.13);
  wait(350, msec);
  collectmove(0);
  set_coast();
}
void final_attack()
{
  timer *t1 = new timer();
  collectmove(-100);
  wing.set(true);
  wait(300, msec);
  wing.set(false);
  collectmove(0);
  collectmove(-80);
  chassis.drive_distance(one_unit * 2.65, -37);
  chassis.turn_to_angle(90, 12.8, 0, 0, 700);
  wing.set(true);
  collectmove(0);
  driveForward(1000, 80, t1);
  wing.set(false);
  chassis.drive_distance(-one_unit*0.9);
  chassis.turn_to_angle(-125,12.8,1, 700, 1000,.3, .001, 2, 15);
  collectmove(-100);
  chassis.drive_distance(one_unit);
  chassis.drive_distance(-one_unit*0.3);
  chassis.turn_to_angle(125, 12.8, 0, 0, 700);
  chassis.drive_distance(one_unit*1.414*1.5, 150);
  chassis.turn_to_angle(65, 12.8, 0, 0, 700);
  wing.set(true);
  chassis.drive_distance(one_unit*0.65);
  chassis.turn_to_angle(15, 12.8, 0, 0, 700);
  wing.set(false);
  chassis.turn_to_angle(20, 12.8, 0, 0, 300);
  collectmove(0);
  collectmove(-60);
  wait(0.2,sec);
  collectmove(0);
  driveForward(500, 100, t1);
  driveForward(300, -100, t1);
  driveForward(600, 100, t1);
  driveForward(200, -100, t1);
  set_coast();
}
void steal_defense()
{
  collectmove(-80);
  chassis.drive_distance(one_unit*-2,16);
  chassis.drive_distance(one_unit*1.55);
  chassis.turn_to_angle(90, 12.8 * 0.8, 0, 0, 500);
  chassis.drive_distance(one_unit * 1.05);
  chassis.turn_to_angle(155, 12.8 *0.8, 0, 0, 700);
  chassis.drive_distance(-one_unit*0.5);
  wing.set(true);
  chassis.turn_to_angle(90, 12.8 * 0.8, 0, 0, 500);
  wing.set(false);
  chassis.drive_distance(one_unit * -1, 120);
  chassis.turn_to_angle(90, 12.8 * 0.8, 0, 0, 500);
  collectmove(0);
  wait(200, msec);
  collectmove(80);
  chassis.drive_distance(one_unit * - 1.15);
  collectmove(0);
  set_coast();
}
void steal_defense2()
{
  collectmove(-80);
  chassis.drive_distance(one_unit*2, 16);
  chassis.turn_to_angle(0, 12.8, 0, 0, 300);
  chassis.drive_distance(-one_unit*0.17);
  wing.set(true);
  chassis.turn_to_angle(90, 12.8, 0, 0, 500);
  collectmove(100);
  wait(200, msec);
  chassis.drive_distance(one_unit*0.95, chassis.desired_heading, 12.8*0.5, 12.8, 0, 0, 1300);
  wing.set(false);
  collectmove(0);

  chassis.drive_distance(-one_unit*0.2);
  chassis.drive_distance(-one_unit*2.5, 20);
  chassis.turn_to_angle(120, 12.8, 0, 0, 600);
  chassis.drive_distance(-one_unit*0.45);
  chassis.turn_to_angle(145, 12.8, 0, 0, 500);

  wing.set(true);
  chassis.drive_distance(one_unit*0.3, 160);
  chassis.turn_to_angle(90, 12.8, 0, 0, 450);
  wing.set(false);

  chassis.drive_distance(one_unit * 1, 120);
  chassis.turn_to_angle(90, 12.8, 0, 0, 400);
  collectmove(100);
  chassis.drive_distance(one_unit * 0.95);

  wait(300, msec);
  chassis.drive_distance(one_unit * -1.5);
  chassis.drive_distance(one_unit * -0.5, 110);
  collectmove(0);
  set_coast();
}
void final_attack2()
{
  timer *t1 = new timer();
  collectmove(-80);
  chassis.drive_distance(10);
  chassis.drive_distance(-one_unit*1.35, 0, 12.8*0.7, 12.8);
  chassis.turn_to_angle(182, 12.8, 0, 0, 500);
  chassis.drive_distance(one_unit*0.5, 145);
  wing.set(true);
  chassis.drive_distance(one_unit*0.5);
  chassis.turn_to_angle(100, 12.8, 0, 0, 400);
  wing.set(false);
  chassis.turn_to_angle(115, 12.8, 0, 0, 650);
  collectmove(0);
  collectmove(60);
  driveForward(500, 100, t1);
  driveForward(300, -80, t1);
  chassis.turn_to_angle(90, 12.8, 0, 0, 400);
  driveForward(800, 100, t1);
  collectmove(0);
  chassis.drive_distance(-one_unit*0.6);
  chassis.turn_to_angle(0, 12.8, 0, 0, 600);
  collectmove(-80);
  chassis.drive_distance(2.2*one_unit, 18);
  chassis.turn_to_angle(150, 12.8, 0, 0, 600);
  collectmove(0);
  collectmove(60);
  chassis.drive_distance(10);
  wait(500, msec);
  collectmove(0);
  chassis.turn_to_angle(55, 12.8, 0, 0, 450);
  collectmove(-80);
  chassis.drive_distance(one_unit);
  wait(300, msec);
  collectmove(0);
  chassis.turn_to_angle(185, 12.8, 0, 0, 600);
  wing.set(true);
  driveForward(800, 100, t1);
  chassis.drive_distance(-one_unit*0.5);
  wing.set(false);
  set_coast();
}

void awp5balls(){
  timer *t1 = new timer();
  collectmove(-100);
  wing.set(true);
  chassis.drive_distance(one_unit * 0.6, -20);
  wing.set(false);
  chassis.turn_to_angle(30, 12.8, 0, 0, 500);

  collectmove(0);
  driveForward(600, 100, t1);
  driveForward(400, -80, t1);
  chassis.turn_to_angle(-2, 12.8, 0, 0, 500);
  driveForward(1000, 100, t1);
  chassis.drive_distance(one_unit*-0.45);
  chassis.turn_to_angle(-90, 12.8, 0, 0, 650);
  driveForward(800, -30, t1);
  wait(200, msec);

  collectmove(-80);
  chassis.drive_distance(one_unit * 1);
  chassis.drive_distance(1.35*one_unit, -60);
  chassis.turn_to_angle(60, 12.8, 0, 0, 600);
  collectmove(0);
  collectmove(60);
  chassis.drive_distance(10);
  wait(500, msec);
  collectmove(0);
  chassis.turn_to_angle(-45, 12.8, 0, 0, 450);
  collectmove(-80);
  chassis.drive_distance(one_unit);
  wait(300, msec);
  collectmove(0);
  chassis.turn_to_angle(95, 12.8, 0, 0, 600);
  wing.set(true);
  driveForward(800, 100, t1);
  chassis.drive_distance(-one_unit*0.5);
  wing.set(false);
  set_coast();


}

void qua_steal_defense(){
  collectmove(-80);
  chassis.drive_distance(one_unit*2, 16);
  chassis.turn_to_angle(0, 12.8, 0, 0, 300);
  chassis.drive_distance(-one_unit*0.17);
  wing.set(true);
  chassis.turn_to_angle(90, 12.8, 0, 0, 500);
  wait(200, msec);
  chassis.drive_distance(one_unit*0.95, chassis.desired_heading, 12.8*0.5, 12.8, 0, 0, 1300);
  wing.set(false);
  chassis.drive_distance(-one_unit*0.4);

  chassis.turn_to_angle(45, 12.8, 0, 0, 400);
  chassis.drive_distance(one_unit * -1.9);
  chassis.turn_to_angle(90, 12.8, 0, 0, 400);
  chassis.drive_distance(one_unit * -0.6);

  chassis.turn_to_angle(150,12.8, 0, 0, 500);
  wing.set(true);
  chassis.drive_distance(one_unit * 0.6);
  chassis.turn_to_angle(75,12.8, 0, 0, 300);
  wing.set(false);
  wait(300, msec);
  chassis.turn_to_angle(130,12.8, 0, 0, 300);
  chassis.drive_distance(one_unit * 0.6);
  chassis.turn_to_angle(90, 12.8, 0, 0, 300);
  collectmove(100);
  chassis.drive_distance(one_unit * 1.35);
  




  set_coast();
}
void skill()
{
  timer *time = new timer();
  wing.set(true);
  chassis.turn_to_angle(45, 12.8, 0, 0, 500);
  chassis.turn_to_angle(-30, 12.8, 0, 0, 500);
  time->clear();
  while(time->time(sec) < 30){
    shooter.spin(fwd, 100, pct);
  }
} */