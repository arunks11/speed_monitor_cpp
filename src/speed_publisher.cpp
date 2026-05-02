#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"
#include <cstdlib>
#include <ctime>

class SpeedPublisher : public rclcpp::Node
{
public:
    SpeedPublisher() : Node("speed_publisher")
    {
        publisher_ = this->create_publisher<std_msgs::msg::Float32>("robot_speed", 10);

        timer_ = this->create_wall_timer(
            std::chrono::seconds(1),
            std::bind(&SpeedPublisher::publish_speed, this));

        std::srand(std::time(0));
    }

private:
    void publish_speed()
    {
        auto message = std_msgs::msg::Float32();

        message.data = rand() % 120;  // Random speed 0–119 km/h

        RCLCPP_INFO(this->get_logger(),
                    "Publishing Speed: %.2f km/h",
                    message.data);

        publisher_->publish(message);
    }

    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SpeedPublisher>());
    rclcpp::shutdown();
    return 0;
}
