#include "Image.h"

void plotCirclePoints(GrayscaleImage &im, int cx, int cy, int x, int y)
{
    im(cx + x, cy + y) = 255;
    im(cx - x, cy + y) = 255;
    im(cx + x, cy - y) = 255;
    im(cx - x, cy - y) = 255;

    im(cx + y, cy + x) = 255;
    im(cx - y, cy + x) = 255;
    im(cx + y, cy - x) = 255;
    im(cx - y, cy - x) = 255;
}

int main()
{
    GrayscaleImage im(250, 250);

    int cx = 120, cy = 75, r = 70;
    int x = r, y = 0;
    int d = 1 - r; // Decision parameter

    while (x >= y)
    {
        plotCirclePoints(im, cx, cy, x, y);
        y++;

        if (d < 0)
        {
            d += 2 * y + 1;
        }
        else
        {
            x--;
            d += 2 * (y - x) + 1;
        }
    }

    im.Save("circle.png");
    return 0;
}
