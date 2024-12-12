//Group Prject By;
//ShaheerAli(BSIT-2024-035)
//saifurrehman(BSIT-2024-037)
//Muhammad Wasif(BSIT-2024-040)
//Muhammad Ammar(BSIT-2024-044)
//Husnain Ali(BSIT-2024-045)
//Abbas Ali(BSIT-2024-046)
//Muhammad Aswed(BSIT-2024-048)

#include <iostream>     //for input output service
#include <string>       //to manage string data type

using namespace std;


class Appointment {     //to store slot details
public:
    string patientName;
    string patientContact;
    std::string patientAilment;
    string status = "available" ;
};

class slots {           //to create slots
private:
    Appointment appointments[8];
    string appointmentStatus[8];

public:
    slots() {
        for (int i = 0; i < 8; ++i) {               //creating slots as objects
            appointmentStatus[i] = "Available";
        }
    }

    void bookappointment() {                //function to book appointment slots
        while(1){
            system("cls");
            cout << " ----- Book Your Appointment ---- \n";
            cout << "\n    ----- Available slots ---- \n\n";

            cout << "Slot#      Time     Slot Status\n-------------------------------\n";
            for (int i = 0; i < 8; ++i) {
                cout <<"  " << i + 1 << "  ->    " << (i + 9) << ":00 - " << appointmentStatus[i] << endl;
            }

            cout << "\n\nInput slot number of your choice or '0' to go back : ";
            int choice;
            cin >> choice;                  //taking user input for desired slot

            if (choice > 0 && choice <= 8) {
                if (appointmentStatus[choice - 1] == "Available") {          //taking patient's info if slot is available    
                cin.ignore();       //ignoring the line left by previous input
                cout << "\nEnter your First name: ";
                getline(std::cin, appointments[choice - 1].patientName);       // input name 

                cout << "\nEnter your contact number: ";
                getline(std::cin, appointments[choice - 1].patientContact);    //input contact number

                cout << "\nBriefly describe your ailment: ";
                getline(std::cin, appointments[choice - 1].patientAilment);   //input illness / ailment

                    appointmentStatus[choice - 1] = "Booked";                 //changing slot status from available to booked
                    appointments[choice - 1].status = "Booked";
                }
                else {                  //telling user if slot is not availble
                    cout << "Slot "<< choice << " is already booked.\npress enter to continue...";
                    cin.ignore();
                    cin.ignore();
                }
            }
            else if (choice < 0 || choice > 8) {           //telling user if the slot does not exist
                cout << "Invalid choice.\n";
            }
            else if(choice == 0){       //going back if input is "0"
                return;
            }
        }
        system("cls");
    }

    void displayAppointments() {        //displaying slot's complete info for doctor
        for (int i = 0; i < 8; ++i) {
            cout << "Slot " << i + 1;
            if (appointmentStatus[i] == "Booked") {  //if slot booked displaying patients info   
                cout << " - Booked\n\t- Patient: " << appointments[i].patientName << "\n \t";   //printing patient's name
                cout<< "- patien contact number: " << appointments[i].patientContact <<"\n \t"; //patient's contact number
                cout<< "- patient Ailment: " <<appointments[i].patientAilment << endl << endl;  //patient's illness or aiment.
            }
            else {
                cout << " - Available" << endl;     //when slot available displaying available
            }
        }
        cout<<"\n Press Enter to continue...";
        getchar();getchar();
    }
};

int login(slots& slotManager) {             //login system for doctor to protect patient's personal info
        string password;
        cout << "\n\npassword = 'doctor'";
        cout << "\n\nenter password: ";
        cin >> password;

        if (password == "doctor") {
            system("cls");
            slotManager.displayAppointments();
        }
        else {
            system("cls");
            cout << "incorrect password\n";
            return 0;
        }
    return 0;}

int main() {
    system("cls");

    cout << "\t\t    --- Clinic Appointment System --- \n-------------------------------------------------------------------------\n";
    cout << "\t\t\t----- Project by ---- \n-------------------------------------------------------------------------\n";
    cout << "        Shaheer Ali(BSIT-2024-035) - Saifurrehman Rao(BSIT-2024-037) \n";
    cout << "       Muhammad Wasif(BSIT-2024-040) - Muhammad Ammar(BSIT-2024-044)";
    cout << "\n           Husnain Ali(BSIT-2024-045) - Abbas Ali(BSIT-2024-046) \n\t\t       Muhamad Aswed(BSIT-2024-048)\n";

    cout<<"\n Press Enter to continue...";
    cin.ignore();
    slots slotManager;
    char continueProgram = 'y';
    system("cls");
    
    while (continueProgram == 'y') {
        int choice;
        cout << "\n--- Home Page ---\n";
        cout << "1. Book An Appointment\n";
        cout << "2. Doctor Login\n";
        cout << "3. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                system("cls");
                slotManager.bookappointment();      //calling appointment booking function
                system("cls");
                break;
            }
            case 2: {
                login(slotManager);         //calling doctor's login function
                system("cls");
                break;
            }

            case 3: {system("cls");
                continueProgram = 'n';  //if exitted, loop is broken
                break;
            }

            default: {          //in case of invalid input printing invalid choice.
                system("cls");
                cout << "Invalid choice!\n";
                break;
            }
        }
    }
    cout << "\nExiting program.\n";
    cout << "\t\t    --- Clinic Appointment System --- \n-------------------------------------------------------------------------\n";
    cout << "\t\t\t----- Project by ---- \n-------------------------------------------------------------------------\n";
    cout << "        Shaheer Ali(BSIT-2024-035) - Saifurrehman Rao(BSIT-2024-037) \n";
    cout << "        Muhammad Wasif(BSIT-2024-040) - Muhammad Ammar(BSIT-2024-044)";
    cout << "\n           Husnain Ali(BSIT-2024-045) - Abbas Ali(BSIT-2024-046) \n\t\t       Muhamad Aswed(BSIT-2024-048)\n";
    return 0;
}
