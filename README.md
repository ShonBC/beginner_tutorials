[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)

# beginner_tutorials
ROS tutorials

# Prerequisites:
- Ubuntu 18.04
- ROS Melodic
- ROS Beginner tutorials installed:
    sudo apt-get install ros-melodic-ros-tutorials

# Build and Run:
Clone the repo in the src folder of a catkin workspace.

    git clone https://github.com/ShonBC/beginner_tutorials.git

Build the packages in the workspace. 
If the catkin workspace was created using catkin_make then navigate to the catkin workspace directory and run:

    catkin_make
    . ~/<catkin_ws_directory_name>/devel/setup.bash

If the workspace was created using catkin build then run:

    catkin build
    . ~/<catkin_ws_directory_name>/devel/setup.bash

## Publisher and Subscriber
Open terminal and initiate a ROS Master:

    roscore

Open a new terminal and initiate the publisher node:

    rosrun beginner_tutorials talker 

Open a new terminal and initiate the subscriber node:

    rosrun beginner_tutorials listener 

## ROS Service
This service will allow for user input to define the message being published to the "chatter" topic. 
To launch the client and server(which also acts as a publisher) run:

    roslaunch beginner_tutorials change.launch my_args:="<Publisher_message>"

This launches the server and client/publisher that will publish a default message if no arguments are passed. It also launches the listener node which is getting the new user defined message published to the chatter topic.

The rqt_console and logger_level screenshots can be found in the docs/rqt_console directory. 

## ROS Tests
To run tests, navigate to the root of the catkin workspace and run:

    catkin_make tests
    catkin_make test

To run the ROS test files run:

    rostest beginner_tutorials beginner_tutorials.test 
