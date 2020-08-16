#pragma once
#include<string>
#include<fstream>
#include<iostream>
#include<boost/algorithm/string.hpp>
#include<vector>


class MeasurementData
{
	static int number_of_measurements;
public:	
	static int get_number_of_measurements();

	std::string filename;
	MeasurementData(std::string filename);
	void read_data();		
	std::vector<std::vector<double>> measurements;	
	std::vector<double> string_to_number(std::vector<std::string> line);
};

