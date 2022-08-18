#ifndef TETRIS_THE_FUN_WAY
#define TETRIS_THE_FUN_WAY

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vector>

#ifndef NDEBUG
#include "./validation_layering.hpp"
#endif

class TetrisTheFunWay {
public:
  TetrisTheFunWay();
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
  ValidationLayering *validationLayering;
  const std::vector<const char *> validationLayers = {
      "VK_LAYER_KHRONOS_validation"};
#endif

  inline void initWindow();

  void createInstance();

  inline void initVulkan();

  inline void mainLoop();

  inline void cleanup();
};

int main();
#endif
