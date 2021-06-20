#pragma once

#include "Client.h"
#include "Item.h"

#include <vector>
#include <iostream>
#include <iomanip>

typedef vector<Item> ItemList;


class Invoice {
public:
	Invoice(const ItemList &purchasedProducts, Client *client);

	ItemList getPurchasedProducts() const;
	Client getClient() const;

	void purchaseProduct(Product &product);
	void purchaseItem(Item &newItem);

	friend ostream& operator<<(ostream& out, const Invoice& invoice);
private:
	ItemList purchasedProducts;
	Client *client;
};