#pragma once

#include <string>
#include "../../../ext/freetype-gl/freetype-gl.h"
#include "../../math/math.h"


namespace GEngine {
	namespace graphics {

		class Font {
		private:
			ftgl::texture_atlas_t* ftAtlas_;
			ftgl::texture_font_t* ftFont_;
			unsigned int size_;

			math::Vec2 scale_;
			std::string name_;
			std::string filePath_;

		public:
			Font(std::string name, std::string filePath, unsigned int size);

			void setScale(float x, float y);
			void setScale(const math::Vec2& scale);

			inline ftgl::texture_font_t* getFTFont() const { return ftFont_; }

			inline const unsigned int getID() const { return ftAtlas_->id; }
			inline const math::Vec2& getScale() const{ return scale_; }
			inline const std::string& getName() const { return name_; }
			inline const std::string& getFilePath() const { return filePath_; }
			inline const unsigned int getSize() const { return size_; }
		};
	}
}
