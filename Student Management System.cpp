#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Student {
    string id;
    string name;
    float score;
};

void showStudents(vector<Student>& list) {
    cout << "\n--- DANH SACH SINH VIEN ---\n";
    for (int i = 0; i < list.size(); i++) {
        cout << "ID: " << list[i].id
             << " | Name: " << list[i].name
             << " | Score: " << list[i].score << endl;
    }
}

void addStudent(vector<Student>& list) {
    Student s;
    cout << "Nhap ID: ";
    cin >> s.id;
    cin.ignore();
    cout << "Nhap ten: ";
    getline(cin, s.name);
    cout << "Nhap diem: ";
    cin >> s.score;

    list.push_back(s);
    cout << ">> Da them sinh vien!\n";
}

void findStudent(vector<Student>& list) {
    string id;
    cout << "Nhap ID can tim: ";
    cin >> id;

    for (auto s : list) {
        if (s.id == id) {
            cout << "Tim thay: " << s.name << " - " << s.score << endl;
            return;
        }
    }
    cout << "Khong tim thay!\n";
}

void deleteStudent(vector<Student>& list) {
    string id;
    cout << "Nhap ID can xoa: ";
    cin >> id;

    for (int i = 0; i < list.size(); i++) {
        if (list[i].id == id) {
            list.erase(list.begin() + i);
            cout << ">> Da xoa!\n";
            return;
        }
    }
    cout << "Khong tim thay!\n";
}

void saveToFile(vector<Student>& list) {
    ofstream file("students.txt");
    for (auto s : list) {
        file << s.id << "," << s.name << "," << s.score << endl;
    }
    file.close();
    cout << ">> Da luu file!\n";
}

void loadFromFile(vector<Student>& list) {
    ifstream file("students.txt");
    if (!file) return;

    Student s;
    while (getline(file, s.id, ',') &&
           getline(file, s.name, ',') &&
           file >> s.score) {
        file.ignore();
        list.push_back(s);
    }
    file.close();
}

int main() {
    vector<Student> list;
    loadFromFile(list);

    int choice;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Them sinh vien\n";
        cout << "2. Hien thi danh sach\n";
        cout << "3. Tim sinh vien\n";
        cout << "4. Xoa sinh vien\n";
        cout << "5. Luu file\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(list); break;
            case 2: showStudents(list); break;
            case 3: findStudent(list); break;
            case 4: deleteStudent(list); break;
            case 5: saveToFile(list); break;
        }

    } while (choice != 0);

    return 0;
}