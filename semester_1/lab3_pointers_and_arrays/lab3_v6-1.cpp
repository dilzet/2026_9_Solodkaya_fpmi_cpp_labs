// Преобразовать массив целых таким образом, чтобы элементы, принадлежащие отрезку [a,b] (числа a и b вводятся с клавиатуры), 
// располагались после всех остальных. Порядок следования элементов не изменять.
//

#include <iostream>
#include <random>
#include <limits>
#include <clocale>


const int max = 100;

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


int readArray(int arr[], int c) {
    int count = 0;

    std::cout << "Введите целые числа по одному.\n" << "Для завершения введите нечисловой символ, например x.\n";

    while (count < c) {
        std::cout << "Элемент " << count + 1 << ": ";

        if (std::cin >> arr[count]) {
            ++count;
        }
        else {
            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
            );
            break;
        }
    }

    if (count == c) {
        std::cout << "Достигнута вместимость массива: " << c << " элементов.\n";
    }

    return count;
}

int fillRandom(int arr[]) {
    std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> distribution(-50, 50);

    for (int i = 0; i < max; ++i) {
        arr[i] = distribution(generator);
    }

    return max;
}


void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << ' ';
    }

    std::cout << '\n';
}


bool inRange(int value, int a, int b) {
    return value >= a && value <= b;
}

void moveRangeToEnd(int arr[], int size, int a, int b) {
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

    int arr[max];
    int size = 0;
    char ch;

    std::cout << "Выберите способ заполнения массива:\n"
        << "h — вручную\n"
        << "r — случайными числами\n"
        << "Ваш выбор: ";
    std::cin >> ch;

    if (ch == 'h') {
        size = readArray(arr, max);
    }
    else if (ch == 'r') {
        size = fillRandom(arr);
        std::cout << "Все " << size << " ячеек заполнены числами от -50 до 50.\n";
    }
    else {
        std::cout << "Ошибка: выберите h или r.\n";
        return 1;
    }

    if (size == 0) {
        std::cout << "Массив пуст. Преобразование невозможно.\n";
        return 1;
    }

    std::cout << "\nИсходный массив (" << size << " элементов):\n";
    printArray(arr, size);

    int a = readInt("Введите левую границу отрезка a: ");
    int b = readInt("Введите правую границу отрезка b: ");

    if (a > b) {
        std::cout << "Ошибка: a не должно быть больше b.\n";
        return 1;
    }

    moveRangeToEnd(arr, size, a, b);

    std::cout << "Массив после перемещения элементов отрезка ["
        << a << ", " << b << "] в конец:\n";
    printArray(arr, size);

    return 0;
}



