// CourseWork2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Calculation.h"
#include <iostream>
#include <fstream>
#include <thread>

Calculation calc;

void countVal(float x, float t, double** mainArray, int from, int to, int column, int i)
{
	for (int j = from; j < to; j++)
	{
		if (i == 0 || from == 0 || from == column - 1) {
			mainArray[i][j] = calc.getExactResolve(x, t);
		}

		else {
			mainArray[i][j] = calc.getApproximateSolution(i, j, mainArray[i - 1][j], mainArray[i - 1][j + 1], mainArray[i - 1][j - 1]);
		}
		
		x += calc.tau;
	}

}


int main()
{
	
	int countThread = 5;
	const int row = 1000, column=100;
	double **mainArray = new double *[row];
	for (int i= 0; i < row; i++)
	{
		mainArray[i] = new double[column];
	}
	std::ofstream out;
	out.open("array.txt", std::ios::app);
	double x = 0;
	double t = 0;

	for (int i = 0; i < row; i++)
	{
		x = 0;
		countVal(x, t,mainArray,0, column, column,i);
		t += calc.h;

		for (int j = 0; j < column; j++)
		{
			out << mainArray[i][j] << " ";
		}
		out << std::endl;
	}

	out.close();
	system("pause");
    return 0;
}

