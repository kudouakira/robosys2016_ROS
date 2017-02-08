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

#include"std_msgs/String.h"
#include"ros/ros.h"
#include<sstream>

int main(int argc, char **argv){
    int n=1;
    ros::init(argc, argv, "feelings_pub");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise <std_msgs::String> ("feelings_out", 1000);

    ros::Rate loop_rate(1);
    while(ros::ok()){
        std_msgs::String msg;
        if(n==1){
            msg.data = "Happy";
        }else if(n==2){
            msg.data = "Sad";
        }else if(n==3){
            msg.data = "Anger";
            n = 0;
        }
        ROS_DEBUG("%s", msg.data.c_str());
        pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
        n += 1;
    }

    return 0;
}
