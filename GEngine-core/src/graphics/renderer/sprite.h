#pragma once

#include "renderable2d.h"

namespace GEngine {
	namespace graphics {

		class Sprite : public Renderable2D {
		public:
			Sprite(float x, float y, float width, float height, const math::Vec4& color);
		};
	}
}