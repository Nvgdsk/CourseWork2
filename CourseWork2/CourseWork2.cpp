// CourseWork2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Calculation.h"
#include <iostream>
#include <fstream>
#include <thread>
#include <ctime>
#include <vector>

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
	
	double duration;
	std::clock_t start;
	

	/* Your algorithm here */

	

	
	
	int countThread = 5;
	const int row = 1000, column=1000;
	double **mainArray = new double *[row];
	for (int i= 0; i < row; i++)
	{
		mainArray[i] = new double[column];
	}
	/*std::ofstream out;
	out.open("array.txt", std::ios::app);*/
	double x = 0;
	double t = 0;
	int from = 0;
	int to = 0;
	int temp = (column / countThread);
	start = std::clock();
	 
	for (int i = 0; i < row; i++)
	{
		x = 0;
		for (int j = 0; j < countThread; j++)
		{
			std::vector <std::thread>  threadVector;
			if (j == (countThread-1))
			{
				to = column;
			}
			to = (j + 1)*temp;
			threadVector.emplace_back(std::thread(countVal,x*from,t,mainArray,from,to,column,i));
			for (int i = 0; i < threadVector.size(); i++)
			{
				threadVector[i].join();
			}
			from = to;
		}
		
		t += calc.h;

		/*for (int j = 0; j < column; j++)
		{
			out << mainArray[i][j] << " ";
		}*/
		/*out << std::endl;*/
	}
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	/*out.close();*/
	std::cout << "time: " << duration << std::endl;
	system("pause");
    return 0;
}

