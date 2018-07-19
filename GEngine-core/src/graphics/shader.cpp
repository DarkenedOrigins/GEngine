#include "shader.h"

namespace GEngine {
	namespace graphics {
		Shader::Shader(const char* vertexPath, const char* fragmentPath) {
			vertPath_ = vertexPath;
			fragPath_ = fragmentPath;
			shaderId_ = load();
		}

		Shader::~Shader() {
			glDeleteProgram(shaderId_);
		}

		void Shader::setUniform1i(const GLchar * name, int val) {
			glUniform1i(this->getUniformLocation(name), val);
		}

		void Shader::setUniform1f(const GLchar * name, float val) {
			glUniform1f(this->getUniformLocation(name), val);
		}

		void Shader::setUniform1fv(const GLchar * name, float * value, int count) {
			glUniform1fv(this->getUniformLocation(name), count, value);
		}

		void Shader::setUniform1iv(const GLchar * name, int * value, int count) {
			glUniform1iv(this->getUniformLocation(name), count, value);
		}

		void Shader::setUniform2f(const GLchar * name, const math::Vec2 & vec) {
			glUniform2f(getUniformLocation(name), vec.x, vec.y);
		}

		void Shader::setUniform3f(const GLchar * name, const math::Vec3 & vec) {
			glUniform3f(getUniformLocation(name), vec.x, vec.y, vec.z);
		}

		void Shader::setUniform4f(const GLchar * name, const math::Vec4 & vec) {
			glUniform4f(getUniformLocation(name), vec.x, vec.y, vec.z, vec.w);
		}

		void Shader::setUniformMatrix4(const GLchar * name, const math::Matrix4 & matrix) {
			glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, matrix.elements);
		}

		void Shader::enable() const {
			glUseProgram(shaderId_);
			return;
		}

		void Shader::disable() const {
			glUseProgram(0);
			return;
		}

		//private funcs
		GLuint Shader::load() {
			//have open gl create program, vertex, and fragment
			GLuint program = glCreateProgram();
			GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
			GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);
			//get shader from source file
			std::string vertexString = FileUtils::readFile(vertPath_);
			std::string fragString = FileUtils::readFile(fragPath_);
			const char* vertexSource = vertexString.c_str();
			const char* fragmentSource = fragString.c_str();
			// send this to open gl
			glShaderSource(vertex, 1, &vertexSource, NULL);
			glCompileShader(vertex);
			//check to see if shader complied properly
			GLint retval;
			glGetShaderiv(vertex, GL_COMPILE_STATUS, &retval);
			if (retval == GL_FALSE) {
				//if it did not print why the compiler errored
				GLint length;
				glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(vertex, length, &length, &error[0]);
				std::cout << "Failed to compile vertex" << &error[0] << std::endl;
				glDeleteShader(vertex);	//delete dead shader
				//we are returning zero because:
					//1) we cant return neg cuz retval is unsigned int
					//2) object 0 is equivalent to a NULL pointer in opengl
				return 0;
			}
			//check for fragment
			glShaderSource(fragment, 1, &fragmentSource, NULL);
			glCompileShader(fragment);
			glGetShaderiv(fragment, GL_COMPILE_STATUS, &retval);
			if (retval == GL_FALSE) {
				//if it did not print why the compiler errored
				GLint length;
				glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(fragment, length, &length, &error[0]);
				std::cout << "Failed to compile fragment:" << &error[0] << std::endl;
				glDeleteShader(fragment);	//delete dead shader
				//we are returning zero because:
					//1) we cant return neg cuz retval is unsigned int
					//2) object 0 is equivalent to a NULL pointer in opengl
				return 0;
			}
			//attach shaders to opengl program
			glAttachShader(program, vertex);
			glAttachShader(program, fragment);
			glLinkProgram(program);
			glValidateProgram(program);
			//delete shaders since they have been linked
			glDeleteShader(vertex);
			glDeleteShader(fragment);
			return program;
		}

		GLint Shader::getUniformLocation(const GLchar * name) {
			return glGetUniformLocation(this->shaderId_, name);
		}

		
	}
}