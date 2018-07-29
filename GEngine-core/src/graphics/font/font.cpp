#include "font.h"

GEngine::graphics::Font::Font(std::string name, std::string filePath, unsigned int size) : name_(name), filePath_(filePath), size_(size_) {
	ftAtlas_ = ftgl::texture_atlas_new(512, 512, 2);
	ftFont_ = ftgl::texture_font_new_from_file(ftAtlas_, (float)size, filePath.c_str());
}
