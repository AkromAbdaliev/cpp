#include <iostream>
#include <memory>

class Unique
{
public:
    Unique() { std::cout << "Unique object created.\n"; }
    ~Unique() { std::cout << "Unique object destroyed.\n"; }
};

int main()
{
    std::unique_ptr<Unique> myClass = std::make_unique<Unique>();
    // Cannot be copied no copy constructor but can be moved.
    auto yourClass = std::move(myClass);

    // with array
    // std::unique_ptr<Unique[]> test_array = std::unique_ptr<Unique[]>(new Unique[10]);

    // with make_unique
    // std::unique_ptr<Unique[]> test_class_with_make = std::make_unique<Unique[]>(10);

    return 0;
}