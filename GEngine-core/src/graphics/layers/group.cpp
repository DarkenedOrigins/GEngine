#include "group.h"

GEngine::graphics::Group::~Group() {
	//delete all renderables submitted in a group
	for (auto& renderablePtr : renderables_) {
		delete renderablePtr;
	}
}

void GEngine::graphics::Group::submit(Renderer2D * renderer) const {
	renderer->push(transformationMatrix_);
	for (auto &renderable : renderables_) {
		renderable->submit(renderer);
	 }
	renderer->pop();
}
