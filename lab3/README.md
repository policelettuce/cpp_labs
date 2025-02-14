# Лабораторная работа №3

### Задание
Задание состоит из последовательности связанных между собой пунктов.
Главная задача: для каждого пункта решить сформулированную в нём
задачу наиболее эффективно**.Для подавляющего, кроме, возможно,
первого пункта применение циклов не будет считаться корректным
решением.

1. Создать вектор v1 размером от 500 до 1000 элементов, число
   элементов не известно до запуска программы. Элементами вектора
   являются экземпляры класса из Л.Р. №2 имеющие
   произвольные(случайные) значения. В случае необходимости этот
   класс должен быть доработан для возможности решать
   поставленные в этой ЛР задачи.
2. Создать вектор v2, поместив в него последние 200 элементов
   вектора v1. Рассмотрите решение для произвольных b и e, которые
   задают позиции первого и последнего копируемых элементов.
3. Сформировать список list1, поместив в него первые n (от 20 до 50)
   наибольших элементов вектора v1 (указанные элементы должны
   быть отсортированы до помещения их в список).
4. Сформировать список list2, поместив в него последние n (от 20 до 50) наименьших элементов вектора v2, порядок элементов не важен.
5. Удалить из векторов v1 и v2 перемещенные элементы.
   Скорректируйте размеры векторов после удаления из них элементов.
6. Для списка list1 найти элемент со средним значением.
   Перегруппировать элементы списка так, чтобы в начале оказались
   все элементы, большие среднего значения.
7. Удалите из списка list2 все нечётные элементы (или используйте
   другой критерий, который однозначно делит экземпляры вашего
   класса на два непересекающихся множества).
8. Создайте вектор v3 из элементов, которые присутствуют и в векторе
   v1 и в векторе v2.
9. Для списков list1 и list2 из списка с большим числом элементов
   удалите первые n так, чтобы оба списка имели бы одинаковый
   размер. Сформируйте из них список list3, который будет хранить
   пары &lt;первый элемент списка list1, первый элемент списка list2&gt;,
   &lt;второй элемент списка list1, второй элемент списка list2&gt; и т. д.

10. Решите предыдущую задачу для векторов v1 и v2 без
    предварительного приведения векторов к одному размеру. Пар с
    пустыми значениями быть не должно.

Оформить отчёт и загрузить по принятым правилам.
** Будем под эффективностью понимать решение, использующее
минимальный код, и не выполняющее лишних действий.

## Решение

Класс CustomClass из ЛР2 был модифицированн добавлением следующего кода
```cpp
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
```
Это необходимо для работы последующих алгоритмов, использующих операторы сравнения.

В задании явно не указано требование самостоятельной реализации алгоритмов, а главная задача звучит как решить сформулированную задачу наиболее эффективно, исходя из чего использование стандартном библиотеки С++ algorithm не запрещено.

### Задание 1 
Создать вектор v1 размером от 500 до 1000 элементов, число элементов не известно до запуска программы. Элементами вектора являются экземпляры класса из Л.Р. №2, имеющие произвольные (случайные) значения.
```cpp
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> size_dist(500, 1000);
size_t N = size_dist(gen);
vector<CustomClass> v1(N);
uniform_int_distribution<> value_dist(1, 1000);
generate(v1.begin(), v1.end(), [&](){
    return CustomClass(value_dist(gen), "random_string");
});
```
 - Инициализируем рандомный генератор, задаем распределение (500, 1000) и генерируем рандомный размер = N
 - Создаем вектор v1 размера N экземпляров CustomClass
 - Методом generate заполняем вектора v1 случайными экзмеплярами CustomClass (generate не использует явные циклы)

### Задание 2 
Создать вектор v2, поместив в него последние 200 элементов
   вектора v1. Рассмотрите решение для произвольных b и e, которые
   задают позиции первого и последнего копируемых элементов.
```cpp
size_t b = N >= 200 ? N - 200 : 0;
size_t e = N - 1;
vector<CustomClass> v2(v1.begin() + b, v1.begin() + e + 1);
```
 - Задаем b по следующему алгоритму: если размер вектора N больше или равен 200, устанавливаем b = N - 200, чтобы взять последние 200 элементов. В ином случае устанавливаем b на 0
 - Создаем вектор v2, копируя элементы из v1 с позиции b до позиции e

### Задание 3 
Сформировать список list1, поместив в него первые n (от 20 до 50)
   наибольших элементов вектора v1 (указанные элементы должны
   быть отсортированы до помещения их в список).
```cpp
uniform_int_distribution<size_t> distrib(20, 50);
size_t n = distrib(gen);
nth_element(v1.begin(), v1.end() - n, v1.end());
sort(v1.end() - n, v1.end());
list<CustomClass> list1; 
move(v1.end() - n, v1.end(), back_inserter(list1));
v1.erase(v1.end() - n, v1.end());
```
 - Генерируем случайное число n в диапазоне (20, 50)
 - Находим n наибольших элементов вектора v1 (они будут перемещены в конец вектора)
 - С помощью sort() сортруем последние наибольшие элементов по возрастанию (тк nth_element не гарантирует порядок наибольших элементов)
 - Создаем пустой список list1
 - С помошью move() перемещением последних n элементов из v1 в list1 (преобразование вектора в список без явного цикла)
 - С помощью erase() удаляем последние n элементов из вектора v1 **(Задание 5)**

### Задание 4
Сформировать список list2, поместив в него последние n (от 20 до 50) наименьших элементов вектора v2, порядок элементов не важен.
```cpp
nth_element(v2.begin(), v2.begin() + n, v2.end()); 
sort(v2.end() - n, v2.end());
list<CustomClass> list2;
move(v2.begin(), v2.begin() + n, back_inserter(list2));;
v2.erase(v2.begin(), v2.begin() + n);
```
 - Находим n наименьших элементов вектора v2 (они будут перемещены в начало вектора)
 - Сортируем последние n наименьших элементов по возрастанию
 - Создаем пустой список list2
 - С помощью move() перемещаем первые n элементов из v2 в list2 (преобразование вектора в список без явного цикла)
 - С помощью erase() удаляем первые n элементов из вектора v1 **(Задание 5)**

### Задание 5
Удалить из векторов v1 и v2 перемещенные элементы.
   Скорректируйте размеры векторов после удаления из них элементов.
   
**Реализовано в пунктах 3 и 4**


### Задание 6
Для списка list1 найти элемент со средним значением.
   Перегруппировать элементы списка так, чтобы в начале оказались
   все элементы, большие среднего значения.
```cpp
double sum = accumulate(list1.begin(), list1.end(), 0.0, [](double acc, const CustomClass& obj){
    return acc + obj.value;
});
double avg = sum / list1.size();
stable_partition(list1.begin(), list1.end(), [avg](const CustomClass& obj){
    return obj.value > avg;
});
```
 - В sum вычисляем сумму значений объектов в списке list1, в avg вычисляем среднее
 - return obj.value > avg; <- Лямбда-функция для определения, должен ли объект быть в первой части list1 (значения строго больше среднего)

### Задание 7
Удалите из списка list2 все нечётные элементы (или используйте
   другой критерий, который однозначно делит экземпляры вашего
   класса на два непересекающихся множества).
```cpp
list2.remove_if([](const CustomClass& obj){
    return obj.isOdd(); // True - если нечетное -> будет удалено
});
```
 - С помощью remove_if и is_Odd удаляем нечетные элементы (если isOdd == true то значение будет удалено)


### Задание 8
Создайте вектор v3 из элементов, которые присутствуют и в векторе
   v1 и в векторе v2.
```cpp
sort(v1.begin(), v1.end());
sort(v2.begin(), v2.end());
vector<CustomClass> v3;
set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v3));
```
 - Сортируем векторы v1 и v2 (set_insertion предполагает что оба вектора отсортированы)
 - Находим пересечение с помощью set_insertion и добавляем в v3


### Задание 9
Для списков list1 и list2 из списка с большим числом элементов
   удалите первые n так, чтобы оба списка имели бы одинаковый
   размер. Сформируйте из них список list3, который будет хранить
   пары &lt;первый элемент списка list1, первый элемент списка list2&gt;,
   &lt;второй элемент списка list1, второй элемент списка list2&gt; и т. д.
```cpp
auto size1 = list1.size();
auto size2 = list2.size();
if (size1 > size2) {
    auto it = list1.begin();
    advance(it, size1 - size2);
    list1.erase(list1.begin(), it);
} else if (size2 > size1) {
    auto it = list2.begin();
    advance(it, size2 - size1);
    list2.erase(list2.begin(), it);
}
list<pair<CustomClass, CustomClass>> list3; // Создаем пустой список list3
transform(list1.begin(), list1.end(), list2.begin(), back_inserter(list3), 
               [](const CustomClass& a, const CustomClass& b){
                   return make_pair(a, b);
               });
```
 - Находим размеры обоих листов, на разницу размеров (list1 - list2) перемещаем итератор list1, и удаляем лишние элементы
 - Проводим ту же операцию для list2 (разница list2 - list1)
 - Создаем пустой список list3, создаем и возвращаем пары

### Задание 10
Решите предыдущую задачу для векторов v1 и v2 без
    предварительного приведения векторов к одному размеру. Пар с
    пустыми значениями быть не должно.
```cpp
size_t min_size = min(v1.size(), v2.size());
vector<pair<CustomClass, CustomClass>> v_pairs;
v_pairs.reserve(min_size);
transform(v1.begin(), v1.begin() + min_size, v2.begin(), back_inserter(v_pairs),
               [](const CustomClass& a, const CustomClass& b){
                   return make_pair(a, b);
               });
```
 - Находим минимальный размер между векторами v1 и v2
 - Создаем вектор v_pairs для хранения пар из v1 и v2 и преаллоцируем память min_size
 - Создаем пару из элементов a и b и возвращаем ее

## Вывод

В результате выполнения лабораторной работы была разработана последовательность шагов для работы с векторами и списками, что позволило продемонстрировать эффективное использование операций с контейнерами C++.