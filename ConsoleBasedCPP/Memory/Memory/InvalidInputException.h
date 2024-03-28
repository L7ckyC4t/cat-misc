#pragma once
#include <exception>

using namespace std;

class InvalidInputException : public exception
{
public:
	InvalidInputException(const char* msg) : exception(msg) {};

};