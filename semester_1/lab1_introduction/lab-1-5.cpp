//Напечатать первые n чисел Фибоначчи. Число n вводится с клавиатуры.
// Числа Фибоначчи вычисляются по формуле : Fn= Fn−1 + Fn−2, где F0 = 0,F1 = 1.

#include <iostream>

int main()
{
	int n;

	std::cout << "Enter n:" << std::endl;
	std::cin >> n;
	if (n <= 0) {
		std::cout << "n must be positive" << std::endl;
		return 0;
	}
	int F0 = 0;
	int F1 = 1;
		for (int i = 0; i < n; i++) {
			std::cout << F0;
			if (i < n - 1) {
				std::cout << ' ';
			}
			int next = F0 + F1;
			F0 = F1;
			F1 = next;
		}

	return 0;
}