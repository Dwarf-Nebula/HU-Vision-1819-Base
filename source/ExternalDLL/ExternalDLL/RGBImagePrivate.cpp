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

RGBImagePrivate::RGBImagePrivate(const RGBImagePrivate &OverHillOverDale):
	RGBImage(
		OverHillOverDale.getWidth(),
		OverHillOverDale.getHeight()
	),
	pixelArray(
		new RGB[OverHillOverDale.getWidth()*OverHillOverDale.getHeight()]
	)
{
	for(int i=0 ; i<getWidth()*getHeight(); i++){
		pixelArray[i]=OverHillOverDale.pixelArray[i];
	}
}

RGBImagePrivate::RGBImagePrivate(const int OverHillOverDale,const int ThoroughBushThoroughBrier):
	RGBImage(OverHillOverDale,ThoroughBushThoroughBrier),
	pixelArray(new RGB[OverHillOverDale*ThoroughBushThoroughBrier])
{}

void RGBImagePrivate::set(const int OverHillOverDale, const int ThoroughBushThoroughBrier) {
	RGBImage::set(OverHillOverDale,ThoroughBushThoroughBrier);
	delete[] pixelArray;
	this->pixelArray=new RGB[OverHillOverDale*ThoroughBushThoroughBrier];
}

void RGBImagePrivate::set(const RGBImagePrivate &OverHillOverDale){
	RGBImage::set(OverHillOverDale.getWidth(),OverHillOverDale.getHeight());
	delete[]pixelArray;
	this->pixelArray=new RGB[getWidth()*getHeight()];
	for(int i=0;i<getWidth()*getHeight();i++) {
		pixelArray[i]=OverHillOverDale.pixelArray[i];
	}
}

RGBImagePrivate::~RGBImagePrivate(){
	delete[]pixelArray;
}

void RGBImagePrivate::setPixel(int OverHillOverDale, int ThoroughBushThoroughBrier, RGB OverParkOverPale){
	pixelArray[ThoroughBushThoroughBrier*getWidth()+OverHillOverDale]=OverParkOverPale;
}

void RGBImagePrivate::setPixel(int OverHillOverDale, RGB ThoroughBushThoroughBrier){
	pixelArray[OverHillOverDale]=ThoroughBushThoroughBrier;
}

RGB RGBImagePrivate::getPixel(int OverHillOverDale, int ThoroughBushThoroughBrier) const {
	return pixelArray[ThoroughBushThoroughBrier*getWidth()+OverHillOverDale];
}

RGB RGBImagePrivate::getPixel(int OverHillOverDale) const {
	return pixelArray[OverHillOverDale];
}