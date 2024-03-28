#include "client.h"
#include <random>
#include <iostream>

client::client()
{
	srand(time(NULL));				

	std::string names[10] = { "Victor", "Michael", "Victoriya", "Veronika", "Samuel","Gregor", "Lusien", "Angela", "Sandra", "Monica"};
	std::string drinks[5] = { "latte", "americano", "espresso", "hot chocolate", "cappuccino" };

	FirstName = names[(rand() % 10)];
	FavouriteDrink = drinks[rand() % 5];
	moneyQuantity = 5;
}



std::string client::orderDrink()
{
	std::cout << "I want to order" + FavouriteDrink << std::endl;

	Order = FavouriteDrink;

	return Order;
}

void client::rateService()
{

}

int client::payForOrder()
{
	int oldMoneyQuantity = moneyQuantity;
	moneyQuantity = 0;

	std::cout << "\t***** You handing your " + std::to_string(oldMoneyQuantity) + "$ " + "banknote to cashier. *****\n\n";
	
	return oldMoneyQuantity;
}

int client::getMoneyQuantity()
{
	return moneyQuantity;
}
