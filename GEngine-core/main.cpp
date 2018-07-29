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
#include "src\graphics\renderer\label.h"
#include "src/graphics/font/fontManager.h"
#include <SFML/Audio.hpp>


int main() {
	using namespace GEngine;
	using namespace graphics;
	using namespace math;

	sf::Music music;
	if (!music.openFromFile("test.wav"))
		return -1; // error
	music.play();


	Window window("test", 960, 540);
	//glClearColor(0, 1, 1, 1);

	Matrix4 ortho = Matrix4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
	//must be on the heap since layer will delete
	Shader* shader = new Shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader->enable();
	shader->setUniform2f("light_pos", Vec2(4.0f, 1.5f));

	TileLayer layer(shader);
	Texture texture("test.png");



	for (float y = -9; y < 9; y += 1) {
		for (float x = -16; x < 16; x += 1) {
			//layer.add(new Sprite(x, y, .9f, .9f, Vec4(rand() % 1000 / 1000.0f, rand() % 1000 / 1000.0f, 1, 1)));
			layer.add(new Sprite(x, y, .9f, .9f, &texture));
		}
	}

	Group* g = new Group(math::Matrix4::translation(math::Vec3(-15.8f, 7.0f, 0.0f)));
	Label* fps = new Label("", 0.4f, 0.4f, FontManager::getDefault(), math::Vec4(0, .2f, 1, 1));
	g->add(new Sprite(0, 0, 4, 1.5f, math::Vec4(0.3f, 0.3f, 0.3f, 0.9f)));
	g->add(fps);

	layer.add(g);



	GLint texIds[] = { 0,1,2,3,4,5,6,7,8,9 };
	shader->enable();
	shader->setUniform1iv("textures", texIds, 10);
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
		if (time.elapsed() - timer > 1.0f) {
			timer += 1;
			fps->setText(std::to_string(frames) + " fps");
			printf("%d fps\n", frames);
			frames = 0; 
		}

	}
	return 0;
}
	