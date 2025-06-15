#include "abms.h"

void showMenu() {
    cout << "1�������ϵ��" << endl;
	cout << "2����ʾ��ϵ��" << endl;
    cout << "3��ɾ����ϵ��" << endl;
    cout << "4��������ϵ��" << endl;
    cout << "5���޸���ϵ��" << endl;
    cout << "6�������ϵ��" << endl;
    cout << "0���˳�ͨѶ¼" << endl;
}

void addPerson(struct Addressbook* ab) {
    if (ab->size == MAX) {
        cout << "ͨѶ¼�ռ�����" << endl;
        return;
    }
    else {
        string name;
        cout << "������������";
        cin >> name;
        ab->personArray[ab->size].name = name;
        int sex;
        bool validInput1 = false;
        while (!validInput1) {
            cout << "�������Ա���=1��Ů=2����";
            if (cin >> sex) {
                if (sex == 1 || sex == 2) {
                    ab->personArray[ab->size].sex = sex;
                    validInput1 = true;
                }
                else {
                    cout << "�������" << endl;
                }
            }
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "������Ч" << endl;
            }
        }
        int age;
        bool validInput2 = false;
        while (!validInput2) {
            cout << "���������䣺";
            if (cin >> age) {
                ab->personArray[ab->size].age = age;
                validInput2 = true;
            }
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "������Ч" << endl;
            }
        }
        string phone;
        cout << "������绰��";
        cin >> phone;
        ab->personArray[ab->size].phone = phone;
        string address;
        cout << "�������ַ��";
        cin >> address;
        ab->personArray[ab->size].address = address;
        ab->size++;
        cout << "��ӳɹ�" << endl;
        saveToFile(ab);
        system("pause");
        system("cls");
    }
}

void showPerson(struct Addressbook* ab) {
    if (ab->size == 0) {
        cout << "ͨѶ¼Ϊ��" << endl;
    }
    else {
        for (int i = 0; i < ab->size; i++) {
            cout << "������" << ab->personArray[i].name
                << "\t�Ա�" << (ab->personArray[i].sex == 1 ? "��" : "Ů")
                << "\t���䣺" << ab->personArray[i].age
                << "\t�绰��" << ab->personArray[i].phone
                << "\t��ַ��" << ab->personArray[i].address << endl;
        }
    }
    system("pause");
    system("cls");
}

int isExist(struct Addressbook* ab, string name) {
    for (int i = 0; i < ab->size; i++) {
        if (ab->personArray[i].name == name) {
            int custom = 0;
            cout << "������" << ab->personArray[i].name
                << "\t�Ա�" << (ab->personArray[i].sex == 1 ? "��" : "Ů")
                << "\t���䣺" << ab->personArray[i].age
                << "\t�绰��" << ab->personArray[i].phone
                << "\t��ַ��" << ab->personArray[i].address << endl;
            bool validInput = false;
            while (!validInput) {
                cout << "�Ƿ�ѡ�и���ϵ�ˣ�(��=1����=0)��";
                if (cin >> custom) {
                    if (custom == 1) {
                        return i;
                    }
                    else if (custom == 0) {
                        break;
                    }
                    else {
                        cout << "�������" << endl;
                    }
                }
                else {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "������Ч" << endl;
                }
            }
        }
    }
    return -1;
}

void deletePerson(struct Addressbook* ab) {
    cout << "��������ϵ��������";
    string name;
    cin >> name;
    int ret = isExist(ab, name);
    if (ret != -1) {
        ab->personArray[ret].name.clear();
        ab->personArray[ret].sex = 0;
        ab->personArray[ret].age = 0;
        ab->personArray[ret].phone.clear();
        ab->personArray[ret].address.clear();
        if (ret < ab->size - 1) {
            for (int i = ret; i < ab->size - 1; i++) {
                ab->personArray[i] = ab->personArray[i + 1];
            }
            int lastIndex = ab->size - 1;
            ab->personArray[lastIndex].name.clear();
            ab->personArray[lastIndex].sex = 0;
            ab->personArray[lastIndex].age = 0;
            ab->personArray[lastIndex].phone.clear();
            ab->personArray[lastIndex].address.clear();
        }
        ab->size--;
        cout << "ɾ���ɹ�" << endl;
    }
    else {
        cout << "δ�ҵ�����ϵ��" << endl;
    }
    saveToFile(ab);
    system("pause");
    system("cls");
}

void findPerson(struct Addressbook* ab) {
    cout << "��������ϵ��������";
    string name;
    cin >> name;
    bool found = false;
    for (int i = 0; i < ab->size; i++) {
        if (ab->personArray[i].name == name) {
            found = true;
            cout << "������" << ab->personArray[i].name
                << "\t�Ա�" << (ab->personArray[i].sex == 1 ? "��" : "Ů")
                << "\t���䣺" << ab->personArray[i].age
                << "\t�绰��" << ab->personArray[i].phone
                << "\t��ַ��" << ab->personArray[i].address << endl;
        }
    }
    if (!found) {
        cout << "δ�ҵ�����ϵ��" << endl;
    }
    system("pause");
    system("cls");
}

void modifyPerson(struct Addressbook* ab) {
    cout << "��������ϵ��������";
    string name;
    cin >> name;
    int ret = isExist(ab, name);
    if (ret != -1) {
        cout << "������" << ab->personArray[ret].name
            << "\t�Ա�" << (ab->personArray[ret].sex == 1 ? "��" : "Ů")
            << "\t���䣺" << ab->personArray[ret].age
            << "\t�绰��" << ab->personArray[ret].phone
            << "\t��ַ��" << ab->personArray[ret].address << endl;
        cout << "�������޸ĺ����Ϣ" << endl;
        string newName;
        cout << "������������";
        cin >> newName;
        ab->personArray[ret].name = newName;
        int sex;
        bool validInput1 = false;
        while (!validInput1) {
            cout << "�������Ա���=1��Ů=2����";
            if (cin >> sex) {
                if (sex == 1 || sex == 2) {
                    ab->personArray[ret].sex = sex;
                    validInput1 = true;
                }
                else {
                    cout << "�������" << endl;
                }
            }
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "������Ч" << endl;
            }
        }
        int age;
        bool validInput2 = false;
        while (!validInput2) {
            cout << "���������䣺";
            if (cin >> age) {
                ab->personArray[ret].age = age;
                validInput2 = true;
            }
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "������Ч" << endl;
            }
        }
        string phone;
        cout << "������绰��";
        cin >> phone;
        ab->personArray[ret].phone = phone;
        string address;
        cout << "�������ַ��";
        cin >> address;
        ab->personArray[ret].address = address;
        cout << "�޸ĳɹ�" << endl;
    }
    else {
        cout << "δ�ҵ�����ϵ��" << endl;
    }
    saveToFile(ab);
    system("pause");
    system("cls");
}

void cleanPerson(struct Addressbook* ab) {
    for (int i = 0; i < ab->size; i++) {
        ab->personArray[i].name.clear();
        ab->personArray[i].sex = 0;
        ab->personArray[i].age = 0;
        ab->personArray[i].phone.clear();
        ab->personArray[i].address.clear();
    }
    ab->size = 0;
    cout << "ͨѶ¼�����" << endl;
    saveToFile(ab);
    system("pause");
    system("cls");
}

void saveToFile(struct Addressbook* ab) {
    ofstream outFile("addressbook.dat");
    if (!outFile) {
        cout << "�޷�����ͨѶ¼���ļ�" << endl;
        return;
    }
    outFile << ab->size << endl;
    for (int i = 0; i < ab->size; i++) {
        outFile << ab->personArray[i].name << endl;
        outFile << ab->personArray[i].sex << endl;
        outFile << ab->personArray[i].age << endl;
        outFile << ab->personArray[i].phone << endl;
        outFile << ab->personArray[i].address << endl;
    }
    outFile.close();
}

void loadFromFile(struct Addressbook* ab) {
    ifstream inFile("addressbook.dat");
    if (!inFile) {
        return;
    }
    inFile >> ab->size;
    inFile.ignore();
    for (int i = 0; i < ab->size; i++) {
        getline(inFile, ab->personArray[i].name);
        inFile >> ab->personArray[i].sex;
        inFile.ignore();
        inFile >> ab->personArray[i].age;
        inFile.ignore();
        getline(inFile, ab->personArray[i].phone);
        getline(inFile, ab->personArray[i].address);
    }
    inFile.close();
}