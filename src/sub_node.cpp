#include "ros/ros.h"
#include <geometry_msgs/Twist.h>

void MsgCB(const geometry_msgs::Twist::ConstPtr& msg)
{
    ROS_INFO("receive: [%lf]", msg->linear.x);
    ROS_INFO("receive: [%lf]", msg->angular.z);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "topic_subscriber");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("cmd_vel", 1000, MsgCB);

    ros::spin();
    return 0;
}