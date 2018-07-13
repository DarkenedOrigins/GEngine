#pragma once

#include "renderable2d.h"

namespace GEngine {
	namespace graphics {

		class StaticSprite : public Renderable2D {
		private:
			//these buffers will be on the heap destructor is needed
			Shader& shader_;
			VertexArray* vertexArray_;
			IndexBuffer* indexBuffer_;
		public:
			StaticSprite(float x, float y, float width, float height, const math::Vec4& color, Shader& shader);
			~StaticSprite() {
				delete vertexArray_;
				delete indexBuffer_;
			}
			inline const VertexArray* getVAO() const { return vertexArray_; }
			inline const IndexBuffer* getIBO() const { return indexBuffer_; }
			inline Shader& getShader() const { return shader_; }
		};
	}
}