#include "Settings.h"
#include "MeasurementData.h"
#include<iostream>
#include<vector>



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
	
	//develop features
	//perform regression
	return 0;
}
