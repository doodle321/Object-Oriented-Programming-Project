#include <iostream>
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Box.H>
#include <cstdlib>

using namespace std;


bool cont = 1;

class stdata{
    public:
        string name;
        string cnic;
        int age;
};

stdata Student [10];
string Dept[5] = {"cs", "IT", "DS", "AI", "Maths"};
int t = 0;

class SimpleWindow : public Fl_Window {
    public:
        SimpleWindow(int w, int h, const char* t) : Fl_Window(w, h, t) {   //window funciton
            begin();
            // x, y, width, height, label

            title = new Fl_Box(100, 10, 200, 50, "Basic Array Database");  //title
            title->labelfont(FL_BOLD);
            title->labelsize(20);

            text = new Fl_Box(10, 50, 110, 40, "Enter your name");         //prompting text box
            name = new Fl_Input(10, 80, 200, 25, "");                      //name field

            text = new Fl_Box(10, 110, 110, 40, "Enter your Age");         //prompting text box
            age = new Fl_Input(10, 140, 200, 25, "");                      //name field

            text = new Fl_Box(10, 170, 110, 40, "Enter your CNIC");         //prompting text box
            cnic = new Fl_Input(10, 200, 200, 25, "");                      //name field

            btn = new Fl_Button(8, 240, 60, 30, "Submit");                  //submit button
            btn->callback(button_cb, this);

            exit = new Fl_Button(68, 240, 60, 30, "Exit");
            exit->callback(exit_btn_cb, this);
            end();
        }
    private:
        Fl_Button* exit;
        Fl_Button* btn;
        Fl_Input* name;
        Fl_Box* text;
        Fl_Box* title;
        Fl_Input* cnic;
        Fl_Input* age;
        Fl_Box* text_error;

        static void button_cb(Fl_Widget* widget, void* data) {
            SimpleWindow* window = (SimpleWindow*)data;
            
            // 2. Push the text into the global variable
            string inputName = window->name->value();
            int inputAge = atoi(window->age->value());
            string inputCnic = window->cnic->value();

            // 2. Validate the INPUT, not the (currently empty) array slot
            if (!inputName.empty() && !inputCnic.empty() && inputAge >= 17){
                Student[t].name = window->name->value();
                Student[t].cnic = window->cnic->value();
                Student[t].age = atoi(window->age->value());
                t++;
                window->hide();
            }
            else if(inputAge < 17){
                if (!window->text_error){
                    window -> text_error = new Fl_Box(138, 240, 200, 30, "Write your correct age.");
                    window->add(window->text_error);
                    window->redraw();
                }
                else {
                    window->text_error->label("Write your correct age (17+).");

                    window->add(window->text_error);
                    window->redraw();
                }
            }
            else {
                if (!window->text_error){
                window -> text_error = new Fl_Box(138, 240, 200, 30, "Enter all your details \nand make sure they're correct");

                    window->add(window->text_error);
                window->redraw();
                }
                else {
                    window->text_error->label("Enter all your details!");
                    window->add(window->text_error);
                    window->redraw();
                }
            }
        }

        static void exit_btn_cb(Fl_Widget* widget, void* data) {
             cont = 0;
             SimpleWindow* win = (SimpleWindow*)data;
             win->hide();
        }
};

void view(){
            for (int r = 0 ; r < t ; r++){
                cout << "Name: " << Student[r].name <<"\nAge: " << Student[r].age << "\ncnic: " << Student[r].cnic; 
                cout <<"\n------------------------------------\n";
            }
        }

int main() {

    while (cont){
        SimpleWindow* win = new SimpleWindow(400, 290, "Registration");
        win->show();
        Fl::run();
    }
    view();
    return 0;
}
