#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student {
public:
  string name;
  int age;
 
  void input() {
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
  }

  void display() {
    cout << "Name: " << name << ", Age: " << age << endl;
  }
};

void writeToFile() {
  Student student;
  student.input();

  fstream outFile ("students.txt", ios::app);
  if (outFile) {
    outFile << student.name << ' ' << student.age << endl;
    outFile.close();
    cout << "Student record written to file." << endl;
  }
  else {
    cout << "Error opening file for writing!" << endl;
  }
}

void readFromFile() {
  Student student;

  ifstream inFile("students.txt");
  if (inFile) {
    cout << "Reading student records from file:" << endl;
    while (inFile >> student.name >> student.age) {
      student.display();
    }
    inFile.close();
  }
  else {
    cout << "Error opening file for reading!" << endl;
  }
}

int main(){
  int choice;

  do {
    cout << "\nMenu:\n";
    cout << "1. Write student to file\n";
    cout << "2. Read students from file\n";
    cout << "3. Update student record\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
      writeToFile();
    }
    else if (choice == 2) {
      readFromFile();
    }
    else if (choice == 4) {
      cout << "Exiting program." << endl;
    }
    else {
      cout << "Invalid choice. Please try again." << endl;
    }
  } while (choice != 4);

  return 0;
}