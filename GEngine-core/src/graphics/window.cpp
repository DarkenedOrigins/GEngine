#include "window.h"

namespace GEngine {
	namespace graphics {
		//public methods
		Window::Window(const char *title, int width, int height) {
			//initialize member var
			title_ = title;
			width_ = width;
			height_ = height;
			//initialize window
			if (init() == false)
				//if initialization failed terminate
				glfwTerminate();
		}

		Window::~Window(){
			glfwTerminate();
		}

		void Window::update() {
			glfwPollEvents();
			glfwGetFramebufferSize(window_, &width_, &height_);
			glViewport(0, 0, width_, height_);
			glfwSwapBuffers(window_);

		}

		void Window::clear() const {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			return;
		}

		bool Window::closed() const {
			return glfwWindowShouldClose(window_) == 1;
		}
		//private methods
		bool Window::init() {
			// init glfw
			if (!glfwInit()) {
				std::cout << "error glfw failed to initialize" << std::endl;
				return false;
			}else {
				std::cout << "glfw has initialized" << std::endl;
			}
			//create window in glfw
			window_ = glfwCreateWindow(width_, height_, title_, NULL, NULL);
			//check if window was created
			if (!window_) {
				// glfwCreateWindow ret null so kill glfw print error and ret
				std::cout << "glfw window failed to create" << std::endl;
				return false;
			}
			//successful create context
			glfwMakeContextCurrent(window_);
			return true;
		}


	}
}