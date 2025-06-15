#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <sstream>
using namespace std;

#define MAX 1000

void showMenu();

void addPerson(struct Addressbook *ab);

void showPerson(struct Addressbook *ab);

int isExist(struct Addressbook* ab, string name);

void deletePerson(struct Addressbook* ab);

void findPerson(struct Addressbook* ab);

void modifyPerson(struct Addressbook* ab);

void cleanPerson(struct Addressbook* ab);

void saveToFile(struct Addressbook* ab);

void loadFromFile(struct Addressbook* ab);

struct Person {
	string name;
	int sex;
	int age;
	string phone;
	string address;
};

struct Addressbook {
	struct Person personArray[MAX];
	int size;
};