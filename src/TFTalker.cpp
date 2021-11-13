/**
 * @file TFTalker.cpp
 * @author Shon Cortes scortes3@umd.edu
 * @brief Broadcast tf frame from /world to /talk
 * @version 0.1
 * @date 2021-11-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char** argv) {
  ros::init(argc, argv, "my_tf_broadcaster");
  ros::NodeHandle node;

  tf::TransformBroadcaster br;
  tf::Transform transform;

    ros::Rate rate(10.0);
    while (node.ok()) {
      transform.setOrigin(tf::Vector3(2, 2, 0.0));
      transform.setRotation(tf::Quaternion(10, 10, 0, 1) );
      br.sendTransform(tf::StampedTransform(transform, ros::Time::now(),
                        "world", "talk"));
      rate.sleep();
    }
    return 0;
}
