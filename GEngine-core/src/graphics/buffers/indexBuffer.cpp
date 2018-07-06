#include "indexBuffer.h"

namespace GEngine {
	namespace graphics {
		IndexBuffer::IndexBuffer(GLushort* data, GLsizei count) {
			this->count_ = count;
			// get a buffer id
			glGenBuffers(1, &(this->bufferId_));
			//bind buffer
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->bufferId_);
			//send data in buffer
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLushort), data, GL_STATIC_DRAW);
			//unbind buffer so user can choose to bind or unbind
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}
		void IndexBuffer::bind() const {
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->bufferId_);
		}
		void IndexBuffer::unbind() const {
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}
	}
}