#include <iostream>
#include <string>
#include <iomanip>
using namespace std; // problematic can come to overlapps with other namespaces (defeats whole point of namespaces)

class Article {
    // as much as possible should be private -> only methods should be public
    // can be easily implemented since constructor alredy demands all atributes to be set beforhand
public:
    // some attributes can be alredy set as const since they aren´t supposed to be changed
    string name;
    double price;
    int stock;
    string* category;
    int id;
   
    //more efficient with initialisation lists
    Article(string name, double price, int stock, string category, int id) {
        name = name;
        price = price;
        stock = stock;
        this->id = id;
        this->category = new string;
        *this->category = category;
    }

    void setPrice(double price) {
        price = price; //double refference to same object (local objects overrides global)
    }

    void sell(int amount) {
        stock = stock - amount; //no check if stock is large enough
    }

    void restock(int amount) {
        this->stock += amount; //doesn´t check amount
    }

    double applyDiscount(double percent) { //return value should be set to void
        price = price - price * percent / 100;
        return price;
    }

    double getPrice() { // can be a const function
        return price;
    }

    //nicer outside class
    bool isAvailable() { //can be a const function
        if (stock > 0)
            return true;
        else
            return false; // blocks missing
    }
    //nicer outside class
    void printInfo() { //can be a const function
        cout << "Article: " << name << endl;
        cout << "Category: " << *category << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << stock << endl;
        cout << "ID: " << id << endl;
    }
};

int main() {
    Article a("Laptop", 999.99, 10, "Electronics", 101); //a is an indestinct name creates confusion

    a.sell(15);
    a.restock(-5); //faulty logic -> restock should b eonly positive numbers
    a.price = -100; // no negative numbers should be allowed
    a.applyDiscount(150); // has a return value which gets lost -> void function should be implemented

    if (a.isAvailable()) cout << "Article available" << endl; //block marks missing

    a.printInfo();
    //return missing
}

// 1. new is not deleted because the destructor is not defined
// 2. copies all point to the same string => if you try to change one name you automatically change all of them
// 3. creates intend => instantly see which functions dont change values
// 4. values can be changed without checks if the change is valid