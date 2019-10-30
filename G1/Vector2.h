#pragma once

#ifndef _VECTOR2_H_
#define _VECTOR2_H_

#include "MathVariables.h"
#include "Time.h"

//namespace G1 {

	class Vector2
	{
	public:
		float x = 0.0;
		float y = 0.0;

		Vector2();
		Vector2(float x, float y);
		Vector2(const Vector2&);

		static Vector2 right() { return Vector2(1, 0); };
		static Vector2 up() { return Vector2(0, -1); };
		static Vector2 left() { return Vector2(-1, 0); };
		static Vector2 down() { return Vector2(0, 1); };

		static Vector2 smoothDump(const Vector2& current, const Vector2& target, Vector2& currentVelocity, float smoothTime);
		/// <summary>
		/// Returns new position beetween two vectors.
		/// Time=0.f returns current. Time=1.0f returns target. Time=0.5f returns vector in middle position between vectors.
		/// </summary>
		static Vector2 lerp(const Vector2& current, const Vector2& target, float time);

		/// <summary>
		/// Angle in degress
		/// </summary>
		/// <param name="angle"></param>
		/// <param name="length"></param>
		void setVectorByAngleAndLength(float angle, float length);

		void set(float x, float y) { this->x = x; this->y = y; };
		/// <summary>
		/// Sumbstract one vector from another
		/// </summary>
		/// <returns>New substracted Vector2</returns>
		Vector2 operator -(const Vector2&) const;
		Vector2 operator +(const Vector2&) const;
		Vector2& operator +=(const Vector2&);
		Vector2 operator*(const float& f) const;
		friend Vector2 operator*(const float&, const Vector2&);
		Vector2& operator*=(const float& f);

		
		/// /// /// <summary> Dot product of two vectors </summary>
		float operator *(const Vector2&) const;

		Vector2 operator/(const float& f);

		bool equal(const Vector2& vector, float precision = 0.001f) const;

		/// <summary>
		/// Direction of vector in witch is facing. Angle is 0 when vector is pointing straight up.
		/// Return's 0 also when x and y are equal 0.
		/// </summary>
		float angle() const;

		/// <summary>Distance between begining and end of the vector</summary>
		float length() const;

		/// /// <summary>Distance to the power 2 between begining and end of the vector</summary>
		float lengthNoSqrt() const;

		/// <summary>Returns vector with length equal 1</summary>
		Vector2 normalize() const;

		Vector2 invertX() const;
		Vector2 invertY() const;
		Vector2 invert() const;

		/// <summary>
		/// Returns quadrant number of coordinate system depending from x and y values
		/// </summary>
		short quadrant() const;

		bool nonZero() const;
	};

//}

#endif // !_VECTOR2_H_
