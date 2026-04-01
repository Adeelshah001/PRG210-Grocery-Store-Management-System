#pragma once
#include "product.h"


class Cart
{
private:
    product* items;   // Dynamic array of products in cart
    int* quantities;  // Corresponding quantities for each product
    int totalItems;        // Number of unique product entires in cart
    double totalCost;  // Total cost indlucing 13% tax

    int findProductIndex(const char* productName) const;
    void resizeAndAdd(const product& product, int quantity);
    void updateTotalCost();

public:
    Cart();
    Cart(const Cart& other);
    Cart& operator=(const Cart& other);
    ~Cart();

    void addItem(const product& product, int quantity);
    void listItems() const;
    void checkout();
    void clear();

    bool isEmpty() const;
    int getTotalItems() const;
    double getSubtotal() const;
    double getTax() const;
    double getTotalCost() const; 
};