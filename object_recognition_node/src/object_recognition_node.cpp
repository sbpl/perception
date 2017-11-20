/**
 * @file sbpl_perception_node.cpp
 * @brief SBPL perception node
 * @author Venkatraman Narayanan
 * Carnegie Mellon University, 2014
 */

#include <object_recognition_node/perception_interface.h>

#include <ros/ros.h>
#include <ros/package.h>

using namespace std;

int main(int argc, char **argv) {
  ros::init(argc, argv, "object_recognition_node");
  ros::NodeHandle nh;
  PerceptionInterface perception_interface(nh);
  pcl::visualization::PCLVisualizer* viewer = perception_interface.mutable_viewer();
  // pcl::visualization::RangeImageVisualizer* range_image_viewer = perception_interface.mutable_range_image_viewer();
  
  //perception_interface.DetectObjects();

  ros::Rate loop_rate(30.0);
  while(ros::ok())
  {
    if (perception_interface.pcl_visualization())
    {
      viewer->spinOnce();
      // range_image_viewer->spinOnce();
    }
    ros::spinOnce();
	loop_rate.sleep();
  }
  return 0;
}
