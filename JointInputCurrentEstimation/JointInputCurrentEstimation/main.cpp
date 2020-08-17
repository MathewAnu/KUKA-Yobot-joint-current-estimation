#include "Settings.h"
#include "MeasurementData.h"
#include<iostream>
#include<vector>
#include "Features.h"


int main()
{
	std::vector<std::vector<double>> measurements_complete;

	for (std::string file : measurement_files)
	{
		MeasurementData md(file);
		md.read_data();
		measurements_complete.insert(measurements_complete.end(), md.measurements.begin(), md.measurements.end());
	}
	std::cout << MeasurementData::get_number_of_measurements()<<std::endl;

	Features::develop_features(measurements_complete);
	for (double value : Features::joint3_output)
		{
			std::cout << value << std::endl;
		}
	//perform regression
	return 0;
}
