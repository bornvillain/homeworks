#include <iostream>

struct BankAccount {
	int number;
	std::string owner;
	double balance;
};

int main()
{
	BankAccount account;
	std::cout << "Введите номер счёта: ";
	std::cin >> account.number;
	std::cout << "Введите имя владельца: ";
	std::cin >> account.owner;
	std::cout << "Введите баланс: ";
	std::cin >> account.balance;
	std::cout << "Введите новый баланс: ";
	std::cin >> account.balance;

	std::cout << "Ваш счёт: " << account.owner << ", " << account.number << ", " << account.balance;

}
