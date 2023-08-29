#pragma once
#include <string>
#include "Dog.h"
#include "Toys.h"
#include <vector>

class Player
{
public:
	Player();
	~Player();
	int time();
	int cash();
	std::vector<Dog> ownedDog;
	std::vector<Dog> availDog;
	std::vector<Toys> availToys;
	float getInc();
	void buyDog(int index);
private:
	int money;
	float inc;


};

