#include <iostream>

struct Address {
	std::string city;
	std::string street;
	int house;
	int flat;
	int index;
};

void PrintAddress(Address& address) {
	std::cout << "Город: " << address.city << std::endl;
	std::cout << "Улица: " << address.street << std::endl;
	std::cout << "Номер дома: " << address.house << std::endl;
	std::cout << "Номер квартиры: " << address.flat << std::endl;
	std::cout << "Индекс: " << address.index << std::endl;
}


int main() {
	Address address1 = { "Москва", "Арбат", 12,8,123456 };
	Address address2 = { "Ижевск", "Пушкина", 59,143,953769 };
	PrintAddress(address1);
	std::cout << std::endl;
	PrintAddress(address2);
}
