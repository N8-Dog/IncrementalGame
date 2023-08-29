#include "Toys.h"

Toys::Toys(std::string p_name, int p_price, int p_val): name(p_name), price(p_price), val(p_val)
{
}

std::string Toys::getName()
{
	return name;
}

int Toys::getPrice()
{
	return price;
}

int Toys::getVal()
{
	return val;
}
