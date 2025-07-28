#include <graphics.h>

void drawX(int x, int y, int S, int color) {
    for (int i = 0; i <= S; ++i) {
        putpixel(x - i, y - i, color); // Top-left diagonal
        putpixel(x + i, y - i, color); // Top-right diagonal
        putpixel(x - i, y + i, color); // Bottom-left diagonal
        putpixel(x + i, y + i, color); // Bottom-right diagonal
    }
}

int main() {
    // Initialize graphics mode (adjust parameters as needed)
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int centerX = 200; // Center x-coordinate of the X
    int centerY = 200; // Center y-coordinate of the X
    int size = 50;     // Size of the X (distance from center to tips)
    int color = WHITE; // Color of the X

    drawX(centerX, centerY, size, color);

    // Wait for user to close
    getch();
    closegraph();

    return 0;
}
