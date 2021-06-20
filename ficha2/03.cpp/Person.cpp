#include "Person.h"


Person::Person(string name, Gender gender, Date birthdate) {
	this->name = name;
	this->birthdate = birthdate;
	this->gender = gender;
}


void Person::setName(string& name) { this->name = name; }


void Person::setGender(Gender& gender) { this->gender = gender; }


Date Person::getBirthdate() const { return birthdate; }


Gender Person::getGender() const { return gender; }


string Person::getName() const { return name; }


void Person::showPerson() const {
	Gender gender = getGender();
	string genderDisplay;
	switch (gender) {
	case Gender::MALE:						// Male
		genderDisplay = "Male";
		break;
	case Gender::FEMALE:					// Female
		genderDisplay = "Female";
		break;
	case Gender::OTHER:						 // Non-Binary 
		genderDisplay = "Non-Binary";
		break;
	}

	cout << "Name: " << getName() << endl
		<< "Gender: " << genderDisplay << endl
		<< "Birthdate: ";
	getBirthdate().show();
}