#pragma once

#include "renderable2d.h"
#include "../../../fontManager.h"

namespace GEngine {
	namespace graphics {
		class Label : public Renderable2D {
		private:
			std::string text_;
			Font* font_;
		public:
			Label(const std::string& text, float x, float y, Font* font, const math::Vec4& color);
			Label(const std::string& text, float x, float y, Font* font, const unsigned int color);
			void submit(Renderer2D* renderer) const override;
			inline void setText(const std::string& text) { text_ = text; }
		};
	}
}
