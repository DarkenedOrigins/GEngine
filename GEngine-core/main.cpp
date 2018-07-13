//the reason timer is on top is cuz it includes windows .h and glfw redefines apientry so windows.h needs to be before glfw and other shit
#include "src\utilities\timer.h"
#include <cstdlib>
#include <iostream>
#include <time.h>
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
#include "src\graphics\renderer\staticSprite.h"
#include "src\graphics\renderer\batchRenderer2D.h"
#include "src\graphics\renderer\sprite.h"
#include "src\graphics\layers\tilelayer.h"
#include "src\graphics\layers\group.h"
#include "src\graphics\texture.h"

#define LARGE_TEST	(1)

int main() {
	using namespace GEngine;
	using namespace graphics;
	using namespace math;

	Window window("test", 960, 540);

	Matrix4 ortho = Matrix4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
	//must be on the heap since layer will delete
	Shader* shader = new Shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader->enable();
	shader->setUniform2f("light_pos", Vec2(4.0f, 1.5f));

	TileLayer layer(shader);

	#if LARGE_TEST
	for (float y = -9; y < 9; y += 1) {
		for (float x = -16; x < 16; x += 1) {
			layer.add(new Sprite(x, y, .9f, .9f, Vec4(rand() % 1000 / 1000.0f, rand() % 1000 / 1000.0f, 1, 1)));
		}
	}
	#endif

	glActiveTexture(GL_TEXTURE0);
	Texture texture("test.png");
	texture.bind();
	shader->enable();
	shader->setUniform1i("tex", 0);
	shader->setUniformMatrix4("pr_matrix", Matrix4::orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f));

	

	Timer time;
	float timer = 0;
	int frames = 0;
	while (!window.closed()) {

		window.clear();
		double x, y;
		window.mousePosition(x, y);
		shader->enable();
		shader->setUniform2f("light_pos", Vec2((float)(x*32.0f / (window.getWidth()) -16.0f), (float)(9.0f - y * 18.0f / (window.getHeight()))));
		layer.render();

		window.update();
		frames++;
		if (time.elasped() - timer > 1.0f) {
			timer += 1;
			printf("%d fps\n", frames);
			frames = 0; 
		}
	}
	return 0;
}