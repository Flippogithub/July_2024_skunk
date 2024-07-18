#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"
int32_t outVal;
class ModePublisher : public rclcpp::Node
{
public:
  ModePublisher()
  : Node("mode_publisher")
  {
    publisher_ = this->create_publisher<std_msgs::msg::Int32>("mode", 10);
    timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&ModePublisher::publish_mode, this));
  }

private:
  void publish_mode()
  {
    outVal=outVal+1;
    auto msg = std_msgs::msg::Int32();
    msg.data = outVal; //mode_value_;
    //RCLCPP_INFO(this->get_logger(), "Publishing mode: %d", msg.data);
    publisher_->publish(msg);
  }

  rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
  int32_t mode_value_ = 0; // Example mode value to publish
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<ModePublisher>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
  
}
