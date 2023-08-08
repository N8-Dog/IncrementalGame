#include "Player.h"
#include<windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

Player::Player(): money(100), inc(1)
{
	char bufferName[256];
	char bufferBreed[256];
	int fileInc = 2;
	int filePrice;

	std::ifstream dogStream;
	dogStream.open("Classes/init.dog", std::ifstream::in);

	/*if (dogStream.is_open() == true) std::cout << "lolololol" << std::endl;*/

	while (fileInc < 70) 
	{

		filePrice = fileInc * fileInc;
		dogStream.getline(bufferName, 256);
		/*std::cout << "ligne : " << bufferName;*/
		dogStream.getline(bufferBreed, 256);
		if (ownedDog.empty() == true) ownedDog.push_back(Dog(0, 0, bufferName, bufferBreed));
		else availDog.push_back(Dog(fileInc, filePrice, bufferName, bufferBreed));

		fileInc = fileInc *2;
	}

	//std::cout << "Owned dog : " << std::endl;
	//for (auto elem : ownedDog) {
	//	std::cout << "    name :" << elem.getName() << std::endl;
	//	std::cout << "    breed :" << elem.getRace() << std::endl;
	//	std::cout << "    price :" << elem.getPrice() << std::endl;
	//	std::cout << "    inc :" << elem.getInc() << std::endl;
	//}
	//std::cout << "Available dog : " << std::endl;
	//for (auto elem : availDog) {
	//	std::cout << "    name :" << elem.getName() << std::endl;
	//	std::cout << "    breed :" << elem.getRace() << std::endl;
	//	std::cout << "    price :" << elem.getPrice() << std::endl;
	//	std::cout << "    inc :" << elem.getInc() << std::endl;
	//}
}

Player::~Player()
{
}

int Player::time() {
	//Sleep(1000);
	money += inc;
	std::cout << cash() << std::endl;
	return money;
}

int Player::cash() {
	return money;
}

float Player::getInc() {
	return inc;
}

