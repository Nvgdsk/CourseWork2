#include "stdafx.h"
#include "Calculation.h"



Calculation::Calculation()
{
	Calculation::a = 4;
	Calculation::b = 5;
}

double Calculation::getExactResolve(double x, double t)
{
	double result = (Calculation::a - x) / (Calculation::b + x);
	return result;
}

Calculation::~Calculation()
{
}
