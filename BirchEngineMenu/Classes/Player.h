#pragma once
#include <string>
#include "Dog.h"
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
	float getInc();
	
private:
	int money;
	float inc;


};
