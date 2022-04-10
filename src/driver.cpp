#include <iostream>
#include "quicksort.hpp"

class Point
{
    public:
        Point(int x, int y) : x{x}, y{y} {}
        uint64_t get_norm(Point const& p) { return p.x*p.x + p.y*p.y; }
        bool operator>(Point const& _p) { return get_norm(*this) > get_norm(_p); }
        bool operator<(Point const& _p) { return get_norm(*this) < get_norm(_p); }
        friend std::ostream& operator<<(std::ostream &os, Point const& _p)
        {
            os << "(" << _p.x << ", " << _p.y << ")";
            return os;
        }
    
    private:
        int x, y;
};

int main()
{
    std::vector<int> integers = {-2,1,8,4,4,1,7,5,1,1,5,4,10,-5};
    std::vector<std::string> names = {"jim", "bob", "kyle", "greg", "adam"};
    std::vector<Point> points = {
        Point(2, 3),
        Point(1, 1),
        Point(1, 8),
        Point(2, 0),
        Point(4, 2)
    };
    
    quicksort::sort<int>(integers);
    std::cout << "INTEGERS SORTED ASCENDING:\n";
    for (int const& item : integers)
        std::cout << item << " ";
    
    quicksort::sort<std::string>(names);
    std::cout << "\n\nNAMES SORTED ASCENDING:\n";
    for (auto const& item : names)
        std::cout << item << " ";

    quicksort::sort<std::string>(names, false); // ascending = false
    std::cout << "\n\nNAMES SORTED DESCENDING:\n";
    for (auto const& item : names)
        std::cout << item << " ";

    quicksort::sort<Point>(points);
    std::cout << "\n\nPOINTS SORTED ASCENDING:\n";
    for (auto const& item : points)
        std::cout << item << " ";
    return 0;
}