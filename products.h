#pragma once
#include <string>

class products
{
public:
	std::string getCurrentPrice(int position);
	std::string getCurrentPosition(int position);
	void getMenu();
	products();	
	
	friend class cashier;
	friend class HeadCasher;

private:
	int quantityOfMilkML;
	std::string menu[5][2] = {
		{"latte", "4"},
		{"americano", "2"},
		{"espresso", "1"},
		{"cacao", "3"},
		{"cappuccino", "4"}
	};
	

	
	

};

