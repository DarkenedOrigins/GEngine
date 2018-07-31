#pragma once

#include <iostream>
#include <GL\glew.h>
#include <GLFW\glfw3.h>

#define MAX_KEYS	(1024)
#define	MAX_BUTTONS	(32)
namespace GEngine {
	namespace graphics {
		class Window {
		private:
			const char *title_;
			int width_, height_;
			bool closed_;
			GLFWwindow *window_;
			bool keys_[MAX_KEYS];
			bool mouseButtons_[MAX_BUTTONS];
			double mouseX_, mouseY_;
		public:
			Window(const char *title, int width, int height);
			~Window();
			inline int getWidth() { return width_; }
			inline int getHeight() { return height_; }
			void update();
			void clear() const;
			bool closed() const;
			bool isKeyPressed(unsigned int keycode)const;
			bool isMouseButtonPressed(unsigned int buttonCode)const;
			void mousePosition(double& x, double& y) const;
		private:
			bool init();
			friend void window_resize_callback(GLFWwindow *window, int width, int height);
			friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
			friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
			friend void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
		};
	}
}