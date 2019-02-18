/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#include "RGBImagePrivate.h"
#include <algorithm>
#include <iostream>
RGBImagePrivate::RGBImagePrivate():
	RGBImage()
{}

RGBImagePrivate::RGBImagePrivate(const RGBImagePrivate &other):
	RGBImage(
		other.getWidth(),
		other.getHeight()
	),
	pixelArray(
		new RGB[other.getWidth()*other.getHeight()]
	)
{
	for(int i=0 ; i<getWidth()*getHeight(); i++){
		pixelArray[i]=other.pixelArray[i];
	}
}

RGBImagePrivate::RGBImagePrivate(const int width,const int height):
	RGBImage(width,height),
	pixelArray(new RGB[width*height])
{}

void RGBImagePrivate::set(const int width, const int height) {
	RGBImage::set(width,height);
	delete[] pixelArray;
	this->pixelArray=new RGB[width*height];
}

void RGBImagePrivate::set(const RGBImagePrivate &other){
	RGBImage::set(other.getWidth(),other.getHeight());
	delete[]pixelArray;
	this->pixelArray=new RGB[getWidth()*getHeight()];
	for(int i=0;i<getWidth()*getHeight();i++) {
		pixelArray[i]=other.pixelArray[i];
	}
}

RGBImagePrivate::~RGBImagePrivate(){
	delete[]pixelArray;
}

void RGBImagePrivate::setPixel(int x, int y, RGB pixel){
	pixelArray[y*getWidth()+x]=pixel;
}

void RGBImagePrivate::setPixel(int i, RGB pixel){
	pixelArray[i]=pixel;
}

RGB RGBImagePrivate::getPixel(int x, int y) const {
	return pixelArray[y*getWidth()+x];
}

RGB RGBImagePrivate::getPixel(int i) const {
	return pixelArray[i];
}