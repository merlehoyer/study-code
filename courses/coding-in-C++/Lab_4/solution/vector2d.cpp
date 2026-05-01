#include <iostream>
#include <cmath>

class Vector2D
{
private:
    double x;
    double y;

public:
    Vector2D() : x(0.0), y(0.0) {}
    Vector2D(double x, double y) : x(x), y(y) {}
    double getX() const { return x; }
    double getY() const { return y; }
    void print();

    double getMagnitude()
    {
        return sqrt((x * x) + (y * y));
    }
    double getMagnitude(int precision);
    Vector2D operator+(const Vector2D &vec) const
    {
        return Vector2D(this->x + vec.getX(), this->y + vec.getY());
    }
    void operator+=(const Vector2D &vec)
    {
        this->x += vec.getX();
        this->y += vec.getY();
    }
    bool operator==(const Vector2D vec)
    {
        return ((this->getX() == vec.getX()) &&
                (this->getY() == vec.getY()));
    }
    bool operator!=(const Vector2D vec)
    {
        return ((this->getX() != vec.getX()) ||
                (this->getY() != vec.getY()));
    }
};

void Vector2D::print()
{
    std::cout << '\n'
              << "(" << this->getX() << ", " << this->getY() << ")" << std::endl;
}

double Vector2D::getMagnitude(int precision)
{
    double factor = std::pow(10.0, precision);
    double length = sqrt((x * x) + (y * y));
    return std::round(length * factor) / factor;
}

Vector2D operator*(int scalar, Vector2D vec)
{
    return Vector2D(scalar * vec.getX(), scalar * vec.getY());
}

Vector2D operator*(Vector2D vec, int scalar)
{
    return Vector2D(scalar * vec.getX(), scalar * vec.getY());
}

std::ostream &operator<<(std::ostream &outstream, const Vector2D &vec)
{
    outstream << "(" << vec.getX() << ", " << vec.getY() << ")";
    return outstream;
}

int main()
{
    // Part 2
    Vector2D vec1(4, 5);
    Vector2D vec2(1, 9);

    std::cout << vec1.getMagnitude() << std::endl;
    std::cout << vec1.getMagnitude(3) << std::endl;

    // Part 3
    Vector2D vec3 = vec1 + vec2;
    vec3.print();
    vec1 += vec2;
    vec1 = vec1 * 5;
    std::cout << vec1 << std::endl;

    // Part 4
    Vector2D vec4(1, 9);

    std::cout << (vec4 == vec2) << std::endl;
    std::cout << (vec1 != vec2) << std::endl;

    return 0;
}
