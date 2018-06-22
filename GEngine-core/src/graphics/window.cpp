#include "window.h"

namespace GEngine {
	namespace graphics {

		Window::Window(const char *name, int width, int height) {
			name_ = name;
			width_ = width;
			height_ = height;
		}
	}
}