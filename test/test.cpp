#include<iostream>
#include<cmath>
#include<chrono>
#include<thread>
#include "../include/integra.h"


double f1(std::vector<double>& p) { return p[0] * p[0] + p[1]; }
double f2(std::vector<double>& p) { return p[0] * p[0]; }
double f3(double p) { return p * p; }
double f4(double x, double y) { return x * x + y; }

void int_1d(std::function<double(double)> fun)
{

	std::pair<double, double> bound{ 0., 1. };
	auto start = std::chrono::high_resolution_clock::now(), end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed{ 0. }, elapsed2{ 0. };
	size_t n = 50;
	for (size_t i = 0; i < n; i++) {

		start = std::chrono::high_resolution_clock::now();;
		double integ_mont = Integral::montecarlo_1D(bound, fun);
		end = std::chrono::high_resolution_clock::now();
		elapsed += end - start;

		start = std::chrono::high_resolution_clock::now();
		double integ_basic = Integral::trapez_rule_1D(bound, fun);
		end = std::chrono::high_resolution_clock::now();;
		elapsed2 += end - start;
	}
	std::cout << "Monte Carlo time: " << elapsed.count() / n << " s" << std::endl << "Trapezoid rule: " << elapsed2.count() / n << " s" << std::endl;;
}

void int_2d(std::function<double(double, double)> fun)
{
	std::vector<std::pair<double, double>> bounds{ { -1., 1. },{0., 1.} };
	auto start = std::chrono::high_resolution_clock::now(), end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed{ 0. }, elapsed2{ 0. };
	size_t n = 20;
	for (size_t i = 0; i < n; i++) {

		start = std::chrono::high_resolution_clock::now();;
		double integ_mont = Integral::montecarlo_2D(bounds, fun);
		end = std::chrono::high_resolution_clock::now();
		elapsed += end - start;

		start = std::chrono::high_resolution_clock::now();
		double integ_basic = Integral::integrate_basic_2d(bounds, fun);
		end = std::chrono::high_resolution_clock::now();
		elapsed2 += end - start;
	}
	std::cout << "Monte Carlo time: " << elapsed.count() / n << " s" << std::endl << "Basic quadrature: " << elapsed2.count() / n << " s" << std::endl;;
}


int main()
{
	std::function<double(std::vector<double>& p)> fun1 = f1;
	std::function<double(std::vector<double>&)> fun2 = f2;
	std::function<double(double p)> fun3 = f3;
	std::function<double(double, double)> fun4 = f4;
	
	

	std::thread th1(int_1d, f3);
	std::thread th2(int_2d, f4);

	std::vector<std::pair<double, double>> bound{ {0., 1.} };
	std::vector<std::pair<double, double>> bounds{ {0., 1.}, {0., 1.} };
	double res = Integral::monteND(bound, fun2);
	std::cout << "Multidimensional  Montecarlo: "<< res << std::endl;

	th1.join();
	th2.join();

	return 0;
}