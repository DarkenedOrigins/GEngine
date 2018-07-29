#pragma once

#include <vector>
#include <GL\glew.h>
#include "../../math/math.h"
#include "../font/font.h"

namespace GEngine {
	namespace graphics {

		class Renderable2D;

		class Renderer2D {
		protected:
			std::vector<math::Matrix4> transformationStack_;
			const math::Matrix4* transformationStackBack_;
		protected:
			Renderer2D() {
				transformationStack_.push_back(math::Matrix4::identity());
				transformationStackBack_ = &transformationStack_.back();
			}
		public:
			void push(math::Matrix4 matrix, bool override = false) {
				if (override) {
					transformationStack_.push_back(matrix);
				} else {
					transformationStack_.push_back(transformationStack_.back() * matrix);
				}
				transformationStackBack_ = &transformationStack_.back();
			}
			void pop() {
				if (transformationStack_.size() > 1) {
					transformationStack_.pop_back();
				}
				transformationStackBack_ = &transformationStack_.back();
				return;
				//todo: log failure
			}
			virtual void drawString(const std::string& text, const math::Vec3& position, const Font& font, const unsigned int& color){}
			virtual void begin(){}
			virtual void end(){}
			virtual void submit(const Renderable2D* renderable) = 0;
			virtual void flush() = 0;
		};
	}
}
