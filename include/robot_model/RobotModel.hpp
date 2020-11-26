#pragma once

#include <ros/ros.h>
#include "geometry_msgs/Twist.h"
#include "std_msgs/Float64MultiArray.h"
#include <float.h>

namespace robotModel
{
    class RobotModel
    {
    public:
        RobotModel(ros::NodeHandle& nodeHandle);
        virtual ~RobotModel();
        void twistCallback(const geometry_msgs::Twist& msg);

    private:
        ros::NodeHandle nodeHandle_;
        ros::Subscriber twister_;
        ros::Publisher to_speed_;
        ros::Publisher to_steer_;
    };
}