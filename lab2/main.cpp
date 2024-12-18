#include "CustomClass.hpp"
#include <vector>
#include <list>

// Create object and return it by value
CustomClass createObjectByValue() {
    CustomClass obj(0, "Zero");
    return obj;
}

// Modify object passed by reference
CustomClass& createObjectByReference(CustomClass &obj) {
    obj = CustomClass(42, "Forty Two");  // Assign new value
    return obj;
}

// Process C vector of CustomClass objects
void processVector(CustomClass *arr, size_t size) {
    std::cout << "Processing C-Style Vector" << std::endl;
    for (size_t i = 0; i < size; ++i) {
        arr[i].print();
    }
}

// Function accepting CustomClass by value
// (CustomClass obj) <- this makes a new copy of obj that exists in the scope of the function
// e.g. a constructor is called
void functionByValue(CustomClass obj) {
    std::cout << "Called function by value" << std::endl;
    obj.print();
}

// Function accepting CustomClass by reference
// (const CustomClass &obj) <- this uses obj by its reference
// e.g. no constructor is called
void functionByReference(const CustomClass &obj) {
    std::cout << "Called function by reference" << std::endl;
    obj.print();
}

int main() {
    // Create static instances
    CustomClass obj1;
    CustomClass obj2(2, "Two");

    // Create dynamic instance
    CustomClass *pObj = new CustomClass(3, "Three");

    // Create and process C-Style vector
    size_t size = 5;
    CustomClass *arr = new CustomClass[size];
    for (size_t i = 0; i < size; ++i) {
        arr[i] = CustomClass(static_cast<int>(i), ("Number " + std::to_string(i)).c_str());
    }
    processVector(arr, size);

    // First calls copy constructor, second doesn't
    functionByValue(obj2);
    functionByReference(obj2);

    // Copy or move constructor
    CustomClass obj3 = createObjectByValue();
    obj3.print();

    // Modify and return by reference
    CustomClass obj4(4, "Four");
    CustomClass &objRef = createObjectByReference(obj4);
    objRef.print();

    // Copy assignment operator
    CustomClass obj5;
    obj5 = obj2;
    // Move assignment operator
    CustomClass obj6;
    obj6 = std::move(obj3);

    // Create vector of CustomClass instances
    std::vector<CustomClass> myVector;
    for (int i = 1; i < 6; ++i) {
        myVector.emplace_back(i, ("Vector " + std::to_string(i)).c_str());
    }

    for (const auto &item : myVector) {
        item.print();
    }

    // Create list of CustomClass instances
    std::list<CustomClass> myList;
    for (int i = 42; i < 52; ++i) {
        myList.emplace_back(i, ("List " + std::to_string(i)).c_str());
    }

    for (const auto &item : myList) {
        item.print();
    }

    // Clean dynamic memory
    delete pObj;
    delete[] arr;

    return 0;
}

