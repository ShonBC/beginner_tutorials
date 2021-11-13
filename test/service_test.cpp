/**
 * @file service_test.cpp
 * @author Shon Cortes scortes3@umd.edu
 * @brief Tests for ROS service
 * @version 0.1
 * @date 2021-11-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <ros/ros.h>
#include <ros/service_client.h>
#include <gtest/gtest.h>
#include "beginner_tutorials/ChangeTalker.h"

std::shared_ptr<ros::NodeHandle> nh;

TEST(TF_TALKER_TEST, tf_talker) {
    ros::ServiceClient client = nh->serviceClient<
                        beginner_tutorials::ChangeTalker>(
      "SrvChgStr");
  beginner_tutorials::ChangeTalker srv;
  srv.request.desired_string = "testing";
  client.call(srv);
  EXPECT_EQ("testing", srv.response.new_string);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  ros::init(argc, argv, "tester");
  ros::NodeHandle nh;
  return RUN_ALL_TESTS();
}
