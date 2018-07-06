#pragma once

#include <GL\glew.h>

namespace GEngine {
	namespace graphics {

		class Buffer {

		private:
			GLuint bufferId_;
			GLuint componentCount_;
		public:
			Buffer(GLfloat* data, GLsizei count, GLuint componentCount);

			void bind() const;
			void unbind() const;

			GLuint getComponentCount() const;


		};
	}
}
