#pragma once
#include <exception>
using namespace std;

class Connect4Exception : public exception
{
public:
	Connect4Exception(const char* msg) : exception(msg) {};
};

