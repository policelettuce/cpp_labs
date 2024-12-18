#ifndef CUSTOMCLASS_HPP
#define CUSTOMCLASS_HPP

#include <iostream>

class CustomClass {
private:
    int value;
    char *stringValue;

public:
    // Default constructor
    CustomClass();

    // Parameterized constructor
    CustomClass(int val, const char *str);

    // Copy constructor
    CustomClass(const CustomClass &other);

    // Move constructor
    CustomClass(CustomClass &&other) noexcept;

    // Copy assignment operator
    CustomClass& operator=(const CustomClass &other);

    // Move assignment operator
    CustomClass& operator=(CustomClass &&other) noexcept;

    // Destructor
    ~CustomClass();

    // Method to print the data
    void print() const;

    bool operator<(const CustomClass& other) const {
        return value < other.value;
    }

    bool operator>(const CustomClass& other) const {
        return value > other.value;
    }

    bool operator==(const CustomClass& other) const {
        return value == other.value;
    }

    bool isOdd() const {
        return value % 2 != 0;
    }

};

#endif // CUSTOMCLASS_HPP
