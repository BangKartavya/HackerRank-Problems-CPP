#include <iostream>
#include <sstream>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/

class Student{
    public:
        int age=0;
        string firstName = "";
        string lastName = "";
        int standard = 0;
    
    public:
        void set_age(int ag){
            age = ag;
        }
        void set_standard(int stdn){
            standard = stdn;
        }
        void set_first_name(string fname){
            firstName = fname;
        }
        void set_last_name(string lname){
            lastName = lname;
        }
        int get_age(){
            return age;
        }
        int get_standard(){
            return standard;
        }
        string get_first_name(){
            return firstName;
        }
        string get_last_name(){
            return lastName;
        }
        string to_string(){
            stringstream s;
            
            s << age;
            s << ",";
            s << firstName;
            s << ",";
            s << lastName;
            s << ",";
            s << standard;
            
            string str;
            s >> str;
            return str;
        }
};

int main() {
    Student st;
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}