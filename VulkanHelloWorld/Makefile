INCLUDE_DIR := -I /usr/local/include

LIBS_DIR := -L/usr/local/lib -L/Users/jie_shen/VulkanSDK/1.3.204.1/macOS/lib

LIBS := glfw.3.3 vulkan.1.3.204 vulkan.1

CPPFLAGS := ${INCLUDE_DIR} ${LIBS_DIR} $(foreach lib, ${LIBS}, -l${lib})

CXXFLAGS := -std=c++20

main: main.cpp

clean:
	@echo run clean
	rm -rf main