// Binary Operators
inline Vector3D<T> operator*(const Vector2D<T>& B)
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

// Binary Assignment Operators
inline Vector3D<T>& operator*=(const Vector2D<T>& B)
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