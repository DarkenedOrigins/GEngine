#pragma once

#include <iostream>
#include <vector>
#include <GL/glew.h>
#include "../utilities/fileutils.h"
#include "../math/math.h"

namespace GEngine {
	namespace graphics {
		class Shader {

		private:
			GLuint shaderId_;
			const char *vertPath_, *fragPath_;
		public:
			Shader(const char* vertexPath, const char* fragmentPath);
			~Shader();


			void setUniform1i(const GLchar* name, int val);
			void setUniform1f(const GLchar* name, float val);

			void setUniform1fv(const GLchar* name, float* value, int count);
			void setUniform1iv(const GLchar* name, int* value, int count);

			void setUniform2f(const GLchar* name, const math::Vec2& vec);
			void setUniform3f(const GLchar* name, const math::Vec3& vec);
			void setUniform4f(const GLchar* name, const math::Vec4& vec);
			void setUniformMatrix4(const GLchar* name, const math::Matrix4& matrix);

			void enable() const;
			void disable() const;

		private:
			GLuint load();
			GLint getUniformLocation(const GLchar* name);
		};
	}
}
