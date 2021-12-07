#pragma once

#include <string>

class Complex {
public:
	/// <summary>
	/// initializes a complex number
	/// </summary>
	/// <param name="real">the real part of the number</param>
	/// <param name="imag">the imaginary part of the number</param>
	Complex(double real, double imag);

	/// <summary>
	/// copy constructor for complex
	/// </summary>
	explicit Complex(Complex* copy);

	/// <summary>
	/// sums two imaginary numbers
	/// </summary>
	/// <param name="other">the other imaginary to sum</param>
	/// <returns>sum of the two numbers</returns>
	Complex operator+ (Complex const& other);
	
	/// <summary>
	/// substructs an imaginary number from this number
	/// </summary>
	/// <param name="other">the other imaginary to substruct</param>
	/// <returns>this number minus the other one</returns>
	Complex operator- (Complex const& other);

	/// <summary>
	/// multiplies two imaginary numbers
	/// </summary>
	/// <param name="other">the other imaginary</param>
	/// <returns>product of the two numbers</returns>
	Complex operator* (Complex const& other);
	
	/// <summary>
	/// real part of this number
	/// </summary>
	double getReal();
	/// <summary>
	/// sets the real part of this number
	/// </summary>
	/// <param name="real">new real part</param>
	void setReal(double real);

	/// <summary>
	/// imaginary part of this number
	/// </summary>
	double getImag();
	/// <summary>
	/// sets the imaginary part of this number
	/// </summary>
	/// <param name="imag">new imaginary part</param>
	void setImag(double imag);

	/// <summary>
	/// to string method
	/// </summary>
	operator std::string() const;
	
	
private:
	double m_real;
	double m_imag;
};

std::ostream& operator<<(std::ostream& os, Complex const& m);