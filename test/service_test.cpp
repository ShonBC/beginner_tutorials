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

/**
 * @brief Construct a new TEST object. Checks if ROS service client exists.
 * 
 */
TEST(SERVICE_TEST, service_exists) {
  ros::ServiceClient client = nh->serviceClient<
                        beginner_tutorials::ChangeTalker>(
      "change_talker");

  bool exists(client.waitForExistence(ros::Duration(1)));
  EXPECT_TRUE(exists);
}

/**
 * @brief Construct a new TEST object. Test if response is equal to the request.
 * 
 */
TEST(SERVICE_TEST, service_change) {
    ros::ServiceClient client = nh->serviceClient<
                        beginner_tutorials::ChangeTalker>(
      "change_talker");
  beginner_tutorials::ChangeTalker srv;
  srv.request.desired_string = "testing";
  client.call(srv);
  EXPECT_EQ("testing", srv.response.new_string);
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "service_test");
  nh.reset(new ros::NodeHandle);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
