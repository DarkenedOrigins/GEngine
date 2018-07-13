#pragma once

#include "math.h"

namespace GEngine {
	namespace math {
		struct Matrix4 {
			union {
				float elements[4 * 4];	//4 by 4 matrix in column major order to follow opengl convention
				Vec4 columns[4];
			};
			//methods
			Matrix4();
			Matrix4(float diagonal);
			Matrix4& multiply(const Matrix4& other);
			//extra multiply methods for various reasons
			Vec3 multiply(const Vec3& other) const;
			Vec4 multiply(const Vec4& other) const;

			//static methods so Matrix4 matrix = Matrix4::identity() (and so on) can be used
			static Matrix4 identity();
			static Matrix4 orthographic(float left, float right, float bottom, float top, float near, float far);
			static Matrix4 perspective(float fieldOfView, float aspectRatio, float near, float far);
			static Matrix4 translation(const Vec3& translation);
			static Matrix4 rotation(float degrees, const Vec3& axis);
			static Matrix4 scale(const Vec3& scale);
			//operator overloads
			friend Matrix4 operator*(const Matrix4& left, const Matrix4& right);
			//operator overloads as well
			friend Vec3 operator*(const Matrix4& left, const Vec3& right);
			friend Vec4 operator*(const Matrix4& left, const Vec4& right);
			Matrix4& operator*=(const Matrix4& other);
			friend std::ostream& operator<<(std::ostream& stream, const Matrix4& matrix);


		};
	}
}
