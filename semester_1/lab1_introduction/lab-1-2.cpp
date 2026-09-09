#include <iostream>
//Вычислить сумму первых n нечётных чисел.Количество чисел N вводится с клавиатуры.
int main()
{
	int n;
	int sum = 0;

	std::cout << "Enter positive n:" << std::endl;
	std::cin >> n;

	if (n <= 0) {
		std::cout << "Error. Enter different number" << std::endl;
		return 0;
	}

	for (int i = 1; i <= n; i++) {
		sum += 2 * i - 1;
	}

	std::cout << "The sum of the N odd numbers =" << sum << std::endl;

	return 0;
}


