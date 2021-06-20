#include "Invoice.h"


Invoice::Invoice(const ItemList& purchasedProducts, Client* client) {
	this->purchasedProducts = purchasedProducts;
	this->client = client;
}


ItemList Invoice::getPurchasedProducts() const {
	return purchasedProducts;
}


Client Invoice::getClient() const {
	return *client;
}


void Invoice::purchaseProduct(Product& product) {
	for (Item& item : purchasedProducts) {
		if (item.getProduct() == product) {
			// If the product exists, buys one more
			item.setQuantity(item.getQuantity() + 1); return;
		}
	}
	// If the product does not exist, buys it
	purchasedProducts.push_back(Item{ &product, 1 });
}


void Invoice::purchaseItem(Item& newItem) {
	for (Item& item : purchasedProducts) {
		if (item.getProduct() == newItem.getProduct()) {
			item.setQuantity(item.getQuantity() + newItem.getQuantity());
			return;
		}
	}
	purchasedProducts.push_back(newItem);
}


ostream& operator<<(ostream& out, const Invoice& invoice) {
	double total = 0;
	ItemList purchasedProducts = invoice.getPurchasedProducts();
	Client client = invoice.getClient();

	out << fixed << setprecision(2) << left
		<< "Client: " << client.getName()    << "\n"
		<< "Address: "<< client.getAddress() << "\n\n";
		
	if (!purchasedProducts.empty()) {
		out << setw(19) << "Description" << setw(7) << "Price" << setw(6) << "Qty" << setw(8) << "Total" << endl
			<< right << setfill('-') << setw(19) << " " << setw(7) << " " << setw(6) << " " << setw(8) << " " << endl;
	} else {
		out << "The shopping cart is empty!" << endl;
	}
	for (const Item& item : purchasedProducts) {
		total += item.getPrice();
		out << left << setfill(' ')
			<< setw(19) << item.getProduct().getDescription()
			<< setw(7)  << item.getPrice()
			<< right << setw(5)  << item.getQuantity()
			<< setw(8)  << item.getPrice() * item.getQuantity() << "\n";
		
	}
	out << "\nAmount due: " << total << "euro" << endl;
	return out;
}