#include "StudentList.h"
#include <fstream>
#include <cstring>
#include <string.h>
#include <cctype> //for extra credit only

using namespace std;
StudentList::StudentList() {
    max = 0;
    size = 0;
    students = nullptr;
}

StudentList::StudentList(int s) {
    size = 0;
    max = size;
    if (max <= 0) {
        students = nullptr;
        max = 0;
    } else Student *students[max];
}

StudentList::~StudentList() {
    delete[] students;
}

void StudentList::Clone(const StudentList& s) {
    max = s.max;
    size = s.size;
    Student** temp = new Student*[max];
    for (int i = 0; i < size-1; i++)
        temp[i] = s.students[i];
    delete[] students;
    students = temp;
}

void StudentList::Resize(unsigned int newSize) {
    Student** temp = new Student*[newSize];
    if (size > 0) {
        for (int i = 0; i < size; i++)
            temp[i] = students[i];
    }
    delete[] students;
    size = newSize;
    students = temp;
}

StudentList::StudentList(const StudentList &c) {
    Clone(c);
}

void StudentList::ShowList() const {
    cout << setw(20) << "LAST NAME:" << setw(20) << 
    "FIRST NAME: "<< setw(20) <<"COURSE:" << endl;
    for (int i = 0; i < size-1; i++) {
        cout << setw(20) << students[i]->getLastName() <<
        setw(20) << students[i]->getFirstName() <<
        setw(20) << students[i]->getCourse() << endl;
    }
}

void StudentList::Insert(Student* s) {
    if (size == max) {
        Resize(max+1);
    }
    students[size-1] = s;
    size++;
}

bool StudentList::ImportFile(const char* filename) {
    ifstream file(filename);
    if (!file.is_open()) return false;

    int len;
    file >> len;
    file.ignore(1, '\n');

    char last[20], first[20], buf[256];
    Student* temp;
    for (int i = 0; i < len; i++) { //do this (len) amount of times
    file.getline(last, 20, ','); // last name
    file.ignore(1, ' '); //ignore space
    file.getline(first, 20, '\n'); //first name

    int index = 0;
    while (true) {
      buf[index] = file.get(); 
      if (isdigit(file.peek())) {
        buf[index] = '\0';
        break;
      }
      index++; //buf is for storing the course
    }

    if (strcmp("English", buf) == 0) { 
      temp = new English(first, last); //create new temp student
    } else if (strcmp("History", buf) == 0) {
      temp = new History(first, last);
    } else if (strcmp("Math", buf) == 0) {
      temp = new Math(first, last);
    } else {
        cout << "buf: " << buf << endl;
    }

    temp->in(file); //what the fuck?
    //create in function for each student type
    //make it virtual function of student
    Resize(size + 1); //add one to aray
    students[size - 1] = temp; //add student to array


    file.ignore(16, '\n'); //go to next line
  }
  return true; //stop
}

bool StudentList::CreateReportFile(const char* filename) {
    ofstream file(filename);
    if (!file.is_open()) return false;

    file << "Student Grade Summary\n---------------------\n\n";

    file << "ENGLISH CLASS\n\n";

    file << "Student  \t\t\t\tFinal\tFinal\tLetter" << endl;
    file << "Name  \t\t\t\t\tExam\tAvg\tGrade" << endl;

    file << "-------------------------------------------------------------------------------\n";
    for (int i = 0; i < size; i++) {
        Student& temp = *students[i];
        string s(temp.getCourse());
        if (strcmp("English", s.c_str()) == 0)
            temp.detailedOutput(file);}
    file << "\n\n";
    
    file << "HISTORY CLASS\n\n";

    file << "Student  \t\t\t\tFinal\tFinal\tLetter" << endl;
    file << "Name  \t\t\t\t\tExam\tAvg\tGrade" << endl;

    file << "-------------------------------------------------------------------------------\n";
    for (int i = 0; i < size; i++) {
        Student& temp = *students[i];
        string s(temp.getCourse());
        if (strcmp("History", s.c_str()) == 0)
            temp.detailedOutput(file);}
    file << "\n\n";
    
    file << "MATH CLASS\n\n";

    file << "Student  \t\t\t\tFinal\tFinal\tLetter" << endl;
    file << "Name  \t\t\t\t\tExam\tAvg\tGrade" << endl;

    file << "-------------------------------------------------------------------------------\n";
    for (int i = 0; i < size; i++) {
        Student& temp = *students[i];
        string s(temp.getCourse());
        if (strcmp("Math", s.c_str()) == 0)
            temp.detailedOutput(file);}
    file << "\n\n";


    int aAmt = 0, bAmt = 0, cAmt = 0, dAmt = 0, fAmt = 0;
    for (int i = 0; i < size; i++) {
        Student& cur = *students[i];
        if (cur.finalAverage() >= 90) aAmt++;
        else if (cur.finalAverage() >= 80) bAmt++;
        else if (cur.finalAverage() >= 70) cAmt++;
        else if (cur.finalAverage() >= 60) dAmt++;
        else fAmt++;
    }

    file << "OVERALL GRADE DISTRIBUTION\n\n";
    file << "A:  " << aAmt << endl;
    file << "B:  " << bAmt << endl;
    file << "C:  " << cAmt << endl;
    file << "D:  " << dAmt << endl;
    file << "F:  " << fAmt << endl;
    return true;
}


void StudentList::SortList() {
    
}






