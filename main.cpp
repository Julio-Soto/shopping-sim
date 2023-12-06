#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

struct Item {
    unsigned int code;
    std::string description;
    float price;
    bool per_pound;
};

int main() {

    std::string file = "inventory-test.txt";
    std::string bar_delimiter = "|";
    std::string slash_delimiter = "/";
    int delimeter_pos = 0;
    std::string code;

    // Open the file
    std::ifstream inputFile(file);

    // Check if the file is opened successfully
    if (!inputFile.is_open()) {
        std::cerr << "We Will Be Closed For Inventory" << std::endl;
        return 1;  // Exit with an error code
    }

    // Process each line in the file
    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream input_line(line);

        Item item;

        delimeter_pos = line.find(bar_delimiter);
        item.code = stoi(line.substr(0,delimeter_pos));
        line.erase(0,delimeter_pos + 1);

        delimeter_pos = line.find(bar_delimiter);
        item.description = line.substr(0,delimeter_pos);
        line.erase(0,delimeter_pos + 1);

        delimeter_pos = line.find(slash_delimiter);
        if(delimeter_pos != line.npos)
        {
            item.price = stof(line.substr(0,delimeter_pos));
            item.per_pound = true;
        }else
        {
        item.price = stof(line);
        item.per_pound = false;
        }

        std::cout << "Code: " << item.code << std::endl;
        std::cout << "Description: " << item.description << std::endl;
        std::cout << "Price: " << item.price << std::endl;
        if(item.per_pound) std::cout << "Per Pound" << std::endl;
        std::cout << "----------------------" << std::endl;
    }

    // Close the file
    inputFile.close();

    return 0; 
}
