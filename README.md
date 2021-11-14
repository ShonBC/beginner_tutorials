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

The rqt_console and logger_level screenshots can be found in the [docs/rqt_console](docs/rqt_console) directory. 

## TF Frames
To demonstrate the broadcasting of frames, a node was designed to broadcast the transformation from the /world frame to a /talk frame which has been offset by a translation and rotation. To run this node open a terminal and run:

    rosrun beginner_tutorials tf_talker

To view the transformations in the terminal simply run:

    rosrun tf tf_echo /world /talk

To view the reference frames tree open a new terminal while the tf_talker node is active and run:

    rosrun rqt_tf_tree rqt_tf_tree

To save a pdf copy of the active nodes reference frame tree run:

    rosrun tf view_frames 
    evince frames.pdf 

An example output can be found in the [docs/tf_view_frames](docs/tf_view_frames) directory.

## ROS Tests
To run tests, navigate to the root of the catkin workspace and run:

    catkin_make tests
    catkin_make test

To run the ROS test files run:

    rostest beginner_tutorials beginner_tutorials.test 

## Recording Bag File
By default the change.launch file will not record a bag file. To run the nodes with a custom published message and record a bag file run:

    roslaunch beginner_tutorials change.launch ros_bag:="true" my_args:="<Custom message>"

The bag file will be recorded in the [docs/bag](docs/bag) directory. To examine the bag file first navigate into the [docs/bag](docs/bag) directory in a terminal and run:

    rosbag info bag_file.bag

To play the bag file back and see the published messages first run the listener node:

    rosrun beginner_tutorials listener

In a new terminal navigate to the [docs/bag](docs/bag) directory and run:

    roscd beginner_tutorials/docs/bag
    rosbag play bag_file.bag
