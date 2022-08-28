#ifndef DEVICES
#define DEVICES
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>

#include <map>
#include <set>
#include <vector>

#include <algorithm>
#include <cstdint>
#include <limits>

#include <optional>

struct SwapChainSupportDetails {
  VkSurfaceCapabilitiesKHR capabilities;
  std::vector<VkSurfaceFormatKHR> formats;
  std::vector<VkPresentModeKHR> presentModes;
};

struct QueueFamilyIndices {
  std::optional<uint32_t> graphicsFamily;
  std::optional<uint32_t> presentFamily;

  bool isComplete() {
    return graphicsFamily.has_value() && presentFamily.has_value();
  }
};

class Devices {
public:
  Devices(VkInstance *instance,
          const std::vector<const char *> *validationLayers,
          VkSurfaceKHR *surface, GLFWwindow *window);

  void createLogicalDevice();
  void cleanup();

  void pickPhysicalDevice();
  void setSurface(VkSurfaceKHR *surface);
  void setWindow(VkSurfaceKHR surface);
  void createSwapChain();

private:
  VkQueue presentQueue;
  VkSwapchainKHR swapChain;

  VkDevice device;
  GLFWwindow *window;
  VkInstance *instance;

  const std::vector<const char *> *validationLayers;

  VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
  VkQueue graphicsQueue;

  VkSurfaceKHR surface;

  const std::vector<const char *> deviceExtensions = {
      VK_KHR_SWAPCHAIN_EXTENSION_NAME};

  std::vector<VkImage> swapChainImages;
  VkFormat swapChainImageFormat;
  VkExtent2D swapChainExtent;

  bool checkDeviceExtensionSupport(VkPhysicalDevice device);
  VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR &capabilities);

  VkSurfaceFormatKHR chooseSwapSurfaceFormat(
      const std::vector<VkSurfaceFormatKHR> &availableFormats);
  VkPresentModeKHR chooseSwapPresentMode(
      const std::vector<VkPresentModeKHR> &availablePresentModes);
  VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR &capabilities,
                              GLFWwindow *window);
  int rateDeviceSuitability(VkPhysicalDevice device);
  bool isDeviceSuitable(VkPhysicalDevice device);
  QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
  SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
};
#endif
