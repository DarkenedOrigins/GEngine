#include "fontManager.h"
#include <iostream>

namespace GEngine {
	namespace graphics {
		std::vector<Font*> FontManager::fonts_;


		void FontManager::add(Font * font) {
			if (fonts_.empty()) {
				fonts_.push_back(new Font("Eczar-Regular", "Eczar-Regular.ttf", 32));
				fonts_.push_back(font);
			} else {
				fonts_.push_back(font);
			}
		}

		Font * FontManager::get(const std::string & name) {
			for (auto& font : fonts_) {
				if (font->getName() == name) {
					return font;
				}
			}
			if (fonts_.empty()) {
				add(new Font("Eczar-Regular", "Eczar-Regular.ttf", 32));
				std::cout << "font manager is empty default returned" << std::endl;
				return fonts_[0];
			} else {
				std::cout << "font by the name of: " << name << "not found default returned" << std::endl;
				return fonts_[0];
			}
		}

		Font * FontManager::get(const std::string & name, const unsigned int & size) {
			for (auto& font : fonts_) {
				if (font->getName() == name && font->getSize() == size) {
					return font;
				}
			}
			if (fonts_.empty()) {
				add(new Font("Eczar-Regular", "Eczar-Regular.ttf", 32));
				std::cout << "font manager is empty default returned" << std::endl;
				return fonts_[0];
			} else {
				std::cout << "font by the name of: " << name << "not found default returned" << std::endl;
				return fonts_[0];
			}
		}

		Font * FontManager::getDefault() {
			if (fonts_.empty()) {
				add(new Font("Eczar-Regular", "Eczar-Regular.ttf", 32));
			}
			return fonts_[0];
		}

		void FontManager::clean() {
			for (auto& font : fonts_) {
				delete font;
			}
		}

	}
}