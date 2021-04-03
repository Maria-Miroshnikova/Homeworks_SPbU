#include <iostream>
#include "BmpStructures.h"
#include "ImageFunctions.h"

void makeBlackAndWhite(RgbImg const& img)
{
	for (int i = 0; i < img.height; ++i)
		for (int j = 0; j < img.width; ++j)
		{
			BYTE median = (img.pixels[i][j].Blue + img.pixels[i][j].Green + img.pixels[i][j].Red) / 3;
			img.pixels[i][j] = { median, median, median };
		}
}

int main()
{
	try
	{
		RgbImg img = read_rgb_img("hehe.bmp");

		makeBlackAndWhite(img);

		write_rgb_img("out.bmp", img);
		for (int i = 0; i < img.height; ++i)
			delete[] img.pixels[i];
		delete[] img.pixels;
	}
	catch (std::exception error)
	{
		std::cout << "Error happened: " << error.what() << '\n';
		return 1;
	}
	std::cout << "Success!\n";
	return 0;
}