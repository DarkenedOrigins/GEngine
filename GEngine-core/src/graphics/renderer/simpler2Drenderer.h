#pragma once

#include <deque>
#include "renderer2D.h"

namespace GEngine {
	namespace graphics {

		class Simple2DRenderer : public Renderer2D{
		private:
			std::deque<const Renderable2D*> renderQueue_;

		public:
			void submit(const Renderable2D* renderable) override;
			void flush() override;
		};
	}
}
