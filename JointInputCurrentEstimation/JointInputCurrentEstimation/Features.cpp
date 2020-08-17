#include "Features.h"

std::vector < std::vector<double>> Features::joint1_input;
std::vector < std::vector<double>> Features::joint2_input;
std::vector < std::vector<double>> Features::joint3_input;
std::vector<double> Features::joint1_output;
std::vector<double> Features::joint2_output;
std::vector<double> Features::joint3_output;

void Features::develop_features(const std::vector<std::vector<double>> measurements_complete)
{

	for (std::vector<double> measurement_t : measurements_complete)
	{
		
		joint1_input.push_back({ 1, 
								sin_degrees(measurement_t.at(0)), 
								sin_degrees(measurement_t.at(0) + measurement_t.at(1)), 
								sin_degrees(measurement_t.at(0) + measurement_t.at(1) + measurement_t.at(2)),
								cos_degrees(measurement_t.at(0)),
								cos_degrees(measurement_t.at(0) + measurement_t.at(1)),
								cos_degrees(measurement_t.at(0) + measurement_t.at(1) + measurement_t.at(2)) });
		joint2_input.push_back({ 1, 
								sin_degrees(measurement_t.at(0) + measurement_t.at(1)),
								sin_degrees(measurement_t.at(0) + measurement_t.at(1) + measurement_t.at(2)),
								cos_degrees(measurement_t.at(0) + measurement_t.at(1)),
								cos_degrees(measurement_t.at(0) + measurement_t.at(1) + measurement_t.at(2)) });
		joint3_input.push_back({ 1, 
								sin_degrees(measurement_t.at(0) + measurement_t.at(1) + measurement_t.at(2)),
								cos_degrees(measurement_t.at(0) + measurement_t.at(1) + measurement_t.at(2)) });
		joint1_output.push_back(measurement_t.at(3));
		joint2_output.push_back(measurement_t.at(4));
		joint3_output.push_back(measurement_t.at(5));
	}
}

template<typename T1>
double Features::sin_degrees(T1 angle)
{
	return std::sin(angle * PI / 180);
}

template<typename T2>
double Features::cos_degrees(T2 angle)
{
	return std::cos(angle * PI / 180);
}