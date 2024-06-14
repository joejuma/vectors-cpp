#pragma once
/*
	# Vector Template Library
	## Version 1.0
	## By Joseph Juma

	## About
	This is a library that provides vector templates. If you're anything like me, 
	you'll keep having projects that can be improved by having simple vector types, 
	and so you'll find you may be reimplementing vectors. To solve this - a simple 
	template library which creates vector templates in the first few dimensions and 
	then provides a scalable form.

	## Copyright
	Copyright Joseph M. Juma, 2024. All rights reserved.
*/
#ifndef VECTOR_TEMPLATE_LIBRARY__H
#define VECTOR_TEMPLATE_LIBRARY__H
/* Deps */
#include <stdint.h>
#include <stdarg.h>
#include <string>
#include <iostream>

/* Structures */
template <typename T>
struct Vector2D
{
	/*
		# Vector 2D (struct)
	*/

	/* Elements */
	T value[2];

	/* Methods */

	// Constructors & Destructor
	Vector2D()
	{
		this->value[0] = T();
		this->value[1] = T();
	};
	Vector2D(const T& i, const T& j)
	{
		this->value[0] = i;
		this->value[1] = j;
	};
	Vector2D(const Vector2D<T>& source)
	{
		this->value[0] = source.value[0];
		this->value[1] = source.value[1];
	};

	// Access Operators
	inline T& x()
	{
		return this->value[0];
	};
	inline T& y()
	{
		return this->value[1];
	};
	inline T& operator[](const uint64_t& i)
	{
		return this->value[i];
	};
	inline T& get(const uint64_t& i)
	{
		return (*this)[i];
	};

	// Serialization
	virtual inline std::string toString() const
	{
		return "(" + std::to_string(this->value[0]) + "," + std::to_string(this->value[1]) + ")";
	};

	// Magnitude Operators
	inline T length()
	{
		return sqrt(pow((double)this->x(),2.0) + pow((double)this->y(), 2.0));
	};
	inline T sum() const
	{
		return (
			abs(this->value[0]) + 
			abs(this->value[1])
		);
	};
	
	// Normalization Methods
	inline T norm()
	{
		return sqrt(
			pow((double)this->x(), 2.0) +
			pow((double)this->y(), 2.0)
		);
	};
	inline T pNorm(const uint64_t& p)
	{
		/*
			A lebesgue p-Norm, where the exponent (2) in the norm formula is generalized
			into a variable p. Thanks again Henri!
		*/

		return pow(
			(
				pow((double)this->x(), (double)p) +
				pow((double)this->y(), (double)p)
			),
			(1.0 / p)
		);
	};
	
	inline Vector2D<T> unitNormal()
	{
		return ((*this) / this->norm());
	};
	inline Vector2D<T> normal() const
	{
		/*
			Returns the normal vector, calculated from dividing each element by the sum 
			of all the elements.
		*/

		T _sum = this->sum();
		return Vector2D<T>(
			((double)this->value[0] / _sum),
			((double)this->value[1] / _sum)
		);
	};

	// Product Operators
	inline T dot(const Vector2D<T>& B)
	{
		return ((this->x() * B.x()) + (this->y() * B.y()));
	};

	// Binary Operators
	inline Vector2D<T> operator+(const Vector2D<T>& B)
	{
		return Vector2D<T>(
			(this->x() + B.x()),
			(this->y() + B.y())
		);
	};
	inline Vector2D<T> operator+(const T& B)
	{
		return Vector2D<T>(
			(this->x() + B),
			(this->y() + B)
		);
	};

	inline Vector2D<T> operator-(const Vector2D<T>& B)
	{
		return Vector2D<T>(
			(this->x() - B.x()),
			(this->y() - B.y())
		);
	};
	inline Vector2D<T> operator-(const T& B)
	{
		return Vector2D<T>(
			(this->x() - B),
			(this->y() - B)
		);
	};

	inline Vector2D<T> operator*(const Vector2D<T>& B)
	{
		return Vector2D<T>(
			(this->x() * B.x()),
			(this->y() * B.y())
		);
	};
	inline Vector2D<T> operator*(const T& B)
	{
		return Vector2D<T>(
			(this->x() * B),
			(this->y() * B)
		);
	};

	inline Vector2D<T> operator/(const Vector2D<T>& B)
	{
		return Vector2D<T>(
			(this->x() / B.x()),
			(this->y() / B.y())
		);
	};
	inline Vector2D<T> operator/(const T& B)
	{
		return Vector2D<T>(
			(this->x() / B),
			(this->y() / B)
		);
	};

	// Binary Assignment Operators
	inline Vector2D<T>& operator+=(const Vector2D<T>& B)
	{
		this->x() = this->x() + B.x();
		this->y() = this->y() + B.y();
		return (*this);
	};
	inline Vector2D<T>& operator+=(const T& B)
	{
		this->x() = this->x() + B;
		this->y() = this->y() + B;
		return (*this);
	};

	inline Vector2D<T>& operator-=(const Vector2D<T>& B)
	{
		this->x() = this->x() - B.x();
		this->y() = this->y() - B.y();
		return (*this);
	};
	inline Vector2D<T>& operator-=(const T& B)
	{
		this->x() = this->x() - B;
		this->y() = this->y() - B;
		return (*this);
	};

	inline Vector2D<T>& operator*=(const Vector2D<T>& B)
	{
		this->x() = this->x() * B.x();
		this->y() = this->y() * B.y();
		return (*this);
	};
	inline Vector2D<T>& operator*=(const T& B)
	{
		this->x() = this->x() * B;
		this->y() = this->y() * B;
		return (*this);
	};

	inline Vector2D<T>& operator/=(const Vector2D<T>& B)
	{
		this->x() = this->x() / B.x();
		this->y() = this->y() / B.y();
		return (*this);
	};
	inline Vector2D<T>& operator/=(const T& B)
	{
		this->x() = this->x() / B;
		this->y() = this->y() / B;
		return (*this);
	};
};

template <typename T>
struct Vector3D
{
	/*
		# Vector 3D (struct)
	*/

	/* Elements */
	T value[3];

	/* Methods */

	// Constructors & Destructor
	Vector3D()
	{
		this->value[0] = T();
		this->value[1] = T();
		this->value[2] = T();
	};
	Vector3D(const T& i, const T& j, const T& k)
	{
		this->value[0] = i;
		this->value[1] = j;
		this->value[2] = k;
	};
	Vector3D(const Vector3D& source)
	{
		this->value[0] = source.value[0];
		this->value[1] = source.value[1];
		this->value[2] = source.value[2];
	};

	// Serialization
	virtual inline std::string toString() const
	{
		return "(" +
			std::to_string(this->value[0]) +
			"," + std::to_string(this->value[1]) +
			"," + std::to_string(this->value[2]) +
		")";
	};

	// Magnitude Operators
	inline T length()
	{
		return sqrt(
			pow((double)this->value[0], 2.0) +
			pow((double)this->value[1], 2.0) +
			pow((double)this->value[2], 2.0)
		);
	};
	inline T sum() const
	{
		return (
			abs(this->value[0]) + 
			abs(this->value[1]) + 
			abs(this->value[2])
		);
	};

	// Normalization Methods
	inline T norm()
	{
		return sqrt(
			pow((double)this->value[0], 2.0) +
			pow((double)this->value[1], 2.0) +
			pow((double)this->value[2], 2.0)
		);
	};
	inline T pNorm(const uint64_t& p)
	{
		/*
			A lebesgue p-Norm, where the exponent (2) in the norm formula is generalized
			into a variable p. Thanks again Henri!
		*/

		return pow(
			(
				pow((double)this->value[0], (double)p) +
				pow((double)this->value[1], (double)p) +
				pow((double)this->value[2], (double)p)
			),
			(1.0 / p)
		);
	};

	inline Vector3D<T> unitNormal()
	{
		return ((*this) / this->norm());
	};
	inline Vector3D<T> normal() const
	{
		/*
			Returns the normal vector, calculated from dividing each element by the sum
			of all the elements.
		*/

		T _sum = this->sum();
		return Vector3D<T>(
			((double)this->value[0] / _sum),
			((double)this->value[1] / _sum),
			((double)this->value[2] / _sum)
		);
	};

	// Access Operators
	inline T& x()
	{
		return this->value[0];
	};
	inline T& y()
	{
		return this->value[1];
	};
	inline T& z()
	{
		return this->value[2];
	};
	inline T& operator[](const uint64_t& i)
	{
		return this->value[i];
	};
	inline T& get(const uint64_t& i)
	{
		return (*this)[i];
	};

	// Product Operators
	inline T dot(const Vector3D<T>& B)
	{
		return (
			(this->x() * B.x()) + 
			(this->y() * B.y()) + 
			(this->z() * B.z())
		);
	};
	inline Vector3D<T> cross(const Vector3D<T>& B)
	{
		return Vector3D<T>(
			(this->y() * B.z()) - (this->z() * B.y()),
			(this->z() * B.x()) - (this->x() * B.z()),
			(this->x() * B.y()) - (this->y() * B.x())
		);
	};

	// Binary Operators
	inline Vector3D<T> operator+(const Vector3D<T>& B)
	{
		return Vector3D<T>(
			(this->x() + B.x()),
			(this->y() + B.y()),
			(this->z() + B.z())
		);
	};
	inline Vector3D<T> operator+(const T& B)
	{
		return Vector3D<T>(
			(this->x() + B),
			(this->y() + B),
			(this->z() + B)
		);
	};

	inline Vector3D<T> operator-(const Vector3D<T>& B)
	{
		return Vector3D<T>(
			(this->x() - B.x()),
			(this->y() - B.y()),
			(this->z() - B.z())
		);
	};
	inline Vector3D<T> operator-(const T& B)
	{
		return Vector3D<T>(
			(this->x() - B),
			(this->y() - B),
			(this->z() - B)
		);
	};

	inline Vector3D<T> operator*(const Vector3D<T>& B)
	{
		return Vector3D<T>(
			(this->x() * B.x()),
			(this->y() * B.y()),
			(this->z() * B.z())
		);
	};
	inline Vector3D<T> operator*(const T& B)
	{
		return Vector3D<T>(
			(this->x() * B),
			(this->y() * B),
			(this->z() * B)
		);
	};

	inline Vector3D<T> operator/(const Vector3D<T>& B)
	{
		return Vector3D<T>(
			(this->x() / B.x()),
			(this->y() / B.y()),
			(this->z() / B.z())
		);
	};
	inline Vector3D<T> operator/(const T& B)
	{
		return Vector3D<T>(
			(this->x() / B),
			(this->y() / B),
			(this->z() / B)
		);
	};

	// Binary Assignment Operators
	inline Vector3D<T>& operator+=(const Vector3D<T>& B)
	{
		this->x() = this->x() + B.x();
		this->y() = this->y() + B.y();
		this->z() = this->z() + B.z();
		return (*this);
	};
	inline Vector3D<T>& operator+=(const T& B)
	{
		this->x() = this->x() + B;
		this->y() = this->y() + B;
		this->z() = this->z() + B;
		return (*this);
	};

	inline Vector3D<T>& operator-=(const Vector3D<T>& B)
	{
		this->x() = this->x() - B.x();
		this->y() = this->y() - B.y();
		this->z() = this->z() - B.z();
		return (*this);
	};
	inline Vector3D<T>& operator-=(const T& B)
	{
		this->x() = this->x() - B;
		this->y() = this->y() - B;
		this->z() = this->z() - B;
		return (*this);
	};

	inline Vector3D<T>& operator*=(const Vector3D<T>& B)
	{
		this->x() = this->x() * B.x();
		this->y() = this->y() * B.y();
		this->z() = this->z() * B.z();
		return (*this);
	};
	inline Vector3D<T>& operator*=(const T& B)
	{
		this->x() = this->x() * B;
		this->y() = this->y() * B;
		this->z() = this->z() * B;
		return (*this);
	};

	inline Vector3D<T>& operator/=(const Vector3D<T>& B)
	{
		this->x() = this->x() / B.x();
		this->y() = this->y() / B.y();
		this->z() = this->z() / B.z();
		return (*this);
	};
	inline Vector3D<T>& operator/=(const T& B)
	{
		this->x() = this->x() / B;
		this->y() = this->y() / B;
		this->z() = this->z() / B;
		return (*this);
	};
};

template <typename T>
struct Vector4D
{
	/*
		# Vector 4D (struct)
	*/

	/* Elements */
	T value[4];

	/* Methods */

	// Constructors & Destructor
	Vector4D()
	{
		this->value[0] = T();
		this->value[1] = T();
		this->value[2] = T();
		this->value[3] = T();
	};
	Vector4D(const T& i, const T& j, const T& k, const T& l)
	{
		this->value[0] = i;
		this->value[1] = j;
		this->value[2] = k;
		this->value[3] = l;
	};
	Vector4D(const Vector4D& source)
	{
		this->value[0] = source.value[0];
		this->value[1] = source.value[1];
		this->value[2] = source.value[2];
		this->value[3] = source.value[3];
	};

	// Magnitude Operators
	inline T length()
	{
		return sqrt(
			pow((double)this->value[0], 2.0) +
			pow((double)this->value[1], 2.0) +
			pow((double)this->value[2], 2.0) +
			pow((double)this->value[3], 2.0)
		);
	};
	inline T sum() const
	{
		return (
			abs(this->value[0]) + 
			abs(this->value[1]) + 
			abs(this->value[2]) + 
			abs(this->value[3])
		);
	};

	// Normalization Methods
	inline T norm()
	{
		return sqrt(
			pow((double)this->value[0], 2.0) +
			pow((double)this->value[1], 2.0) +
			pow((double)this->value[2], 2.0) +
			pow((double)this->value[3], 2.0)
		);
	};
	inline T pNorm(const uint64_t& p)
	{
		/*
			A lebesgue p-Norm, where the exponent (2) in the norm formula is generalized
			into a variable p. Thanks again Henri!
		*/

		return pow(
			(
				pow((double)this->value[0], (double)p) +
				pow((double)this->value[1], (double)p) +
				pow((double)this->value[2], (double)p) +
				pow((double)this->value[3], (double)p)
			),
			(1.0 / p)
		);
	};

	inline Vector4D<T> unitNormal()
	{
		return ((*this) / this->norm());
	};
	inline Vector4D<T> normal() const
	{
		/*
			Returns the normal vector, calculated from dividing each element by the sum
			of all the elements.
		*/

		T _sum = this->sum();
		return Vector4D<T>(
			((double)this->value[0] / _sum),
			((double)this->value[1] / _sum),
			((double)this->value[2] / _sum),
			((double)this->value[3] / _sum)
		);
	};

	// Access Operators
	inline T& x()
	{
		return this->value[0];
	};
	inline T& y()
	{
		return this->value[1];
	};
	inline T& z()
	{
		return this->value[2];
	};
	inline T& t()
	{
		return this->value[3];
	};
	inline T& operator[](const uint64_t& i)
	{
		return this->value[i];
	};
	inline T& get(const uint64_t& i)
	{
		return (*this)[i];
	};

	// Serialization
	virtual inline std::string toString() const
	{
		return "(" + 
			std::to_string(this->value[0]) + 
			"," + std::to_string(this->value[1]) + 
			"," + std::to_string(this->value[2]) + 
			"," + std::to_string(this->value[3]) + 
		")";
	};

	// Product Operators
	inline T dot(const Vector4D<T>& B)
	{
		return (
			(this->x() * B.x()) +
			(this->y() * B.y()) +
			(this->z() * B.z()) +
			(this->t() * B.t())
		);
	};

	// Binary Operators
	inline Vector4D<T> operator+(const Vector4D<T>& B)
	{
		return Vector4D<T>(
			(this->x() + B.x()),
			(this->y() + B.y()),
			(this->z() + B.z()),
			(this->t() + B.t())
		);
	};
	inline Vector4D<T> operator+(const T& B)
	{
		return Vector4D<T>(
			(this->x() + B),
			(this->y() + B),
			(this->z() + B),
			(this->t() + B)
		);
	};

	inline Vector4D<T> operator-(const Vector4D<T>& B)
	{
		return Vector4D<T>(
			(this->x() - B.x()),
			(this->y() - B.y()),
			(this->z() - B.z()),
			(this->t() - B.t())
		);
	};
	inline Vector4D<T> operator-(const T& B)
	{
		return Vector4D<T>(
			(this->x() - B),
			(this->y() - B),
			(this->z() - B),
			(this->t() - B)
		);
	};

	inline Vector4D<T> operator*(const Vector4D<T>& B)
	{
		return Vector4D<T>(
			(this->x() * B.x()),
			(this->y() * B.y()),
			(this->z() * B.z()),
			(this->t() * B.t())
		);
	};
	inline Vector4D<T> operator*(const T& B)
	{
		return Vector4D<T>(
			(this->x() * B),
			(this->y() * B),
			(this->z() * B),
			(this->t() * B)
		);
	};

	inline Vector4D<T> operator/(const Vector4D<T>& B)
	{
		return Vector4D<T>(
			(this->x() / B.x()),
			(this->y() / B.y()),
			(this->z() / B.z()),
			(this->t() / B.t())
		);
	};
	inline Vector4D<T> operator/(const T& B)
	{
		return Vector4D<T>(
			(this->x() / B),
			(this->y() / B),
			(this->z() / B),
			(this->t() / B)
		);
	};

	// Binary Assignment Operators
	inline Vector4D<T>& operator+=(const Vector4D<T>& B)
	{
		this->x() = this->x() + B.x();
		this->y() = this->y() + B.y();
		this->z() = this->z() + B.z();
		this->t() = this->t() + B.t();
		return (*this);
	};
	inline Vector4D<T>& operator+=(const T& B)
	{
		this->x() = this->x() + B;
		this->y() = this->y() + B;
		this->z() = this->z() + B;
		this->t() = this->t() + B;
		return (*this);
	};

	inline Vector4D<T>& operator-=(const Vector4D<T>& B)
	{
		this->x() = this->x() - B.x();
		this->y() = this->y() - B.y();
		this->z() = this->z() - B.z();
		this->t() = this->t() - B.t();
		return (*this);
	};
	inline Vector4D<T>& operator-=(const T& B)
	{
		this->x() = this->x() - B;
		this->y() = this->y() - B;
		this->z() = this->z() - B;
		this->t() = this->t() - B;
		return (*this);
	};

	inline Vector4D<T>& operator*=(const Vector4D<T>& B)
	{
		this->x() = this->x() * B.x();
		this->y() = this->y() * B.y();
		this->z() = this->z() * B.z();
		this->t() = this->t() * B.t();
		return (*this);
	};
	inline Vector4D<T>& operator*=(const T& B)
	{
		this->x() = this->x() * B;
		this->y() = this->y() * B;
		this->z() = this->z() * B;
		this->t() = this->t() *B;
		return (*this);
	};

	inline Vector4D<T>& operator/=(const Vector4D<T>& B)
	{
		this->x() = this->x() / B.x();
		this->y() = this->y() / B.y();
		this->z() = this->z() / B.z();
		this->t() = this->t() / B.t();
		return (*this);
	};
	inline Vector4D<T>& operator/=(const T& B)
	{
		this->x() = this->x() / B;
		this->y() = this->y() / B;
		this->z() = this->z() / B;
		this->t() = this->t() / B;
		return (*this);
	};
};

template <uint64_t N, typename T>
struct Vector
{
	/*
		# Vector (struct)
	*/

	/* Elements */
	T value[N];

	/* Methods */
	
	// Constructors & Destructor
	Vector()
	{
		for (uint64_t i = 0; i < N; i++)
		{
			this->value[i] = T();
		};
	};
	Vector(const T v...)
	{
		va_list args;
		va_start(args, v);
		this->value[0] = v;
		for (uint64_t i = 1; i < N; i++)
		{
			this->value[i] = va_arg(args, T);
		};
		va_end(args);
	};
	Vector(const Vector<N, T>& source)
	{
		for (uint64_t i = 0; i < N; i++)
		{
			this->value[i] = source[i];
		};
	};

	// Access Operators
	inline T& operator[](const uint64_t& i)
	{
		return this->value[i];
	};
	inline T& get(const uint64_t& i)
	{
		return (*this)[i];
	};

	// Serialization
	virtual inline std::string toString() const
	{
		std::string s = "(";
		for (uint64_t i = 0; i < N; i++)
		{
			s += std::to_string(this->value[i]);
			if ((i + 1) < N)
			{
				s += ",";
			};
		};
		s += ")";
		return s;
	};

	// Magnitude Operators
	inline T length()
	{
		T sum = T();
		for (uint64_t i = 0; i < N; i++)
		{
			sum += pow((double)this->get(i), 2.0);
		};

		return sqrt(sum);
	};
	inline T sum()
	{
		T sum = T();
		for (uint64_t i = 0; i < N; i++)
		{
			sum += abs(this->value[i]);
		};

		return sum;
	};

	// Normalization Methods
	inline T norm() const
	{
		T sum = T();
		for (uint64_t i = 0; i < N; i++)
		{
			sum += pow((double)this->value[i], 2.0);
		};

		return sqrt(sum);
	};
	inline T pNorm(const uint64_t& p) const
	{
		T sum = T();
		for (uint64_t i = 0; i < N; i++)
		{
			sum += pow((double)this->value[i], (double)p);
		};

		return pow(sum, (1.0/(double)p));
	};
	
	inline Vector<N, T> unitNormal()
	{
		return ((*this) / this->norm());
	};
	inline Vector<N, T> normal() const
	{
		T _sum = this->sum();
		Vector<N, T> v;

		for (uint64_t i = 0; i < N; i++)
		{
			v.get(i) = (this->get(i) / _sum);
		};

		return v;
	};

	// Product Operators
	inline T dot(const Vector<N, T>& B)
	{
		T value = T();
		for (uint64_t i = 0; i < N; i++)
		{
			value += (this->get(i) * ((Vector<N,T>&)B).get(i));
		};

		return value;
	};
};

/* Pipe Operators */
template <typename T>
std::ostream& operator<<(std::ostream& stream, const Vector2D<T>& value)
{
	return stream << value.toString();
};
template <typename T>
std::ostream& operator<<(std::ostream& stream, const Vector3D<T>& value)
{
	return stream << value.toString();
};
template <typename T>
std::ostream& operator<<(std::ostream& stream, const Vector4D<T>& value)
{
	return stream << value.toString();
};
template <uint64_t N, typename T>
std::ostream& operator<<(std::ostream& stream, const Vector<N,T>& value)
{
	return stream << value.toString();
};

#endif