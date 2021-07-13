#!/bin/sh

# deploy turtlebot in environment
xterm  -e  "roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=\"$(rospack find add_markers)/map/my_world.world\"" &
sleep 10

# Observe map in Rviz
xterm  -e  "roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 10

# Perform SLAM
xterm  -e  "roslaunch turtlebot_gazebo amcl_demo.launch map_file:=\"$(rospack find add_markers)/map/map.yaml\"" &
sleep 10

# Launch add_markers_static node
xterm  -e  "rosrun add_markers add_markers" &
sleep 1

# Launch the static marker node
xterm -e "rosrun pick_objects static_marker"

