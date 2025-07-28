#include <iostream>
#include <fstream>

int main()
{
    std::ofstream svg("boat.svg");

    svg << "<?xml version='1.0' ?>\n";
    svg << "<svg width='200' height='400' xmlns='http://www.w3.org/2000/svg'>\n";

    // Draw the irregular hull shape
    svg << "<polygon points='1,200 198,200 140,290 60,290' fill='maroon' stroke='black' stroke-width='2'/>\n";
    
    // Draw the sail
    svg << "<polygon points='80,120 120,120 160,200 40,200' fill='gold' stroke='black' stroke-width='2'/>\n";
    
    // Draw portholes
    svg << "<circle cx='75' cy='160' r='10' fill='skyblue'/>\n";
    svg << "<circle cx='100' cy='160' r='10' fill='skyblue'/>\n";
    svg << "<circle cx='125' cy='160' r='10' fill='skyblue'/>\n";
    
    // Draw the mast
    svg << "<rect x='98' y='60' width='4' height='60' fill='#000000'/>\n";
    
    // Draw the black sail
    svg << "<polygon points='100,70 100,100 160,90' fill='black' stroke='black' stroke-width='2'/>\n";
    
    // Draw the sea
    svg << "<path d='M2 290 Q1 310, 48 290 T80 290 T120 290 T160 290 T197 290 L197 396 L2 396 Z' stroke='blue' fill='cornflowerblue' stroke-width='3'/>\n";

    svg << "</svg>\n";     

    std::cout << "SVG file created successfully: boat.svg" << std::endl;
    
    return 0;
}
