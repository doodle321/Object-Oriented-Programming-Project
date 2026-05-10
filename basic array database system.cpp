#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class Students{
    public:
        string name;
        int age;
        int cnic;
        char dept;
        
        void add_stud(){
            system("clear");

            cout << "Student Name: ";
            cin >> name;
            cout << "\nAge: ";
            cin>> age;
            cout << "\ncnic: ";
            cin>>cnic;
            cout << "\na) CS\nb) IT\nc) DS\nd) maths\ndepartment choice: ";
            cin >>dept;
        }
        void view(){
            cout << "Name: " << name <<"\nAge: " << age << "\ncnic: " << cnic << "\ndept: ";
            switch (dept) {
                case 'a': {
                    cout << "Computer Science\n";
                    break;
                }

                case 'b': {
                    cout << "Information Technology\n";
                    break;
                }

                case 'c': {
                    cout << "Data Science\n";
                    break;
                }

                case 'd': {
                    cout << "Maths\n";
                    break;
                }
            }
            cout <<"\n------------------------------------\n";
        }
};

int main(){
    system("clear");
    Students studs[100];
    int i = 0;
    int l = 0;

    while (true){
        string choice;
        
        cout << "new register? y/n: " ;
        cin >> choice;

        if (choice == "y"){
            l =0;
            system("clear");
            studs[i].add_stud();
            i++;
            system("clear");
        }
        
        else{
            l++;
            if (l == 2){
                exit(0);
            }
            if(i == 0 || i < 0){
                break;
            }
            else{
                system("clear");
                for(int t= 0; t < i ; t++){
                    studs[t].view();
                }  
            }
        }
    }
}
