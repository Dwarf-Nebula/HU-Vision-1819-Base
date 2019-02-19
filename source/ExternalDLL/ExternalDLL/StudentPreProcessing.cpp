#include "StudentPreProcessing.h"
#include "IntensityImageStudent.h"

IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	IntensityImageStudent * grayImage = new IntensityImageStudent(image.getWidth(), image.getHeight());
	unsigned int arrayLenght = grayImage->getWidth() * grayImage->getHeight();
	RGB pixel;
	//float weightR = 0.2989;
	//float weightG = 0.5870;
	//float weightB = 0.1140;
	//float weightR = .25;
	//float weightG = .5;
	//float weightB = .25;
	for (unsigned int i = 0; i < arrayLenght; i++) {
		pixel = image.getPixel(i);
		//grayImage->setPixel(i, Intensity(weightR * pixel.r + weightG * pixel.g + weightB * pixel.b));
		grayImage->setPixel(i, Intensity((pixel.r + pixel.g + pixel.b)/3));
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