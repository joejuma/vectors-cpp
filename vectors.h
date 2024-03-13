#pragma once
/*
	# Vector Template Library
	## Version 0.1
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
	Vector2D(const Vector2D& source)
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
	inline T& w()
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
};
#endif