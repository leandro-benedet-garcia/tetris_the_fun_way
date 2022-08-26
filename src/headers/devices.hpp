#ifndef DEVICES
#define DEVICES
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <map>
#include <optional>
#include <vector>

struct QueueFamilyIndices {
  std::optional<uint32_t> graphicsFamily;

  bool isComplete() { return graphicsFamily.has_value(); }
};

class Devices {
public:
  void createLogicalDevice();
  void cleanup();

  void pickPhysicalDevice(VkInstance instance);

private:
  VkDevice device;
  VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
  VkQueue graphicsQueue;

  int rateDeviceSuitability(VkPhysicalDevice device);
  bool isDeviceSuitable(VkPhysicalDevice device);
  QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
};
#endif
