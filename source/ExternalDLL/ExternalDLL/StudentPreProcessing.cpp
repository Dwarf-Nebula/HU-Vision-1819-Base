#include "StudentPreProcessing.h"
#include "ImageFactory.h" 

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

IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	auto grayImage = ImageFactory::newIntensityImage(image.getWidth(), image.getHeight());
	unsigned int arrayLenght = grayImage->getWidth() * grayImage->getHeight();
	RGB pixel;

	// Luminance Grayscale generated using a formula similar to (Red * 0.3 + Green * 0.59 + Blue * 0.11)
	/*float weightR = 0.3;
	float weightG = 0.59;
	float weightB = 0.11;*/
	// Looks nice to the human eye, doesn't function that wel in this face detection program.

	for (unsigned int i = 0; i < arrayLenght; i++) {
		pixel = image.getPixel(i);
		//grayImage->setPixel(i, Intensity(weightR * pixel.r + weightG * pixel.g + weightB * pixel.b));
		//grayImage->setPixel(i, Intensity((pixel.r + pixel.g + pixel.b) / 3));

		// Desaturation
		grayImage->setPixel(i, Intensity((max(pixel.r, pixel.g, pixel.b) + min(pixel.r, pixel.g, pixel.b)) / 2));

		// Maximum Decomposition
		//grayImage->setPixel(i, Intensity(max(pixel.r, pixel.g, pixel.b)));

		// Minimum Decomposition
		//grayImage->setPixel(i, Intensity(min(pixel.r, pixel.g, pixel.b)));
	}
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