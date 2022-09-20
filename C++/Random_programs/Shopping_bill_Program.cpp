#include <iostream>     //defining the header files
#include <iomanip>
#include <string>
using namespace std;

int main() {

    int n;
    cout << "Enter how many products you bought: ";
    cin >> n;
    cin.ignore(1000, '\n'); // eat the newline

    double total_amount = 0.0;

    for (int i = 0; i < n; ++i) {

        string product_name;
        double price;
        int amount;

        cout << "Enter the name of the product you bought: ";
        getline(cin, product_name);

        cout << "Enter the price of the product: ";
        cin >> price;

        cout << "Enter the quantity of the product: ";
        cin >> amount;
        cin.ignore(1000, '\n'); // eat the newline

        double subtotal = price * amount;
        cout << "Your subtotal for " << product_name << " is: " << subtotal << "\n\n";

        total_amount += subtotal;
    }

    cout << "Your total is: " << total_amount << '\n'<<"Thank you"<<endl;


return 0;

}
