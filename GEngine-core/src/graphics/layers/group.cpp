#include "group.h"

void GEngine::graphics::Group::submit(Renderer2D * renderer) const {
	renderer->push(transformationMatrix_);
	for (auto &renderable : renderables_) {
		renderable->submit(renderer);
	 }
	renderer->pop();
}
