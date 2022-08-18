#include "./headers/validation_layering.hpp"

#include <cstdio>
#include <cstring>
#include <stdexcept>

ValidationLayering::ValidationLayering(std::vector<const char *> validationLayers){
  currValidationLayers = validationLayers;
}

std::vector<const char *> ValidationLayering::getRequiredExtensions() {
  uint32_t glfwExtensionCount = 0;
  const char **glfwExtensions;
  glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

  std::vector<const char *> extensions(glfwExtensions,
                                       glfwExtensions + glfwExtensionCount);

  for (const char *currLayer : currValidationLayers) {
    extensions.push_back(currLayer);
  }

  return extensions;
}

bool ValidationLayering::checkValidationLayerSupport() {
  uint32_t layerCount;

  vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

  std::vector<VkLayerProperties> availableLayers(layerCount);
  vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

  for (const char *layerName : currValidationLayers) {
    bool layerFound = false;

    for (const auto &layerProperties : availableLayers) {
      if (strcmp(layerName, layerProperties.layerName) == 0) {
        layerFound = true;
        break;
      }
    }

    if (!layerFound) {
      char *error;

      std::sprintf(error, "Validation Layer %s requested, but not available!",
                   layerName);

      throw std::runtime_error(error);
    }
  }

  return true;
}
