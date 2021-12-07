#pragma once
#include <iostream>
#include <string>

class DivideByZeroException : public std::exception {
	using std::exception::exception;
};

class UnknownOperatorException : public std::exception {
	using std::exception::exception;
};

class Calculator final {
public:
	/**
	* calculates x + y
	*/
	double add(double x, double y) const;
	/**
	* calculates x - y
	*/
	double substruct(double x, double y) const;
	/**
	* calculates x / y
	* @throws CalculatorException::DIVIDE_BY_ZERO if y is 0
	*/
	double divide(double x, double y) const;
	/**
	* calculates x * y
	*/
	double multiply(double x, double y) const;
	/**
	* performs the opetation between the two given numbers
	* @param x: first number
	* @param opertaion: opertaion (as char): +, -, *, /
	* @param y: second number
	* @throws CalculatorException::UNKNOWN_OPERTAION if operation is unknown
	*/
	double calculate(double x, char operation, double y) const;
};