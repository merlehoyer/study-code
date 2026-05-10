#include <iostream>
#include <string>
#include <iomanip>
//using namespace std; // problematic can come to overlapps with other namespaces (deletes whole point of namespaces)

class Article {
    // as much as possible should be private -> only methods should be public
    // can be easily implemented since constructor alredy demands all atributes to be set beforhand
private:
    // some attributes can be alredy set as const since they aren´t supposed to be changed
    const std::string name;
    double price;
    int stock;
    const std::string category;
    const int id;
 public:  
    //more efficient with initialisation lists
    Article(std::string name, double price, int stock, std::string category, int id) 
    : name(name) , price(price), stock(stock), category(category), id(id)
    {}

    void setPrice(double price) {
        this->price = price; //double refference to same object (local objects overrides global)
    }

    void sell(int amount) {
        if((stock - amount)>=0){
        stock = stock - amount; //no check if stock is large enough
        }
        return;
    }

    void restock(int amount) {
        if(amount>0){
        this->stock += amount; //doesn´t check amount
        }
        return;
    }

    void applyDiscount(double percent) { //return value should be set to void
        
        if(percent>=0 && percent<100){
           price = price - price * (percent / 100); 
        }
        
        return;
    }

    double getPrice() const { // can be a const function
        return price;
    }

    bool isAvailable() const;
    void printInfo()const;
   
};

bool Article::isAvailable() const { //can be a const function
        if (stock > 0){
                return true;
            }
        else{
            return false;
        } // blocks missing
    }

void Article::printInfo() const { //can be a const function
        std::cout << "Article: " << name << std::endl;
        std::cout << "Category: " << category << std::endl;
        std::cout << "Price: " << price << std::endl;
        std::cout << "Stock: " << stock << std::endl;
        std::cout << "ID: " << id << std::endl;
    }

int main() {
    Article Laptop("Laptop", 999.99, 10, "Electronics", 101); //a is an indestinct name creates confusion

    Laptop.sell(15);
    Laptop.restock(5); //faulty logic -> restock should b eonly positive numbers
    //a.price = -100; // no negative numbers should be allowed
    Laptop.applyDiscount(30); // has a return value which gets lost -> void function should be implemented / should check wertebereich

    if (Laptop.isAvailable()) std::cout << "Article available" << std::endl; //block marks missing

    Laptop.printInfo();
    return 0;
    //return missing
}

// 1. new is not deleted because the destructor is not defined
// 2. copies all point to the same string => if you try to change one name you automatically change all of them
// 3. creates intend => instantly see which functions dont change values
// 4. values can be changed without checks if the change is valid

