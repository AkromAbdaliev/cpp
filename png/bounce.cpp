#include "Image.h" 
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>

// Ball structure to manage position and velocity
struct Ball {
    int x, y;       // Current position
    int vx, vy;     // Velocity
    int radius;     // Radius of the ball
};

void drawBall(Image& img, const Ball& ball, int color) {
    // Draw a simple filled circle (using a fictional drawCircle function)
    for (int i = -ball.radius; i <= ball.radius; i++) {
        for (int j = -ball.radius; j <= ball.radius; j++) {
            if (i * i + j * j <= ball.radius * ball.radius) {
                int px = ball.x + i;
                int py = ball.y + j;
                if (px >= 0 && px < img.width && py >= 0 && py < img.height) {
                    img.setPixel(px, py, color);
                }
            }
        }
    }
}

int main() {
    const int width = 800;
    const int height = 600;
    const int frames = 100; // Number of frames to generate
    const int ballColor = 0xFFFFFF; // White color (assuming RGB format)

    Ball ball = {width / 2, height / 2, 3, 5, 20}; // Initial ball position and velocity

    for (int frame = 0; frame < frames; ++frame) {
        // Create a new image for this frame
        Image img(width, height, 0x000000); // Black background

        // Update ball position
        ball.x += ball.vx;
        ball.y += ball.vy;

        // Handle boundary collisions
        if (ball.x - ball.radius < 0 || ball.x + ball.radius >= width) ball.vx *= -1;
        if (ball.y - ball.radius < 0 || ball.y + ball.radius >= height) ball.vy *= -1;

        // Draw the ball
        drawBall(img, ball, ballColor);

        // Save the frame as an image
        std::ostringstream filename;
        filename << "frame_" << std::setw(4) << std::setfill('0') << frame << ".bmp";
        img.save(filename.str().c_str()); // Assuming `save()` writes to BMP format

        std::cout << "Saved frame: " << filename.str() << std::endl;
    }

    std::cout << "Animation frames saved! Use a tool to combine them into a video or GIF.\n";
    return 0;
}
