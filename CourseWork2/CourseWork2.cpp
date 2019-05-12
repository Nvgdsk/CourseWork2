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
	
	
	int countThread = 4;
	const int row = 1000, column=100;
	double **mainArray = new double *[row];
	for (int i= 0; i < row; i++)
	{
		mainArray[i] = new double[column];
	}
	
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
			
			from = to;
		}
		for (int z = 0; z < threadVector.size(); z++)
		{
			threadVector[z].join();
		}
	
		t += calc.tau;


	}

	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << "time parallel: " << duration << std::endl;
	///
	std::ofstream out;

	double sumParallel = 0;
	out.open("array.txt", std::ios_base::trunc);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			sumParallel += mainArray[i][j];
			out << mainArray[i][j] << " ";
		}
		out << std::endl;
	}
	out.close();
	start = std::clock();
	for (int i = 0; i < row; i++)
	{
		x = 0;
		from = 0;
		
	
		countVal( x, t, mainArray, from, column, column, i);

		

		t += calc.tau;

		
	
	}
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << "time: " << duration << std::endl;
	out.open("array2.txt", std::ios_base::trunc);
	double sum = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			sum += mainArray[i][j];
			out << mainArray[i][j] << " ";
		}
		out << std::endl;
	}
	out.close();
	std::cout << "SumP: " << sumParallel << std::endl;
	std::cout << "Sum: " << sum << std::endl;
	std::cout << "mistake: " << std::abs(sum-sumParallel)/(row*column) << std::endl;
	system("pause");
    return 0;
}

