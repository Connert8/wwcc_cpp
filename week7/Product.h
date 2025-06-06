#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

class Product{
private:
    string name;
    string id;
    double price;
    int quantity;

public:
    Product();
    Product(string n, string i, double p, int q);

    string getProductName() const;
    string getProductId() const;
    double getProductPrice() const;
    int getProductQuantity() const;
    void getWholeProduct() const;

    void setProductName(string n);
    void setProductId(string i);
    void setProductPrice(double p);
    void setProductQuantity(int q);

    void addStock(int q);
    void removeStock(int q);


};


#endif

