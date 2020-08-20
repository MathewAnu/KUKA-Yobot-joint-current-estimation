#include "MeasurementData.h"

template<typename T>
int MeasurementData<T>::number_of_measurements = 0;

template<typename T>
MeasurementData<T>::MeasurementData(std::string filename)
{
	this->filename = filename;
}

template<typename T>
void MeasurementData<T>::read_data()
{
	std::ifstream file(filename);
	if (file.is_open())
	{
		std::string line_to_split;
		while (std::getline(file, line_to_split))
		{
			std::vector<std::string> line_strings;
			boost::split(line_strings, line_to_split, boost::is_any_of(","));
			measurements.push_back(string_to_number(line_strings));
			number_of_measurements++;
		}
		file.close();
	}

}

template<typename T>
std::vector<T> MeasurementData<T>::string_to_number(std::vector<std::string> line)
{	
	std::vector<T> measurement_vector_t;
	for (std::string str : line)
	{
		measurement_vector_t.push_back(std::stod(str));
	}

	return measurement_vector_t;
}

template<typename T>
int MeasurementData<T>::get_number_of_measurements()
{
	return number_of_measurements;
}

template class MeasurementData<float>;
template class MeasurementData<double>;
