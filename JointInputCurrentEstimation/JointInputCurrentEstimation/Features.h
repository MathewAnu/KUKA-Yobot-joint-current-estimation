#pragma once
#include<vector>
#include<cmath>
#include<iostream>
#include<typeinfo>

const double PI = 3.14159265;

class Features
{
public:
	static std::vector < std::vector<double>> joint1_input, joint2_input, joint3_input;
	static std::vector<double> joint1_output, joint2_output, joint3_output;
	static void develop_features(const std::vector<std::vector<double>> measurements_complete);
	template<typename T1>
	static double sin_degrees(T1 angle);
	template<typename T2>
	static double cos_degrees(T2 angle);
};

