#include <fstream>
#include <string>
#include <algorithm>

struct Address {
	std::string city;
	std::string street;
	int home;
	int flat;
};

void SortAddressesByCity(Address* addresses, int size) {
	for (int j = 0; j < size - 1; ++j) {
		for (int i = 0; i < size - 1 - j; ++i) {
			if (addresses[i].city > addresses[i + 1].city) {
				std::swap(addresses[i], addresses[i + 1]);
			}
		}
	}
}

int main() {
	std::ifstream ifile("in.txt");

	int n;
	ifile >> n;

	Address* addarray = new Address[n];

	for (int i = 0; i < n; ++i) {
		Address address;
		ifile >> address.city;
		ifile >> address.street;
		ifile >> address.home;
		ifile >> address.flat;
		addarray[i] = address;
	}

	ifile.close();
	std::ofstream ofile("out.txt");

	SortAddressesByCity(addarray, n);

	for (int i = 0; i < n; ++i) {
		ofile << addarray[i].city << ", " << addarray[i].street << ", " << addarray[i].home << ", " << addarray[i].flat << std::endl;
	}

	ofile.close();


	delete[] addarray;
}