#include "buffer.h"

namespace GEngine {
	namespace graphics {

		Buffer::Buffer(GLfloat* data, GLsizei count, GLuint componentCount) {
			this->componentCount_ = componentCount;
			// get a buffer id
			glGenBuffers(1, &(this->bufferId_));
			//bind buffer
			glBindBuffer(GL_ARRAY_BUFFER, this->bufferId_);
			//send data in buffer
			glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
			//unbind buffer so user can choose to bind or unbind
			glBindBuffer(GL_ARRAY_BUFFER, 0);

		}

		void Buffer::bind() const {
			glBindBuffer(GL_ARRAY_BUFFER, this->bufferId_);
		}

		void Buffer::unbind() const {
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

		GLuint Buffer::getComponentCount() const {
			return this->componentCount_;
		}

	}
}