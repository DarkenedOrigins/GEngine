#include "simpler2Drenderer.h"
#include "renderable2d.h"

void GEngine::graphics::Simple2DRenderer::submit(const Renderable2D* renderable) {
	renderQueue_.push_back((StaticSprite*)renderable);
}

void GEngine::graphics::Simple2DRenderer::flush() {
	// loops thru the queue and renders everything within it 
	while (!renderQueue_.empty()) {
		const StaticSprite* renderable = renderQueue_.front();
		renderable->getVAO()->bind();
		renderable->getIBO()->bind();
		renderable->getShader().setUniformMatrix4("ml_matrix", math::Matrix4::translation(renderable->getPosition()));
		glDrawElements(GL_TRIANGLES, renderable->getIBO()->getCount(), GL_UNSIGNED_SHORT, 0);
		renderable->getVAO()->unbind();
		renderable->getIBO()->unbind();
		renderQueue_.pop_front();
	}
	return;
}
