#include <iostream>
//window.h is before glfw is b/c glew.h needs to be included before gl.h and gl.h is included in glfw
#include "src/graphics/window.h" 
#include <GLFW/glfw3.h>
#include "src/math/math.h"


#define USE_GLFW	(1)
int main() {
	using namespace GEngine;
	using namespace graphics;
	using namespace math;

	Window window("test", 800, 600);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	Matrix4 mat = Matrix4::identity();
	Vec4& col = mat.columns[3];
	std::cout << mat << std::endl;
	std::cout << mat.columns[2] << std::endl;

	while (!window.closed()) {
		window.clear();
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