#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "product.h"
#include "department.h"
using namespace std;

// Dynamic array that will hold all departments loaded from the CSV file.
extern Department* StoreDepartments;

// Stores the total number of departments in the grocery store.
extern int TotalDepartments;

// Stores the path of the CSV file.
extern const char* csvFile;

// Opens the CSV file, reads all department and product data, and stores it into the program's dynamic arrays.
// Returns: 0 = success, 1 = failed to open file
int loadDataFromCsv(const char* filePath);

// Writes all current department and product data back into the CSV file.
// Returns: 0 = success, 1 = failed to open file
int saveDataToCsv(const char* filePath);