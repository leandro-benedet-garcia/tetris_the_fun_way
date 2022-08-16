CFLAGS = -std=c++20 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi
BUILD_DIR = build
SOURCE_DIR = src

$(BUILD_DIR)/VulkanTest: $(SOURCE_DIR)/main.cpp
	mkdir $(BUILD_DIR)
	clang++ $(CFLAGS) -o $(BUILD_DIR)/VulkanTest $(SOURCE_DIR)/main.cpp $(LDFLAGS)

.PHONY: test clean

test: $(BUILD_DIR)/VulkanTest
	$(BUILD_DIR)/VulkanTest

clean:
	rm -r $(BUILD_DIR)
