cmake_minimum_required(VERSION 3.5)
project(skunk)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_srvs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(sllidar_ros2 REQUIRED)

include_directories(
  ${sllidar_ros2_INCLUDE_DIRS}  # Assuming sllidar_ros2 provides include directories
)

add_executable(mode_node src/mode_node.cpp)

ament_target_dependencies(mode_node
  rclcpp
  std_srvs
  sensor_msgs
  sllidar_ros2
)

install(TARGETS
  mode_node
  DESTINATION lib/${PROJECT_NAME}
)
install(PROGRAMS
  launch/skunk_launch.py
  DESTINATION lib/${PROJECT_NAME}
)
# Install launch files
install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)
ament_package()
