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
			~Buffer() {
				glDeleteBuffers(1, &bufferId_);
			}

			void bind() const;
			void unbind() const;

			GLuint getComponentCount() const;


		};
	}
}
