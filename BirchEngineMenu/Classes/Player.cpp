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

	dogStream.close();
	std::ifstream toyStream;
	int toyPrice = 100;
	int toyVal = 1;

	toyStream.open("Classes/init.toys", std::ifstream::in);

	if (toyStream.is_open()) {
		int i = 1;
		while (i < 7) {
			toyStream.getline(bufferName, 256);
			availToys.push_back(Toys(bufferName, toyPrice, toyVal));
			toyVal *= ++i;
			toyPrice *= i * 2;
		}
		toyStream.close();
	}
	else {
		std::cout << "Error: Could not open the file." << std::endl;
	}
	//// Define a string to store each line from the file
	//std::string line;

	//// Read and process each line in the file
	//while (std::getline(inputFile, line)) {
	//	// Do something with the line (e.g., print it)
	//	
	//}

	//// Close the file when you're done with it
	//inputFile.close();

	//for (auto elem : availToys) {
	//	std::cout << elem.getname() << std::endl;
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

void Player::buyDog(int index) {
	if (money > availDog.at(index).getPrice()) {
		inc += availDog.at(index).getInc();
		money -= availDog.at(index).getPrice();
		ownedDog.push_back(availDog.at(index));
		availDog.erase(availDog.begin() + index);
		std::cout << "purchase completed" << std::endl;
	}
	else std::cout << "not enough mounaye" << std::endl;
	
}

