#include "vec2.h"

namespace GEngine {
	namespace math {
		Vec2::Vec2() {
			x = 0.0;
			y = 0.0;
		}
		Vec2::Vec2(const float& x, const float& y) {
			this->x = x;
			this->y = y;
		}
		Vec2& Vec2::add(const Vec2& other) {
			this->x += other.x;
			this->y += other.y;
			return *this;
		}
		Vec2& Vec2::subtract(const Vec2& other) {
			this->x -= other.x;
			this->y -= other.y;
			return *this;
		}
		Vec2& Vec2::multiply(const Vec2& other) {
			this->x *= other.x;
			this->y *= other.y;
			return *this;
		}
		Vec2& Vec2::divide(const Vec2& other) {
			this->x /= other.x;
			this->y /= other.y;
			return *this;
		}
		bool Vec2::operator==(const Vec2& other) {
			return this->x == other.x && this->y == other.y;
		}
		bool Vec2::operator!=(const Vec2& other) {
			return !(*this == other);
		}
		Vec2& Vec2::operator+=(const Vec2& other) {
			return this->add(other);
		}
		Vec2& Vec2::operator-=(const Vec2& other) {
			return this->subtract(other);
		}
		Vec2& Vec2::operator*=(const Vec2& other) {
			return this->multiply(other);
		}
		Vec2& Vec2::operator/=(const Vec2& other) {
			return this->divide(other);
		}




		//non member funcs
		Vec2 operator+(Vec2 left, const Vec2& right) {
			return left.add(right);
		}
		Vec2 operator-(Vec2 left, const Vec2& right) {
			return left.subtract(right);
		}
		Vec2 operator*(Vec2 left, const Vec2& right) {
			return left.multiply(right);
		}
		Vec2 operator/(Vec2 left, const Vec2& right) {
			return left.divide(right);
		}
		std::ostream& operator<<(std::ostream& stream, const Vec2& vec) {
			stream << "Vec2: (" << vec.x << ", " << vec.y << ")";
			return stream;
		}
	}
}