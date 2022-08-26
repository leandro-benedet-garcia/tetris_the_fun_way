#define GLFW_INCLUDE_VULKAN

#include <GLFW/glfw3.h>

#include <cstdlib>
#include <iostream>
#include <stdexcept>

#ifndef NDEBUG
#include "headers/validation_layering.hpp"
#endif

#include "headers/devices.hpp"

class TetrisTheFunWay {
public:
  TetrisTheFunWay() {
#ifndef NDEBUG
    validationLayering = new ValidationLayering(validationLayers);
#endif
    devices = new Devices();
  }
  void run() {
    initWindow();
    initVulkan();
    mainLoop();
    cleanup();
  }

private:
  GLFWwindow *window;
  VkInstance instance;

  Devices *devices;

  const uint16_t WIDTH = 800;
  const uint16_t HEIGHT = 600;

  const char *WINDOW_NAME = "Vulkan";
  const char *GAME_NAME = "Tetris the !!Fun!! Way";
  const char *ENGINE_NAME = "!!FUN!!";

  const uint32_t GAME_VERSION = VK_MAKE_VERSION(0, 0, 1);
  const uint32_t ENGINE_VERSION = VK_MAKE_VERSION(0, 0, 1);


#ifdef NDEBUG
  const bool ENABLE_VALIDATION_LAYERS = false;
#else
  const bool ENABLE_VALIDATION_LAYERS = true;
  ValidationLayering *validationLayering;
  const std::vector<const char *> validationLayers = {
      "VK_LAYER_KHRONOS_validation",
  };
#endif

  inline void initWindow() {
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(WIDTH, HEIGHT, WINDOW_NAME, nullptr, nullptr);
  }

  inline void initVulkan() {
    createInstance();
#ifndef NDEBUG
    validationLayering->setupDebugMessenger(instance);
#endif
    devices->pickPhysicalDevice(instance);
    devices->createLogicalDevice();
  }

  void createInstance() {
#ifndef NDEBUG
    validationLayering->checkValidationLayerSupport();
#endif

    VkApplicationInfo appInfo{};
    VkInstanceCreateInfo createInfo{};

    uint32_t glfwExtensionCount = 0;
    const char **glfwExtensions;

    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;

    appInfo.pApplicationName = GAME_NAME;
    appInfo.applicationVersion = GAME_VERSION;

    appInfo.pEngineName = ENGINE_NAME;
    appInfo.engineVersion = ENGINE_VERSION;

    appInfo.apiVersion = VK_API_VERSION_1_0;

    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    createInfo.enabledExtensionCount = glfwExtensionCount;
    createInfo.ppEnabledExtensionNames = glfwExtensions;

#ifdef NDEBUG
    createInfo.enabledLayerCount = 0;

    createInfo.pNext = nullptr;

#else
    auto extensions = validationLayering->getRequiredExtensions();
    createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
    createInfo.ppEnabledExtensionNames = extensions.data();

    VkDebugUtilsMessengerCreateInfoEXT debugCreateInfo{};

    createInfo.enabledLayerCount =
        static_cast<uint32_t>(validationLayers.size());
    createInfo.ppEnabledLayerNames = validationLayers.data();

    validationLayering->populateDebugMessengerCreateInfo(debugCreateInfo);
    createInfo.pNext = (VkDebugUtilsMessengerCreateInfoEXT *)&debugCreateInfo;
#endif

    VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);

    if (result != VK_SUCCESS)
      throw std::runtime_error("failed to create instance!");
  }

  inline void mainLoop() {
    while (!glfwWindowShouldClose(window))
      glfwPollEvents();
  }

  inline void cleanup() {
    devices->cleanup();

#ifndef NDEBUG
    validationLayering->DestroyDebugUtilsMessengerEXT(instance, nullptr);
#endif
    vkDestroyInstance(instance, nullptr);

    glfwDestroyWindow(window);

    glfwTerminate();
  }
};

int main() {
  TetrisTheFunWay app;

  try {
    app.run();
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
};
