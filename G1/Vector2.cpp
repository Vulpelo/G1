#include "Vector2.h"

//namespace G1 {

	Vector2::Vector2()
		: x(0), y(0) {}

	Vector2::Vector2(float x, float y)
		: x(x), y(y) {}

	Vector2::Vector2(const Vector2 &vec)
	{
		this->x = vec.x;
		this->y = vec.y;
	}

	Vector2 Vector2::smoothDump(const Vector2 & current, const Vector2 & target, Vector2& currentVelocity, float smoothTime)
	{
		if (target.equal(current, 0.f) ) {
			return target;
		}
		Vector2 direction = (target - current);
		currentVelocity += (( (direction ) - currentVelocity) * (1.f / smoothTime));
		Vector2 newPos = (current + currentVelocity* G1::Time::getDeltaTime());
		if (((target - newPos).normalize()).equal(direction.normalize())) {
			return newPos;
		}
		currentVelocity.set(0.f, 0.f);
		return target;
	}

	Vector2 Vector2::lerp(const Vector2 & current, const Vector2 & target, float time)
	{
		return target + ((target - current) * time);
	}

	Vector2 Vector2::byAngleAndLength(float angle, float length)
	{
		float s = angle * float(M_PI) / 180;
		return Vector2(length * sinf(s), length * cosf(s));
	}

	float Vector2::crossZ(const Vector2 & vec1, const Vector2 & vec2)
	{
		return vec1.x * vec2.y - vec1.y * vec2.x;
	}

	Vector2 Vector2::operator-(const Vector2 & other) const
	{
		return Vector2(this->x - other.x, this->y - other.y);
	}

	Vector2 Vector2::operator+(const Vector2 & other) const
	{
		return Vector2(this->x + other.x, this->y + other.y);
	}

	Vector2 & Vector2::operator+=(const Vector2 & vec)
	{
		this->x += vec.x;
		this->y += vec.y;

		return *this;
	}

	Vector2 Vector2::operator*(const float & f) const
	{
		return Vector2(this->x * f, this->y * f);
	}

	Vector2& Vector2::operator*=(const float & f)
	{
		this->x *= f;
		this->y *= f;
		
		return *this;
	}

	float Vector2::operator*(const Vector2 & vector) const
	{
		return this->x * vector.x + this->y * vector.y;
	}

	Vector2 Vector2::operator/(const float & f)
	{
		if (f == 0.f) {
			return Vector2(_FMAX, _FMAX);
		}
		return Vector2(this->x / f, this->y / f);
	}

	bool Vector2::operator==(const Vector2 & vec) const
	{
		return vec.x == x && vec.y == y;
	}

	bool Vector2::equal(const Vector2& vector, float precision) const
	{
		return (vector.x - precision <= this->x && this->x <= vector.x + precision &&
			vector.y - precision <= this->y && this->y <= vector.y + precision);
	}

	Vector2 operator*(const float & f, const Vector2 & vector)
	{
		return Vector2(vector.x * f, vector.y * f);
	}

	float Vector2::angle() const
	{
		float value = 0;
		if (y != 0) {
			value = (180 * atanf(x / y)) / float(M_PI);
			if (y < 0)
				value += 180;
			if (x < 0 && y >= 0)
				value += 360;
		}
		else if (x > 0)
			value = 90;
		else if (x < 0)
			value = 270;

		return value;
	}

	float Vector2::length() const
	{
		return sqrtf(x*x + y*y);
	}

	float Vector2::lengthNoSqrt() const {
		return x*x + y*y;
	}

	Vector2 Vector2::normalize() const
	{
		Vector2 nV;
		if (this->length() == 0) {
			return nV;
		}
		nV.x = this->x / this->length();
		nV.y = this->y / this->length();
		return nV;
	}

	Vector2 Vector2::invertX() const
	{
		return Vector2(-x, y);
	}

	Vector2 Vector2::invertY() const
	{
		return Vector2(x, -y);
	}

	Vector2 Vector2::invert() const
	{
		return Vector2(-x, -y);
	}

	short Vector2::quadrant() const
	{
		if (x < 0) {
			if (y < 0) {
				return 3;
			}
			else {
				return 2;
			}
		}
		else {
			if (y < 0) {
				return 4;
			}
			else {
				return 1;
			}
		}
	}

	bool Vector2::nonZero() const
	{
		return x != 0.f || y != 0.f;
	}

//}
