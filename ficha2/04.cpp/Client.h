#pragma once

#include <string>

using namespace std;

class Client {
public:
	Client(string name, string address);

	string getName() const;
	string getAddress() const;

	void setName(string name);
	void setAddress(string address);
private:
	string name;
	string address;
};