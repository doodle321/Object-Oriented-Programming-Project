#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class Students{
    public:
        string name;
        int age;
        string cnic;
        int dept;
        string deptl [4] = {"Information Technology", "Data Science", "Computer Science", "Maths"};
        
        void add_stud(){
            int cont = 1;
            char choice;
            system("clear");

            while(cont == 1){
                choice = 'a';
                cout << "Student Name: ";
                cin >> name;
                cout << "\nAge: ";
                cin>> age;
                cout << "\ncnic: ";
                cin>>cnic;
                cout << "\n1) IT\n2) DS\n3) CS\n4) Maths\ndepartment choice: ";
                cin >>dept;
                dept--;
                
                while(choice != 'y' && choice != 'n'){
                    cout << "\n\nPlease recheck all the information\n\nSubmit? (y/n): ";
                    cin >> choice;
                    if (choice == 'y'){
                        cont = 0;
                    }
                    else if (choice == 'n'){
                        cont = 1;
                        system("clear");
                        cout << "enter your details again\n";
                    } 
                    else {
                        cout << "\n invalid choice.";
                    }
                }
            }
        }
        void view(){
            cout << "Name: " << name <<"\nAge: " << age << "\ncnic: " << cnic << "\ndept: " << deptl[dept];
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
            else if(i == 0 || i < 0){
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
    return 0;
}
