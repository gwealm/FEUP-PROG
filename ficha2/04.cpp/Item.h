#pragma once

#include "Product.h"

class Item {
public:
	Item(Product* product, unsigned int quantity);

	Product getProduct() const;
	unsigned int getQuantity() const;
	double getPrice() const;
	
	void setQuantity(unsigned int quantity);
private:
	Product *product;
	unsigned int quantity;
};