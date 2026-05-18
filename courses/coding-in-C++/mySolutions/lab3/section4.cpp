#include <iostream>
#include <string>
#include <vector>
#define MAX_WEAPONS 10

class Weapon{
    private:
        
        int damageValue;
    public:
        std::string name;
        Weapon(std::string name): name(name){}
};

class Inventory{
    private:
        Weapon* inventory[MAX_WEAPONS];
    public:
        bool isEmpty()const;
        bool isFull() const;
        bool addItem(const std::string& item);
        int InventorySlotsfree()const;
        std::string removeLastItem();
        Inventory(){
            for(int i=0;  i <10; i++){
                inventory[i]= nullptr;
            }
        }
        ~Inventory(){ // needs destructor so that no memoryleaks occur
            int iterator=0;
            while(inventory[iterator]!= nullptr && iterator!=MAX_WEAPONS){
                iterator++; //läuft bis 10 hoch wenn inventory voll ist
            }
            
            iterator--; //inventory[9] 
            
            for(int i=iterator ; i>=0; i--){
               
                delete inventory[i];

            }
        }
};

class Healer;

class Character{
    friend class Healer;
    public:
        void printStatus();
        void levelUp();
        Inventory& getInventory();
        Character(std::string name, int healthpoints): name(name),healthPoints(healthpoints), inventory(){}
    private:
        int healthPoints;
    protected:
        int level;
        std::string name;
        Inventory inventory;
};

class Warrior: public Character{
    protected: 
        int weaponSkillPoints;
    public:
    Warrior(std::string name, int healthpoints):Character(name, healthpoints){}
    
};

class Mage: public Character{
    protected:
        int manaPoints;
    public:
        Mage(std::string name, int healthpoints):Character(name, healthpoints){}
};

class Thief: public Warrior{
    public:
        Thief& steal( Character& Target);
        Thief(std::string name,int healthpoints):Warrior(name, healthpoints){}
};

class Healer: public Mage{
    public:
        Healer& heal(Character& Healer);
        Healer(std::string name,int healthpoints):Mage(name,healthpoints){}
};

int main(){

    Character character("try out", 24);
    Inventory inventory= character.getInventory();
    //Weapon newWeapon;
    
    bool items= inventory.addItem("sword");
    
    bool ja_nein= inventory.isEmpty();

    std::cout<<ja_nein<<std::endl;

    Thief Molly_Thief("Molly",24);
    Healer Gandalf_Healer("Gandalf",24);

    Molly_Thief.getInventory().addItem("sword");
    Gandalf_Healer.getInventory().addItem("Wizzardstick");

    Molly_Thief.printStatus();
    Gandalf_Healer.printStatus();

    Molly_Thief.steal(Gandalf_Healer);
    Gandalf_Healer.heal(Gandalf_Healer);

    Molly_Thief.printStatus();
    Gandalf_Healer.printStatus();

    
    return 0;
}

//---------- Functions Character-------------//

void Character::printStatus() { //const weggemacht damit getInventory funktioniert

    int slotsfree= getInventory().InventorySlotsfree();


    std::cout<<"Character: "<< name<< " | Healthpoints: "<<healthPoints<<" | Slots in Inventory occupied: "<< slotsfree<<std::endl;
    
    return;
}
void Character::levelUp(){}
Inventory& Character::getInventory(){
    return inventory;
}

//----------Functions Inventory----------------//

bool Inventory::isEmpty()const{
    
    bool myReturn= true;
    
    for(int i =0; i<10; i++){
        if(inventory[i]!=nullptr){
            myReturn= false;
        }

        
    }

    return myReturn;
}
bool Inventory::isFull() const{
    
    bool myReturn= true;
    
    for(int i =0; i<10; i++){
        if(inventory[i]==nullptr){
            myReturn= false;
        }

        
    }

    return myReturn;
}
bool Inventory::addItem(const std::string& item){
    bool myReturn = false;
    int iterator=0;
    while(inventory[iterator]!= nullptr && iterator!=9){
        iterator++;
    }
    if(iterator==9 && inventory[9]!=nullptr){
        myReturn= false;
        // -> inventory full no space left to add
    }else{
        inventory[iterator]= new Weapon(item); //dynamically else object weapon will be lost after function ends -> needs destructor
        myReturn= true;
    }

    return myReturn;
    
}
std::string Inventory::removeLastItem(){
    // delete weapon!!!!!!!
    // removes last Item => ignores string
    // warum hat die fnktion ein rückgabe wert?
    
    int iterator=0;

    while(inventory[iterator]!= nullptr && iterator!=9){
        iterator++;
    }
    iterator--; //damit der letzte mit !=nullptr gelöscht wird
    std::string weaponName = inventory[iterator]->name;
    delete inventory[iterator];
    inventory[iterator]= nullptr;

    return weaponName;
}

int Inventory::InventorySlotsfree() const{
    //returns how many slots occupied
    int iterator =0;
    while(inventory[iterator]!= nullptr && iterator!=9){
        iterator++;
    }

    return iterator;
}

//----------- Functions Characters ----------------//

Healer& Healer::heal(Character& target){

    target.healthPoints++;

    return *this;
}

Thief& Thief::steal(Character& target){

    std::string nameItem =target.getInventory().removeLastItem();
    this->getInventory().addItem(nameItem);

    return *this;
}

