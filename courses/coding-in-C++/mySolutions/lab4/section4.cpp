#include <iostream>
#include <vector>
#include <string>

class Product;
class Inspection;
class InspectionTemplate;
class WeightCheck;
class VisualInspection;
class TemperatureTest;
class electricEngine;
class combustionMotor;

int main(){
    return 0;
}

//Interface
class Inspection{
    public:
        virtual void inspect()=0;
        virtual void printInspection()const=0;
        virtual ~Inspection();
};

//abstract class
class Product{
    protected:
        InspectionTemplate *InspectionTemplate;
        int ID;
        std::string name;
    public:
        virtual void createReport() const =0;
        virtual ~Product(){}
};

class electricEngine: public Product{
    private:
        double temp;
        bool visualDefectStatus;
        double weight;
        double voltage;
    public:
        bool getDefectStatus(){
            return visualDefectStatus;
        }

        double getWeight(){
            return weight;
        }

        double getTemp(){
            return temp;
        }

        double getVoltage(){
            return voltage;
        }
};