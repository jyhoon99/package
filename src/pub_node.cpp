#include "ros/ros.h"
#include <geometry_msgs/Twist.h>

using namespace std;

// // gcc 없이 키보드 입력받기
// // 출처( https://indra17.tistory.com/entry/Linux-C%EC%97%90%EC%84%9C-%ED%82%A4%EB%B3%B4%EB%93%9C-%EC%9D%B4%EB%B2%A4%ED%8A%B8-%EB%B0%9B%EA%B8%B0)
// static struct termios initial_settings, new_settings;

// static int peek_character = -1;



// void init_keyboard()

// {

// 	tcgetattr(0,&initial_settings);

// 	new_settings = initial_settings;

// 	new_settings.c_lflag &= ~ICANON;

// 	new_settings.c_lflag &= ~ECHO;

// 	new_settings.c_cc[VMIN] = 1;

// 	new_settings.c_cc[VTIME] = 0;

// 	tcsetattr(0, TCSANOW, &new_settings);

// }



// void close_keyboard()

// {

// 	tcsetattr(0, TCSANOW, &initial_settings);

// }



// int _kbhit()

// {

// 	unsigned char ch;

// 	int nread;



// 	if (peek_character != -1) return 1;

// 	new_settings.c_cc[VMIN]=0;

// 	tcsetattr(0, TCSANOW, &new_settings);

// 	nread = read(0,&ch,1);

// 	new_settings.c_cc[VMIN]=1;

// 	tcsetattr(0, TCSANOW, &new_settings);

// 	if(nread == 1) 

// 	{

// 		peek_character = ch;

// 		return 1;

// 	}

// 	return 0;

// }



// int _getch()

// {

// 	char ch;



// 	if(peek_character != -1) 

// 	{

// 		ch = peek_character;

// 		peek_character = -1;

// 		return ch;

// 	}

// 	read(0,&ch,1);

// 	return ch;

// }



// int _putch(int c) {

// 	putchar(c);

// 	fflush(stdout);

// 	return c;

// }



int main(int argc, char **argv)
{
    ros::init(argc, argv, "topic_publisher");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("cmd_vel",1000);
    ros::Rate loop_rate(10);

    geometry_msgs::Twist msg;        
        msg.linear.x = 1.0;
        msg.angular.z = 2.0;

    int count = 0;
    while (ros::ok())
    {                       
            char ch;
            cin>>ch;
            switch(ch){
                case 'w' :
                case 'W' :
                     msg.linear.x +=0.1;
                     break;
                case 's' :
                case 'S' :
                     msg.linear.x -= 0.1;
                     break;
                case 'a' :
                case 'A' :
                    msg.angular.z -= 0.1;
                    break;
                case 'd' :
                case 'D' :
                    msg.angular.z += 0.1;
                    break;

            }
        
        ROS_INFO("%lf", msg.linear.x);
        ROS_INFO("%lf", msg.angular.z);

        pub.publish(msg);
        ros::spinOnce();
    }
  //  close_keyboard();
}