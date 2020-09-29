
#include<iostream>
using namespace std;
class Course{
    int c_number;
    float c_gpa;
    float c_credits;
public:
    void set_c_info(int c_number,float c_gpa,float c_credits){
        this->c_number = c_number;
        this->c_gpa = c_gpa;
        this->c_credits = c_credits;
    }
};
class Student{
    Course course[3];
public:
    int student_id;
    float cgpa;
    int merit_position;

    friend istream& operator>>(istream&,Student&);
    friend ostream& operator<<(ostream& out,Student student);

};
istream& operator>>(istream& in,Student& student){
    cout<<"Enter Student ID: ";
    cin>>student.student_id;
    float c_gpa,c_credits;
    float total_credits=0,total_gpa=0;
    for(int i=0;i<3;i++){
        cout<<"Enter Course "<<i+1<<" Grad point and credits: ";
        cin>>c_gpa>>c_credits;
        total_credits+=c_credits;
        total_gpa+=(c_gpa*c_credits);
        student.course[i].set_c_info(i+1,c_gpa,c_credits);
    }
    student.cgpa=(total_gpa/total_credits);
    return in;
};
ostream& operator<<(ostream& out,Student student){
    cout<<"student id: "<<student.student_id<<endl;
    cout<<"Cgpa: "<<student.cgpa<<endl;
    cout<<"Merit: "<<student.merit_position<<endl;
    return out;
}
void set_merit(Student student[],int N){
    for(int i=0;i<N;i++){
        int merit=0;
        for(int j=0;j<N;j++){
            if(student[i].cgpa<student[j].cgpa) merit++;
        }student[i].merit_position=merit+1;
    }

}
int main(){
    cout<<"Enter the number of Student: ";
    int number_of_student;
    cin>>number_of_student;
    Student student[number_of_student];
    for(int i=0;i<number_of_student;i++){
        cin>>student[i];
    }
    set_merit(student,number_of_student);
    for(int i=0;i<number_of_student;i++){
        cout<<student[i]<<endl;
    }
    return 0;
}
