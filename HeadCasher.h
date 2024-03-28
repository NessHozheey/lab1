#pragma once
#include "cashier.h"
class HeadCasher : public cashier
{
public:
	HeadCasher();
	void fillTheMilk(products& Products);
	

private:
	std::string firstName;
	int a;
};

