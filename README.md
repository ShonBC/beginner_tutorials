# beginner_tutorials
ROS tutorials

# Prerequisites:
- Ubuntu 18.04
- ROS Melodic
- ROS Beginner tutorials installed:
    sudo apt-get install ros-melodic-ros-tutorials

# Build and Run:
- Clone the repo in the src folder of a catkin workspace.
    git clone https://github.com/ShonBC/beginner_tutorials.git
- Build the packages in the workspace. 
    - If the catkin workspace was created using catkin_make then run:
        cd ~/catkin_ws
        catkin_make
        . ~/catkin_ws/devel/setup.bash
    - If the workspace was created using catkin build then run:
        catkin build
        . ~/catkin_ws/devel/setup.bash
- 