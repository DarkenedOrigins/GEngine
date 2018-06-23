#include <iostream>
#include <GLFW/glfw3.h>

#include "src/graphics/window.h"


int main(){
	using namespace GEngine;
	using namespace graphics;
	Window window("test", 800, 600);
	glClearColor(0.2, .3, .8, 1);
	while (!window.closed()) {
		//std::cout << window.getHeight() << ":" << window.getWidth() << std::endl;
		window.clear();
		glBegin(GL_TRIANGLES);
		glVertex2f(-.5, -.5);
		glVertex2f(.5, .5);
		glVertex2f(.5, -.5);
		glEnd();
		window.update();
	}
	return 0;
}