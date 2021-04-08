#include<iostream>
#include<cmath>
#include "integra.h"


double f(double x, double y) { return x * x + y; }

int main()
{
	std::function<double(double, double)> fun = f;
	std::vector<std::pair<double, double>> bound{ { 0., 1. }, {0., 1.} };
	std::cout << integrate_basic_2d(bound, fun) << std::endl;
}