/*
Note: In order to use this node with the script add_markers.sh, all code with the
nodeHandle n should be commented out and the 5 second sleep timers should be uncommented.
*/



#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "add_markers");
    ros::NodeHandle n;
    ros::Rate r(1);
    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

    // Setup initial state and parameters of the cube
	visualization_msgs::Marker marker;
	marker.header.frame_id = "map";
	marker.type = visualization_msgs::Marker::CUBE;

    // Unique namespace and id for this marker
	marker.ns = "add_markers";
	marker.id = 0;

    // Init pose, color and scale of the marker
    marker.pose.position.x = 6.8;
	marker.pose.position.y = 4.2;
	marker.pose.position.z = 0.0;
	marker.pose.orientation.x = 0.0;
	marker.pose.orientation.y = 0.0;
	marker.pose.orientation.z = 0.0;
	marker.pose.orientation.w = 1.0;

	marker.scale.x = 0.3;
	marker.scale.y = 0.3;
	marker.scale.z = 0.05;

    marker.color.r = 1.0f;
	marker.color.g = 0.0f;
	marker.color.b = 0.0f;
	marker.color.a = 1.0;

    // ros param to talk to pick up node
    bool reached_pick_up_location = false;
    bool reached_drop_off_location = false;

    // Loop until robot reaches pick up location
    while(ros::ok())
    {
        marker.header.stamp = ros::Time::now();
        marker.action = visualization_msgs::Marker::ADD;
        marker.lifetime = ros::Duration();

        // Publishing marker
        marker_pub.publish(marker);
		
		r.sleep();
        // ros::Duration(5).sleep();


		n.getParam("reached_pick_up_location", reached_pick_up_location);
		if (reached_pick_up_location)
			break;
    }

    // Once loop breaks, the robot has arrived to pick up the object
    ROS_INFO("Robot arrived! Marker is being picked up...");
    marker.action = visualization_msgs::Marker::DELETE;
    marker_pub.publish(marker);
    // ros::Duration(5).sleep();

    // n.getParam("reached_drop_off_location", reached_drop_off_location);
    while(true){
        n.getParam("reached_drop_off_location", reached_drop_off_location);
        if(reached_drop_off_location){
            ROS_INFO("Marker will now be dropped at the second location...");
            break;
        }
    }

    // Once robot has arrived at the drop off site, the object is dropped off
    marker.pose.position.x = 3.6;
	marker.pose.position.y = -8.6;
	marker.pose.position.z = 0.05;
	marker.pose.orientation.x = 0.0;
	marker.pose.orientation.y = 0.0;
	marker.pose.orientation.z = 0.0;
	marker.pose.orientation.w = 1.0;

    while(ros::ok()){
        marker.header.stamp = ros::Time::now();
        marker.action = visualization_msgs::Marker::ADD;
        marker.lifetime = ros::Duration();

        marker_pub.publish(marker);
        r.sleep();
    }
}
