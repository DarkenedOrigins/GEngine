#pragma once

#include <string>
#include <FreeImage.h>
#include <GL\glew.h>
#include "../utilities/imageLoad.h"

namespace GEngine {
	namespace graphics {
		class Texture {
		private:
			std::string filepath_;
			GLuint textureId_;
			unsigned int width_, height_;
		public:
			Texture( const std::string& filepath);
			~Texture();
			void bind() const;
			void unbind() const;
			inline const unsigned int getWidth() { return width_; }
			inline const unsigned int getHeight() { return height_; }
			inline const GLuint getId() { return textureId_; }

		private:
			GLuint load();

		};
	}
}
