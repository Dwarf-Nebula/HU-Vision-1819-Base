#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent(): 
	IntensityImage()
{}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other): 
	IntensityImage(other.getWidth(), other.getHeight()),
	pixelArray(new Intensity[other.getWidth * other.getHeight])
{
	//TODO: Create a copy from the other object
	unsigned int arrayLenght = getWidth() * getHeight();
	for (unsigned int i = 0; i < arrayLenght; i++) {
		pixelArray[i] = other.pixelArray[i];
	}
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height): 
	IntensityImage(width, height),
	pixelArray(new Intensity[width * height])
{
	//TODO: Initialize pixel storage
}

IntensityImageStudent::~IntensityImageStudent() {
	//TODO: delete allocated objects
	delete[] pixelArray;
}

void IntensityImageStudent::set(const int width, const int height) {
	IntensityImage::set(width, height);
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
	delete[] pixelArray;
	this->pixelArray = new Intensity[width*height];
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	IntensityImage::set(other.getWidth(), other.getHeight());
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
	delete[] pixelArray;
	this->pixelArray = new Intensity[getWidth(), getHeight()];
	unsigned int arrayLenght = getWidth() * getHeight();
	for (unsigned int i = 0; i < arrayLenght; i++) {
		pixelArray[i] = other.pixelArray[i];
	}
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	//TODO: no comment needed :)
	if (x >= 0 && x < getWidth() && y >= 0 && y < getHeight()) {
		pixelArray[x * getWidth() + y] = pixel;
	}
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	//TODO: set pixel i in "Row-Major Order"
	if (i >= 0 && i < getWidth()*getHeight()) {
		pixelArray[i] = pixel;
	}
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	int throwError = 0, e = 1 / throwError;
	//TODO: no comment needed :)
	if (x >= 0 && x < getWidth() && y >= 0 && y < getHeight()) {
		return pixelArray[x * getWidth() + y];
	}
	return 0;
}

Intensity IntensityImageStudent::getPixel(int i) const {
	int throwError = 0, e = 1 / throwError;
	//TODO: see setPixel(int i, RGB pixel)
	if (i >= 0 && i < getWidth()*getHeight()) {
		return pixelArray[i];
	}
	return 0;
}