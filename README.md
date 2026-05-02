# ROS 2 Speed Monitoring System 🚗

This project is a simple ROS 2 C++ Publisher-Subscriber application that simulates a robot speed monitoring system.

## Project Overview
- Publisher node generates random speed values
- Subscriber node receives speed values
- If speed exceeds 80 km/h, it displays an overspeed warning

This project helped me understand ROS 2 topic communication using C++.

---

## Technologies Used
- ROS 2
- C++
- rclcpp
- std_msgs

---

## Project Structure
speed_monitor_cpp/

├── src/ 

│   ├── speed_publisher.cpp

│   ├── speed_subscriber.cpp

├── CMakeLists.txt

├── package.xml

---

## How It Works

### Publisher Node
Publishes random speed values between 0–120 km/h.

Example:
Publishing Speed: 95 km/h

### Subscriber Node
Receives speed values and checks safety threshold.

Example:
⚠️ Overspeed Alert! Current Speed: 95 km/h

---

## Build Instructions

```bash
cd ~/ros2_ws
colcon build --packages-select speed_monitor_cpp
source install/setup.bash
Run Subscriber
ros2 run speed_monitor_cpp speed_subscriber
Run Publisher
ros2 run speed_monitor_cpp speed_publisher
