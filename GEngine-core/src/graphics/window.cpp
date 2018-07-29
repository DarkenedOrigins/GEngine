#include "window.h"

namespace GEngine {
	namespace graphics {
		//friends (callback functions)
		void window_resize_callback(GLFWwindow *window, int width, int height) {
			Window *usrWinPtr = (Window*)glfwGetWindowUserPointer(window);
			usrWinPtr->width_ = width;
			usrWinPtr->height_ = height;
			glViewport(0, 0, width, height);
		}
		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
			if (key < 0) {
				return;
			}
			Window *userWinPtr = (Window*)glfwGetWindowUserPointer(window);
			userWinPtr->keys_[key] = action != GLFW_RELEASE;
		}
		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
			if (button < 0) {
				return;
			}
			Window *userWinPtr = (Window*)glfwGetWindowUserPointer(window);
			userWinPtr->mouseButtons_[button] = action != GLFW_RELEASE;
		}
		void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
			Window *userWinPtr = (Window*)glfwGetWindowUserPointer(window);
			userWinPtr->mouseX_ = xpos;
			userWinPtr->mouseY_ = ypos;
		}

		//public methods
		Window::Window(const char *title, int width, int height) {
			//initialize member var
			title_ = title;
			width_ = width;
			height_ = height;
			// this inits both key and button (hash)arrays to false
			for (int i = 0; i < MAX_KEYS; i++) {
				if (i < MAX_BUTTONS) {
					mouseButtons_[i] = false;
				}
				keys_[i] = false;
			}
			//initialize window
			if (init() == false)
				//if initialization failed terminate
				glfwTerminate();
		}

		Window::~Window(){
			glfwTerminate();
		}

		void Window::update() {
			GLenum error = glGetError();
			if (error != GL_NO_ERROR) {
				std::cout << "OpenGL error: " << error << std::endl;
			}
			glfwPollEvents();
			//glfwGetFramebufferSize(window_, &width_, &height_);
			glfwSwapBuffers(window_);
		}

		void Window::clear() const {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			return;
		}

		bool Window::closed() const {
			return glfwWindowShouldClose(window_) == 1;
		}
		bool Window::isKeyPressed(unsigned int keycode) const{
			// todo: log failed keycode
			if (keycode >= MAX_KEYS) {
				return false;
			}
			return keys_[keycode];
		}
		bool Window::isMouseButtonPressed(unsigned int buttonCode) const{
			// todo: log failed mouse button keycode
			if (buttonCode >= MAX_BUTTONS) {
				return false;
			}
			return mouseButtons_[buttonCode];
		}
		void Window::mousePosition(double& x, double& y) const{
			x = mouseX_;
			y = mouseY_;
		}

		//private methods
		bool Window::init() {
			// init glfw
			if (!glfwInit()) {
				std::cout << "error glfw failed to initialize" << std::endl;
				return false;
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
			glfwSetWindowUserPointer(window_, this);
			glfwSetFramebufferSizeCallback(window_, window_resize_callback);
			glfwSetKeyCallback(window_, key_callback);
			glfwSetMouseButtonCallback(window_, mouse_button_callback);
			glfwSetCursorPosCallback(window_, cursor_position_callback);
			glfwSwapInterval(0);

			if (glewInit() != GLEW_OK) {
				std::cout << "glew failed to init" << std::endl;
				return false;
			}
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;

			return true;
		}


	}
}