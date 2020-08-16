#include "MeasurementData.h"


int MeasurementData::number_of_measurements = 0;

MeasurementData::MeasurementData(std::string filename)
{
	this->filename = filename;
}

int MeasurementData::get_number_of_measurements()
{
	return number_of_measurements;
}

void MeasurementData::read_data()
{
	std::ifstream file(filename);
	if (file.is_open())
	{
		std::string line_to_split;
		while (std::getline(file, line_to_split))
		{
			std::vector<std::string> line;
			boost::split(line, line_to_split, boost::is_any_of("\t"));
			measurements.push_back(string_to_number(line));
			number_of_measurements++;
		}
		file.close();
	}

}

std::vector<double> MeasurementData::string_to_number(std::vector<std::string> line)
{	
	std::vector<double> measurement_vector_t;
	for (std::string str : line)
	{
		measurement_vector_t.push_back(std::stod(str));
	}

	return measurement_vector_t;
}