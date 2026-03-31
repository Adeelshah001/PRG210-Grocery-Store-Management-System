#include "product.h"
#include <iostream>
#include <cstring>
using namespace std;

// default constructor
product::product() {
    //default name
    strcpy(productName, "NA");
    //defalt price
    productPrice = 0.0;
    //default quantity
    productQuantity = 0;
}

// 3-arg constructor
product::product(const char name[], double price, int quantity) {
    //using setProduct function to assign the name, price, quantity
    setProduct(name, price, quantity);
}

// set functions
//set all product info
void product::setProduct(const char name[], double price, int quantity) {
    setName(name);
    setPrice(price);
    setQuantity(quantity);
}
//set product name, name cannot be empty, if given name is not valid, use 'NA'
void product::setName(const char name[]){
    // if name is null or empty string
    if (name == nullptr || name[0] == '\0'){
        strcpy(productName, "NA");
    }
    else { //copy name into product with last character as null terminator
        strncpy(productName, name, name_size - 1);
        productName[name_size - 1] = '\0';
    }
}

// get functions
//get name
const char* product::getName() const {
    return productName;
}
//get price
double product::getPrice() const {
    return productPrice;
}
//get quantity
int product::getQuantity() const {
    return productQuantity;
}

//display function
void product::display() const {
    cout << "Product Name: " << productName << endl;
    cout << "Price: $" << productPrice << endl;
    cout << "Quantity: " << productQuantity << endl;
}