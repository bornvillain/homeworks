#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>
#include <iostream>

class Book;
class Publisher {
public:
	std::string name = "";
	Wt::Dbo::collection< Wt::Dbo::ptr<Book> > books;

	template <typename Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, name, "name");
		Wt::Dbo::hasMany(a, books, Wt::Dbo::ManyToOne, "publisher");
	}
};
class Stock;
class Book {
public:
	std::string title = "";
	Wt::Dbo::ptr<Publisher> publisher;
	Wt::Dbo::collection< Wt::Dbo::ptr<Stock> > stocks;
	template <typename Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, title, "title");
		Wt::Dbo::belongsTo(a, publisher, "publisher");
		Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "book");
	}
};
class Shop;
class Sale;
class Stock {
public:
	int count = 0;
	Wt::Dbo::ptr<Shop> shop;
	Wt::Dbo::ptr<Book> book;
	Wt::Dbo::collection< Wt::Dbo::ptr<Sale> > sales;
	template <typename Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, count, "count");
		Wt::Dbo::belongsTo(a, shop, "shop");
		Wt::Dbo::belongsTo(a, book, "book");
		Wt::Dbo::hasMany(a, sales, Wt::Dbo::ManyToOne, "stock");
	}
};

class Shop {
public:
	std::string name = "";
	Wt::Dbo::collection< Wt::Dbo::ptr<Stock> > stocks;
	template <typename Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, name, "name");
		Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "shop");
	}
};

class Sale {
public:
	int price = 0;
	std::string date_sale = "";
	int count = 0;
	Wt::Dbo::ptr<Stock> stock;

	template <typename Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, price, "price");
		Wt::Dbo::field(a, date_sale, "date_sale");
		Wt::Dbo::field(a, count, "count");
		Wt::Dbo::belongsTo(a, stock, "stock");
	}
};


int main()
{
	try {
		std::string connectionString = "host=10.15.48.201 "
			" port=5432"
			" dbname=clients"
			" user=postgres"
			" password=postgres";
		auto postgres = std::make_unique<Wt::Dbo::backend::Postgres>(connectionString);
		Wt::Dbo::Session session;
		session.setConnection(std::move(postgres));
		session.mapClass<Book>("book");
		session.mapClass<Publisher>("publisher");
		session.mapClass<Sale>("sale");
		session.mapClass<Shop>("shop");
		session.mapClass<Stock>("stock");

		session.createTables();

		Wt::Dbo::Transaction t{ session };

		auto publisher1 = std::unique_ptr<Publisher>(new Publisher{ "Alex" });
		auto publisher2 = std::unique_ptr<Publisher>(new Publisher{ "Viktor" });

		Wt::Dbo::ptr<Publisher> ppublisher1 = session.add(std::move(publisher1));
		Wt::Dbo::ptr<Publisher> ppublisher2 = session.add(std::move(publisher2));

		auto book1 = std::unique_ptr<Book>(new Book{ "The Sun", ppublisher1 });
		auto book2 = std::unique_ptr<Book>(new Book{ "Underworld",ppublisher2 });
		auto book3 = std::unique_ptr<Book>(new Book{ "Serenity", ppublisher1 });

		Wt::Dbo::ptr<Book> pbook1 = session.add(std::move(book1));
		Wt::Dbo::ptr<Book> pbook2 = session.add(std::move(book2));
		Wt::Dbo::ptr<Book> pbook3 = session.add(std::move(book3));

		auto shop1 = std::unique_ptr<Shop>(new Shop{ "BookMarket" });
		auto shop2 = std::unique_ptr<Shop>(new Shop{ "Dauntbooks" });
		auto shop3 = std::unique_ptr<Shop>(new Shop{ "Biblio" });

		Wt::Dbo::ptr<Shop> pshop1 = session.add(std::move(shop1));
		Wt::Dbo::ptr<Shop> pshop2 = session.add(std::move(shop2));
		Wt::Dbo::ptr<Shop> pshop3 = session.add(std::move(shop3));

		auto stock1 = std::unique_ptr<Stock>(new Stock{ 5,pshop1,pbook1 });
		auto stock2 = std::unique_ptr<Stock>(new Stock{ 10,pshop2,pbook2 });
		auto stock3 = std::unique_ptr<Stock>(new Stock{ 3,pshop3,pbook3 });

		Wt::Dbo::ptr<Stock> pstock1 = session.add(std::move(stock1));
		Wt::Dbo::ptr<Stock> pstock2 = session.add(std::move(stock2));
		Wt::Dbo::ptr<Stock> pstock3 = session.add(std::move(stock3));

		auto sale1 = std::unique_ptr<Sale>(new Sale{ 150,"2024-07-08",1,pstock1 });
		auto sale2 = std::unique_ptr<Sale>(new Sale{ 300,"2024-07-09",1,pstock2 });

		Wt::Dbo::ptr<Sale> psale1 = session.add(std::move(sale1));
		Wt::Dbo::ptr<Sale> psale2 = session.add(std::move(sale2));
		std::string name;
		do {
			std::cout << "Enter publisher name or 'q' to exit: ";
			std::cin >> name;
			if (name == "q") {
				std::cout << "Godbye!" << std::endl;
			}
			else {
				Wt::Dbo::ptr<Publisher> publisher = session.find<Publisher>().where("name = ? ").bind(name);
				if (!publisher) {
					std::cout << "Books by the publisher " << name << " are not presented in shops." << std::endl;
				}
				else {
					std::cout << "Books by the publisher " << publisher->name << " are available in the following shops:" << std::endl;
					for (const auto& book : publisher->books) {
						for (const auto& stock : book->stocks) {
							std::cout << stock->shop->name << std::endl;
						}
					}
				}
			}
		} while (name != "q");
		t.commit();
	}
	catch (const Wt::Dbo::Exception& e) {
		std::cout << e.what() << std::endl;
	}
}
