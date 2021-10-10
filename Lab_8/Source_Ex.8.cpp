#include <string>
#include <iostream>
#pragma warning (disable:4996)


using namespace std;

class Person {
public:
	Person(const char* name = "nobody");
	virtual ~Person() = default;
	virtual void identity() const;
	virtual void interrogate();
private:
	string name;
};

class Spy : public Person {
public:
	Spy(const char* name_zero = "nobody", const char* alias_zero = "nobody", int resistance_zero = 0);
	virtual void identity() const override;
	virtual void interrogate() override;
	void set_identity(const char* alias_final);

private:
	string alias_first;
	int resistance;
};

int main(int argc, char** argv) {

	Person agent("James Bond");
	Spy spy("Emilio Largo", "William Johnson", 3);
	Spy spy2("Ernst Blofield", "John Keats", 5);

	cout << endl << "Nice to meet you. ";
	agent.identity();

	for (int i = 0; i < 6; ++i) {
		cout << "Who are you?" << endl;
		spy.interrogate();
		spy.identity();
	}
	spy.set_identity("Bill Munny");
	spy.identity();

	cout << endl << "Nice to meet you. ";
	agent.identity();

	for (int i = 0; i < 6; ++i) {
		cout << "Who are you?" << endl;
		spy2.interrogate();
		spy2.identity();
	}

	return 0;
}

Person::Person(const char* name_zero) : name(name_zero) {}

void Person::interrogate() {} //empty

void Person::identity() const
{
	printf("My name is: ");
	cout << name << endl;
}

Spy::Spy(const char* name_zero, const char* alias_zero, int resistance_zero) : Person(name_zero), alias_first(alias_zero), resistance(resistance_zero) {}

void Spy::identity() const
{
	if (resistance > 0)
	{
		printf("My name is: ");
		cout << alias_first << endl;
	}
	else
	{
		Person::identity();
		printf("My alias is: ");
		cout << alias_first << endl;
	}
}

void Spy::interrogate()
{
	resistance -= 1;
}

void Spy::set_identity(const char* alias_final) //final id
{
	alias_first = alias_final;
}