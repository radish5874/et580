#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int exam1grade,exam2grade;
    
    
    double calcGPA(int g1,int g2){
    return (g1+g2)/2;
    }


public:
    // mutator
    void setName(string n){
        name = n;
    }
    void setExam1(int g1){
        exam1grade = g1;
    }
    void setExam2(int g2){
        exam2grade = g2;
    }

    // accessor 访问者
    string getName(){ return name;}
    int getExam1(){ return exam1grade;}
    int getExam2(){ return exam2grade;}
    char getGrade(){ 
    double gpa =calcGPA(exam1grade,exam2grade);
    if(gpa>=90) return 'A';
    else if(gpa>=80) return 'B';
    else if(gpa>=70) return 'C';
    else if(gpa>=60) return 'D';
    else return 'F';
    }
};

int main(){
    Student a; 
    a.setName("David"); 
    a.setExam1(90);
    a.setExam2(80); 
    cout<<a.getName()<<endl; 
    cout<<a.getExam1()<<endl; 
    cout<<a.getExam2()<<endl; 
    cout<<a.getGrade()<<endl;

return 0;
}
