#include <iostream>
#include <map>
#include <string>

std::map<std::string, int> variables; // Variable storage

int main() {
    std::string input;

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);

        if (input == "exit") {
            break;
        } else if (input.find("print ") == 0) {
            // Print command
            std::string varName = input.substr(6);
            if (variables.find(varName) != variables.end()) {
                std::cout << variables[varName] << std::endl;
            } else {
                std::cout << "Undefined variable: " << varName << std::endl;
            }
        } else if (input.find('=') != std::string::npos) {
            // Assignment
            size_t pos = input.find('=');
            std::string varName = input.substr(0, pos);
            int value = std::stoi(input.substr(pos + 1));
            variables[varName] = value;
        } else if (input.find('+') != std::string::npos) {
            // Addition
            size_t pos = input.find('+');
            std::string varName1 = input.substr(0, pos);
            std::string varName2 = input.substr(pos + 1);

            if (variables.find(varName1) != variables.end() && variables.find(varName2) != variables.end()) {
                int result = variables[varName1] + variables[varName2];
                variables[varName1] = result;
            } else {
                std::cout << "Undefined variable(s): ";
                if (variables.find(varName1) == variables.end()) {
                    std::cout << varName1 << " ";
                }
                if (variables.find(varName2) == variables.end()) {
                    std::cout << varName2;
                }
                std::cout << std::endl;
            }
        } else {
            std::cout << "Invalid input" << std::endl;
        }
    }

    return 0;
}
