#include <fstream>
#include <string>

struct Address {
	std::string city;
	std::string street;
	int home;
	int flat;
};

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

	for (int i = 0; i < n; ++i) {
		ofile << addarray[n - i - 1].city << ", " << addarray[n - i - 1].street << ", " << addarray[n - i - 1].home << ", " << addarray[n - i - 1].flat << std::endl;
	}

	ofile.close();


	delete[] addarray;
}