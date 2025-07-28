#include <iostream>
#include <future>

int square(int x)
{
    return x * x;
}

int main()
{
    // passing it to another thread to get the result later
    std::future<int> asyncCall = std::async(&square, 4);

    int i = 0;
    while (i < 5)
    {
        std::cout << i << std::endl;
        i++;
    }

    int result = asyncCall.get(); // blocking till it gets the value
    std::cout << "future result: " << result << std::endl;

    // std::move moves the ovnership of the memory from a to b instead of copying it 
    std::string greeting = "hello";
    std::string saying = std::move(greeting);
    std::cout << "Greeting: " << greeting << std::endl;
    std::cout << "Saying: " << saying << std::endl;

    return 0;
}