#include "vertexArray.h"

namespace GEngine {
	namespace graphics {
		VertexArray::VertexArray() {
			glGenVertexArrays(1, &vertexArrayId_);

		}
		VertexArray::~VertexArray() {
			// since vertex array owns the buffers passed to it 
			// it must be the one to delete them
			for (auto &buf : buffers_) {
				delete buf;
			}
		}

		void VertexArray::addBuffer(Buffer * buffer, GLuint index) {
			this->bind();
			buffer->bind();

			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index, buffer->getComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);
			
			buffer->unbind();
			this->unbind();
			buffers_.push_back(buffer);
		}

		void VertexArray::bind() const {
			glBindVertexArray(vertexArrayId_);
		}

		void VertexArray::unbind() const {
			glBindVertexArray(0);
		}

	}
}