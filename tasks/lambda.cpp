#include <iostream>
int main()
{

    auto lambda_add = [](int x, int y)
    { return x + y; };

    std::cout << "f: " << lambda_add(2, 5) << std::endl;

    int a = 5;
    int b = 2;

    // by reference
    auto labda_ref = [&]()
    {
        a += 5;
        b += 5;
        std::cout << "Inside [&] lambda_ref: a = " << a << ", b = " << b << "\n";
    };
    std::cout << "before: global: a = " << a << ", b = " << b << "\n";
    labda_ref();
    std::cout << "after: global: a = " << a << ", b = " << b << "\n";

    // by value
    auto lambda_val = [=]() mutable { // variables are read-only so mutable needed to make changes of the copy.
        a += 5;
        b += 5;
        std::cout << "Inside [=] mutable lambda_val: a = " << a << ", b = " << b << "\n";
    };

    std::cout << "before: global: a = " << a << ", b = " << b << "\n";
    lambda_val();
    std::cout << "after: global: a = " << a << ", b = " << b << "\n";

    // mutable needed to work with 'a'.
    auto lambda_mix = [a, &b]() mutable
    {
        a += 5;
        b += 2;
        std::cout << "Inside [a, &b] lambda_mix: a = " << a << ", b = " << b << "\n";
    };

    std::cout << "before: global: a = " << a << ", b = " << b << "\n";
    lambda_mix();
    std::cout << "after: global: a = " << a << ", b = " << b << "\n";
}