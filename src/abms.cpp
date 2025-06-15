#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <sstream>
#include "abms.h"
using namespace std;

int main() {
	Addressbook* ab = new Addressbook();
	ab->size = 0;
	loadFromFile(ab);
	int select = 0;
	while (true) {
		showMenu();
		cin >> select;
		switch (select) {
		case 1:
			addPerson(ab);
			break;
		case 2:
			showPerson(ab);
			break;
		case 3:
			deletePerson(ab);
            break;
		case 4:
			findPerson(ab);
			break;
		case 5:
			modifyPerson(ab);
			break;
		case 6:
			cleanPerson(ab);
			break;
		case 0:
			cout << "请民主地等待..." << endl;
			saveToFile(ab);
			return 0;
			break;
		default:
			break;
		}
	}
	delete ab;
	system("pause");
	return 0;
}
