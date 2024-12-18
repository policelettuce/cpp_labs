# Лабораторная работа №1
### Задание
Разработать программу, которая вводит с клавиатуры два или три типа
данных, и в качестве результата выводит в файл функцию, в которой будут
созданы и проинициализированы переменные указанных типов, а также
осуществлены арифметические операции над этими переменными с
последующим выводом результата.

### Реузльтат
Исходный код генератора функций представлен в файле **generator.cpp**. Данная программа принимает на вход аргументы
 от пользователя посредством ввода в терминал. Программа принимает на вход 2 или 3 типа данных, а также их значения,
после чего генерирует файл **function.cpp**, который содержит программу, выполняющую базовые арифметические операции
со введенными переменными.

 - Пример компиляции генератора с помощью g++:
```bash
g++ generator.cpp -o generator
```
 - Запуск генераторра:
```bash
.\generator
```
 - Пример ввода данных в консоль и вывода программы генератора:
```bash
Enter two or three data types: int float double
Enter values for the specified data types: 1 25 100
+++ function.cpp is generated successfully! +++
```
 - Для этих данных будет сгенерирована данная программа в файле function.cpp:
```c++
#include <iostream>

int main() {
    int var1 = 1;
    float var2 = 25;
    double var3 = 100;
    std::cout << "var1 + var2 = " << (var1 + var2) << std::endl;
    std::cout << "var2 + var3 = " << (var2 + var3) << std::endl;
    std::cout << "var1 + var3 = " << (var1 + var3) << std::endl;
    std::cout << "var1 - var2 = " << (var1 - var2) << std::endl;
    std::cout << "var2 - var3 = " << (var2 - var3) << std::endl;
    std::cout << "var1 - var3 = " << (var1 - var3) << std::endl;
    std::cout << "var1 / var2 = " << (var1 / var2) << std::endl;
    std::cout << "var2 / var3 = " << (var2 / var3) << std::endl;
    std::cout << "var1 / var3 = " << (var1 / var3) << std::endl;
    std::cout << "var1 * var2 = " << (var1 * var2) << std::endl;
    std::cout << "var2 * var3 = " << (var2 * var3) << std::endl;
    std::cout << "var1 * var3 = " << (var1 * var3) << std::endl;
    return 0;
}
```
 - Скомпилируем сгенерированную программу и запустим:
```bash
g++ function.cpp -o function
.\function
```
 - Вывод сгенерированной программы:
```c++
var1 + var2 = 26
var2 + var3 = 125
var1 + var3 = 101
var1 - var2 = -24
var2 - var3 = -75
var1 - var3 = -99
var1 / var2 = 0.04
var2 / var3 = 0.25
var1 / var3 = 0.01
var1 * var2 = 25
var2 * var3 = 2500
var1 * var3 = 100
```

Программа также поддерживает оператор модуля (%), если все введенные типы данных являются типом int:
```bash
Enter two or three data types: int int
Enter values for the specified data types: 10 25
+++ function.cpp is generated successfully! +++
```
 - Результирующая программа:
```c++
#include <iostream>

int main() {
    int var1 = 10;
    int var2 = 25;
    std::cout << "var1 + var2 = " << (var1 + var2) << std::endl;
    std::cout << "var1 - var2 = " << (var1 - var2) << std::endl;
    std::cout << "var1 / var2 = " << (var1 / var2) << std::endl;
    std::cout << "var1 * var2 = " << (var1 * var2) << std::endl;
    std::cout << "var1 % var2 = " << (var1 % var2) << std::endl;
    return 0;
}
```
 - Вывод скомпилированной function.cpp:
```c++
var1 + var2 = 35
var1 - var2 = -15
var1 / var2 = 0
var1 * var2 = 250
var1 % var2 = 10
```