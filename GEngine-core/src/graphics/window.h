#pragma once

#include <GLFW\glfw3.h>
#include <iostream>


namespace GEngine {
	namespace graphics {
		class Window {
		private:
			const char *title_;
			int width_, height_;
			bool closed_;
			GLFWwindow *window_;
		public:
			Window(const char *title, int width, int height);
			~Window();
			inline int getWidth() { return width_; }
			inline int getHeight() { return height_; }
			void update();
			void clear() const;
			bool closed() const;
		private:
			bool init();
		};
	}
}