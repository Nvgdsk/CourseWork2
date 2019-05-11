// CourseWork2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Calculation.h"
#include <iostream>
int main()
{
	Calculation calc;
	const int dim_i = 10, dim_k=15;

	double mainArray[dim_i][dim_k] = {0};
	double x = 0;
	double t = 0;
	for (int i = 0; i < dim_i; i++)
	{
		x = 0;
		for (int k = 0; k < dim_k; k++)
		
		{

			if (i == 0) {
				mainArray[i][k] = calc.getExactResolve(x, t);
			}
			else if (k == 0) {
				mainArray[i][k] = calc.getExactResolve(x, t);
			}
			else if (k == dim_k-1) {
				mainArray[i][k] = calc.getExactResolve(x, t);
			}
			x += calc.tau;
			std::cout << mainArray[i][k] << " ";
		}
		t += calc.h;
		std::cout << std::endl;
	}
	system("pause");
    return 0;
}

