#include "label.h"

GEngine::graphics::Label::Label(const std::string& text, float x, float y, Font* font, const math::Vec4& color) : Renderable2D(), text_(text), font_(font) {
	position_ = math::Vec3(x, y, 0.0f);
	color_ = 0;
	int r = color.x*255.0f;
	int g = color.y*255.0f;
	int b = color.z*255.0f;
	int a = color.w*255.0f;
	color_ = a << 24 | b << 16 | g << 8 | r;
}

GEngine::graphics::Label::Label(const std::string & text, float x, float y, Font* font, const unsigned int color) : Renderable2D(), text_(text), font_(font) {
	position_ = math::Vec3(x, y, 0);
	color_ = color;
}

void GEngine::graphics::Label::submit(Renderer2D * renderer) const {
	renderer->drawString(text_, position_, *font_, color_);
}
