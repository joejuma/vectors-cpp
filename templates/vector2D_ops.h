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
inline Vector2D<T> operator+=(const T& B)
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
inline Vector2D<T> operator-=(const T& B)
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
inline Vector2D<T> operator*=(const T& B)
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
inline Vector2D<T> operator/=(const T& B)
{
	this->x() = this->x() / B;
	this->y() = this->y() / B;
	return (*this);
}; 