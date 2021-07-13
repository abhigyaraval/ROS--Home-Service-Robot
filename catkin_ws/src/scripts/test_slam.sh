#!/bin/sh

# Deploy turtlebot in the environment
xterm -e "roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=\"$(rospack find add_markers)/map/my_world.world\"" &
sleep 10

# Launch gmapping_demo
xterm -e "roslaunch turtlebot_gazebo gmapping_demo.launch" &
sleep 10

# View navigation in Rviz
xterm  -e  "roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 10

# Teleop to control manually
xterm -e "roslaunch turtlebot_teleop keyboard_teleop.launch"
