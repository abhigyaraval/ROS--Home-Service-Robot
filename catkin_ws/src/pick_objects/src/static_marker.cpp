#include <ros/ros.h>


int main(int argc, char** argv){

  ros::init(argc, argv, "static_marker");

  ros::NodeHandle n1;
  n1.setParam("reached_pick_up_location", false);
  n1.setParam("reached_drop_off_location", false);
  
//   ROS_INFO();
  ros::Duration(5).sleep();

    n1.setParam("reached_pick_up_location", true);
  


  ros::Duration(5).sleep(); 



    n1.setParam("reached_drop_off_location", true);

    while(ros::ok()){
        if (!ros::ok()){
            return 0;
        }
    }
}