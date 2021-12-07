#include "calculator.h"

double Calculator::add(double x, double y) {
	return x + y;
}

double Calculator::substruct(double x, double y) {
	return x - y;
}

double Calculator::multiply(double x, double y) {
	return x * y;
}

double Calculator::divide(double x, double y) {
	if (y == 0.0) {
		throw CalculatorException::DIVIDE_BY_ZERO;
	}
	return x / y;
}

double Calculator::calculate(double x, char op, double y) {
	switch (op) {
	case '+':
		return this->add(x, y);
	case '-':
		return this->substruct(x, y);
	case '*':
		return this->multiply(x, y);
	case '/':
		return this->divide(x, y);
	default:
		throw CalculatorException::UNKNOWN_OPERATION;
	}
}