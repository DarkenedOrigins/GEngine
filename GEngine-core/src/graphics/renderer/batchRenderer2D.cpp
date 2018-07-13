#include "batchRenderer2D.h"

namespace GEngine {
	namespace graphics {
		BatchRenderer2D::BatchRenderer2D() {
			init();
		}
		BatchRenderer2D::~BatchRenderer2D() {
			delete ibo_;
			glDeleteBuffers(1, &vbo_);
		}
		void BatchRenderer2D::begin() {
			glBindBuffer(GL_ARRAY_BUFFER, vbo_);
			buffer_ = (VertexData*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
		}
		void BatchRenderer2D::end() {
			glUnmapBuffer(GL_ARRAY_BUFFER);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
		void BatchRenderer2D::submit(const Renderable2D * renderable) {
			const math::Vec3& position = renderable->getPosition();
			const math::Vec2& size = renderable->getSize();
			const math::Vec4 color = renderable->getColor();
			const std::vector<math::Vec2> texCoords = renderable->getTexCoord();

			int r = color.x*255.0f;
			int g = color.y*255.0f;
			int b = color.z*255.0f;
			int a = color.w*255.0f;
			unsigned int c = a << 24 | b << 16 | g << 8 | r;

			//we are doing this 4 times cuz 4 vetex in a square

			buffer_->vertex = *transformationStackBack_ * position;
			buffer_->texCoord = texCoords[0];
			buffer_->color = c;
			buffer_++;

			buffer_->vertex = *transformationStackBack_ * math::Vec3(position.x, position.y + size.y, position.z);
			buffer_->texCoord = texCoords[1];
			buffer_->color = c;
			buffer_++;

			buffer_->vertex = *transformationStackBack_ * math::Vec3(position.x + size.x, position.y + size.y, position.z);
			buffer_->texCoord = texCoords[2];
			buffer_->color = c;
			buffer_++;

			buffer_->vertex = *transformationStackBack_ * math::Vec3(position.x + size.x, position.y, position.z);
			buffer_->texCoord = texCoords[3];
			buffer_->color = c;
			buffer_++;
			indexCount_ += 6;
		}
		void BatchRenderer2D::flush() {
			glBindVertexArray(vao_);
			ibo_->bind();
			glDrawElements(GL_TRIANGLES, indexCount_, GL_UNSIGNED_SHORT, NULL);
			ibo_->unbind();
			glBindVertexArray(0);
			indexCount_ = 0;
		}



		//private funcs
		void BatchRenderer2D::init() {
			glGenVertexArrays(1, &vao_);
			glGenBuffers(1, &vbo_);
			glBindVertexArray(vao_);
			glBindBuffer(GL_ARRAY_BUFFER, vbo_);
			glBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);

			glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
			glEnableVertexAttribArray(SHADER_TEX_COORD_INDEX);
			glEnableVertexAttribArray(SHDER_COLOR_INDEX);

			glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const GLvoid*)0);
			glVertexAttribPointer(SHADER_TEX_COORD_INDEX, 2, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const GLvoid*) offsetof(VertexData, VertexData::texCoord));
			glVertexAttribPointer(SHDER_COLOR_INDEX, 4, GL_UNSIGNED_BYTE, GL_TRUE, RENDERER_VERTEX_SIZE, (const GLvoid*) offsetof(VertexData, VertexData::color));
			glBindBuffer(GL_ARRAY_BUFFER, 0);

			int offset = 0;
			GLushort indices[RENDERER_INDICES_SIZE];
			for (int i = 0; i < RENDERER_INDICES_SIZE; i += 6) {
				indices[i] = offset + 0;
				indices[i+1] = offset + 1;
				indices[i+2] = offset + 2;
				indices[i+3] = offset + 2;
				indices[i+4] = offset + 3;
				indices[i+5] = offset + 0;
				offset += 4;
			}

			ibo_ = new IndexBuffer(indices, RENDERER_INDICES_SIZE);
			glBindVertexArray(0);
		}
	}
}