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

double Calculation::getApproximateSolution(int i, int k, double h, double tau, double w_i, double w_i_p, double w_i_m)
{
	double result = ((w_i_m - 2 * w_i + w_i_p) * tau / (h * h)) + (w_i*tau*(w_i_p - w_i_m) / (2 * h)) + w_i;
	return result;
};

Calculation::~Calculation()
{
}
