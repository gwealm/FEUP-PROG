#include "Person.h"

int main() {
	Person me("Guilherme", Gender::MALE, Date{ 2020, 12, 16 });
	me.showPerson();
	
	return 0;
}