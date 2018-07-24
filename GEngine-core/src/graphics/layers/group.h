#pragma once

#include "../renderer/renderable2d.h"

namespace GEngine {
	namespace graphics {

		class Group : public Renderable2D {
		private:
			std::vector<Renderable2D*> renderables_;
			math::Matrix4 transformationMatrix_;
		public:
			Group(const math::Matrix4& transform) { transformationMatrix_ = transform; }
			~Group();
			void add(Renderable2D* renderable) {
				renderables_.push_back(renderable);
			}
			void submit(Renderer2D* renderer) const override;
		};

	}
}
