#include <iostream>
#include <cmath>
#include <vector>

// Function to draw a circle outline using the naive algorithm
void naiveCircleOutline(int x_center, int y_center, int radius, float epsilon = 0.5) {
    // Canvas size (bounding square)
    int grid_size = radius * 2 + 1;
    std::vector<std::vector<char>> canvas(grid_size, std::vector<char>(grid_size, ' '));

    // Loop through each point in the bounding square
    for (int x_prime = x_center - radius; x_prime <= x_center + radius; ++x_prime) {
        for (int y_prime = y_center - radius; y_prime <= y_center + radius; ++y_prime) {
            // Calculate the distance squared
            float distance_squared = std::pow(x_prime - x_center, 2) + std::pow(y_prime - y_center, 2);
            // Check if the point is near the circle's outline
            if (std::pow(radius, 2) - epsilon <= distance_squared && distance_squared <= std::pow(radius, 2) + epsilon) {
                canvas[x_prime - x_center + radius][y_prime - y_center + radius] = '*'; // Mark the pixel
            }
        }
    }

    // Print the canvas
    for (const auto& row : canvas) {
        for (const auto& pixel : row) {
            std::cout << pixel;
        }
        std::cout << '\n';
    }
}

int main() {
    // Test the naive circle outline algorithm
    int x_center = 0, y_center = 0, radius = 10;
    naiveCircleOutline(x_center, y_center, radius);
    return 0;
}
