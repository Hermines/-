#include "abms.h"

void showMenu() {
    cout << "1、添加联系人" << endl;
	cout << "2、显示联系人" << endl;
    cout << "3、删除联系人" << endl;
    cout << "4、查找联系人" << endl;
    cout << "5、修改联系人" << endl;
    cout << "6、清空联系人" << endl;
    cout << "0、退出通讯录" << endl;
}

void addPerson(struct Addressbook* ab) {
    if (ab->size == MAX) {
        cout << "通讯录空间已满" << endl;
        return;
    }
    else {
        string name;
        cout << "请输入姓名：";
        cin >> name;
        ab->personArray[ab->size].name = name;
        int sex;
        bool validInput1 = false;
        while (!validInput1) {
            cout << "请输入性别（男=1，女=2）：";
            if (cin >> sex) {
                if (sex == 1 || sex == 2) {
                    ab->personArray[ab->size].sex = sex;
                    validInput1 = true;
                }
                else {
                    cout << "输入错误" << endl;
                }
            }
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "输入无效" << endl;
            }
        }
        int age;
        bool validInput2 = false;
        while (!validInput2) {
            cout << "请输入年龄：";
            if (cin >> age) {
                ab->personArray[ab->size].age = age;
                validInput2 = true;
            }
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "输入无效" << endl;
            }
        }
        string phone;
        cout << "请输入电话：";
        cin >> phone;
        ab->personArray[ab->size].phone = phone;
        string address;
        cout << "请输入地址：";
        cin >> address;
        ab->personArray[ab->size].address = address;
        ab->size++;
        cout << "添加成功" << endl;
        saveToFile(ab);
        system("pause");
        system("cls");
    }
}

void showPerson(struct Addressbook* ab) {
    if (ab->size == 0) {
        cout << "通讯录为空" << endl;
    }
    else {
        for (int i = 0; i < ab->size; i++) {
            cout << "姓名：" << ab->personArray[i].name
                << "\t性别：" << (ab->personArray[i].sex == 1 ? "男" : "女")
                << "\t年龄：" << ab->personArray[i].age
                << "\t电话：" << ab->personArray[i].phone
                << "\t地址：" << ab->personArray[i].address << endl;
        }
    }
    system("pause");
    system("cls");
}

int isExist(struct Addressbook* ab, string name) {
    for (int i = 0; i < ab->size; i++) {
        if (ab->personArray[i].name == name) {
            int custom = 0;
            cout << "姓名：" << ab->personArray[i].name
                << "\t性别：" << (ab->personArray[i].sex == 1 ? "男" : "女")
                << "\t年龄：" << ab->personArray[i].age
                << "\t电话：" << ab->personArray[i].phone
                << "\t地址：" << ab->personArray[i].address << endl;
            bool validInput = false;
            while (!validInput) {
                cout << "是否选中该联系人？(是=1，否=0)：";
                if (cin >> custom) {
                    if (custom == 1) {
                        return i;
                    }
                    else if (custom == 0) {
                        break;
                    }
                    else {
                        cout << "输入错误" << endl;
                    }
                }
                else {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "输入无效" << endl;
                }
            }
        }
    }
    return -1;
}

void deletePerson(struct Addressbook* ab) {
    cout << "请输入联系人姓名：";
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
        cout << "删除成功" << endl;
    }
    else {
        cout << "未找到该联系人" << endl;
    }
    saveToFile(ab);
    system("pause");
    system("cls");
}

void findPerson(struct Addressbook* ab) {
    cout << "请输入联系人姓名：";
    string name;
    cin >> name;
    bool found = false;
    for (int i = 0; i < ab->size; i++) {
        if (ab->personArray[i].name == name) {
            found = true;
            cout << "姓名：" << ab->personArray[i].name
                << "\t性别：" << (ab->personArray[i].sex == 1 ? "男" : "女")
                << "\t年龄：" << ab->personArray[i].age
                << "\t电话：" << ab->personArray[i].phone
                << "\t地址：" << ab->personArray[i].address << endl;
        }
    }
    if (!found) {
        cout << "未找到该联系人" << endl;
    }
    system("pause");
    system("cls");
}

void modifyPerson(struct Addressbook* ab) {
    cout << "请输入联系人姓名：";
    string name;
    cin >> name;
    int ret = isExist(ab, name);
    if (ret != -1) {
        cout << "姓名：" << ab->personArray[ret].name
            << "\t性别：" << (ab->personArray[ret].sex == 1 ? "男" : "女")
            << "\t年龄：" << ab->personArray[ret].age
            << "\t电话：" << ab->personArray[ret].phone
            << "\t地址：" << ab->personArray[ret].address << endl;
        cout << "请输入修改后的信息" << endl;
        string newName;
        cout << "请输入姓名：";
        cin >> newName;
        ab->personArray[ret].name = newName;
        int sex;
        bool validInput1 = false;
        while (!validInput1) {
            cout << "请输入性别（男=1，女=2）：";
            if (cin >> sex) {
                if (sex == 1 || sex == 2) {
                    ab->personArray[ret].sex = sex;
                    validInput1 = true;
                }
                else {
                    cout << "输入错误" << endl;
                }
            }
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "输入无效" << endl;
            }
        }
        int age;
        bool validInput2 = false;
        while (!validInput2) {
            cout << "请输入年龄：";
            if (cin >> age) {
                ab->personArray[ret].age = age;
                validInput2 = true;
            }
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "输入无效" << endl;
            }
        }
        string phone;
        cout << "请输入电话：";
        cin >> phone;
        ab->personArray[ret].phone = phone;
        string address;
        cout << "请输入地址：";
        cin >> address;
        ab->personArray[ret].address = address;
        cout << "修改成功" << endl;
    }
    else {
        cout << "未找到该联系人" << endl;
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
    cout << "通讯录已清空" << endl;
    saveToFile(ab);
    system("pause");
    system("cls");
}

void saveToFile(struct Addressbook* ab) {
    ofstream outFile("addressbook.dat");
    if (!outFile) {
        cout << "无法保存通讯录到文件" << endl;
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