#include "RGBImageStudent.h"
#include <stdexcept>

//TODO: Nothing
RGBImageStudent::RGBImageStudent(): 
	RGBImage() 
{}

//TODO: Create a copy from the other object
RGBImageStudent::RGBImageStudent(const RGBImageStudent &other):
	RGBImage(
		other.getWidth(),
		other.getHeight()
	),
	pixelArray(
		new RGB[other.getWidth()*other.getHeight()]
	)
{
	for (int i = 0; i < getWidth()*getHeight(); i++) {
		pixelArray[i] = other.pixelArray[i];
	}
}

//TODO: Initialize pixel storage
RGBImageStudent::RGBImageStudent(const int width, const int height):
	RGBImage(width, height),
	pixelArray(new RGB[width*height])
{}

//TODO: delete allocated objects
RGBImageStudent::~RGBImageStudent() {
	delete[]pixelArray;
}

//TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);
	delete[] pixelArray;
	this->pixelArray = new RGB[width*height];
}

//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	delete[]pixelArray;
	this->pixelArray = new RGB[getWidth()*getHeight()];
	for (int i = 0; i < getWidth()*getHeight(); i++) {
		pixelArray[i] = other.pixelArray[i];
	}
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	if ((x >= 0 || x <= getWidth()) && (y >= 0 || y <= getHeight())) {
		pixelArray[y*getWidth() + x] = pixel;
	}
	else {
		throw std::out_of_range{ "Pixel out of range!" };
	}
}

/*
	* TODO: set pixel i in "Row-Major Order"
	*
	*
	* Original 2d image (values):
	* 9 1 2
	* 4 3 5
	* 8 7 8
	*
	* 1d representation (i, value):
	* i		value
	* 0		9
	* 1		1
	* 2		2
	* 3		4
	* 4		3
	* 5		5
	* 6		8
	* 7		7
	* 8		8
	*/
void RGBImageStudent::setPixel(int i, RGB pixel) {
	pixelArray[i] = pixel;
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	return pixelArray[y*getWidth() + x];
}

RGB RGBImageStudent::getPixel(int i) const {
	return pixelArray[i];
}