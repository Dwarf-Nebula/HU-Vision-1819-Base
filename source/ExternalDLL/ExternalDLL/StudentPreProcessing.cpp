#include "StudentPreProcessing.h"
#include "ImageFactory.h"
#include "GrayscalingMethods.hpp"
#include <thread>

IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	auto grayImage = ImageFactory::newIntensityImage(image.getWidth(), image.getHeight());
	unsigned int arrayLenght = grayImage->getWidth() * grayImage->getHeight();
	RGB pixel;
	auto start = 0;
	auto end = arrayLenght - start;
	GrayscalingMethods gray_methode;
	for (unsigned int i = start; i < end; i++) {
		pixel = image.getPixel(i);
		grayImage->setPixel(i, Intensity(gray_methode.regular(pixel.r, pixel.g, pixel.b)));
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
