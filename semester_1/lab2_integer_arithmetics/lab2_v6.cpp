// С клавиатуры вводится натуральное число n. Найти все простые числа Мерсенна, не превосходящие n
// 2^(n) - 1 = k
#include <iostream>
//поверка на простоту

bool isPrime(long long k);

int main() {
    setlocale(LC_ALL, "Russian");

    long long n;
    std::cout << "С клавиатуры вводится натуральное число n. Найти все простые числа Мерсенна, не превосходящие n\n";
    std::cout << "Введите натуральное число n: ";

    if (!(std::cin >> n) || n < 2) {
        std::cout << "Ошибка! Число n должно быть натуральным (n > 1)!\n";
        return 0;
    }

    std::cout << "Простые числа Мерсенна, не превосходящие " << n << ":\n";

    for (long long p = 2; p <= 63; p++) {

        long long ki = 1;
        for (long long i = 0; i < p; i++) {
            ki *= 2;
            if (ki > n) break;
        }
        ki -= 1;

        if (ki > n) break;

        if (isPrime(ki)) {
            std::cout << ki << " (2^" << p << " - 1)\n";
        }
    }

    return 0;
}

bool isPrime(long long k) {
    if (k < 2) return false;
    if (k == 2) return true;
    if (k % 2 == 0) return false;

    for (long long i = 3; i * i <= k; i += 2) {
        if (k % i == 0) return false;
    }
    return true;
}

    //вычисление + проверка на больше-меньше

    
