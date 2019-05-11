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
		if (i == 0 || from == 0 || to == column) {
			mainArray[i][j] = calc.getExactResolve(x, t);
		}

		else {
			mainArray[i][j] = calc.getApproximateSolution(i, j, mainArray[i - 1][j], mainArray[i - 1][j + 1], mainArray[i - 1][j - 1]);
		}
		
		x += calc.h;
	}

}


int main()
{
	
	double duration;
	std::clock_t start;
	

	/* Your algorithm here */

	

	
	
	int countThread = 5;
	const int row = 10, column=10;
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
		from = 0;
		std::vector <std::thread>  threadVector;
		for (int j = 0; j < countThread; j++)
		{
			
			if (j == (countThread-1))
			{
				to = column;
			}
			else {
				to = temp*(j+1);
			}
			double temp_x = (x + calc.h) * from;
			threadVector.emplace_back(std::thread(countVal, temp_x,t,mainArray,from,to,column,i));
			std::cout << temp_x << " " << t << " " << from << " " << to << "  " << i << std::endl;
			from = to;
		}
		for (int z = 0; z < threadVector.size(); z++)
		{
			threadVector[z].join();
		}
	
		t += calc.tau;

		/*for (int j = 0; j < column; j++)
		{
			out << mainArray[i][j] << " ";
		}*/
		/*out << std::endl;*/
	}

	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	/*out.close();*/
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			std::cout << mainArray[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "time: " << duration << std::endl;
	system("pause");
    return 0;
}

