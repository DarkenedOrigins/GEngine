#include "vec3.h"

namespace GEngine {
	namespace math {
		//constructors
		Vec3::Vec3() {
			x = 0.0;
			y = 0.0;
			z = 0.0;
		}
		Vec3::Vec3(const float& x, const float& y, const float& z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}

		//arithmatic operations
		Vec3& Vec3::add(const Vec3& other) {
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
			return *this;
		}
		Vec3& Vec3::subtract(const Vec3& other) {
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
			return *this;
		}
		Vec3& Vec3::multiply(const Vec3& other) {
			this->x *= other.x;
			this->y *= other.y;
			this->z *= other.z;
			return *this;
		}
		Vec3& Vec3::divide(const Vec3& other) {
			this->x /= other.x;
			this->y /= other.y;
			this->z /= other.z;
			return *this;
		}

		//operator overloads
		bool Vec3::operator==(const Vec3& other) {
			return this->x == other.x && this->y == other.y && this->z == other.z;
		}
		bool Vec3::operator!=(const Vec3& other) {
			return !(*this == other);
		}
		Vec3& Vec3::operator+=(const Vec3& other) {
			return this->add(other);
		}
		Vec3& Vec3::operator-=(const Vec3& other) {
			return this->subtract(other);
		}
		Vec3& Vec3::operator*=(const Vec3& other) {
			return this->multiply(other);
		}
		Vec3& Vec3::operator/=(const Vec3& other) {
			return this->divide(other);
		}

		//non member funcs
		Vec3 operator+(Vec3 left, const Vec3& right) {
			return left.add(right);
		}
		Vec3 operator-(Vec3 left, const Vec3& right) {
			return left.subtract(right);
		}
		Vec3 operator*(Vec3 left, const Vec3& right) {
			return left.multiply(right);
		}
		Vec3 operator/(Vec3 left, const Vec3& right) {
			return left.divide(right);
		}
		std::ostream& operator<<(std::ostream& stream, const Vec3& vec) {
			stream << "Vec3: (" << vec.x << ", " << vec.y << ", " << vec.z << ")";
			return stream;
		}
	}
}