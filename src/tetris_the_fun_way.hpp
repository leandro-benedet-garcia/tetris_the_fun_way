#ifndef TETRIS_THE_FUN_WAY
#define TETRIS_THE_FUN_WAY

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <vector>

class TetrisTheFunWay {
public:
  void run();

private:
  GLFWwindow *window;

  VkInstance instance;

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
#endif

  const std::vector<const char *> validationLayers = {
      "VK_LAYER_KHRONOS_validation"};

  inline void initWindow();

  std::vector<const char *> getRequiredExtensions();

  bool checkValidationLayerSupport(std::vector<const char *> validationLayers);

  void createInstance();

  inline void initVulkan();

  inline void mainLoop();

  inline void cleanup();
};

int main();
#endif
