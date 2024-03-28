#include <iostream>
#include <chrono>
#include <thread>
#include "products.h"
#include "client.h"
#include "cashier.h"
#include "headCasher.h"
using namespace std;

void wait() {
	std::this_thread::sleep_for(chrono::milliseconds(800));
}


void main() {
	products Products;
	client Me;
	cashier Cashier;
	HeadCasher HeadCashier;
	cout << "=========================================================================================\n";
	cout << "============================   Welcome to the Coffee Shop!   ============================\n";
	cout << "=========================================================================================\n\n";
	wait();
	cout << "                          Your cashier`s name today is: " + Cashier.getName() + '.' + '\n';
	cout << "                     ------------------------------------------------\n\n\n";
	wait();

	cout << ' ' + Cashier.getName() + ": " + Cashier.getWelcomePhrase() + "\n\n";
	wait();

	int answer;


	cout << "1: Get menu\n";
	cout << "2: Go away\n\n";
	cout << "Your choose: ";
	cin >> answer;

	switch (answer)
	{
	case 1:
		cout << "\n";
		cout << " You: Hey, I just want to look at menu.\n\n";
		wait();
		cout << ' ' + Cashier.getName() + ": " + "Ok, feel yourself comfortable =)\n\n\n";
		wait();
		Products.getMenu();
		break;
	case 2: 

		cout << "\n You: Oops, wrong door, sorry. Goodbye!\n\n";
		return;
	
	default:
		return;
	}

	cout << "\n\nChecking wallet...\n";
	wait();
	wait();
	cout << "Your balance is: " + to_string(Me.getMoneyQuantity()) + '$';
	wait();
	wait();

	cout << "\n\n " + Cashier.getName() + ": " + "What do you prefer today ? (1 - 5)\n";
	
	cout << "\nYour choose: ";
	cin >> answer;
	
	int positionPrice = stoi(Products.getCurrentPrice(answer - 1));
	string ChosenDrink = Products.getCurrentPosition(answer - 1);
	int milkQuantity = Cashier.getMilkQuantity(Products);
	
	if (Me.getMoneyQuantity() >= positionPrice) {
		cout << "\n You: I want to order " + ChosenDrink + ".\n";
	}
	else {
		cout << "\n You: It would be cool to order " + ChosenDrink + ", but i can't afford it. Goodbye!\n\n";
		return;
	}
	wait();
	cout << "\n " + Cashier.getName() + ": " + "Ok, it'll be ready in a minute...\n\n";
	wait();
	wait();

	if (answer == 1 || answer == 4 || answer == 5) {
		cout << "\t***** " + Cashier.getName() + " is checking, if it's enough milk for it... *****\n\n";
		wait();
		wait();
		cout << "\t***  Quantity of milk is: " + to_string(milkQuantity) + "ml" + " (your drink needs 50ml)..." + " ***\n\n";
		wait();
		wait();

		if (Cashier.getMilkQuantity(Products) >= 50) {

			cout << "\t** " + Cashier.getName() + " made your drink, and now filling it with milk... **\n\n";
			Cashier.UseMilkForCoffee(Products);
			milkQuantity = Cashier.getMilkQuantity(Products);
			wait();
			wait();
			cout << "\t\t***** (Quantity of milk now is: " + to_string(milkQuantity) + "ml.)... *****\n\n";
			wait();
			cout << " " + Cashier.getName() + ": " + "Here is your " + ChosenDrink + "!\n\n\n";
			wait();
			wait();
			int cash = Me.payForOrder();
			wait();
			wait();
			Cashier.giveChange(cash, positionPrice);
			wait();
			wait();
			cout << " You: Thanks, have a nice day!\n\n";

			return;
		}

		else {
			cout << "\n " + Cashier.getName() + ": I'm sorry, it's not enough milk for your drink, i'll call our head cashier ";
			
			cout << HeadCashier.getName() + "...\n";
			wait();
			wait();
			wait();
			wait();
			cout << "\n " + HeadCashier.getName() + ": " + "Greetings! My name is " + HeadCashier.getName() + ", i will finish your drink =)\n";
			wait();
			wait();
			cout << "\n\t***** " + HeadCashier.getName() + " is replenishing milk supplies... *****\n\n";
			HeadCashier.fillTheMilk(Products);
			milkQuantity = HeadCashier.getMilkQuantity(Products);
			wait();
			wait();
			cout << "\t*****  Updated quantity of milk is: " + to_string(milkQuantity) + "ml ... *****\n\n";
			wait();
			wait();
			wait();

			cout << "\t** " + HeadCashier.getName() + " made your drink, and now filling it with milk... **\n\n";
			HeadCashier.UseMilkForCoffee(Products);
			milkQuantity = HeadCashier.getMilkQuantity(Products);
			wait();
			wait();
			cout << "\t***** (Quantity of milk now is: " + to_string(milkQuantity) + "ml.)... *****\n\n";
			wait();
			cout << " " + HeadCashier.getName() + ": " + "Here is your " + ChosenDrink + "!\n\n\n";
			wait();
			int cash = Me.payForOrder();
			wait();
			wait();
			Cashier.giveChange(cash, positionPrice);
			wait();
			wait();
			cout << " You: Thanks, have a nice day!\n\n";
		
			return;

		}

		
	}

	cout << "\t\t***** " + Cashier.getName() + " is making " + ChosenDrink + "... *****\n\n";
	wait();
	wait();
	wait();

	cout << " " + Cashier.getName() + ": " + "Your tasty drink is ready!\n\n";
	wait();
	wait();
	int cash = Me.payForOrder();
	wait();
	wait();
	Cashier.giveChange(cash, positionPrice);
	wait();
	wait();
	cout << " You: Thanks, have a nice day!\n\n";
	wait();

	return;






	
	

}