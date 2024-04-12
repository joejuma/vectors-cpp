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
	this->t{} = this->t{} + B;
	return (*this);
};