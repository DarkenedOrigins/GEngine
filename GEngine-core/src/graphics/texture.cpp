#include "texture.h"

GEngine::graphics::Texture::Texture(const std::string & filepath) : filepath_(filepath){
	textureId_ = load();
}

GEngine::graphics::Texture::~Texture() {}

void GEngine::graphics::Texture::bind() const {
	glBindTexture(GL_TEXTURE_2D, textureId_);
}

void GEngine::graphics::Texture::unbind() const {
	glBindTexture(GL_TEXTURE_2D, 0);
}

GLuint GEngine::graphics::Texture::load() {
	BYTE* pixels = load_image(filepath_.c_str(), &width_, &height_);
	GLuint result;
	glGenTextures(1, &result);
	glBindTexture(GL_TEXTURE_2D, result);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width_, height_, 0, GL_BGR, GL_UNSIGNED_BYTE, pixels);
	glBindTexture(GL_TEXTURE_2D, 0);
	delete[] pixels;
	return result;
}
