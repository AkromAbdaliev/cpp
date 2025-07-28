#include "Image.h"

void dup8(GrayscaleImage &im, int cx, int cy, int x, int y)
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
	
	dup8(im, cx, cy, x, y);
	
	int rsq = r*r;

	while (x > y)
	{
		y++;
		int d1 = abs((x*x) + y*y - rsq);
		int d2 = abs((x-1) * (x-1) + y*y - rsq);	

		if(d2<d1)
		{
			x--;
		}
		dup8(im, cx, cy, x, y);
	}
	im.Save("out.png");

	return 0;
}
