#include "products.h"
#include <iostream>

products::products()
{
	srand(time(NULL));
	quantityOfMilkML = rand() % 100;

}


std::string products::getCurrentPrice(int position) {
	return menu[position][1];
}

std::string products::getCurrentPosition(int position) {
	return menu[position][0];
}

void products::getMenu()
{
	int i = 1;

	std::cout << "===================================================================================\n";


	std::cout << "========================\t       MENU\t\t===========================\n";

	for (auto& item : menu)
	{	
		
		std::cout <<"========================  " + std::to_string(i) + ". " + item[0] + "\t\t" + '$' + item[1] + "\t===========================" << std::endl;
		i++;
	}

	std::cout << "===================================================================================\n";
}