#pragma once

#include <GL\glew.h>
#include "../buffers/buffer.h"
#include "../buffers/indexbuffer.h"
#include "../buffers/vertexArray.h"
#include "..\..\math\math.h"
#include "../shader.h"
#include "renderer2D.h"
#include "../texture.h"

namespace GEngine {
	namespace graphics {

		struct VertexData {
			math::Vec3 vertex;
			math::Vec2 texCoord;
			float texId;
			unsigned int color;
		};

		class Renderable2D {
		protected:
			math::Vec2 size_;
			math::Vec3 position_;
			unsigned int color_;
			std::vector<math::Vec2> texCoords_;
			Texture* texture_;

		protected:
			Renderable2D() { texture_ = nullptr; setTexCoordDefaults(); }	//empty constructor so group does not need to take in size position and color

		public:
			Renderable2D(const math::Vec3& position, const math::Vec2& size, const unsigned int& color) : position_(position), size_(size), color_(color), texture_(nullptr) { setTexCoordDefaults(); }
			Renderable2D(const math::Vec3& position, const math::Vec2& size, const math::Vec4& color) : position_(position), size_(size), texture_(nullptr) { 
				color_ = 0;
				int r = color.x*255.0f;
				int g = color.y*255.0f;
				int b = color.z*255.0f;
				int a = color.w*255.0f;
				color_ = a << 24 | b << 16 | g << 8 | r;
				setTexCoordDefaults(); 
			}

			~Renderable2D() {}

			virtual void submit(Renderer2D* renderer) const {
				renderer->submit(this);
			}

			//initial const means the retval is const and the second const means the function is const
			inline const math::Vec2& getSize() const { return size_; }
			inline const math::Vec3& getPosition() const { return position_; }
			inline const unsigned int& getColor() const { return color_; }
			inline const std::vector<math::Vec2>& getTexCoord() const { return texCoords_; }
			inline const GLuint getTId() const{ return texture_ == nullptr ? 0 : texture_->getId(); }

			inline void setColor(unsigned int color) { color_ = color; }
			inline void setColor(const math::Vec4& color) {
				color_ = 0;
				int r = color.x*255.0f;
				int g = color.y*255.0f;
				int b = color.z*255.0f;
				int a = color.w*255.0f;
				color_ = a << 24 | b << 16 | g << 8 | r;
			}

		private:
			void setTexCoordDefaults() {
				texCoords_.push_back(math::Vec2(0, 0));
				texCoords_.push_back(math::Vec2(0, 1));
				texCoords_.push_back(math::Vec2(1, 1));
				texCoords_.push_back(math::Vec2(1, 0));
			}
		};
	}
}
