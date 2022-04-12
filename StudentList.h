#include "Student.h"
using namespace std;
class StudentList
{
public:
    StudentList();		// starts out empty
    StudentList(const StudentList& c);
    ~StudentList();		// cleanup (destructor)
    StudentList(int s);
    void Insert(Student* s);

    bool ImportFile(const char* filename);
    bool CreateReportFile(const char* filename);

    void ShowList() const;	// print basic list data
    void SortList();

//examples/templates/tlist/tlist.h

private:
    Student** students;
    unsigned int size;
    int max;
    void Clone(const StudentList& );
    void Resize(unsigned int newSize);
};