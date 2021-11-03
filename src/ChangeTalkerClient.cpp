/**
 * @file ChangeTalkerClient.cpp
 * @author Shon Cortes scortes3@umd.edu
 * @brief Publisher Client that publishes a message that can be changed based off of user inputs.
 * @version 0.1
 * @date 2021-11-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <cstdlib>
#include <sstream>
#include <vector>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "beginner_tutorials/ChangeTalker.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "change_talker_client");

    if (argc == 0) {
    ROS_WARN_STREAM("No arguments passed, default message will be published.");
    }

    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient
        <beginner_tutorials::ChangeTalker>("change_talker");

    beginner_tutorials::ChangeTalker srv;

    if (argc > 2) {
        std::vector<std::string> words(argv +1, argv + argc);

        for (std::vector<std::string>::const_iterator
                            i = words.begin(); i != words.end(); ++i) {
            srv.request.desired_string += *i + " ";
        }
    ROS_DEBUG_STREAM("argc: " << argc << " argv: " << argv
                            << "New message: " << srv.request.desired_string);
    } else if (argc < 2) {
        srv.request.desired_string = "Default message. No arguments passed.";
        } else {
        srv.request.desired_string = argv[1];
    }

    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

    ros::Rate loop_rate(10);

    int count = 0;
    // Begin publisher loop
    while (ros::ok()) {
        ROS_DEBUG_STREAM("Began publishing loop.");

        // Call the server
        if (client.call(srv)) {
            ROS_INFO_STREAM("SRV Publishing: " << srv.response.new_string);
            } else {
                ROS_ERROR_STREAM("Failed to call service change_talker");
        return 1;
        }

        std_msgs::String msg;

        std::stringstream ss;
        ss << srv.response.new_string << count;
        msg.data = ss.str();

        ROS_INFO("%s", msg.data.c_str());

        chatter_pub.publish(msg);

        ros::spinOnce();

        loop_rate.sleep();

        ++count;
  }


  return 0;
}
