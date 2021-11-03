/**
 * @file ChangeTalkerServer.cpp
 * @author Shon Cortes scortes3@umd.edu
 * @brief Change the message a Publisher produces
 * @version 0.1
 * @date 2021-11-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "ros/ros.h"
#include "beginner_tutorials/ChangeTalker.h"

/**
 * @brief Server method to take the request parameter and set the response parameter equal to it.
 * 
 * @param req The input parameter 
 * @param res The returned parameter
 * @return true Once the response has been set equal to the request.
 */
bool ChangeString(beginner_tutorials::ChangeTalker::Request &req,
                        beginner_tutorials::ChangeTalker::Response &res) {
    res.new_string = req.desired_string;

    ROS_INFO_STREAM("Request: " << req.desired_string <<
                    " Response: " << res.new_string);

    return true;
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "change_talker_server");
    ros::NodeHandle n;
    ros::ServiceServer service = n.advertiseService("change_talker",
                                                        ChangeString);
    ROS_INFO_STREAM("Ready to change the publish message.");
    ros::spin();
    return 0;
}
