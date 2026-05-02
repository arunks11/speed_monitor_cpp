#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"

class SpeedSubscriber : public rclcpp::Node
{
public:
    SpeedSubscriber() : Node("speed_subscriber")
    {
        subscription_ = this->create_subscription<std_msgs::msg::Float32>(
            "robot_speed",
            10,
            std::bind(&SpeedSubscriber::speed_callback, this, std::placeholders::_1));
    }

private:
    void speed_callback(const std_msgs::msg::Float32::SharedPtr msg)
    {
        float speed = msg->data;

        if (speed > 80)
        {
            RCLCPP_WARN(this->get_logger(),
                        "⚠️ Overspeed Alert! Current Speed: %.2f km/h",
                        speed);
        }
        else
        {
            RCLCPP_INFO(this->get_logger(),
                        "Speed is Normal: %.2f km/h",
                        speed);
        }
    }

    rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SpeedSubscriber>());
    rclcpp::shutdown();
    return 0;
}
