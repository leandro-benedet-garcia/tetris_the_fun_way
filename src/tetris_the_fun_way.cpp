#include "./headers/tetris_the_fun_way.hpp"
#ifndef NDEBUG
#include "./validation_layering.hpp"
#endif
#include <cstdlib>
#include <iostream>
#include <stdexcept>

TetrisTheFunWay::TetrisTheFunWay() {
#ifndef NDEBUG
  validationLayering = new ValidationLayering(validationLayers);
#endif
}

inline void TetrisTheFunWay::run() {
  initWindow();
  initVulkan();
  mainLoop();
  cleanup();
}

inline void TetrisTheFunWay::initWindow() {
  glfwInit();

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  window = glfwCreateWindow(WIDTH, HEIGHT, WINDOW_NAME, nullptr, nullptr);
}

void TetrisTheFunWay::createInstance() {
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
#else
  createInfo.enabledLayerCount =
      static_cast<uint32_t>(validationLayering->currValidationLayers.size());
  createInfo.ppEnabledLayerNames = validationLayering->currValidationLayers.data();
#endif

  VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);

  if (result != VK_SUCCESS)
    throw std::runtime_error("failed to create instance!");
}

inline void TetrisTheFunWay::initVulkan() { createInstance(); }

inline void TetrisTheFunWay::mainLoop() {
  while (!glfwWindowShouldClose(window))
    glfwPollEvents();
}

inline void TetrisTheFunWay::cleanup() {
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
