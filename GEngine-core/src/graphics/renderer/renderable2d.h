#pragma once

#include <GL\glew.h>
#include "../buffers/buffer.h"
#include "../buffers/indexbuffer.h"
#include "../buffers/vertexArray.h"
#include "..\..\math\math.h"
#include "../shader.h"

namespace GEngine {
	namespace graphics {
		class Renderable2D {
		protected:
			math::Vec2 size_;
			math::Vec3 position_;
			math::Vec4 color_;

			//these buffers will be on the heap destructor is needed
			Shader& shader_;
			VertexArray* vertexArray_;
			IndexBuffer* indexBuffer_;
		public:
			Renderable2D(math::Vec3 position, math::Vec2 size, math::Vec4 color, Shader& shader) : position_(position), size_(size), color_(color), shader_(shader){
				vertexArray_ = new VertexArray();
				GLfloat vertices[] = {
					0, 0, 0,
					0, size.y, 0,
					size.x, size.y, 0,
					size.x, 0, 0
				};
				GLfloat colors[] = {
					color.x, color.y, color.z, color.w,
					color.x, color.y, color.z, color.w,
					color.x, color.y, color.z, color.w,
					color.x, color.y, color.z, color.w
				};
				vertexArray_->addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
				vertexArray_->addBuffer(new Buffer(colors, 4 * 4, 4), 1);
				//default indicies until new ones provided
				GLushort indicies[] = { 0,1,2,2,3,0 };
				indexBuffer_ = new IndexBuffer(indicies, 6);
			}
			~Renderable2D() {
				delete vertexArray_;
				delete indexBuffer_;
			}

			//initial const means the retval is const and the second const means the function is const
			inline const VertexArray* getVAO() const { return vertexArray_; }
			inline const IndexBuffer* getIBO() const { return indexBuffer_; }
			inline Shader& getShader() const { return shader_; }
			inline const math::Vec2& getSize() const { return size_; }
			inline const math::Vec3& getPosition() const { return position_; }
			inline const math::Vec4& getColor() const { return color_; }
		};
	}
}
