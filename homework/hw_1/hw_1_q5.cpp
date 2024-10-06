#include <iostream>
using namespace std;

class Student{
private:
    class GPA{
    public:
        GPA(){}
        GPA(double g): lgpa(g){}

        char getLetterGrade(double gpa){
            if(gpa>=3.5) return 'A';
            else if(gpa>=2.5) return 'B';
            else if(gpa>=1.5) return 'C';
            else if(gpa>=1) return 'D';
            else return 'F';
        }
        double lgpa = 0.0;
    };
    GPA gpa;
    
    string name = "blank", major = "blank";
    char grade;

public: 

    Student(string n, string m, double g): name(n),major(m) {gpa.lgpa = g;}
    
    void display () {
        cout << "Name: " << name << endl << "Major: " << major << endl;
        cout << "GPA: " << gpa.lgpa << endl << "Grade: " << gpa.getLetterGrade(gpa.lgpa) << endl;
    }

};

int main() {

cout.setf(ios::fixed); // set to print two digit after decimal 
cout.precision(2);


Student s1("John Williams", "Music", 4.0); 
Student s2("Isaac Asimov", "English", 2.53); 
s1.display();
s2.display();




cout << endl;
return 0; }
