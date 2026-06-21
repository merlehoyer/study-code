#include "header.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

int main(){
    Car::IDcounter=0;
    Fahrer::IDcounter=0;

    Elektro firstCarre(100,"MErcedes","B");
    PKW secondCarre(6.0, "Merceds","B");
    Fahrer myFahrer("Emma", "B");
    Fahrer secondFahrer("Greta", "A");
    firstCarre.printInfo();

    firstCarre.setNewFahrer(&myFahrer);
    secondCarre.setNewFahrer(&secondFahrer);

    firstCarre.printInfo();


    return 0;
}

//FunctionsCar
void Car::setNewFahrer( Fahrer *newFahrer){
    if(this->momFahrer!=nullptr){
        momFahrer= newFahrer;
    }else{
        std::cout<<"Error"<<std::endl;
    }
    return;
}
bool &Car::getAvailabilty (){
    return Avaliblity;
}
Car::Car(std::string Hersteller, std::string neededLicenz):Hersteller(Hersteller),neededLicenz(neededLicenz),CarID(IDcounter), Avaliblity(true), momFahrer(nullptr){
    IDcounter++;
}
std::string &Car::getLizenc(){
    return neededLicenz;
}

//Functions Fahrer
void Fahrer::borrowCar( Car *Fahrzeug){
    bool FührerscheinDa= false;
    auto it= std::find(Lizenc.begin(),Lizenc.end(), Fahrzeug->getLizenc());
    if(it!=Lizenc.end()){
        FührerscheinDa=true;
    }
    if(borrowedCar!=nullptr && FührerscheinDa==true && Fahrzeug->getAvailabilty()==true){
        borrowedCar=Fahrzeug;
        std::cout<<"Borrowed Fahrzeug"<<std::endl;
    }else{
        std::cout<<"Error could not borrow Car"<<std::endl;
    }
    return;
}
void Fahrer::setNewLicenz(std::string Licenz){
    Lizenc.push_back(Licenz);
    return;
}
void Fahrer::deletLizenc(std::string LizencToDel){
    auto it= std::find(Lizenc.begin(),Lizenc.end(), LizencToDel);
    if(it!=Lizenc.end()){
        Lizenc.erase(it);
    }else{
        std::cout<<"Lizenc could not be deleted"<<std::endl;
    }

}
Fahrer::Fahrer(std::string Name, std::string firstLizenc):Name(Name), Lizenc(1,firstLizenc),ID(IDcounter),borrowedCar(nullptr){
    IDcounter++;
};
std::string &Fahrer::getName(){
    return Name;
}

//Functions Elektro
void Elektro::printInfo() const {
    std::cout<<std::setw(20)<<"Type: "<<std::setw(20)<<"Electric Car"<<std::endl;
    std::cout<<std::setw(20)<<"Barnd: "<<std::setw(20)<<Hersteller<<std::endl;
    std::cout<<std::setw(20)<<"BatteryKapa: "<<std::setw(20)<<batteryKap<<std::endl;
    std::cout<<std::setw(20)<<"Available: "<<std::setw(20)<<Avaliblity<<std::endl;
    std::cout<<std::setw(20)<<"NeededLicense: "<<std::setw(20)<<neededLicenz<<std::endl;
    std::string nameFahrer;
    if(momFahrer==nullptr){
    nameFahrer="No Driver assigned";
   }else{
    nameFahrer= momFahrer->getName();
   }
    std::cout<<std::setw(20)<<"Driver: "<<std::setw(20)<<nameFahrer<<std::endl;
}
Elektro::Elektro(double batteryKapa, std::string Hersteller, std::string neededLicenz):batteryKap(batteryKapa), Car(Hersteller, neededLicenz){}

//Functions PKW

void PKW::printInfo() const {
    std::cout<<std::setw(20)<<"Type: "<<std::setw(20)<<"PKW"<<std::endl;
    std::cout<<std::setw(20)<<"Barnd: "<<std::setw(20)<<Hersteller<<std::endl;
    std::cout<<std::setw(20)<<"Verbrauch: "<<std::setw(20)<<Verbrauch<<std::endl;
    std::cout<<std::setw(20)<<"Available: "<<std::setw(20)<<Avaliblity<<std::endl;
    std::cout<<std::setw(20)<<"NeededLicense: "<<std::setw(20)<<neededLicenz<<std::endl;
   std::string nameFahrer;
   if(momFahrer==nullptr){
    nameFahrer="No Driver assigned";
   }else{
    nameFahrer= momFahrer->getName();
   }
    std::cout<<std::setw(20)<<"Driver: "<<std::setw(20)<<nameFahrer<<std::endl;
}

PKW::PKW(double Verbrauch, std::string Hersteller, std::string neededLicenz):Verbrauch(Verbrauch), Car(Hersteller, neededLicenz){}