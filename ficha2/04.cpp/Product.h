#pragma once

#include <string>

using namespace std;

class Product {
public:
	Product(string description, double price);

	string getDescription();
	double getPrice();

	void setDescription(string description);
	void setPrice(double price);
	
	bool operator==(const Product& secProd) const;
private:
	string description;
	double price;
};