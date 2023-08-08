#include "Dog.h"


Dog::Dog(int p_inc, int p_price, std::string p_name, std::string p_race) : inc(p_inc), price(p_price), name(p_name), race(p_race) {

}
Dog::~Dog() {

}

std::string Dog::getName() {
	return name;
}
std::string Dog::getRace() {
	return race;
}
int Dog::getPrice() {
	return price;
}
int Dog::getInc() {
	return inc;
}