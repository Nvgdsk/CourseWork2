#pragma once
class Calculation
{
public:
	int a;
	int b;
	double tau;
	double h;

	Calculation();

	double getExactResolve(double x, double t);
	double getApproximateSolution(double h, double tau, double w_i, double w_i_p, double w_i_m);

	~Calculation();
};

