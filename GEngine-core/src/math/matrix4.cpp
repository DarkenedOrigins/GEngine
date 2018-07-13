#define _USE_MATH_DEFINES
#include <math.h>
#include "matrix4.h"

//secret func
float toRad(float deg) {
	return deg * (float)M_PI / 180.0f;
}

namespace GEngine {
	namespace math {
		Matrix4::Matrix4() {
			for (int i = 0; i < 4 * 4; i++) {
				elements[i] = 0.0f;
			}
		}
		//makes a diagonal 4x4 matrix with the given value
		Matrix4::Matrix4(float diagonal) {
			for (int i = 0; i < 4 * 4; i++) {
				elements[i] = 0.0f;
			}
			//col major order indexed as row + col * 4(size)
			elements[0 + 0 * 4] = diagonal;
			elements[1 + 1 * 4] = diagonal;
			elements[2 + 2 * 4] = diagonal;
			elements[3 + 3 * 4] = diagonal;
		}
		Matrix4& Matrix4::multiply(const Matrix4& other) {
			//col major order indexed as row + col * 4(size)
			float data[16];
			for (int y = 0; y < 4; y++) {
				for (int x = 0; x < 4; x++) {
					float sum = 0;
					//this loop to iterate over other matrix column
					for (int e = 0; e < 4; e++) {
						sum += this->elements[x + e * 4] * other.elements[e + y * 4];
					}
					data[x + y * 4] = sum;
				}
			}
			memcpy(this->elements, data, 4 * 4 * sizeof(float));	// its a 4 by 4 matrix of floats hence 4 * 4 * sizeof(float)
			return *this;
		}
		Vec3 Matrix4::multiply(const Vec3 & other) const {
			return Vec3(
				columns[0].x * other.x + columns[1].x * other.y + columns[2].x * other.z + columns[3].x,
				columns[0].y * other.x + columns[1].y * other.y + columns[2].y * other.z + columns[3].y,
				columns[0].z * other.x + columns[1].z * other.y + columns[2].z * other.z + columns[3].z
			);
		}
		Vec4 Matrix4::multiply(const Vec4 & other) const {
			return Vec4(
				columns[0].x * other.x + columns[1].x * other.y + columns[2].x * other.z + columns[3].x * other.w, 
				columns[0].y * other.x + columns[1].y * other.y + columns[2].y * other.z + columns[3].y * other.w, 
				columns[0].z * other.x + columns[1].z * other.y + columns[2].z * other.z + columns[3].z * other.w, 
				columns[0].w * other.x + columns[1].w * other.y + columns[2].w * other.z + columns[3].w * other.w 
			);
		}
		//operators 
		Matrix4 operator*(const Matrix4& left, const Matrix4& right) {
			Matrix4 retval = left;
			return retval.multiply(right);
		}
		Vec3 operator*(const Matrix4 & left, const Vec3 & right) {
			return left.multiply(right);
		}
		Vec4 operator*(const Matrix4 & left, const Vec4 & right) {
			return left.multiply(right);
		}
		Matrix4& Matrix4::operator*=(const Matrix4& other) {
			return this->multiply(other);
		}
		std::ostream& operator<<(std::ostream& stream, const Matrix4& matrix) {
			for (int row = 0; row < 4; row++) {
				stream << "Row" << row << ": [";
				for (int col = 0; col < 4; col++) {
					stream << matrix.elements[row + col * 4];
					if (col != 3) {
						stream<< ", ";
					}
				}
				stream << "]" << std::endl;
			}
			return stream;
		}
		//static methods
		Matrix4 Matrix4::identity() {
			return Matrix4(1);
		}
		Matrix4 Matrix4::orthographic(float left, float right, float bottom, float top, float near, float far) {
			Matrix4 result = Matrix4::identity();
			//col major order indexed as row + col * 4(size)
			result.elements[0 + 0 * 4] = 2.0f / (right - left);
			result.elements[1 + 1 * 4] = 2.0f / (top - bottom);
			result.elements[2 + 2 * 4] = -2.0f / (far - near);
			result.elements[0 + 3 * 4] = -1.0f * ((right + left) / (right - left));
			result.elements[1 + 3 * 4] = -1.0f * ((top + bottom) / (top - bottom));
			result.elements[2 + 3 * 4] = -1.0f * ((far + near) / (far - near));
			return result;
		}
		Matrix4 Matrix4::perspective(float fieldOfView, float aspectRatio, float near, float far) {
			Matrix4 result;
			float b = tanf(toRad(fieldOfView) / 2.0f);
			//col major order indexed as row + col * 4(size)
			result.elements[0 + 0 * 4] = 1.0f / (aspectRatio*b);
			result.elements[1 + 1 * 4] = 1.0f / b;
			result.elements[2 + 2 * 4] = (far + near) / (near - far);
			result.elements[2 + 3 * 4] = (2.0f*far*near) / (near - far);
			result.elements[3 + 2 * 4] = -1.0f;
			return result;
		}
		Matrix4 Matrix4::translation(const Vec3& translation) {
			Matrix4 result = Matrix4::identity();
			//col major order indexed as row + col * 4(size)
			result.elements[0 + 3 * 4] = translation.x;
			result.elements[1 + 3 * 4] = translation.y;
			result.elements[2 + 3 * 4] = translation.z;
			return result;
		}
		Matrix4 Matrix4::rotation(float degrees, const Vec3& axis) {
			Matrix4 result(1.0f);
			float rad = toRad(degrees);
			float c = cos(rad);
			float s = sin(rad);
			float oneMinusCos = 1.0f - c;
			float x = axis.x;
			float y = axis.y;
			float z = axis.z;
			//col major order indexed as row + col * 4(size)
			result.elements[0 + 0 * 4] = x * oneMinusCos + c;
			result.elements[1 + 0 * 4] = y * x * oneMinusCos + z * s;
			result.elements[2 + 0 * 4] = x * z * oneMinusCos - y * s;

			result.elements[0 + 1 * 4] = x * y*oneMinusCos - z * s;
			result.elements[1 + 1 * 4] = y * oneMinusCos + c;
			result.elements[2 + 1 * 4] = y * z*oneMinusCos + x * s;

			result.elements[0 + 2 * 4] = x * z*oneMinusCos + y * s;
			result.elements[1 + 2 * 4] = y * z*oneMinusCos - x * s;
			result.elements[2 + 2 * 4] = z * oneMinusCos + c;

			return result;
		}
		Matrix4 Matrix4::scale(const Vec3& scale) {
			Matrix4 result = Matrix4::identity();
			result.elements[0 + 0 * 4] = scale.x;
			result.elements[1 + 1 * 4] = scale.y;
			result.elements[2 + 2 * 4] = scale.z;
			return result;
		}
	}
}