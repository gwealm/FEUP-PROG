#include "Product.h"

Product::Product(string description, double price) {
	this->description = description;
	this->price = price;
}

string Product::getDescription() {
	return description;
}


double Product::getPrice() {
	return price;
}


void Product::setDescription(string description) {
	this->description = description;
}


void Product::setPrice(double price) {
	this->price = price;
}


bool Product::operator==(const Product& secProd) const {
	return (description == secProd.description && price == secProd.price);
}