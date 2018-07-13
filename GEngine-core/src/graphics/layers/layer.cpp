#include "layer.h"

GEngine::graphics::Layer::Layer(Renderer2D * renderer, Shader * shader, math::Matrix4 projectionMatrix) : renderer_(renderer), shader_(shader), projectionMatrix_(projectionMatrix){
	shader_->enable();
	shader_->setUniformMatrix4("pr_matrix", projectionMatrix_);
	shader_->disable();
}


GEngine::graphics::Layer::~Layer() {
	delete shader_;
	delete renderer_;
	for (auto &r : renderables_) {
		delete r;
	}
}

void GEngine::graphics::Layer::add(Renderable2D * renderable) {
	renderables_.push_back(renderable);
}

void GEngine::graphics::Layer::render() {
	//shader_->disable();
	shader_->enable();
	renderer_->begin();
	for (auto &renderable : renderables_) {
		renderable->submit(renderer_);
	}
	renderer_->end();
	renderer_->flush();
}
