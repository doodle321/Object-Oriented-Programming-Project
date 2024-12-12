//Group Prject By;
//ShaheerAli(BSIT-2024-035)
//saifurrehman(BSIT-2024-037)
//Muhammad Wasif(BSIT-2024-040)
//Muhammad Ammar(BSIT-2024-044)
//Husnain Ali(BSIT-2024-045)
//Abbas Ali(BSIT-2024-046)
//Muhammad Aswed(BSIT-2024-048)

#include <iostream>
#include <string>

using namespace std;


class Appointment {
public:
    string patientName;
    string patientContact;
    std::string patientAilment;
    string status = "available" ;
};

class slots {
private:
    Appointment appointments[8];
    string appointmentStatus[8];

public:
    slots() {
        for (int i = 0; i < 8; ++i) {
            appointmentStatus[i] = "Available";
        }
    }

    void bookappointment() {
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
            cin >> choice;

            if (choice > 0 && choice <= 8) {
                if (appointmentStatus[choice - 1] == "Available") {
                cin.ignore(); //ignoring the line left by previous input
                cout << "\nEnter your First name: ";
                getline(std::cin, appointments[choice - 1].patientName);

                cout << "\nEnter your contact number: ";
                getline(std::cin, appointments[choice - 1].patientContact);

                cout << "\nBriefly describe your ailment: ";
                getline(std::cin, appointments[choice - 1].patientAilment);

                    appointmentStatus[choice - 1] = "Booked";
                    appointments[choice - 1].status = "Booked";
                }
                else {
                    cout << "Slot "<< choice << " is already booked.\npress enter to continue...";
                    cin.ignore();
                    cin.ignore();
                }
            }
            else if (choice < 0 || choice > 8) {
                cout << "Invalid choice.\n";
            }
            else if(choice == 0){
                return;
            }
        }
        system("cls");
    }

    void displayAppointments() {
        for (int i = 0; i < 8; ++i) {
            cout << "Slot " << i + 1;
            if (appointmentStatus[i] == "Booked") {
                cout << " - Booked\n\t- Patient: " << appointments[i].patientName << "\n \t";
                cout<< "- patien contact number: " << appointments[i].patientContact <<"\n \t";
                cout<< "- patient Ailment: " <<appointments[i].patientAilment << endl << endl;
            }
            else {
                cout << " - Available" << endl;
            }
        }
        cout<<"\n Press Enter to continue...";
        getchar();getchar();
    }
};

int login(slots& slotManager) {
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
    cout << "        Shaheer Ali(BSIT-2024-035) - Saifurrehman Rao(BSIT-2024-037) \n        Muhammad Wasif(BSIT-2024-040) - Muhammad Ammar(BSIT-2024-044) ";
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
                slotManager.bookappointment();
                system("cls");
                break;
            }
            case 2: {
                login(slotManager);
                system("cls");
                break;
            }

            case 3: {system("cls");
                continueProgram = 'n';
                break;
            }

            default: {
                system("cls");
                cout << "Invalid choice!\n";
                break;
            }
        }
    }
    cout << "\nExiting program.\n";
    cout << "\t\t    --- Clinic Appointment System --- \n-------------------------------------------------------------------------\n";
    cout << "\t\t\t----- Project by ---- \n-------------------------------------------------------------------------\n";
    cout << "        Shaheer Ali(BSIT-2024-035) - Saifurrehman Rao(BSIT-2024-037) \n        Muhammad Wasif(BSIT-2024-040) - Muhammad Ammar(BSIT-2024-044) ";
    cout << "\n           Husnain Ali(BSIT-2024-045) - Abbas Ali(BSIT-2024-046) \n\t\t       Muhamad Aswed(BSIT-2024-048)\n";
    return 0;
}
