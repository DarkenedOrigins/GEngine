#pragma once

#include "renderable2d.h"

namespace GEngine {
	namespace graphics {
		class Label : public Renderable2D {
		private:
			std::string text_;
			unsigned int fontSize_;
		public:
			Label(const std::string& text, float x, float y, const math::Vec4& color, unsigned int fontSize = 28);
			Label(const std::string& text, float x, float y, const unsigned int& color, unsigned int fontSize = 28);
			void submit(Renderer2D* renderer) const override;
			inline void setText(const std::string& text) { text_ = text; }
		};
	}
}
