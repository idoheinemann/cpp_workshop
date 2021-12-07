#include <sstream>

#include "complex.h"


Complex::Complex(double real, double imag) : m_real(real), m_imag(imag)
{
}

Complex::Complex(Complex* copy) : m_real(copy->m_real), m_imag(copy->m_imag)
{
}

Complex Complex::operator+(Complex const& other)
{
	Complex copy(this);
	copy.m_real += other.m_real;
	copy.m_imag += other.m_imag;
	return copy;
}

Complex Complex::operator-(Complex const& other)
{
	Complex copy(this);
	copy.m_real -= other.m_real;
	copy.m_imag -= other.m_imag;
	return copy;
}

Complex Complex::operator*(Complex const& other)
{
	Complex copy(this);
	copy.m_real = this->m_real * other.m_real - this->m_imag * other.m_imag;
	copy.m_imag += this->m_real * other.m_imag + this->m_imag * other.m_real;
	return copy;
}

double Complex::getReal()
{
	return this->m_real;
}

void Complex::setReal(double real)
{
	this->m_real = real;
}

double Complex::getImag()
{
	return this->m_imag;
}

void Complex::setImag(double imag)
{
	this->m_imag = imag;
}

Complex::operator std::string() const
{
	std::stringstream s;
	s << this->m_real << "+" << this->m_imag << "i";
	return s.str();
}

std::ostream& operator<<(std::ostream& os, Complex const& m)
{
	return os << std::string(m);
}
