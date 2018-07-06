#include <iostream>
//window.h is before glfw is b/c glew.h needs to be included before gl.h and gl.h is included in glfw
#include "src/graphics/window.h" 
#include <GLFW/glfw3.h>
#include "src\graphics\shader.h"
#include "src/math/math.h"
#include "src\graphics\buffers\buffer.h"
#include "src\graphics\buffers\indexBuffer.h"
#include "src\graphics\buffers\vertexArray.h"
#include "src\graphics\renderer\renderable2d.h"
#include "src\graphics\renderer\simpler2Drenderer.h"



int main() {
	using namespace GEngine;
	using namespace graphics;
	using namespace math;

	Window window("test", 960, 540);
	//glClearColor(1,1,1,1);

	Matrix4 ortho = Matrix4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();
	shader.setUniformMatrix4("pr_matrix", ortho);
	shader.setUniformMatrix4("ml_matrix", Matrix4::translation(Vec3(4.0f, 3.0f, 0.0f)));
	shader.setUniform2f("light_pos", Vec2(4.0f, 1.5f));
	shader.setUniform4f("colour", Vec4(0.2f, 0.3f, 0.8f, 1.0f));

	Renderable2D sprite(Vec3(5, 5, 0), Vec2(4, 4), Vec4(1, 0, 1, 1), shader);
	Renderable2D sprite2(Vec3(7, 1, 0), Vec2(2, 3), Vec4(0.2f, 0, 1, 1), shader);
	Simple2DRenderer renderer;

	while (!window.closed()) {
		window.clear();
		double x, y;
		window.mousePosition(x, y);
		shader.setUniform2f("light_pos", Vec2((float)(x*16.0f / (window.getWidth())), (float)(9.0f - y * 9.0f / (window.getHeight()))));
		renderer.submit(&sprite);
		renderer.submit(&sprite2);
		renderer.flush();
		window.update();
	}
	return 0;
}