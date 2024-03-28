#pragma once
#include <string>
#include "products.h"


class cashier
{
public:
	cashier();
	void giveChange(int cash, int price);
	std::string getName();
	std::string getWelcomePhrase();
	int getMilkQuantity(products& Products);
	void UseMilkForCoffee(products& Products);

	
	


private:
	std::string FirstName;
	std::string WelcomePhrase;
	




};

