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
    std::shared_ptr<Shared> sharedPtr = std::make_shared<Shared>();
    std::weak_ptr<Shared> weakPtr = sharedPtr;

    std::cout << "Use count: " << sharedPtr.use_count() << std::endl;
    std::cout << "Unique: " << sharedPtr.unique() << std::endl;

    sharedPtr.reset();
    std::cout << "Is weak expired? " << std::boolalpha << weakPtr.expired() << "\n";

    if (auto locked = weakPtr.lock())
    {
        std::cout << "Locked successfully.\n";
    }
    else
    {
        std::cout << "Could not lock. Object already destroyed.\n";
    }

    return 0;
}