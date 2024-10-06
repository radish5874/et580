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

void addStudent( Student *a,int capacity, int &num,string name,int E1, int E2){
    if (num < capacity){
        Student x;
        x.setName(name);
        x.setExam1(E1);
        x.setExam2(E2);
        a[num]= x;
        num++;
    }
}

void output(Student *arr,int capacity){
    for(int i=0; i<capacity;i++){
        cout<< "Name: " << arr[i].getName() << endl;
        cout<< "Exam 1: " << arr[i].getExam1() << endl;
        cout<< "Exam 2: " << arr[i].getExam2() << endl;
        cout<< "GPA: " << arr[i].getGrade() << endl;
        cout<< endl;
    
    }
}

int main(){
    int capacity = 10;
    Student students[capacity];
    int num = 0; 
    addStudent(students,capacity,num,"Amy",95,90); 
    addStudent(students,capacity,num,"Bob",74,63); 
    addStudent(students,capacity,num,"Charlie",86,80); 
    addStudent(students,capacity,num,"Daisy",75,90); 
    addStudent(students,capacity,num,"Edward",24,66); 
    output(students,num);
return 0;
}
