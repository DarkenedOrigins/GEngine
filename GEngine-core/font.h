#pragma once

#include <string>
#include "ext\freetype-gl\freetype-gl.h"


namespace GEngine {
	namespace graphics {

		class Font {
		private:
			ftgl::texture_atlas_t* ftAtlas_;
			ftgl::texture_font_t* ftFont_;
			unsigned int size_;

			std::string name_;
			std::string filePath_;

		public:
			Font(std::string name, std::string filePath, unsigned int size);

			inline ftgl::texture_font_t* getFTFont() const { return ftFont_; }

			inline const unsigned int getID() const { return ftAtlas_->id; }
			inline const std::string& getName() const { return name_; }
			inline const std::string& getFilePath() const { return filePath_; }
			inline const unsigned int getSize() const { return size_; }
		};
	}
}
