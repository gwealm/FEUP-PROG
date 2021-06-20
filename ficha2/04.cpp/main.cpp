#include "Invoice.h"

using namespace std;

int main() {
	Client me("Guilherme Almeida", "OPorto");

	Product RPi("Raspberry Pi", 65.60);
	Item octoPi(&RPi, 10);
	ItemList purchasedProds = { octoPi };

	Invoice invoice(purchasedProds, &me);

	cout << invoice << endl;

	Product keyboard("Keyboard", 99.99);
	invoice.purchaseProduct(keyboard);

	cout << invoice;

	return 0;
}