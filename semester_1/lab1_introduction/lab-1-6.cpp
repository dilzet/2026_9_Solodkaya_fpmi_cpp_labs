// Дана арифметическая прогрессия :ak = ak−1 + d.
// Вывести все члены этой прогрессии, кратные 3, которые лежат на отрезке [a,b].
// Числа a,b,d вводятся с клавиатуры (a0 = a).

#include <iostream>

int main()
{
    int a, d, b;
    std::cout << "Enter a, d, b:" << std::endl;
    std::cin >> a >> d >> b;

    if ((a > b) || (b < a)) {
        std::cout << "Error. Enter different a, b, d:" << std::endl;
        return 0;
    }

    std::cout << "\nMultiple of 3:\n";

    for (int ak = a; ak <= b; ak += d) {
      
        if (ak % 3 == 0) {
            std::cout << ak << " ";
        }

    }

    std::cout << std::endl;
    return 0;
}