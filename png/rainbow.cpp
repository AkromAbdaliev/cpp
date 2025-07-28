#include "Image.h"
#include <cmath>

void drawArc(GrayscaleImage &im, int cx, int cy, int radius, int thickness, int intensity)
{
    for (int r = radius; r > radius - thickness; --r)
    {
        int x = r, y = 0;
        im(cx + x, cy + y) = intensity;
        im(cx - x, cy + y) = intensity;
        im(cx + x, cy - y) = intensity;
        im(cx - x, cy - y) = intensity;

        int d = 1 - r;
        while (x > y)
        {
            y++;
            if (d < 0)
                d += 2 * y + 1;
            else
            {
                x--;
                d += 2 * (y - x) + 1;
            }
            if (x >= y) // Partial arc for semi-circle
            {
                im(cx + x, cy + y) = intensity;
                im(cx - x, cy + y) = intensity;
                im(cx + x, cy - y) = intensity;
                im(cx - x, cy - y) = intensity;

                im(cx + y, cy + x) = intensity;
                im(cx - y, cy + x) = intensity;
                im(cx + y, cy - x) = intensity;
                im(cx - y, cy - x) = intensity;
            }
        }
    }
}

int main()
{
    const int width = 500, height = 500;
    GrayscaleImage im(width, height);

    int cx = 250, cy = 400; // Center of the rainbow (off-center for bottom arc)
    int radius = 200;       // Starting radius for outermost arc
    int thickness = 10;     // Thickness of each arc

    // Draw each arc with different intensities
    for (int i = 0; i < 7; ++i) // 7 arcs for the rainbow
    {
        int intensity = 255 - i * 35; // Gradually darker shades
        drawArc(im, cx, cy, radius, thickness, intensity);
        radius -= thickness; // Move to the next inner arc
    }

    im.Save("test.png");
    std::cout << "Image saved successfully!" << std::endl;

    return 0;
}
