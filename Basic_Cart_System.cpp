#include <iostream>
using namespace std;

class fruit{
    public:
        string name;
        int weight;
        int price;
        int space;

        int add(string& cart,int& wgt, int& aprc){
            weight = 0;
            system("clear");
            cout <<name << " " << price <<"/KG \nenter the weight (KGs): ";
            cin >> weight;

            cout << "\n \n \n";

            if (weight < 0){
                cout << "can not add negative weight. \n";
                return 0;
            }

            wgt += space*weight;

            if (wgt > 100){
                if (wgt-100 < space){
                    cout << "insufficient storage, can not add this item to cart \ntry adding something else \n \n";
                }

                else if (weight > 1 && wgt-100 > space){
                    cout << "insufficient storage, try adding less of this item \n";
                }
                wgt -= space*weight;
            }

            else{
                system("clear");
                aprc += price*weight;
                cart += name + "(" + to_string(weight) + "KGs) Rs" + to_string(price*weight);
                cout << cart << "   Total Price: Rs" << aprc << endl << endl;
                if (wgt < 98){
                    cout << "want to add something else? \navailable items:  apple   mango   orange  melon   banana \n";
                }
            }
            return 0;
        }
};

void checkout(int cprc, string ccart){
    system("clear");
    int pay;
    cout << "\n \n" << ccart << "\n";
    cout << "\n \nyour total is: Rs" << cprc;
    cout << "\nenter amount to pay: Rs";
    cin >> pay;

    if(pay < cprc){
        do{
            cout << "insufficient amount. try again.";
            cout << "\nenter amount to pay: Rs";
            cin >> pay;
        }while(pay < cprc);
    }

    if(pay >= cprc){
        cout << "your change is: Rs" << pay - cprc << "\n \nthanks for shopping \n \n";
        char quit;
        cout << "enter any key to exit";
        cin >> quit;
    }
}

int main(){

    string c = "cart: ";
    string choice;
    int adwgt = 0;
    int mprc = 0;

    fruit apple;
        apple.name = "   apple";
        apple.price = 60;
        apple.space = 2;

    fruit mango;
        mango.name = "   mango";
        mango.price = 140;
        mango.space = 4;

    fruit banana;
        banana.name = "   banana";
        banana.price = 70;
        banana.space = 5;

    fruit melon;
        melon.name = "   melon";
        melon.price = 80;
        melon.space = 6;

    fruit orange;
        orange.name = "   orange";
        orange.price = 60;
        orange.space = 3;

    fruit grape;
        grape.name = '   grape';
        grape.price = 60;
        grape.space = 4;

    cout << "hello and welcome to our shop. what do you want to buy today? \nadd apple, mango, banana, melons and oranges to you cart\nor just type checkout for checkout \n";

    do{
        if (98 < adwgt && choice != "cart"){
            cout << "your cart is full type 'checkout' to checkout \n";
        }

        cin >> choice;

        if(choice == "apple"){
            system("clear");
            apple.add(c,adwgt,mprc);
        }

        else if(choice == "mango"){
            system("clear");
            mango.add(c,adwgt,mprc);
        }

        else if(choice == "banana"){
            system("clear");
            banana.add(c,adwgt,mprc);
        }

        else if(choice == "melon"){
            system("clear");
            melon.add(c,adwgt,mprc);
        }

        else if(choice == "orange"){
            system("clear");
            orange.add(c,adwgt,mprc);
        }

        else if (choice == "cart"){
            system("clear");
            cout << "\n \nfilled:" << adwgt << "%    remaining space: " << 100-adwgt << "%\n \n";

            cout << c << "   Total Price: Rs" << mprc << endl << endl;

            if (99 <= adwgt){
                cout << "can not add anything else to the cart, type 'checkout' to checkout \n \n";
            }

            else{
                cout << "want to add something else? \navailable items:  apple   mango   orange  melon   banana \nor enter checkout for chekout \n \n";
            }
        }

        else if (choice == "checkout"){}

        else{
            cout << "please enter the correct name. \n \n \n";
        }

        }while(choice != "checkout");

            system("clear");
            checkout(mprc,c);

        return 0;
}
