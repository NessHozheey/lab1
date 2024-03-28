#include "cashier.h"
#include <iostream>
#include <thread>
#include <chrono>

cashier::cashier() {
	std::string names[10] = { "Victor", "Michael", "Victoriya", "Veronika", "Samuel","Gregor", "Lusien", "Angela", "Sandra", "Monica" };
	std::string welcomePhrases[5] = { "Ey buddy! What's up?",
									  "Good Morning! I'm glad to see you here.",
									  "Hey there! Come on in.",
									  "Hello! What brought you to us?",
									  "Greetings! What a wonderful weather today, isn't it?"};
	FirstName = names[rand() % 10];
	WelcomePhrase = welcomePhrases[rand() % 5];
}

void cashier::giveChange(int cash, int price)
{
	std::cout << "\t\t***** " + this->FirstName + " takes the cash... *****\n\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	std::cout << "\n " + this->FirstName + ": " + "Here is your change " + "(" + std::to_string((cash - price)) + "$) please.\n\n";

	} 

void cashier::UseMilkForCoffee(products& Products)
{
	Products.quantityOfMilkML -= 50;
}



std::string cashier::getName()
{
	return FirstName;
}

std::string cashier::getWelcomePhrase()
{
	return	WelcomePhrase;
}

int cashier::getMilkQuantity(products& Products)
{
	return Products.quantityOfMilkML;
}



