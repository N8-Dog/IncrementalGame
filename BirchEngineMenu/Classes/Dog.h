#pragma once
#include <string>
class Dog
{public:
	Dog(int p_inc, int p_price, std::string p_name, std::string p_race);
	~Dog();

	std::string getName();
	std::string getRace();
	int getPrice();
	int getInc();

private:
	int inc;
	int price;
	std::string name;
	std::string race;
};

