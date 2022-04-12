#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
using namespace std;
class Student {
public:
    Student();
    Student(const char* first, const char* last , const string& c);
    const char* getFirstName() const;
    const char* getLastName() const;
    void setFirstName(char* fName);
    void setLastName(char* lName);
    const string& getCourse();
    bool setCourse(const string& c);
    virtual bool enterGrade(const string& g, double s) = 0;
    virtual double finalAverage() const = 0;
    virtual istream& in(istream& in) = 0;
    void detailedOutput(ostream& o) const;
    virtual int getFinalExam() const = 0;
    static char finalToLetterGrade(double score);
// static char finaltolettergrade()
protected:
    char firstName[20];
    char lastName[20];
    string course;
};

class English: public Student {
public:
    English();
    English(const char* first, const char* last);
    int getFinalExam() const;
    double finalAverage() const;
    bool enterGrade(const string& g, double s);
private:
    double TERM_PAPER;
    double MIDTERM;
    double FINAL_EXAM;
    istream& in(istream& in);
};

class History: public Student {
public:
    History();
    History(const char* first, const char* last);
    int getFinalExam() const;
    double finalAverage() const;
    bool enterGrade(const string& , double );
private:
    double ATTENDANCE;
    double PROJECT;
    double MIDTERM;
    double FINAL_EXAM;
    istream& in(istream& in);

};

class Math: public Student {
public:
    Math();
    Math(const char* first, const char* last);
    int getFinalExam() const;
    double finalAverage() const;
    bool enterGrade(const string& g, double s);
private:
    double q1,q2,q3,q4,q5;
    double TEST_1;
    double TEST_2;
    double FINAL_EXAM;
    istream& in(istream& in);

};