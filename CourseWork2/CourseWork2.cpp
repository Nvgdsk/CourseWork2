// CourseWork2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Calculation.h"
#include <iostream>
#include <fstream>

int main()
{
	Calculation calc;
	const int dim_i = 10, dim_k=10;
	double mainArray[dim_i][dim_k] = {0};
	std::ofstream out;
	out.open("array.txt", std::ios::app);
	double x = 0;
	double t = 0;

	for (int i = 0; i < dim_i; i++)
	{
		x = 0;
		for (int k = 0; k < dim_k; k++)
		
		{

			if (i == 0  || k == 0|| k == dim_k - 1)  {
				mainArray[i][k] = calc.getExactResolve(x, t);
			}
			
			else {
				mainArray[i][k] = calc.getApproximateSolution(i, k, mainArray[i - 1][k], mainArray[i - 1][k + 1], mainArray[i - 1][k - 1]);
			}
			x += calc.tau;
			std::cout << mainArray[i][k] << " ";
			out << mainArray[i][k] << " ";
		}
		t += calc.h;
		std::cout << std::endl;
		out << std::endl;
	}

	out.close();
	system("pause");
    return 0;
}

