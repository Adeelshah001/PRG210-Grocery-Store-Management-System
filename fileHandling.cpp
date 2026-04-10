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
    if (!file.is_open())
    {
        cerr << "Error opening file." << endl;
        return 1;
    }

    // If data was already loaded before, free old memory first
    if (StoreDepartments != nullptr)
    {
        delete[] StoreDepartments;
        StoreDepartments = nullptr;
        TotalDepartments = 0;
    }

    string line;

    // Read total number of departments
    getline(file, line);
    TotalDepartments = stoi(line);

    // Create department array
    StoreDepartments = new Department[TotalDepartments];

    // Read each department block
    for (int d = 0; d < TotalDepartments; d++)
    {
        getline(file, line);

        string depName;
        int pCount;

        stringstream ss(line);
        getline(ss, depName, ',');
        ss >> pCount;

        product* p = new product[pCount];

        for (int i = 0; i < pCount; i++)
        {
            getline(file, line);

            string pName;
            double pPrice;
            int pQuantity;

            stringstream productStream(line);
            getline(productStream, pName, ',');
            productStream >> pPrice;
            productStream.ignore();
            productStream >> pQuantity;

            p[i].setProduct(pName.c_str(), pPrice, pQuantity);
        }

        StoreDepartments[d].setDepartmentInfo(depName.c_str(), p, pCount);

        // Delete temporary product array after deep copy into Department
        delete[] p;
    }

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
