//С клавиатуры вводится четырёхзначное натуральное число.
// Выяснить, является ли оно палиндромом
// (т.е.читается одинаково как слева направо, так и справа налево).

#include <iostream>

int main() {
    int number;

    std::cout << "Enter a four-digit number: ";
    std::cin >> number;

    if (number < 1000 || number > 9999) {
        std::cout << "Error: enter a four-digit number." << std::endl;
        return 0;
    }

    int a = number / 1000;
    int b = (number / 100) % 10;
    int c = (number / 10) % 10;
    int d = number % 10;

    if (a == d && b == c) {
        std::cout << "This number is a palidrome." << std::endl;
    }
    else {
        std::cout << "This number is not a palidrome." << std::endl;
    }

    return 0;
}
