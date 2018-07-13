#pragma once

#include <GL\glew.h>
#include "../buffers/buffer.h"
#include "../buffers/indexbuffer.h"
#include "../buffers/vertexArray.h"
#include "..\..\math\math.h"
#include "../shader.h"
#include "renderer2D.h"

namespace GEngine {
	namespace graphics {

		struct VertexData {
			math::Vec3 vertex;
			math::Vec2 texCoord;
			unsigned int color;
		};

		class Renderable2D {
		protected:
			math::Vec2 size_;
			math::Vec3 position_;
			math::Vec4 color_;
			std::vector<math::Vec2> texCoords_;

		protected:
			Renderable2D() { setTexCoordDefaults(); }	//empty constructor so group does not need to take in size position and color

		public:
			Renderable2D(math::Vec3 position, math::Vec2 size, math::Vec4 color) : position_(position), size_(size), color_(color) { setTexCoordDefaults(); }

			~Renderable2D() {}

			virtual void submit(Renderer2D* renderer) const {
				renderer->submit(this);
			}

			//initial const means the retval is const and the second const means the function is const
			inline const math::Vec2& getSize() const { return size_; }
			inline const math::Vec3& getPosition() const { return position_; }
			inline const math::Vec4& getColor() const { return color_; }
			inline const std::vector<math::Vec2>& getTexCoord() const { return texCoords_; }

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
