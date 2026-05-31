#include <iostream>
#include <string>

constexpr double PI = 3.14159;

class Shape{
    public:
        virtual double calcArea()const =0;
        virtual ~Shape(){
            std::cout <<"del"<<std::endl;
        }
    protected:
       
};

class Cirlce: public Shape{
    public:
        double calcArea ()const {
            return PI * this->radius*this->radius;
        }
        Cirlce(int radius):radius(radius){}
        ~Cirlce()override{
            std::cout <<"circ del"<<std::endl;
        };
    protected:
        int radius;
        
};

class Rectangle: public Shape{
    public:
        double calcArea ()const{
            return this->length*this->width;
        }
        Rectangle(int length, int width): length(length), width(width){}
        ~Rectangle()override{
            std::cout<<"del Rec"<<std::endl;
        };
        protected:
        int length;
        int width;
        
};

int main(){

    Rectangle rec1(1,2);
    Rectangle rec2(3,4);

    Cirlce circ1(2);
    Cirlce circ2(3);

    
    Shape* arr_shape[4]={&rec1, &rec2, &circ1, &circ2};

    for(int i=0; i<4; i++){
        double area= arr_shape[i]->calcArea();
        std::cout<<area<<std::endl;
    }

    return 0;
}
// i see no difference between base and abstract class???