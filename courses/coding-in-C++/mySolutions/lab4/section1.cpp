#include <iostream>
#include <vector>
#include <cmath>

class Vector2D{
    private:
        double x;
        double y;
    public:
        Vector2D():x(0),y(0){}
        Vector2D(double x, double y):x(x),y(y) {}
        double getX(){
            return x;
        }
        double getY(){
            return y;
        }
        void printV()const{
            std::cout<<"x: "<<x<<" | y:"<<y<<std::endl;
        }
        double lengthVector(){
            double length= sqrt((getX()*getX())+(getY()*getY()));
            return length;
        }
        double lengthVector(int precision){
            double length= sqrt((getX()*getX())+(getY()*getY()));
            double factor= std::pow(10.0, precision);
            return std::round(length*factor) /factor;
        }
        Vector2D &add2Vec(Vector2D vec1, Vector2D vec2){
            Vector2D newVec((vec1.getX() +vec2.getX()), (vec1.getY() +vec2.getY()));

            return newVec;
        }

        Vector2D& operator +=( Vector2D& vec_right){
            this->x= x + vec_right.getX();
            this->y= y+ vec_right.getY();
            return *this;
        }

        Vector2D& operator *(int a){
            this->x= x*a;
            this->y= y*a;

            return *this;
        }
        
    
};

Vector2D operator +(Vector2D& vec_right, Vector2D& vec_left){
    
    return Vector2D(vec_right.getX()+vec_left.getX(), vec_right.getY()+vec_left.getY());
}

Vector2D operator *(int a, Vector2D& vec){
    return Vector2D(vec.getX()*a, vec.getY()*a);
}




int main(){

    Vector2D myV(1,2);
     

    return 0;
}