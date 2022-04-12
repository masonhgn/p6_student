#include "Student.h"
#include <iostream>
using namespace std;


Student::Student() {
    strcpy(firstName, "");
    strcpy(lastName, "");
    course = "";
}

Student::Student(const char* fName, const char* lName, const string& c) {
    strcpy(firstName, fName);
    strcpy(lastName, lName);    
    course = c;
}

const string& Student::getCourse() {return course;}

bool Student::setCourse(const string& c) {
    course = c;
    return true;
}

const char* Student::getFirstName() const {return firstName;}
const char* Student::getLastName() const {return lastName;}

void Student::setFirstName(char* fName) {
    strcpy(firstName, fName);
}

void Student::setLastName(char* lName) {
    strcpy(lastName, lName);
}

char Student::finalToLetterGrade(double d) {
    if (d >= 90) return 'A';
  else if (d >= 80) return 'B';
  else if (d >= 70) return 'C';
  else if (d >= 60) return 'D';
  else return 'F';
}

void Student::detailedOutput(ostream& o) const {

    o << left << firstName << " " << 
    setw(41-strlen(firstName)) //name part
     << lastName << //name part
    setw(5) << getFinalExam() << setw(8) << finalAverage() << 
    Student::finalToLetterGrade(finalAverage()) << endl;
}


////////////////////////////////////////////////////////

English::English() {
    strcpy(firstName, "");
    strcpy(lastName, "");  
    course = "English";

    TERM_PAPER = 0, MIDTERM = 0; FINAL_EXAM = 0;
}

English::English(const char* fName, const char* lName) 
: Student(fName,lName, "English") {
    //repeat for all 
    // ./a.out
    TERM_PAPER = 0, MIDTERM = 0; FINAL_EXAM = 0;
}

double English::finalAverage() const {
    double totalGrade = 0;
    totalGrade += ((TERM_PAPER/100)*0.25);
    totalGrade += ((MIDTERM/100)*0.35);
    totalGrade += ((FINAL_EXAM/100)*0.4);
    totalGrade = totalGrade * 100;
    return totalGrade;
}

int English::getFinalExam() const {
    return FINAL_EXAM;
}

bool English::enterGrade(const string& grade, double score){
    if (grade == "term_paper" || grade == "TERM_PAPER") {
        TERM_PAPER = score;
        return true;
    } else if (grade == "midterm" || grade == "MIDTERM") {
        MIDTERM = score;
        return true;
    } else if (grade == "final_exam" || grade == "FINAL_EXAM") {
        FINAL_EXAM = score;
        return true;
    } else return false;
}

istream& English::in(istream& in) {
    return in >> TERM_PAPER >> MIDTERM >> FINAL_EXAM;
}


//////////////////////////////////////////////////

History::History() {
    strcpy(firstName, "");
    strcpy(lastName, "");  
    course = "History";

    ATTENDANCE = 0, PROJECT = 0, MIDTERM = 0, FINAL_EXAM = 0;
}

History::History(const char* fName, const char* lName) 
: Student(fName, lName, "History") {

    ATTENDANCE = 0, PROJECT = 0, MIDTERM = 0, FINAL_EXAM = 0;
}

double History::finalAverage() const {
    double totalGrade = 0;
    totalGrade += ((ATTENDANCE/100)*0.1);
    totalGrade += ((PROJECT/100)*0.3);
    totalGrade += ((MIDTERM/100)*0.3);
    totalGrade += ((FINAL_EXAM/100)*0.3);
    totalGrade = totalGrade * 100;

    return totalGrade;
}

int History::getFinalExam() const {
    return FINAL_EXAM;
}


bool History::enterGrade(const string& grade, double score) {
    if (grade == "attendance" || grade == "ATTENDANCE") {
        ATTENDANCE = score;
        return true;
    } else if (grade == "project" || grade == "PROJECT") {
        PROJECT = score;
        return true;
    } else if (grade == "midterm" || grade == "MIDTERM") {
        MIDTERM = score;
        return true;
    } else if (grade == "final_exam" || grade == "FINAL_EXAM") {
        FINAL_EXAM = score;
        return true;
    } else return false;
}

istream& History::in(istream& in) {
    return in >> ATTENDANCE >> PROJECT >> MIDTERM >> FINAL_EXAM;
}


//////////////////////////////////////////////////


Math::Math() {
    strcpy(firstName, "");
    strcpy(lastName, "");
    course = "Math";

    q1=0,q2=0,q3=0,q4=0,q5=0, TEST_1 = 0, TEST_2 = 0, FINAL_EXAM = 0;
}

Math::Math(const char* fName, const char* lName) 
: Student(fName, lName, "Math") {
    q1=0,q2=0,q3=0,q4=0,q5=0, TEST_1 = 0, TEST_2 = 0, FINAL_EXAM = 0;

}

bool Math::enterGrade(const string& grade, double score) {
    if (grade == "test_1" || grade == "TEST_1") {
        TEST_1 = score;
        return true;
    } else if (grade == "test_2" || grade == "TEST_2") {
        TEST_2 = score;
        return true;
    } else if (grade == "final_exam" || grade == "FINAL_EXAM") {
        FINAL_EXAM = score;
        return true;
    } else return false;
}

double Math::finalAverage() const {
    double totalGrade = 0;
    totalGrade += (((q1+q2+q3+q4+q5)/500)*0.2);
    totalGrade += ((TEST_1/100)*0.25);
    totalGrade += ((TEST_2/100)*0.25);
    totalGrade += ((FINAL_EXAM/100)*0.3);
    totalGrade = totalGrade * 100;

    return totalGrade;
}

int Math::getFinalExam() const {
    return FINAL_EXAM;
}

istream& Math::in(istream& in) {
    return in >> q1 >> q2 >> q3 >> q4 >> q5 >> TEST_1
    >> TEST_2 >> FINAL_EXAM;
}


