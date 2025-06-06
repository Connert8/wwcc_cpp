#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "Product.h"
using namespace std;

class Inventory {
private:
    vector<Product> products;

public:
    Inventory();

    void getAllProducts() const;
    void getOutOfStock() const;
    void getLowStock() const;

    void addProduct(const Product& product);

    void updateProductInfo();
    void calculateTotalValue(const Product& product);


};


#endif
