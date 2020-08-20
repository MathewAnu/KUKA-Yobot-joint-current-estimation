#include "Settings.h"
#include "MeasurementData.h"
#include<iostream>
#include<vector>
#include "Features.h"


int main()
{
	typedef float measurement_type;
	std::vector<std::vector<measurement_type>> measurements_complete;

	for (std::string file : measurement_files)
	{
		MeasurementData<measurement_type>  md(file);
		md.read_data();
		measurements_complete.insert(measurements_complete.end(), md.measurements.begin(), md.measurements.end());
	}
	std::cout << MeasurementData<measurement_type>::get_number_of_measurements()<<std::endl;

	Features<measurement_type, double>::develop_features(measurements_complete);
	
	//perform regression
	return 0;
}
