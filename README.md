# ROS-Home Service Robot

## Overview
Home Service Robot is responsible for picking up virtual objects from a certain location and dropping them off at another location. The project implements SLAM using gmapping package and the 2D map generated from there is used for the primary tasks.


**Keywords:** gmapping, SLAM, localization, turtlebot, ROS


### License

The source code is released under a [Apache License 2.0](/LICENSE).

**Author: Abhigya Raval<br />
Maintainer: Abhigya Raval, abhigyaraval@gmail.com**

The packages has been tested under [ROS] Kinetic on Ubuntu 16.04.



![Example image](docs/action.gif)

**Gazebo env**
![Example image](docs/gazebo_preview.png)

**Rviz viz**
![Example image](docs/rviz_preview.png)



## Installation

### Installation from Packages

Using the mentioned version of ROS and Ubuntu, make sure to install the dependecies for the following packages using:

<!-- Or better, use `rosdep`: -->
```
sudo apt-get update
source devel/setup.bash
rosdep -i install gmapping
rosdep -i install turtlebot_teleop
rosdep -i install turtlebot_rviz_launchers
rosdep -i install turtlebot_gazebo
```
### Building from Source

<!-- #### Dependencies

- [Robot Operating System (ROS)](http://wiki.ros.org) (middleware for robotics),
- [Eigen] (linear algebra library)

	sudo rosdep install --from-paths src -->

#### Building

To build from source, clone the latest version from this repository into your catkin workspace and compile the package using
```
cd catkin_ws
catkin_make
source devel/setup.bash
```
<!-- ### Running in Docker

Docker is a great way to run an application with all dependencies and libraries bundles together.
Make sure to [install Docker](https://docs.docker.com/get-docker/) first.

First, spin up a simple container:

	docker run -ti --rm --name ros-container ros:noetic bash

This downloads the `ros:noetic` image from the Docker Hub, indicates that it requires an interactive terminal (`-t, -i`), gives it a name (`--name`), removes it after you exit the container (`--rm`) and runs a command (`bash`).

Now, create a catkin workspace, clone the package, build it, done!

	apt-get update && apt-get install -y git
	mkdir -p /ws/src && cd /ws/src
	git clone https://github.com/leggedrobotics/ros_best_practices.git
	cd ..
	rosdep install --from-path src
	catkin_make
	source devel/setup.bash
	roslaunch ros_package_template ros_package_template.launch -->

### Unit Tests

```
cd catkin_ws
catkin_make
source devel/setup.bash
```
To create a new map using SLAM

	./src/scripts/test_slam.sh


<!-- ### Static code analysis

Run the static code analysis with

	catkin_make roslint_ros_package_template -->

## Usage

To run home service example

```
cd catkin_ws
catkin_make
source devel/setup.bash
./src/scripts/home_service.sh
```
