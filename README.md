# beginner_tutorials
ROS tutorials

## Prerequisites:
- Ubuntu 18.04
- ROS Melodic
- ROS Beginner tutorials installed:
    sudo apt-get install ros-melodic-ros-tutorials

## Build and Run:
Clone the repo in the src folder of a catkin workspace.

    git clone https://github.com/ShonBC/beginner_tutorials.git

Build the packages in the workspace. 
If the catkin workspace was created using catkin_make then navigate to the catkin workspace directory and run:

    catkin_make
    . ~/<catkin_ws_directory_name>/devel/setup.bash

If the workspace was created using catkin build then run:

    catkin build
    . ~/catkin_ws/devel/setup.bash

Open terminal and initiate a ROS Master:

    roscore

Open a new terminal and initiate the publisher node:

    rosrun beginner_tutorials talker 

Open a new terminal and initiate the subscriber node:

    rosrun beginner_tutorials listener 
