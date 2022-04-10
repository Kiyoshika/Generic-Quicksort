# Quicksort
I've never implemented a sorting algorithm before (besides old bubble sort).

This is my attempt at creating a generic quicksort to work with native types as well as user-defined types.

# Building
Even though this project is structured as a CMake project, this is a header-only library (since it's templated).

Obvously, I advise against actually using this. We have `std::sort`!!!

# How to use user-defined types
In the driver.cpp I have an example of a `Point` class I created that sorts points in order of their magnitude (norm).

In order for quicksort to work with user-defined types, you must implement a `>` and `<` operator overload (to support ascending and descending).

# Full examples (taken from driver.cpp)
```c++
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
    for (auto const& item : integers)
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
```
Output:
```text
INTEGERS SORTED ASCENDING:
-5 -2 1 1 1 1 4 4 4 5 5 7 8 10

NAMES SORTED ASCENDING:
adam bob greg jim kyle

NAMES SORTED DESCENDING:
kyle jim greg bob adam

POINTS SORTED ASCENDING:
(1, 1) (2, 0) (2, 3) (4, 2) (1, 8)
```
