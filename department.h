#pragma once
#include "product.h"

// The Department class stores:
// - department name
// - dynamic array of product objects
// - the number of products in that department

class Department{
private:
  char departmentName[50]; // fixed-size character array for departmentr
  product* items;          // dynamic array of products
  int totalItems;          // number of products currently stored

  // helper function to copy constructor and assignment operator
  // Ensures deep copying of dynamic memory
  void copyFrom(const Department& other);

public: 
  Department();                                    // default constructor: initializes the empty department
  Department(const char* name);                    // constructor that sets the department name
  Department(const Department& other);             // copy constructor: performs deep copy
  Department& operator=(const Department& other);  // assignment operator: deep copy with clean up
  ~Department();                                   // destructor: frees dynamic memory

  void setDepartmentInfo(const char* nane, product* products, int count);   // used by fileHandling.cpp to load department data from CSV 
                                                                            // copies the name, product array, and product count into this object

  const char* getDepartmentName() const;  // returns department name (read only)
  int getTotalItems() const;              // returns number of products in this departmente
  product* getProducts() const;           // return pointer to internal product array (used by CSV savings)
  void addItem(const product& p);         // adds a new product by resizing the dynamic array
  void listItems() const;                 // prints all items in this department (for manager/customr menus)
};


