#include "../include/Integra.h"
#include<random>
#include<algorithm>
size_t Integral::N = 5000;
double Integral::epsilon = 1e-3;
std::size_t Integral::seed = 29973456;

double Integral::integrate_basic_1d(std::pair<double, double>& bounds, std::function<double(double)>& function)
{
	
	double step = (bounds.second - bounds.first) / N;
	double sup_sum{ 0 }, inf_sum{ 0 };
	for (size_t i = 0; i < N; ++i)
	{
		sup_sum += step * function((i + 1) * step);
		inf_sum += step * function(i * step);
	}

	if (std::abs(sup_sum - inf_sum) < epsilon) return (inf_sum + sup_sum) / 2;
	else return -1;

}

double Integral::integrate_basic_2d(std::vector<std::pair<double, double>>& bounds, std::function<double(double, double)>& function)
{
	
	
	std::vector<double> steps;
	for (auto& a : bounds) steps.push_back((a.second - a.first) / N);
	double sup_sum{ 0 }, inf_sum{ 0 };
	for (std::size_t i = 0; i < N; i++) {
		for (std::size_t j = 0; j < N; j++)
		{
			sup_sum += steps[0] * steps[1] * function(i * steps[0], j * steps[1]);
			inf_sum += steps[0] * steps[1] * function((i + 1) * steps[0], (j + 1) * steps[1]);
		}
	}

	if (std::abs(sup_sum - inf_sum) < epsilon) return inf_sum;
	else return std::numeric_limits<double>::max();
}

double Integral::trapez_rule_1D(std::pair<double, double>& bounds, std::function<double(double)>& function)
{
	double step = (bounds.second - bounds.first) / N;
	double sum{ 0 };
	for (size_t i = 0; i < N; ++i)
	{
		sum += (function((i + 1) * step) + function(i * step)) * step / 2;
	}
	return sum;
}

double Integral::montecarlo_1D(std::pair<double, double>& bounds, std::function<double(double)>& function)
{

	std::mt19937 engine(seed);
	std::uniform_real_distribution<double> distribution(bounds.first, bounds.second);
	double sum{ 0.0 };

	for (size_t i = 0; i < N; i++) sum += function(distribution(engine))/N;
	return sum;
}

double Integral::montecarlo_2D(std::vector<std::pair<double, double>>& bounds, std::function<double(double, double)>& function)
{

	std::mt19937_64  engine1(std::random_device{}());
	std::mt19937_64 engine2(std::random_device{}());
	std::uniform_real_distribution<double> dist1(bounds[0].first, bounds[0].second);
	std::uniform_real_distribution<double> dist2(bounds[1].first, bounds[1].second);

	double sum{ 0. };
	for (size_t i = 0; i < N; i++)
	{
		sum += function(dist1(engine1), dist2(engine2)) / N ;
	}

	return sum;
}


double Integral::monteND(std::vector<std::pair<double, double>>& bounds, std::function<double(std::vector<double>&)>&function)
{

	double sum{ 0. };
	std::mt19937_64 engine(std::random_device{}());
	std::vector<std::uniform_real_distribution<double>> dist;
	std::vector<double> vars;
	for (auto& b : bounds)
	{
		dist.push_back(std::uniform_real_distribution<double>(b.first, b.second));
	}
	for (size_t i = 0; i < N; i++)
	{
		generate_rnd(dist,engine, vars);
		sum += function(vars)/N;
	}
	return sum;
}

void Integral::generate_rnd(std::vector<std::uniform_real_distribution<double>>& dist, std::mt19937_64& mer, std::vector<double>& res)
{
	for (auto& elem : dist) res.push_back(elem(mer));
}