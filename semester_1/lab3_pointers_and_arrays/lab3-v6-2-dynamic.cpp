// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <random>
#include <limits>
#include <clocale>


int readInt(const char* m) {
    int v;

    while (true) {
        std::cout << m;

        if (std::cin >> v) {
            return v;
        }

        std::cout << "Ошибка: требуется целое число.\n";
        std::cin.clear();
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            '\n'
        );
    }
}

int* growArray(int* arr, int size, int& cap, int newCap) {
    int* newArr = new int[newCap];

    for (int i = 0; i < size; ++i) {
        newArr[i] = arr[i];
    }

    delete[] arr;
    cap = newCap;
    return newArr;
}



int* readArray(int* arr, int& size, int& capacity) {
    std::cout << "Введите целые числа по одному.\n" << "Для завершения введите нечисловой символ, например x.\n";

    while (true) {
        int value;

        std::cout << "Элемент " << size + 1 << ": ";

        if (!(std::cin >> value)) {
            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
            );
            break;
        }

        if (size == capacity) {
            arr = growArray(arr, size, capacity, capacity * 2);
        }

        arr[size] = value;
        ++size;
    }

    return arr;
}


int* fillRandom(int* arr, int& size, int& capacity) {
    std::cout << "Сколько случайных чисел сгенерировать? ";
    int n = readInt("");

    if (n <= 0) {
        return arr;
    }

    while (n > capacity) {
        arr = growArray(arr, size, capacity, capacity * 2);
    }

    std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> distribution(-50, 50);

    for (int i = 0; i < n; ++i) {
        arr[i] = distribution(generator);
    }

    size = n;
    std::cout << "Сгенерировано " << size << " чисел от -50 до 50.\n";
    return arr;
}


void printArray(const int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << ' ';
    }

    std::cout << '\n';
}


bool inRange(int value, int a, int b) {
    return value >= a && value <= b;
}


void moveRangeToEnd(int* arr, int size, int a, int b) {
    int nextPosition = 0;

    for (int i = 0; i < size; ++i) {
        if (!inRange(arr[i], a, b)) {
            int value = arr[i];

            for (int j = i; j > nextPosition; --j) {
                arr[j] = arr[j - 1];
            }

            arr[nextPosition] = value;
            ++nextPosition;
        }
    }
}


int main() {
    std::setlocale(LC_ALL, "");

    int capacity = 8;              // начальная вместимость
    int* arr = new int[capacity];
    int size = 0;
    char ch;

    std::cout << "Выберите способ заполнения массива:\n" << "h — вручную\n" << "r — случайными числами\n" << "Ваш выбор: ";
    std::cin >> ch;

    if (ch == 'h') {
        arr = readArray(arr, size, capacity);
    }
    else if (ch == 'r') {
        arr = fillRandom(arr, size, capacity);
    }
    else {
        std::cout << "Ошибка: выберите h или r.\n";
        delete[] arr;
        return 1;
    }

    if (size == 0) {
        std::cout << "Массив пуст. Преобразование невозможно.\n";
        delete[] arr;
        return 1;
    }

    std::cout << "\nИсходный массив (" << size << " элементов):\n";
    printArray(arr, size);

    int a = readInt("Введите левую границу отрезка a: ");
    int b = readInt("Введите правую границу отрезка b: ");

    if (a > b) {
        std::cout << "Ошибка: a не должно быть больше b.\n";
        delete[] arr;
        return 1;
    }

    moveRangeToEnd(arr, size, a, b);

    std::cout << "Массив после перемещения элементов отрезка [" << a << ", " << b << "] в конец:\n";
    printArray(arr, size);

    delete[] arr;
    return 0;
}