#pragma once
#include <string>

class client
{
public:
	client();		
	std::string orderDrink();
	void rateService();
	int payForOrder();
	int getMoneyQuantity();


	

private:
	std::string FirstName;
	std::string FavouriteDrink;
	std::string Order;
	int moneyQuantity;

	

};

