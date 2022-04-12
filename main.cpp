#include <iostream>
#include <fstream>
#include "StudentList.h"
#include <cstring>
using namespace std;


void ShowScreen(StudentList& sl);

int main() {
    StudentList sl;
    sl.ImportFile("test1.txt");
    sl.ImportFile("test2.txt");
    sl.ShowList();
    sl.SortList();
    cout << "sorted list: " << endl;
    sl.ShowList();
    return 0;
}

void ShowScreen(StudentList& sl) {
    char temp;
    cout << "\t*** Student List menu ***" << endl;

    cout << "I\tImport students from a file" << endl;
    cout << "S\tShow student list  (brief)" << endl;
    cout << "E\tExport a grade report (to file)" << endl;
    cout << "M\tShow this Menu" << endl;
    cout << "Q\tQuit Program" << endl;
    cin >> temp;

    if (temp == 'I') {
        char s[128];
        cout << "Enter filename: ";
        cin >> s;
        sl.ImportFile(s);
        ShowScreen(sl);
    }
    else if (temp == 'S') {
        sl.ShowList();
        ShowScreen(sl);
    }
    else if (temp == 'E') {
        char s[128];
        cout << "Enter filename: ";
        cin >> s;
        sl.CreateReportFile(s);
        ShowScreen(sl);
    }
    else if (temp == 'M') {
        ShowScreen(sl);
    }
    else if (temp == 'Q') {
        cout << "Goodbye!";
        exit(EXIT_SUCCESS);
    }
}