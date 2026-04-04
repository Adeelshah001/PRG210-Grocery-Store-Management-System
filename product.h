#pragma once
class product {
    private:
    // static product name size 
    static const int name_size = 100;
    // product name intialized with name_size
    char productName[name_size];
    // product price stores as double.
    double productPrice;
    // int product quantity 
    int productQuantity;

    public:
    //default constructor
    product();
    // 3-arg constructor
    product(const char name[], double price, int quantity);

    // set functions
    // set product information
    void setProduct(const char name[], double price, int quantity);
    // set product name
    void setName(const char name[]);
    // set product price
    void setPrice(double price);
    // set product quantity
    void setQuantity(int quantity);

    // get functions
    // return product name
    const char* getName() const;
    // return product price
    double getPrice() const;
    // return product quantity
    int getQuantity() const;

    //display function
    // will display product details
    void display() const;
};