#pragma once
#include <iostream>
#include <string>
using namespace std;


class ErrorOpeningFile :public std::exception {
public:
	ErrorOpeningFile(const char* msg ): exception(msg) {}
};