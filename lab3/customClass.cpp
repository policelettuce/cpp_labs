#include "customClass.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

// write log message to constructor_log.txt file
void writeLog(const string & log) {
    // Append, not rewrite!
    ofstream logFile("constructor_log.txt", std::ios::app);
    if (!logFile) {
        std::cerr << "Error opening file!" << std::endl;
    }
    logFile << log << endl;
    logFile.close();
}

// Default constructor
CustomClass::CustomClass() : value(0), stringValue(nullptr) {
    writeLog("Default constructor called");
}

// Parametrized constructor
CustomClass::CustomClass(int val, const char * str) : value(val) {
    ostringstream oss;
    oss << "Parametrized constructor called, int value " << val << " str value " << str;
    writeLog(oss.str());
    if (str) {
        stringValue = new char[strlen(str) + 1];
        strcpy(stringValue, str);
    } else {
        stringValue = nullptr;
    }
}

// Copy constructor
CustomClass::CustomClass(const CustomClass & other) : value(other.value) {
    ostringstream oss;
    oss << "Copy constructor called, copy to address " << &other;
    writeLog(oss.str());
    if (other.stringValue) {
        stringValue = new char[strlen(other.stringValue) + 1];
        strcpy(stringValue, other.stringValue);
    } else {
        stringValue = nullptr;
    }
}

// Move constructor
CustomClass::CustomClass(CustomClass && other) noexcept : value(other.value), stringValue(other.stringValue) {
    ostringstream oss;
    oss << "Move constructor called, move to address " << &other;
    writeLog(oss.str());
    other.stringValue = nullptr;
}

// Copy assignment operator
CustomClass& CustomClass::operator=(const CustomClass & other) {
    ostringstream oss;
    oss << "Copy assignment called, copy to address " << &other;
    writeLog(oss.str());
    if (this != &other) {
        delete[] stringValue;
        value = other.value;
        if (other.stringValue) {
            stringValue = new char[strlen(other.stringValue) + 1];
            strcpy(stringValue, other.stringValue);
        } else {
            stringValue = nullptr;
        }
    }
    return *this;
}

// Move assignment operator
CustomClass& CustomClass::operator=(CustomClass && other) noexcept {
    ostringstream oss;
    oss << "Move assignment called, Move to address " << &other;
    writeLog(oss.str());
    if (this != &other) {
        delete[] stringValue;
        value = other.value;
        stringValue = other.stringValue;
        other.stringValue = nullptr;
    }
    return *this;
}

// Destructor
CustomClass::~CustomClass() {
    writeLog("Destructor called");
    delete[] stringValue;
}

// Print method
void CustomClass::print() const {
    ostringstream oss;
    oss << "Print method called, int value " << value << " str value " << stringValue;
    writeLog(oss.str());
    std::cout << "Value: " << value << ", String Value: ";
    if (stringValue) {
        std::cout << stringValue;
    } else {
        std::cout << "nullptr";
    }
    std::cout << std::endl;
}
