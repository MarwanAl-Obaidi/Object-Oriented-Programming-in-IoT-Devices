#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <ctime>
#pragma warning (disable:4996)


using namespace std;

class Car {
	friend ostream &operator<<(ostream &out, const Car &car);
public:
	Car(const char* m = "Ford", const char* l = nullptr, int ml = 0) : model(m), license(l ? l : (rand() % 2 ? "FOO-" : "BAR-") + to_string(rand() % 999 + 1)), mileage(ml ? ml : rand() % 10000) {};
	~Car() { cout << model << " " << license << " deleted" << endl; };
	void Read();
	string GetLicense() const { return license; }
private:
	string model;
	string license;
	int mileage;
};

void Car::Read()
{
	//std::cout << "Enter car information" << std::endl;
	// replace the following with your own code
	this->model = "Seat";
	this->license = (rand() % 2 ? "ZAP-" : "ZIP-") + to_string(rand() % 999 + 1);
	this->mileage = 10000 + rand() % 10000;
}

ostream & operator<<(ostream & out, const Car & car)
{
	cout << "Model: " << car.model << endl << "License: " << car.license << endl << "Mileage: " << car.mileage << endl;

	return out;
}

/* ---------------------- */

class Website {
public:
	Website(const char *n = nullptr) : name(n ? n : "www.cars" + to_string(rand() % 99 + 1) + ".com") {}
	~Website() { cout << name << " deleted" << endl; };
	void advertise(shared_ptr<Car> car) { listing.push_back(car); }
	void print(ostream &out = cout) { out << name << endl; for(auto car : listing) out << *car; out << name << " end of list\n" << endl;
	}
	void remove(shared_ptr<Car> car) { listing.erase(std::remove(listing.begin(), listing.end(), car),listing.end()); } 
private:
	vector<shared_ptr<Car>> listing;
	string name;
};

class Dealer {
	friend ostream &operator<<(ostream &out, const Dealer &dealer);
public:
	Dealer(const char *name_ = "John Doe") : name(name_) {};
	~Dealer() { cout << name << " deleted" << endl; };
	void buy();
	void sell();
	void add(shared_ptr<Car> car) { cars.push_back(car); for (auto site : sites) site->advertise(car); }
	void add_site(shared_ptr<Website> w) { sites.push_back(w); }
private:
	string name;
	vector<shared_ptr<Car>> cars;
	vector<shared_ptr<Website>> sites;
};

void Dealer::buy()
{
	shared_ptr<Car> car = make_shared<Car>();
	car->Read();
	add(car);
}

void Dealer::sell()
{
	cout << *this; // print my list of cars
	cout << "\nEnter license of car you want to buy" << endl;

	string license;
	cin >> license;
	auto ci = find_if(cars.begin(), cars.end(), [&license](shared_ptr<Car> c){return license == c->GetLicense(); });
	if (ci != cars.end())
	{
		for (auto site : sites) site->remove(*ci); // modify code wso that this is not needed
		cars.erase(ci);
	}
}


ostream & operator<<(ostream & out, const Dealer & dealer)
{
	cout << dealer.name << "'s cars for sale" << endl;
	for (auto car : dealer.cars) cout << *car;
	cout << "End of " << dealer.name << "'s cars listing\n" << endl;

	return out;
}

/* ---------------------- */



void car_sales()
{
	cout << "Car sales started" << endl;
	shared_ptr<Website> wa = make_shared<Website>("www.auto.com");
	shared_ptr<Website> wb = make_shared<Website>("www.bilar.com");
	shared_ptr<Website> wc = make_shared<Website>("www.cars.com");
	shared_ptr<Dealer> a = make_shared<Dealer>("Alan Aldis");
	shared_ptr<Dealer> b = make_shared<Dealer>("Bill Mundy");

	{
		shared_ptr<Dealer>  c = make_shared<Dealer>("Casey Ball");
		shared_ptr<Car> ca = make_shared<Car>();
		shared_ptr<Car> cb = make_shared<Car>();

		a->add_site(wa);
		a->add_site(wb);
		b->add_site(wb);
		b->add_site(wc);

		c->add_site(wa);
		c->add_site(wb);
		c->add_site(wc);

		a->buy();
		a->buy();
		a->buy();
		a->buy();

		b->buy();
		b->buy();
		b->buy();

		c->buy();
		c->buy();

		c->add(ca);
		c->add(cb);

		wa->print();
		wb->print();
		wc->print();

		cout << *a << *b << *c << endl;

		a->sell();

		cout << *a << *b << *c << endl;

		wa->print();
		wb->print();
		wc->print();
	}

	wa->print();
	wb->print();
	wc->print();


	cout << "Car sales ended" << endl;

}

int main(int argc, char **argv) {
	_CrtMemState s1;
	_CrtMemCheckpoint(&s1);

	srand(time(NULL));

	car_sales();

	_CrtMemState s2,s3;
	_CrtMemCheckpoint(&s2);
	if (_CrtMemDifference(&s3, &s1, &s2)) {
		_CrtDumpMemoryLeaks();
		_CrtMemDumpStatistics(&s3);
	}

	return 0;
}