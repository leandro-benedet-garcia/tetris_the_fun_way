#define GLFW_INCLUDE_VULKAN
#include "./tetris_the_fun_way.hpp"
#include <GLFW/glfw3.h>

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <vector>

void TetrisTheFunWay::run() {
  initWindow();
  initVulkan();
  mainLoop();
  cleanup();
}

void TetrisTheFunWay::initWindow() {
  glfwInit();

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  window = glfwCreateWindow(WIDTH, HEIGHT, WINDOW_NAME, nullptr, nullptr);
}

std::vector<const char *> TetrisTheFunWay::getRequiredExtensions() {
  uint32_t glfwExtensionCount = 0;
  const char **glfwExtensions;
  glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

  std::vector<const char *> extensions(glfwExtensions,
                                       glfwExtensions + glfwExtensionCount);

  if (ENABLE_VALIDATION_LAYERS)
    extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);

  return extensions;
}

bool TetrisTheFunWay::checkValidationLayerSupport(
    std::vector<const char *> validationLayers) {
  uint32_t layerCount;

  vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

  std::vector<VkLayerProperties> availableLayers(layerCount);
  vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

  for (const char *layerName : validationLayers) {
    bool layerFound = false;

    for (const auto &layerProperties : availableLayers) {
      if (strcmp(layerName, layerProperties.layerName) == 0) {
        layerFound = true;
        break;
      }
    }

    if (!layerFound) {
      char *error;

      std::sprintf(error, "validation %s requested, but not available!",
                   layerName);

      throw std::runtime_error(error);
    }
  }

  return true;
}

void TetrisTheFunWay::createInstance() {
  if (ENABLE_VALIDATION_LAYERS)
    checkValidationLayerSupport(validationLayers);

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

  if (ENABLE_VALIDATION_LAYERS) {
    createInfo.enabledLayerCount =
        static_cast<uint32_t>(validationLayers.size());
    createInfo.ppEnabledLayerNames = validationLayers.data();
  } else {
    createInfo.enabledLayerCount = 0;
  }

  VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);

  if (result != VK_SUCCESS)
    throw std::runtime_error("failed to create instance!");
}

void TetrisTheFunWay::initVulkan() { createInstance(); }

void TetrisTheFunWay::mainLoop() {
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
  }
}

void TetrisTheFunWay::cleanup() {
  vkDestroyInstance(instance, nullptr);

  glfwDestroyWindow(window);

  glfwTerminate();
}

int main() {
  TetrisTheFunWay app;

  try {
    app.run();
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
