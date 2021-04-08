#include "integra.h"


double integrate_basic_1d(std::pair<double, double>& bounds, std::function<double(double)>& function)
{
	const unsigned int N = 10000;
	const double epsilon = 1e-4;
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

double integrate_basic_2d(std::vector<std::pair<double, double>>& bounds, std::function<double(double, double)>& function)
{
	const int N = 5000;
	double epsilon = 1e-3;
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
	else return -1;
}
