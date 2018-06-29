#include "vec4.h"

namespace GEngine {
	namespace math {
		//constructors
		Vec4::Vec4() {
			x = 0.0;
			y = 0.0;
			z = 0.0;
			w = 0.0;
		}
		Vec4::Vec4(const float& x, const float& y, const float& z, const float& w) {
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}

		//arithmatic operations
		Vec4& Vec4::add(const Vec4& other) {
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
			this->w += other.w;
			return *this;
		}
		Vec4& Vec4::subtract(const Vec4& other) {
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
			this->w -= other.w;
			return *this;
		}
		Vec4& Vec4::multiply(const Vec4& other) {
			this->x *= other.x;
			this->y *= other.y;
			this->z *= other.z;
			this->w *= other.w;
			return *this;
		}
		Vec4& Vec4::divide(const Vec4& other) {
			this->x /= other.x;
			this->y /= other.y;
			this->z /= other.z;
			this->w /= other.w;
			return *this;
		}

		//operator overloads
		bool Vec4::operator==(const Vec4& other) {
			return this->x == other.x && this->y == other.y && this->z == other.z && this->w == other.w;
		}
		bool Vec4::operator!=(const Vec4& other) {
			return !(*this == other);
		}
		Vec4& Vec4::operator+=(const Vec4& other) {
			return this->add(other);
		}
		Vec4& Vec4::operator-=(const Vec4& other) {
			return this->subtract(other);
		}
		Vec4& Vec4::operator*=(const Vec4& other) {
			return this->multiply(other);
		}
		Vec4& Vec4::operator/=(const Vec4& other) {
			return this->divide(other);
		}

		//non member funcs
		Vec4 operator+(Vec4 left, const Vec4& right) {
			return left.add(right);
		}
		Vec4 operator-(Vec4 left, const Vec4& right) {
			return left.subtract(right);
		}
		Vec4 operator*(Vec4 left, const Vec4& right) {
			return left.multiply(right);
		}
		Vec4 operator/(Vec4 left, const Vec4& right) {
			return left.divide(right);
		}
		std::ostream& operator<<(std::ostream& stream, const Vec4& vec) {
			stream << "Vec4: (" << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << ")";
			return stream;
		}
	}
}