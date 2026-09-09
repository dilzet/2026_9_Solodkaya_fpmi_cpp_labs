// С клавиатуры вводится шестизначное натуральное число. 
// Написать программу, которая определяет, является ли это число «счастливым» 
// (т.е. сумма первых трёх цифр равняется сумме последних трёх цифр).

#include <iostream>;
int main()
{
	int number;
	std::cout << "Enter positive six-digit number:" << std::endl;
	std::cin >> number;

	if ((number <= 0) || (number < 100000 || number > 999999)) {
		std::cout << "Error: enter positive six-digit number" << std::endl;
		return 0;
	}

	int a = number / 100000;
	int b = (number / 10000) % 10;
	int c = (number / 1000) % 10;
	int d = (number / 100) % 10;
	int i = (number / 10) % 10;
	int f = number % 10;

	int sum1 = a + b + c;
	int sum2 = d + i + f;

	if (sum1 == sum2) {
		std::cout << "This number is lucky!!!" << std::endl;
	}
	else {
		std::cout << "This number is not lucky..." << std::endl;
	}
	return 0;
}