#include "Item.h"


Item::Item(Product* product, unsigned int quantity) {
	this->product = product;
	this->quantity = quantity;
}


Product Item::getProduct() const {
	return *product;
}


unsigned int Item::getQuantity() const {
	return quantity;
}


double Item::getPrice() const {
	return this->product->getPrice() * this->quantity;
}


void Item::setQuantity(unsigned int quantity) {
	this->quantity = quantity;
}