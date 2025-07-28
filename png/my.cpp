#include "image.h"
#include <cmath>
#include <iostream>
#include <string>

void RotatePoint(double& x, double& y, double angle) {
    double radians = angle * M_PI / 180.0;
    double cosAngle = cos(radians);
    double sinAngle = sin(radians);

    double newX = cosAngle * x - sinAngle * y;
    double newY = sinAngle * x + cosAngle * y;

    x = newX;
    y = newY;
}

void DrawLine(ColorImage& img, int x1, int y1, int x2, int y2, RGBA color) {
    int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
    int dy = abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;

    while (true) {
        img.SetPixel(x1, y1, color);
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x1 += sx; }
        if (e2 < dx) { err += dx; y1 += sy; }
    }
}

void DrawTriangle(ColorImage& img, double x1, double y1, double x2, double y2, double x3, double y3) {
    RGBA color(0, 0, 0, 255);  // Black color for the triangle
    DrawLine(img, x1, y1, x2, y2, color);
    DrawLine(img, x2, y2, x3, y3, color);
    DrawLine(img, x3, y3, x1, y1, color);
}

int main() {
    double x1 = 100, y1 = 50;
    double x2 = 150, y2 = 150;
    double x3 = 50, y3 = 150;

    int width = 200, height = 200;
    ColorImage img(width, height);

    // Manually clear the image to a white background
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            img.SetPixel(x, y, RGBA(255, 255, 255, 255)); // White background
        }
    }

    int numFrames = 20;
    double angleStep = 360.0 / numFrames;

    for (int i = 0; i < numFrames; ++i) {
        double angle = i * angleStep;
        double rx1 = x1, ry1 = y1;
        double rx2 = x2, ry2 = y2;
        double rx3 = x3, ry3 = y3;

        RotatePoint(rx1, ry1, angle);
        RotatePoint(rx2, ry2, angle);
        RotatePoint(rx3, ry3, angle);

        // Clear and redraw the triangle
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                img.SetPixel(x, y, RGBA(255, 255, 255, 255));  // Clear with white
            }
        }

        DrawTriangle(img, rx1, ry1, rx2, ry2, rx3, ry3);

        std::string fileName = "frame_" + std::to_string(i) + ".png";
        img.Save(fileName);
        std::cout << "Saved: " << fileName << "\n";
    }

    std::cout << "Animation frames generated.\n";
    return 0;
}
