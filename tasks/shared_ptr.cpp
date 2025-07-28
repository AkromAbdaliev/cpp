#include <iostream>
#include <memory>

class Shared
{
public:
    Shared() { std::cout << "Shared object created.\n"; }
    ~Shared() { std::cout << "Shared object destroyed.\n"; }
};

int main()
{
    std::shared_ptr<Shared> sharedPtr1 = std::make_shared<Shared>();
    auto sharedPtr2 = sharedPtr1;
    auto sharedPtr3 = sharedPtr2;

    std::cout << "Use counts: " << sharedPtr1.use_count() << std::endl;
    std::cout << "Printing address 1: " << sharedPtr1.get() << std::endl;
    std::cout << "Printing address 2: " << sharedPtr2.get() << std::endl;
    std::cout << "Printing address 3: " << sharedPtr3.get() << std::endl;
    // std::cout << "Printing unique: " << sharedPtr1.unique() << std::endl;
    sharedPtr1.reset();
    std::cout << "Use counts: " << sharedPtr1.use_count() << std::endl;
    std::cout << "Printing address 1: " << sharedPtr1.get() << std::endl;
    std::cout << "Use counts (sharedPtr2): " << sharedPtr2.use_count() << std::endl;


    return 0;
}