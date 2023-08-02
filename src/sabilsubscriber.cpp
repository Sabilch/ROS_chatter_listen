#include "ros/ros.h"
//#include "sabilsubscriber/person_data.h"
#include <std_msgs/String.h>


void writeMsgToLog(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("Hearing:[%s] ", msg->data.c_str());
    ros::Rate rate(1);
    while (ros::ok())
    {
    ros::spinOnce();
    rate.sleep();
    }
}


int main (int args, char **argv) {

    ros::init(args, argv, "sabilsubscriber");

    ros::NodeHandle n;

    ros::Subscriber topic_sub = n.subscribe("/sabilData", 1 ,writeMsgToLog);

    ros::spin();

    return 0;
}