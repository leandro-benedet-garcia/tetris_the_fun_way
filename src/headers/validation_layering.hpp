#ifndef VALIDATION_LAYERING
#define VALIDATION_LAYERING

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vector>

class ValidationLayering {
public:
  std::vector<const char *> currValidationLayers;

  ValidationLayering(std::vector<const char *> validationLayers);

  std::vector<const char *> getRequiredExtensions();

  bool checkValidationLayerSupport();
};
#endif
