#ifndef _INTEGRA_H
#define _INTEGRA_H

#include<functional>

#include<utility>
#include<vector>
#include<random>



class Integral
{
	static size_t N;
	static double epsilon;
	static std::size_t seed;
	static std::seed_seq seeds;

	static void generate_rnd(std::vector<std::uniform_real_distribution<double>>&, std::mt19937_64& mer, std::vector<double>&);
public:
	static void set_steps(const size_t&& n) { N = n; }
	static void set_epsilon(const double&& eps) { epsilon = eps; }
	static double integrate_basic_1d(std::pair<double, double>& bounds, std::function<double(double)>& function);
	static double integrate_basic_2d(std::vector<std::pair<double, double>>& bounds, std::function<double(double, double)>& function);
	static double trapez_rule_1D(std::pair<double, double>& bounds, std::function<double(double)>& function);
	static double montecarlo_1D(std::pair<double, double>& bounds, std::function<double(double)>& function);
	static double montecarlo_2D(std::vector<std::pair<double, double>>& bounds, std::function<double(double, double)>& function);

	static double monteND(std::vector<std::pair<double, double>>& bounds, std::function<double(std::vector<double>&)>&);
};

#endif


