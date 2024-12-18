# Лабораторная работа №2

### Задание
Целью данной работы является проектирование класса в языке C++, который осуществляет хранение данных, связанных с экземпляром класса, в динамической памяти. В качестве примера был разработан класс CustomClass, который хранит целочисленное значение и строковое представление этого значения.

### Решение
Класс CustomClass предназначен для хранения пары данных:

- Целочисленное значение (int value).
- Строковое представление числа (char *stringValue), хранящееся в динамической памяти.

Класс содержит необходимые конструкторы: конструктор копирования и перемещения, деструктор, а также перегруженные операторы присваивания (копирования и перемещения). Каждый метод выводит сообщение при своем вызове.

В фалйе main.cpp демонстрируется работа с экземплярами класса CustomClass: создание объектов, передачу их в функции, использование std::vector и std::list.
В функции main создаются:

Статические экземпляры:

    obj1 — конструктор по умолчанию.
    obj2 — параметризованный конструктор с значением 2 и строкой "Two".


Динамический экземпляр:

    pObj — создается с помощью оператора new, значение 3, строка "Three".

Создается массив arr из CustomClass размером 5. Далее массив заполняется объектами, инициализируемыми параметризованным конструктором. Функция processVector обрабатывает и выводит содержимое массива.

Передача по значению:

- Функция functionByValue получает объект CustomClass по значению, что вызывает конструктор копирования.

Передача по ссылке:

- Функция functionByReference получает объект по константной ссылке, конструктор не вызывается.

Возврат объекта по значению:

- Функция createObjectByValue создает локальный объект и возвращает его по значению, что может вызвать конструктор копирования или перемещения.

Возврат объекта по ссылке:

- Функция createObjectByReference модифицирует переданный объект и возвращает ссылку на него.

Вектор myVector:

- С помощью emplace_back добавляются объекты с значениями от 1 до 5.

Список myList:

- Аналогично вектору, добавляются объекты с значениями от 42 до 51.

### Вывод программы
При запуске программы получаем следующий вывод в терминале (вызовы функций из main):
```bash
Processing C-Style Vector
Value: 0, String Value: Number 0
Value: 1, String Value: Number 1
Value: 2, String Value: Number 2
Value: 3, String Value: Number 3
Value: 4, String Value: Number 4
Called function by value
Value: 2, String Value: Two
Called function by reference
Value: 2, String Value: Two
Value: 0, String Value: Zero
Value: 42, String Value: Forty Two
Value: 1, String Value: Vector 1
Value: 2, String Value: Vector 2
Value: 3, String Value: Vector 3
Value: 4, String Value: Vector 4
Value: 5, String Value: Vector 5
Value: 42, String Value: List 42
Value: 43, String Value: List 43
Value: 44, String Value: List 44
Value: 45, String Value: List 45
Value: 46, String Value: List 46
Value: 47, String Value: List 47
Value: 48, String Value: List 48
Value: 49, String Value: List 49
Value: 50, String Value: List 50
Value: 51, String Value: List 51
```

А также логгирование конструкторов (файл constructor_log.txt):
```bash
Default constructor called
Parametrized constructor called, int value 2 str value Two
Parametrized constructor called, int value 3 str value Three
Default constructor called
Default constructor called
Default constructor called
Default constructor called
Default constructor called
Parametrized constructor called, int value 0 str value Number 0
Move assignment called, Move to address 0x61fe34
Destructor called
Parametrized constructor called, int value 1 str value Number 1
Move assignment called, Move to address 0x61fe34
Destructor called
Parametrized constructor called, int value 2 str value Number 2
Move assignment called, Move to address 0x61fe34
Destructor called
Parametrized constructor called, int value 3 str value Number 3
Move assignment called, Move to address 0x61fe34
Destructor called
Parametrized constructor called, int value 4 str value Number 4
Move assignment called, Move to address 0x61fe34
Destructor called
Print method called, int value 0 str value Number 0
Print method called, int value 1 str value Number 1
Print method called, int value 2 str value Number 2
Print method called, int value 3 str value Number 3
Print method called, int value 4 str value Number 4
Copy constructor called, copy to address 0x61fe24
Print method called, int value 2 str value Two
Destructor called
Print method called, int value 2 str value Two
Parametrized constructor called, int value 0 str value Zero
Print method called, int value 0 str value Zero
Parametrized constructor called, int value 4 str value Four
Parametrized constructor called, int value 42 str value Forty Two
Move assignment called, Move to address 0x61fd98
Destructor called
Print method called, int value 42 str value Forty Two
Default constructor called
Copy assignment called, copy to address 0x61fe24
Default constructor called
Move assignment called, Move to address 0x61fe1c
Parametrized constructor called, int value 1 str value Vector 1
Parametrized constructor called, int value 2 str value Vector 2
Move constructor called, move to address 0x10417a0
Destructor called
Parametrized constructor called, int value 3 str value Vector 3
Move constructor called, move to address 0x1041c58
Move constructor called, move to address 0x1041c60
Destructor called
Destructor called
Parametrized constructor called, int value 4 str value Vector 4
Parametrized constructor called, int value 5 str value Vector 5
Move constructor called, move to address 0x1041c88
Move constructor called, move to address 0x1041c90
Move constructor called, move to address 0x1041c98
Move constructor called, move to address 0x1041ca0
Destructor called
Destructor called
Destructor called
Destructor called
Print method called, int value 1 str value Vector 1
Print method called, int value 2 str value Vector 2
Print method called, int value 3 str value Vector 3
Print method called, int value 4 str value Vector 4
Print method called, int value 5 str value Vector 5
Parametrized constructor called, int value 42 str value List 42
Parametrized constructor called, int value 43 str value List 43
Parametrized constructor called, int value 44 str value List 44
Parametrized constructor called, int value 45 str value List 45
Parametrized constructor called, int value 46 str value List 46
Parametrized constructor called, int value 47 str value List 47
Parametrized constructor called, int value 48 str value List 48
Parametrized constructor called, int value 49 str value List 49
Parametrized constructor called, int value 50 str value List 50
Parametrized constructor called, int value 51 str value List 51
Print method called, int value 42 str value List 42
Print method called, int value 43 str value List 43
Print method called, int value 44 str value List 44
Print method called, int value 45 str value List 45
Print method called, int value 46 str value List 46
Print method called, int value 47 str value List 47
Print method called, int value 48 str value List 48
Print method called, int value 49 str value List 49
Print method called, int value 50 str value List 50
Print method called, int value 51 str value List 51
Destructor called
Destructor called
Destructor called
Destructor called
Destructor called
Destructor called
Destructor called
Destructor called
Destructor called
Destructor called
Destructor called
Destructor called
Destructor called
Destructor called
Destructor called
Destructor called
Destructor called
Destructor called
Destructor called
Destructor called
Destructor called
Destructor called
Destructor called
Destructor called
Destructor called
Destructor called
Destructor called

```

### Анализ вывода:

Создание статических экземпляров:

- Default constructor вызывается при создании obj1.
- Parameterized constructor вызывается при создании obj2 c аргументами 2 и "Two".

Создание динамического экземпляра:

- Cоздается динамический объект pObj с помощью параметризованного конструктора - Parameterized constructor.

Создание и заполнение массива (C vector):

- При создании массива объектов вызывается конструктор по умолчанию для каждого элемента - Default constructor (5 раз).
- Создаётся временный объект с помощью параметризованного конструктора - Parameterized constructor.
- Присваивание временного объекта элементу массива arr[i] вызывает оператор присваивания перемещением - Move assignment operator.
- Временный объект уничтожается, вызывается деструктор - Destructor.

(Компиляторы оптимизируют код, используя перемещение вместо копирования, когда это возможно. Поэтому вместо оператора присваивания копированием вызывается оператор присваивания перемещением, поскольку временный объект является rvalue.)

Обработка массива (processCStyleVector(arr, size)):

- Пороисходит обработка масива, функция выводит Processing C-Style Vector и значения для каждого элемента массива.

Передача по значению (functionByValue(obj2)):

- При передаче obj2 по значению вызывается конструктор копирования - Copy constructor, внутри функции выводится Function by value и содержимое объекта, после выхода из функции временный объект уничтожается, вызывается деструктор - Destructor.

Передача по ссылке(functionByReference(obj2)):

- При передаче obj2 по ссылке, копирования не происходит, выводится - Function by reference и выводится содержимое обекта.

Возврат объекта из функции по значению:

- Создаётся локальный объект obj3 с помощью параметризованного конструктора - Parameterized constructor.<br>(Компилятор применяет оптимизацию возврата значений (RVO), поэтому дополнительных конструкторов не вызывается.)
- Вызывается метод print() - выводится содержимое obj3.

Изменение объекта через ссылку:

- Cоздается obj4 - Parameterized constructor.
- Внутри createObjectByReference() Создается временный обект (CustomClass(99, "Ninety-Nine")) - Parameterized constructor.
- Присваивание этого временного объекта вызывает оператор присваивания перемещением - Move assignment operator.
- Временный обект уничтожается - Destructor.
- Выводится обновленное значение objRef.

Оператор присваивания копированием:

- Создается obj5 с помощью конструктора по умолчанию - Default constructor.
- Присваивание obj5 = obj2 вызывает оператор присваивания копированием - Copy assignment operator.

Оператор присваивания перемещением:
- Создается obj6 с помощью конструктора по умолчанию - Default constructor.
- obj6 = std::move(obj3) превращает obj3 в rvalue, поэтому вызывается оператор присваивания перемещением - Move assignment operator.

Создание вектора объектов CustomClass:

- При вызове emplace_back объект создаётся с помощью параметризованного конструктора - Parameterized constructor.
- При добавлении элементов вектор перевыделяет память, ранее созданные элементы перемещаются на новое место с помощью конструктора перемещения - Move constructor.
- Старые объекты уничтожаются, вызывается деструктор - Destructor.
- Выводится содержимое вектора (Value: 5, String Value: Vector 5, ...)

Создание списка объектов CustomClass:

- Список не требует перевыделения памяти, поэтому объекты создаются напрямую с помощью параметризованного конструктора - Parameterized constructor (5 раз).
- Выводется содержимое списка (Value: 10, String Value: List 10, ...).

Удаление динамических объектов:

- Удаление pObj вызывает деструктор - Destructor.
- Удаление массива arr вызывает деструкторы для каждого элемента - Destructor (5 раз).

Завершения program (main.cpp):

- При выходе из main вызываются деструкторы для всех объектов на стеке и в контейнерах (obj1, ... , myVector и myList).<br>
  (Количество вызовов зависит от числа созданных объектов.)

### Вывод

В результате лабораторной работы был создан класс CustomClass, демонстрирующий использование различных конструкторов, деструкторов, а также механизмов копирования и перемещения в C++. Был проведен анализ полученного вывода работы программы и разбор работы компилятора.