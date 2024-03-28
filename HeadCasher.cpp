#include "HeadCasher.h"


void HeadCasher::fillTheMilk(products& Products)
{
	Products.quantityOfMilkML = 1000;
}

HeadCasher::HeadCasher() {
	std::string names[4] = { "Leonid", "Sofia", "Pedro", "Maximillian"};
	firstName = names[rand() % 4];
}