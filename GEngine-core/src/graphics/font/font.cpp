#include "font.h"

GEngine::graphics::Font::Font(std::string name, std::string filePath, unsigned int size) : name_(name), filePath_(filePath), size_(size_) {
	scale_ = math::Vec2(960.0f / 32.0f, 540.0f / 18.0f);
	ftAtlas_ = ftgl::texture_atlas_new(512, 512, 2);
	ftFont_ = ftgl::texture_font_new_from_file(ftAtlas_, (float)size, filePath.c_str());
}

void GEngine::graphics::Font::setScale(float x, float y) {
	scale_ = math::Vec2(x, y);
}

void GEngine::graphics::Font::setScale(const math::Vec2 & scale) {
	scale_ = scale;
}
