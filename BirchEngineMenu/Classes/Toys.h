#pragma once
#include <string>

class Toys
{
public:
	Toys(std::string p_name, int p_price, int p_val);
	std::string getName();
	int getPrice();
	int getVal();

private:
	std::string name;
	int price;
	int val;

};

