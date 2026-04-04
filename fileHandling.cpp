#include "fileHandling.h"
#include <sstream>

// StoreDepartments
// This will point to the dynamic array of departments in memory.
Department* StoreDepartments = nullptr;

// TotalDepartments
// This stores how many departments exist in the store.
int TotalDepartments = 0;

// csv File path
const char* csvFile = "grocery.csv";

// The following function loads all grocery store data from the CSV file
// CSV expected format:
// 1 - total number of departments
// 2 - DepartmentName, totalItems in department
// 3 - Item 1 Name, Price, Quantity
//  ...etc
// Example:
// 2
// Produce, 3
// Apples, 2.99, 10
// Bananas, 1.49, 15
// Oranges, 3.25, 8

int loadDataFromCsv(const char* filePath)
{
    // Open the file for reading
    ifstream file(filePath);

    // Check if the file opened successfully
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    // This string will temporarily store each line from the file
    string line;

    // Read the first line of the file which stores the total number of departments
    getline(file, line);

    // Convert that line from string to int
    TotalDepartments = stoi(line);

    // Create a dynamic array of Department objects
    StoreDepartments = new Department[TotalDepartments];

    // READ EACH DEPARTMENT
    for (int d = 0; d < TotalDepartments; d++)
    {
        // Read one department header line
        getline(file, line);

        // Temporary variables for department data
        string depName;
        int pCount;

        // Use stringstream to split the line by comma
        stringstream ss(line);

        // Read department name up to the comma
        getline(ss, depName, ',');

        // Read the product count after the comma
        ss >> pCount;

        // Make a dynamic array of products for this department
        product* p = new product[pCount];

        // READ ALL PRODUCTS IN THIS DEPARTMENT
        for (int i = 0; i < pCount; i++)
        {
            // Read one product line
            getline(file, line);

            // Temporary variables for one product
            string pName;
            double pPrice;
            int pQuantity;

            // Use stringstream to split the product line
            stringstream productStream(line);

            // Read product name up to the first comma
            getline(productStream, pName, ',');

            // Read price
            productStream >> pPrice;

            // Ignore the comma after price
            productStream.ignore();

            // Read quantity
            productStream >> pQuantity;

            // Store the values in the product object
            p[i].setProduct(pName.c_str(), pPrice, pQuantity);
        }

        // Save the department name, product array, and item count into the current Department object

        // ***ENSURE THIS IS THE SAME DEPARTMENT CLASS FUNCTION NAME IN THE DEPARTMENT .H AND .CPP FILE AND THEN DELETE THESE 3 COMMENT LINES***
        // ***This assumes your Department class has a function:***
        // ***setDepartmentInfo(const char*, product*, int)***
        StoreDepartments[d].setDepartmentInfo(depName.c_str(), p, pCount);
    }

    // Close the file
    file.close();
    return 0;
}

// This function saves all current grocery store data back into the CSV file
int saveDataToCsv(const char* filePath)
{
    // Open the file for writing
    ofstream file(filePath);

    // Check if the file opened successfully
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    // WRITE TOTAL DEPARTMENTS
    file << TotalDepartments << endl;


    // WRITE EACH DEPARTMENT
    for (int d = 0; d < TotalDepartments; d++)
    {
        // ***NOTE: DELETE THESE COMMENTS ONCE YOU ENSURE THE FUNCTION NAMES ARE THE SAME***
        // ***The lines below assume your Department class has:***
        // ***getDepartmentName()***
        // ***getTotalItems()***
        // ***getProducts()***
        // ***If your group used different names,***
        // ***only these function names need to be changed.***

        // Write department header line
        file << StoreDepartments[d].getDepartmentName() << ","
             << StoreDepartments[d].getTotalItems() << endl;

        // Get the product array and item count for this department
        product* p = StoreDepartments[d].getProducts();
        int pCount = StoreDepartments[d].getTotalItems();

        // Write each product line
        for (int i = 0; i < pCount; i++)
        {
            // productName, price, quantity
            file << p[i].getName() << ","
                 << p[i].getPrice() << ","
                 << p[i].getQuantity() << endl;
        }
    }
    // Close the file
    file.close();
    return 0;
}