#pragma once

#include "Date.h"

#include <string>


using namespace std;


enum class Gender : char { 
		MALE		= 'M',
		FEMALE		= 'F',
		OTHER		= 'O',
};


class Person {
public:
	Person(string name, Gender gender, Date birthdate);

	void setName(string &name);
	void setGender(Gender &gender);

	string getName() const;
	Gender getGender() const;
	Date getBirthdate() const;

	void showPerson() const;
	
private:
	string name;
	Gender gender;
	Date birthdate;
};