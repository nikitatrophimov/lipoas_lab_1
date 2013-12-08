/*
 * Example
 *
 * Input data:
 * interval begin - 0
 * interval end - 1
 *
 * Output:
 * 0.739085
 */

#include <cmath>
#include <iostream>

// Функция, для которой мы будем применять метод половинного деления
// В данном случае используется функция x - cos(x)
double some_func(double x)
{
	return x - std::cos(x);
}

int main()
{
	std::cout << "This program shows an example of bisection method usage in C++ for the \"x - cos(x)\" function \n"
			  << "Author: Trophimov N. A. \n\n";

	std::cout << "Enter interval begin = ";
	double interval_begin;
	std::cin >> interval_begin;

	std::cout << "Enter interval end = ";
	double inverval_end;
	std::cin >> inverval_end;

	double middle = (interval_begin + inverval_end) / 2;

	while (std::fabs(inverval_end - interval_begin) > std::numeric_limits<double>::epsilon() && some_func(middle) != 0.0)
	{
		if (some_func(interval_begin) * some_func(middle) < 0)
		{
			inverval_end = middle;
		}
		else
		{
			interval_begin = middle;
		}
		middle = (interval_begin + inverval_end) / 2;
	}

	std::cout << "Answer = " << middle << '\n';
}
