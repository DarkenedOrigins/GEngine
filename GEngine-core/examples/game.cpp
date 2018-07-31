
#include "../src/GEngine.h"

using namespace GEngine;
using namespace graphics;


class Game : public GEngine {
public:
	Layer* layer;
	Label* fps;
	Sprite* sprite;
	Shader* shader;

public:
	Game() : GEngine() {

	}

	~Game() {
		delete layer;
		//shader and sprite and label are all handeled by layer
	}

	void init() override {
		createWindow("example game", 960, 540);
		FontManager::getDefault()->setScale(window_->getWidth() / 32.0f, window_->getHeight() / 18.0f);
		shader = new Shader("src/shaders/basic.vert", "src/shaders/basic.frag");
		layer = new Layer(new BatchRenderer2D(), shader, math::Matrix4::orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f));
		sprite = new Sprite(0.0f, 0.0f, 4, 4, new Texture("test.png"));
		layer->add(sprite);

		fps = new Label("", -15.5f, 7.8f, FontManager::getDefault(), 0xffffffff);
		layer->add(fps);

	}

	void tick() override {
		fps->setText( std::to_string(getFPS()) + " fps" );
		std::cout << getUPS() << " ups, " << getFPS() << " fps" << std::endl;
	}

	void update() override {
		float speed = 0.5f;
		if (window_->isKeyPressed(GLFW_KEY_UP))
			sprite->changePosition().y += speed;
		else if (window_->isKeyPressed(GLFW_KEY_DOWN))
			sprite->changePosition().y -= speed;
		if (window_->isKeyPressed(GLFW_KEY_LEFT))
			sprite->changePosition().x -= speed;
		else if (window_->isKeyPressed(GLFW_KEY_RIGHT))
			sprite->changePosition().x += speed;

		double x, y;
		window_->mousePosition(x, y);
		shader->setUniform2f("light_pos", math::Vec2((float)(x * 32.0f / window_->getWidth() - 16.0f), (float)(9.0f - y * 18.0f / window_->getHeight())));
	}

	void render() override {
		layer->render();
	}

};

int main() {
	Game game;
	game.start();
	return 0;
}