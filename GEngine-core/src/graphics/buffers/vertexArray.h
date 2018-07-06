#pragma once

#include <vector>
#include <GL\glew.h>

#include "buffer.h"

namespace GEngine {
	namespace graphics {

		class VertexArray {
		private:
			GLuint vertexArrayId_;
			std::vector<Buffer*> buffers_;	//this hold and OWN all the buffers which need to be sent to a shader
		public:
			VertexArray();
			//owns all buffers which need to be deleted
			~VertexArray();

			void addBuffer(Buffer* buffer, GLuint index);
			void bind() const;
			void unbind() const;


		};
	}
}
