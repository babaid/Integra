#ifndef _INTEGRA_H
#define _INTEGRA_H

#include<functional>
#include<concepts>
#include<utility>
#include<vector>



double integrate_basic_1d(std::pair<double, double>& bounds, std::function<double(double)>& function);
double integrate_basic_2d(std::vector<std::pair<double, double>>& bounds, std::function<double(double, double)>& function);
class Integral
{



};

//template<typename T>
//concept Number = std::integral<T> || std::floating_point<T>;

template<typename T>
double multi_integrate(T&&, std::function<double(double ...)> function);


#endif



template<typename T>
inline double multi_integrate(std::vector<std::pair<double, double>>& bounds, std::function<double(double...)> function)
{
	const int N = 1000;
	std::vector<double> steps;
	for (auto& a : bounds) steps.push_back((a.first - a.second) / N);


	return 0.0;
}
