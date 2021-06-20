#include "Client.h"

Client::Client(string name, string address) {
	this->name = name;
	this->address = address;
}


string Client::getName() const {
	return name;
}


string Client::getAddress() const {
	return address;
}


void Client::setName(string name) {
	this->name = name;
}


void Client::setAddress(string address) {
	this->address = address;
}