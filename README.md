# Алгоритмы и структуры данных
В этом репозитории содержится исходный код лабораторных и курсовых работ
за 2 семестра по предмету "Алгоритмы и структуры данных" в СПбГЭТУ "ЛЭТИ" (2019-2020).

Для каждой лабораторной работы и курсовых проектов реализованы
модульные тесты 
при помощи библиотеки [gtest](https://github.com/google/googletest "ссылка на исходный код библиотеки").
## Краткое описание работ
### Первый Семестр

### Лабораторная работа 1

Односвязный список с дополнительными методами.

### Лабораторная работа 2

Стек с шаблонным типом данных. 

### Лабораторная работа 3

Бинарное дерево. Итераторы для его обхода в глубину и ширину при помощи абстрактного класса.

### Лабораторная работа 4

Реализация и сравнение алгоритмов сортировки: быстрая, вставками, 
двоичным деревом, болотная (Bogosort), подсчётом. 

### Курсовой проект

Решение классической задачи о рюкзаке при помощи динамического программирования. 

### Второй Семестр

### Лабораторная работа 1

Ассоциативный массив на основе красно-чёрного дерева. 

### Лабораторная работа 2

Кодирование и декодирование строк методом Шеннона-Фано при помощи списка и кучи.

### Лабораторная работа 3

Алгоритм Дейкстры для поиска оптимального маршрута перелётов между городами.

### Курсовая работа

Решение задачи о максимальном потоке в транспортной сети при помощи алгоритма Форда-Фалкерсона. 

## Запуск у себя 
Предварительно необходимо установить [CMake](https://cmake.org/download/ "скачать CMake") и компилятор.
Библиотека **gtest** устанавливается автоматически. 

### Linux
 
Скачать репозиторий и перейти в него.
```
git clone https://github.com/homuwell/Algorithms.git && cd Algorithms
```
Создать папку build и перейти в неё
```
mkdir build && cd build
```
Сгенерировать файлы для сборки
```
cmake ..
```
Выполнить сборку
```
make 
```
Выполнить программу (к примеру, 1 лабораторную работу первого семестра)
```
./S1L1
```
Имена других программ находятся в файле CmakeList.txt. Для некоторых лабораторные используют файлы для ввода и вывода. 
