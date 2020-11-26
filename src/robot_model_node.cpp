#include <ros/ros.h>
#include "robot_model/RobotModel.hpp"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "robot_model");
    ros::NodeHandle nodeHandle("~");

    robotModel::RobotModel robotModel(nodeHandle);

    ros::spin();
    return 0;
}