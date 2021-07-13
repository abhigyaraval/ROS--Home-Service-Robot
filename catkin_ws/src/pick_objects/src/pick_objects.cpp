#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

// Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
  // Initialize the simple_navigation_goals node
  ros::init(argc, argv, "pick_objects");

  // Node handle for params server
  ros::NodeHandle n1;
  n1.setParam("reached_pick_up_location", false);
  n1.setParam("reached_drop_off_location", false);
  

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  // Wait 5 sec for move_base action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal;

  // set up the frame parameters
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();

  // Define a position and orientation for the robot to reach
  goal.target_pose.pose.position.x = 6.8;
  goal.target_pose.pose.position.y = 4.2;
  goal.target_pose.pose.orientation.w = 1.0;
  goal.target_pose.pose.orientation.z = 0.0;


   // Send the goal position and orientation for the robot to reach
  ROS_INFO("Sending pick up location coordinates...");
  ac.sendGoal(goal);

  // Wait an infinite time for the results
  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
    ROS_INFO("The robot has reached the pick up location successfully!");
    n1.setParam("reached_pick_up_location", true);
  }
  else{
    ROS_INFO("The robot failed to reach the pick up location!");
  }

  ros::Duration(5).sleep(); // Simulate picking up the object

// Drive to drop off location
  goal.target_pose.pose.position.x = 3.6;
  goal.target_pose.pose.position.y = -8.6;
  goal.target_pose.pose.orientation.w = 0.0;
  goal.target_pose.pose.orientation.z = 1.0;

   // Send the goal position and orientation for the robot to reach
  ROS_INFO("Sending drop off location coordinates...");
  ac.sendGoal(goal);

  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
    ROS_INFO("The robot has reached the drop off location successfully!");
    n1.setParam("reached_drop_off_location", true);
  }
  else
    ROS_INFO("The robot failed to reach the drop off location!");
}
