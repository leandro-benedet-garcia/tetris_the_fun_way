#ifndef DEVICES
#define DEVICES
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>

#include <set>
#include <map>
#include <vector>

#include <optional>

struct QueueFamilyIndices {
  std::optional<uint32_t> graphicsFamily;
  std::optional<uint32_t> presentFamily;

  bool isComplete() {
    return graphicsFamily.has_value() && presentFamily.has_value();
  }
};

class Devices {
public:
  void createLogicalDevice();
  void cleanup();

  void pickPhysicalDevice(VkInstance instance);
  void setSurface(VkSurfaceKHR surface);

private:
  VkDevice device;
  VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
  VkQueue graphicsQueue;

  VkSurfaceKHR surface;

  int rateDeviceSuitability(VkPhysicalDevice device);
  bool isDeviceSuitable(VkPhysicalDevice device);
  QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
};
#endif
