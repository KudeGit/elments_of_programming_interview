#include <iostream>
#include <stdexcept>
#include "../utils.hpp"


struct Point {
    int x;
    int y;
};
std::ostream& operator<< (std::ostream& out, const Point& p)
{
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}
bool operator== (const Point& a, const Point& b) 
{
    return a.x == b.x && b.y == a.y;
}
bool operator != (const Point& a, const Point& b)
{
    return !operator== (a, b);
}
bool operator< (const Point& a, const Point& b) 
{
    return a.x < b.x && a.y < b.y;
}
bool operator>= (const Point& a, const Point& b)
{
    return !operator<(a,b);
}
bool operator> (const Point& a, const Point& b)
{
    return operator<(b, a);
}
bool operator<= (const Point& a, const Point& b)
{
    return !operator>(a, b);
}

class Rectangle {
    private:
        Point *bl;
        Point *tr;
        void swap (Rectangle& other) {
            std::swap(bl, other.bl);
            std::swap(tr, other.tr);
        }
    public:
        Point getBottomLeft (void) const {
            if (bl) {
                return *bl;
            } 
            throw std::runtime_error("bl is a null pointer");
        }
        Point getTopRight (void) const {
            if (tr) {
                return *tr;
            }
            throw std::runtime_error("tr is a null pointer");
        }
        Rectangle (const Point& a, const Point& b);
        Rectangle () : bl(nullptr), tr(nullptr) {
            error("Rectangle default constructor");
        };
        Rectangle& operator=(Rectangle other);
        Rectangle (const Rectangle &r);
        Rectangle (Rectangle &&r);
        ~Rectangle() {
            error("Rectangle destructor");
        }
};

Rectangle::Rectangle (Rectangle &&r)
{
    error("Rectangle moving constructor");
    bl = r.bl; r.bl = nullptr;
    tr = r.tr; r.tr = nullptr;
}

Rectangle& Rectangle::operator= (Rectangle other)
{
    error("Rectangle assignement operator");
    swap(other);
    return *this;
}

Rectangle::Rectangle (const Rectangle& other)
{
    error("Rectangle copy constructor");
    if (other.bl) {
        bl = new Point(*other.bl);
    }
    if(other.tr) {
        tr = new Point(*other.tr);
    }
}

Rectangle::Rectangle (const Point& a, const Point& b)
{
    error("Rectangle personalized constructor");
    if (!(a < b)) {
        throw std::invalid_argument ("These points do not describe a valid rectangle");
    }
    bl = new Point(a);
    tr = new Point(b);
}

std::ostream& operator<< (std::ostream& out, const Rectangle& r)
{
    try {
        out << "[" << r.getBottomLeft() << "; " << r.getTopRight() << "]";
    } catch(const std::runtime_error& e) {
        out << "[(NA, NA); (NA, NA)]";
    }
    return out;
}


bool check_intersection (const Rectangle& a, const Rectangle& b)
{
    if(a.getBottomLeft().x > b.getTopRight().x ||
       a.getTopRight().x < b.getBottomLeft().x ||
       a.getBottomLeft().y > b.getTopRight().y ||
       a.getTopRight().y < b.getBottomLeft().y) {
        return false;
    }
    return true;
}

Rectangle intersection(const Rectangle& a, const Rectangle &b) 
{
    if(check_intersection(a, b)) {
        return Rectangle(
                {std::max(a.getBottomLeft().x, b.getBottomLeft().x), 
                 std::max(a.getBottomLeft().y, b.getBottomLeft().y)},
                {std::min(a.getTopRight().x, b.getTopRight().x),
                 std::min(a.getTopRight().y, b.getTopRight().y)});
    }
    return Rectangle();
}

int main (void)
{
    try{
        //Rectangle r1({1,1}, {2,2});
        //Rectangle r2(r1);
        //Rectangle r3;
        //r3 = r2;
        //std::cout << r1 << std::endl;
        //std::cout << r2 << std::endl;
        //std::cout << r3 << std::endl;

        Rectangle ra({1,1}, {10, 10});
        std::vector<Rectangle> rectangles;
        rectangles.emplace_back(Rectangle({11, 1}, {12, 3})); //rb left ra
        rectangles.emplace_back(Rectangle({1, 11}, {2, 13})); //rc above ra
        rectangles.emplace_back(Rectangle({-10, 3}, {0, 5})); //rd rigth ra
        rectangles.emplace_back(Rectangle({-12, 3}, {0, 6})); //re below ra
        rectangles.emplace_back(Rectangle({2,2}, {5,5}));       //inside ra
        rectangles.emplace_back(Rectangle({-10,2}, {5,5}));       //left interesection
        rectangles.emplace_back(Rectangle({8,2}, {15,5}));       //rigth interesection
        rectangles.emplace_back(Rectangle({-10,2}, {5,5}));       //bottom interesection
        rectangles.emplace_back(Rectangle({9,9}, {10,15}));       //top interesection



        for (const auto& r: rectangles) {
        std::cout << ra << " and " << r <<" intersects? " 
            << intersection(ra, r) << std::endl;
        }



    } catch (const std::exception& e) {
        error("%s", e.what());
        return 1;
    }
    return 0;
}



