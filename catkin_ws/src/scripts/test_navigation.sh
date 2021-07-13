#!/bin/sh

# deploy turtlebot in environment
xterm  -e  "roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=\"$(rospack find add_markers)/map/my_world.world\"" &
sleep 10

# launch SLAM
xterm  -e  "roslaunch turtlebot_gazebo amcl_demo.launch map_file:=\"$(rospack find add_markers)/map/map.yaml\"" &
sleep 10

xterm -e "roslaunch turtlebot_teleop keyboard_teleop.launch" &
sleep 5


# observe map in Rviz
xterm  -e  "roslaunch turtlebot_rviz_launchers view_navigation.launch"

