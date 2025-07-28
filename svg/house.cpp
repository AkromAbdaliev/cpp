#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

const std::string colors[] = {"teal", "cadetblue", "brown", 
"salmon", "darkred", "indigo", "saddlebrown", "coral", 
"chocolate", "darkcyan", "crimson", "firebrick", "green", 
"darkmagenta", "darkgreen", "darkolivegreen", "maroon", 
"blueviolet", "darkslateblue", "indianred", "sienna"};




int main()
{
    std::ofstream svg("houses.svg");
    
    std::cout << "How many house(s) do you want to draw?\n";
    int houseCount = 0;
    std::cin >> houseCount;

    // std::srand(static_cast<unsigned>(std::time(0)));

    svg << "<?xml version='1.0' ?>\n";
    svg << "<svg viewBox='0 0 " << (houseCount * 250) << " 500' xmlns='http://www.w3.org/2000/svg'>\n";
    
    // background for night
    svg << "<rect width='100%' height='100%' fill='midnightblue' />\n";
    // moon
    svg << "<circle cx='70' cy='50' r='40' fill='khaki' />\n";

    for (int i = 0; i < houseCount; i++)
    {
        int spaceBetween = i * 250;

        std::string randomColor = colors[std::rand() % (sizeof(colors) / sizeof(colors[0]))];

        // roof
        svg << 
            "<polygon points='"<<(50 + spaceBetween)<<",200 "
            <<(125 + spaceBetween)<<",100 "<<(200 + spaceBetween)
            <<",200' fill='" << randomColor <<"' stroke='red' stroke-width='3' />\n";
        // wall
        svg << "<rect x='"<<(50 + spaceBetween)<<"' y='203' " 
            << "width='150' height='150' fill='tan' "
            << "stroke='blue' stroke-width='3' />\n";
        // dormer window
        svg << "<circle cx='" << (125 + spaceBetween) 
            << "' cy='160' r='20' fill='lightskyblue' " 
            << "stroke='black' stroke-width='2' />\n";
        // main window
        svg << "<rect x='"<<(70 + spaceBetween)<<"' y='260' "
            << "width='60' height='40' fill='lightskyblue' "
            << "stroke='black' stroke-with='2' />\n";
        // door
        svg << "<rect x='"<<(145 + spaceBetween)<<"' y='260' "
            << "width='40' height='80' fill='"<< randomColor  
            << "' stroke='red' stroke-with='3' />\n";
    }
        // asphalt road
        svg << "<rect x='0' y='380' width='" << (houseCount * 250) 
            << "' height='102' fill='dimgray' />\n";
        svg <<"</svg>\n";     
    
    std::cout<<"Success";
    return 0;
}
