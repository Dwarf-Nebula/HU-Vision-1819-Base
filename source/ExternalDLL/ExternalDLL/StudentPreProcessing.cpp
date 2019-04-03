#include "StudentPreProcessing.h"
#include "ImageFactory.h"
#include <thread>

int max(int r, int g, int b) {
	int mx = r;
	if (g > mx) {
		mx = g;
	}
	if (b > mx) {
		return b;
	}
	return mx;
}

int min(int r, int g, int b) {
	int mn = r;
	if (g < r) {
		mn = g;
	}
	if (b < mn) {
		return b;
	}
	return mn;
}

/*void RGBtoGrayThread(const RGBImage &from, IntensityImage* to, unsigned int start, unsigned int end) {
	RGB pixel;
	for (unsigned int i = start; i < end; i += 4) {
		pixel = from.getPixel(i);
		to->setPixel(i, Intensity((pixel.r + pixel.g + pixel.b) * 0.333));
	}
}*/

IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	auto grayImage = ImageFactory::newIntensityImage(image.getWidth(), image.getHeight());
	unsigned int arrayLenght = grayImage->getWidth() * grayImage->getHeight();
	/*auto start = 0;
	auto end = arrayLenght;
	std::thread t1(RGBtoGrayThread, std::ref(image), grayImage, start, end);
	std::thread t2(RGBtoGrayThread, std::ref(image), grayImage, start+1, end);
	std::thread t3(RGBtoGrayThread, std::ref(image), grayImage, start+2, end);
	std::thread t4(RGBtoGrayThread, std::ref(image), grayImage, start+3, end);
	t1.join();
	t2.join();
	t3.join();
	t4.join();*/
	RGB pixel;
	/*RGB pixel1;
	RGB pixel2;
	RGB pixel3;
	RGB pixel4;
	RGB pixel5;*/
	
	// Luminance Grayscale generated using a formula similar to (Red * 0.3 + Green * 0.59 + Blue * 0.11)
	float weightR = 0.3;
	float weightG = 0.59;
	float weightB = 0.11;
	// Looks nice to the human eye, doesn't function that wel in this face detection program.
	auto start = 0;
	auto end = arrayLenght - start;
	for (unsigned int i = start; i < end; i++) {
		pixel = image.getPixel(i);

		grayImage->setPixel(i, Intensity(weightR * pixel.r + weightG * pixel.g + weightB * pixel.b));
		
		//grayImage->setPixel(i, Intensity((pixel.r + pixel.g + pixel.b)*0.33));

		//grayImage->setPixel(i, Intensity(pixel.g));

		// Desaturation
		//grayImage->setPixel(i, Intensity((max(pixel.r, pixel.g, pixel.b) + min(pixel.r, pixel.g, pixel.b)) / 2));

		// Maximum Decomposition
		//grayImage->setPixel(i, Intensity(max(pixel.r, pixel.g, pixel.b)));

		// Minimum Decomposition
		//grayImage->setPixel(i, Intensity(min(pixel.r, pixel.g, pixel.b)));
	}

	return grayImage;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}