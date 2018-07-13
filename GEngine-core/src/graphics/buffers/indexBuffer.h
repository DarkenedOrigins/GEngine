#pragma once

#include <GL\glew.h>

namespace GEngine {
	namespace graphics {

		class IndexBuffer {

		private:
			GLuint bufferId_;
			GLuint count_;
		public:
			IndexBuffer(GLushort * data, GLsizei count);
			~IndexBuffer();
			void bind() const;
			void unbind() const;

			inline GLuint getCount() const { return count_; };


		};
	}
}
