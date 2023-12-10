#include <sstream>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char**argv){
    ros::init(argc,argv,"publish");
    ros::NodeHandle n;
    ros::Publisher chatter_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",1000);
    ros::Rate loop_rate(100);
    while(ros::ok()){
        geometry_msgs::Twist msg;
        geometry_msgs::Vector3 linear;
        linear.x = 0;
        linear.y = 0;
        linear.z = 1;

        geometry_msgs::Vector3 angular;
        angular.x = 0;
        angular.y = 0;
        angular.z = 0;

        msg.linear = linear;
        msg.angular = angular;
        
        chatter_pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}