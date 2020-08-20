#include "Features.h"

template<typename T1, typename T2>
std::vector < std::vector<T2>> Features<T1, T2>::joint1_input;
template<typename T1, typename T2>
std::vector < std::vector<T2>> Features<T1, T2>::joint2_input;
template<typename T1, typename T2>
std::vector < std::vector<T2>> Features<T1, T2>::joint3_input;
template<typename T1, typename T2>
std::vector<T1> Features<T1, T2>::joint1_output;
template<typename T1, typename T2>
std::vector<T1> Features<T1, T2>::joint2_output;
template<typename T1, typename T2>
std::vector<T1> Features<T1, T2>::joint3_output;

template<typename T1, typename T2>
void Features<T1, T2>::develop_features(const std::vector<std::vector<T1>> measurements_complete)
{

	for (std::vector<T1> measurement_t : measurements_complete)
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

template<typename T1, typename T2>
T2 Features<T1, T2>::sin_degrees(T1 angle)
{
	return std::sin(angle * PI / 180);
}

template<typename T1, typename T2>
T2 Features<T1, T2>::cos_degrees(T1 angle)
{
	return std::cos(angle * PI / 180);
}

template class Features<float, double>;
template class Features<float, float>;
template class Features<double, float>;
template class Features<double, double>;
