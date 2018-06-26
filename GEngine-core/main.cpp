#include <iostream>
//window.h is before glfw is b/c glew.h needs to be included before gl.h and gl.h is included in glfw
#include "src/graphics/window.h" 
#include <GLFW/glfw3.h>


#define USE_GLFW	(1)
int main() {
	using namespace GEngine;
	using namespace graphics;
	Window window("test", 800, 600);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
	int i = 0;
	while (!window.closed()) {
		window.clear();
		double x, y;
		window.mousePosition(x, y);
		std::cout << x << ", " << y << std::endl;
		#if USE_GLFW
		glBegin(GL_TRIANGLES);
		glVertex2f(-.5, -.5);
		glVertex2f(.5, .5);
		glVertex2f(.5, -.5);
		glEnd();
		#else
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
		#endif
		window.update();
	}
	return 0;
}