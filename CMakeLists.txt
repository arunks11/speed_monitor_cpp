cmake_minimum_required(VERSION 3.8)
project(speed_monitor_cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(speed_publisher src/speed_publisher.cpp)
ament_target_dependencies(speed_publisher rclcpp std_msgs)

add_executable(speed_subscriber src/speed_subscriber.cpp)
ament_target_dependencies(speed_subscriber rclcpp std_msgs)

install(TARGETS
  speed_publisher
  speed_subscriber
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
