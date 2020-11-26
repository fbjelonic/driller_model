#include "robot_model/RobotModel.hpp"

namespace robotModel
{
    RobotModel::RobotModel(ros::NodeHandle &nodeHandle)
    : nodeHandle_(nodeHandle)
    {
        twister_ = nodeHandle_.subscribe("/driller_drive_controller/cmd_vel", 10, &RobotModel::twistCallback, this);
        to_speed_ = nodeHandle_.advertise<std_msgs::Float64MultiArray>("/driller_drive_controller/command", 10);
        to_steer_ = nodeHandle_.advertise<std_msgs::Float64MultiArray>("/driller_steer_controller/command", 10);
    }
    RobotModel::~RobotModel() {}
    void RobotModel::twistCallback(const geometry_msgs::Twist &msg)
    {
        std_msgs::Float64MultiArray speed;
        speed.data.resize(2);
        speed.data[0] = msg.linear.x;
        speed.data[1] = msg.linear.x;
        to_speed_.publish(speed);
        std_msgs::Float64MultiArray steer;
        steer.data.resize(2);
        steer.data[0] = msg.angular.z;
        steer.data[1] = msg.angular.z;
        to_steer_.publish(steer);
    }
}