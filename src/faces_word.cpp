/*
    Copyright (C) 2017  Akira Kudo
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include<ros/ros.h>
#include<std_msgs/String.h>

void Callback(const std_msgs::String::ConstPtr& msg){
    if(!strcmp(msg->data.c_str(), "Happy")){
        ROS_INFO("(^o^)/ \n\n");   
    }else if(!strcmp(msg->data.c_str(), "Sad")){
        ROS_INFO("(T^T) \n\n");
    }else if(!strcmp(msg->data.c_str(), "Anger")){
        ROS_INFO("(#'_') \n\n");   
    }
}

int main (int argc, char **argv){
    ros::init(argc, argv, "faces_word");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("feelings_out", 1000, Callback);
    ros::spin();
    return 0;
}
