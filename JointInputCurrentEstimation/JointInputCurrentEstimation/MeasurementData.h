#pragma once
#include<string>
#include<fstream>
#include<iostream>
#include<boost/algorithm/string.hpp>
#include<vector>
#include<array>

template<typename T>
class MeasurementData
{
	static int number_of_measurements;
public:	
	static int get_number_of_measurements();

	std::string filename;
	MeasurementData(std::string filename);
	void read_data();		
	std::vector<std::vector<T>> measurements;	
	std::vector<T> string_to_number(std::vector<std::string> line);
};


