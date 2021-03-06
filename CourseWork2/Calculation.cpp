#include "stdafx.h"
#include "Calculation.h"



Calculation::Calculation()
{
	Calculation::a = 4;
	Calculation::b = 5;
	Calculation::tau = 0.0001;
	Calculation::h = 0.1;
}

double Calculation::getExactResolve(double x, double t)
{
	double result = (Calculation::a - x) / (Calculation::b + t);
	return result;
}

double Calculation::getApproximateSolution(double h, double tau , double w_i, double w_i_p, double w_i_m)
{
	double result = ((w_i_m - 2 * w_i + w_i_p) * tau / (h * h)) + (w_i*tau*(w_i_p - w_i_m) / (2 * h)) + w_i;
	return result;
};

Calculation::~Calculation()
{
}
