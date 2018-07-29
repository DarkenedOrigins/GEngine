#pragma once


#include <vector>
#include "font.h"

namespace GEngine {
	namespace graphics {
		class FontManager {
		private:
			static std::vector<Font*> fonts_;
		public:
			static void add(Font* font);
			static Font* get(const std::string& name);
			static Font* get(const std::string& name, const unsigned int& size);
			static Font* getDefault();
			static void clean();
		private:
			FontManager();
		};
	}
}
