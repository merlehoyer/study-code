#ifndef HEADER_HPP
#define HEADER_HPP
#include <string>
#include <iostream>
#include <vector>

class Fahrer;

class Car{
    protected:
    const int CarID;
    std::string Hersteller;
    bool Avaliblity;
    std::string neededLicenz;
    Fahrer *momFahrer;
    public:
    static int IDcounter;
    virtual void printInfo() const =0;
    void setNewFahrer( Fahrer *newFahrer);
    bool &getAvailabilty ();
    virtual ~Car(){};
    Car(std::string Hersteller, std::string neededLicenz);
    std::string &getLizenc();
};

class Fahrer{
    private:
    const int ID;
    std::string Name;
    Car *borrowedCar;
    std::vector<std::string> Lizenc;

    public:
    static int IDcounter;
    void borrowCar( Car *Fahrzeug);
    void setNewLicenz(std::string Licenz);
    void deletLizenc(std::string LizencToDel);
    std::string &getName();
    Fahrer(std::string Name, std::string firstLizenc);
    ~Fahrer(){};
};

class Elektro: public Car{
    private:
    double batteryKap;
    public:
    void printInfo() const override;
    ~Elektro()override{}
    Elektro(double batteryKapa, std::string Hersteller, std::string neededLicenz);
};

class PKW: public Car{
    private:
    double Verbrauch;
    public:
    void printInfo() const override;
    ~PKW()override{}
    PKW(double Verbrauch, std::string Hersteller, std::string neededLicenz);
};

#endif