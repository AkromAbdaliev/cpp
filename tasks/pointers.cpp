#include <iostream>

int add(int first, int second)
{
    return first + second;
}

int subtract(int first, int second)
{
    return first - second;
}
int multiply(int first, int second)
{
    return first * second;
}
int divide(int first, int second)
{
    return first / second;
}

int main()
{
    // int x = 5;
    // creating a ptrX pointer
    // int *ptrX; // in the state of <<wild pointer>>

    // assigning adress by using addressof operator (&)
    // ptrX = &x; // <-- &x

    // update the x's value
    // x = 11;

    // std::cout << "-> x holds: " << x << std::endl;
    // std::cout << "-> x address: " << &x << std::endl;
    // std::cout << "-> ptrX holds: " << ptrX << std::endl;
    // std::cout << "-> ptrX address: " << &ptrX << std::endl;
    // std::cout << "-> ptrX dereference: " << *ptrX << std::endl;

    // null pointer -> does not point to any valid memory location but NULL
    // int *ptrNull = NULL;

    // void* pointer
    // int value = 12;
    // void *ptrVoid = &value; // assigning address
    // std::cout << "-> value holds: " << value << "\n";
    // std::cout << "-> value address: " << &value << "\n";
    // std::cout << "-> ptrVoid holds: " << ptrVoid << "\n";
    // std::cout << "-> ptrVoid address: " << &ptrVoid << "\n";

    // Error: cannot dereference void pointer
    // std::cout << *ptrVoid;

    // Typecast before dereferencing
    // std::cout << "-> ptrVoid dereference: "<<*(static_cast<int *>(ptrVoid)) << "\n";

    // function pointer
    int (*ptrFunc)(int, int);
    std::cout << "Enter the number \n1) for add\n2) for subtract\n3) for multiply\n4) for subtract\nChoice: ";
    int choice;
    std::cin >> choice;
    if (choice == 1)
    {
        ptrFunc = add;
    }
    else if (choice == 2)
    {
        ptrFunc = subtract;
    }
    else if (choice == 3)
    {
        ptrFunc = multiply;
    }
    else if (choice == 4)
    {
        ptrFunc = divide;
    }

    int first, second;
    std::cout << "Enter the first number: ";
    std::cin >> first;
    std::cout << "Enter the second number: ";
    std::cin >> second;
    std::cout << "Result: " << ptrFunc(first, second) << std::endl;
    int dereferenced_result = ptrFunc(first, second);
    std::cout << "result holds : " << dereferenced_result;
}