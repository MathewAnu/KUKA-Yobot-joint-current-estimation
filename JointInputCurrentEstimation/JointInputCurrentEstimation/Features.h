#pragma once
#include<vector>
#include<cmath>
#include<iostream>
#include<typeinfo>

const double PI = 3.14159265;

template<typename T1, typename T2>
class Features
{
public:
	static std::vector < std::vector<T2>> joint1_input, joint2_input, joint3_input;
	static std::vector<T1> joint1_output, joint2_output, joint3_output;
	static void develop_features(const std::vector<std::vector<T1>> measurements_complete);
	static T2 sin_degrees(T1 angle);
	static T2 cos_degrees(T1 angle);
};

