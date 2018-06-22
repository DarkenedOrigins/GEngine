#pragma once

namespace GEngine {
	namespace graphics {
		class Window {
		private:
			const char *name_;
			int width_, height_;
		public:
			Window(const char *name, int width, int height);
			~Window();
			void update() const;


		};
	}
}