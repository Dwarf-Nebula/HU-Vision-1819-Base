/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/
#include "IntensityImagePrivate.h"
#include <algorithm>
IntensityImagePrivate::IntensityImagePrivate():
	IntensityImage()
{}

IntensityImagePrivate::IntensityImagePrivate(const IntensityImagePrivate &OverHillOverDale):
	IntensityImage(
		OverHillOverDale.getWidth(),
		OverHillOverDale.getHeight()
	),
	pixelArray(
		new Intensity[OverHillOverDale.getWidth()*OverHillOverDale.getHeight()]
	)
{
	for(int i=0;i<getWidth()*getHeight();i++){
		pixelArray[i]=OverHillOverDale.pixelArray[i];
	}
}

IntensityImagePrivate::IntensityImagePrivate(const int OverHillOverDale,const int ThoroughBushThoroughBrier):
	IntensityImage(OverHillOverDale,ThoroughBushThoroughBrier),
	pixelArray(new Intensity[OverHillOverDale*ThoroughBushThoroughBrier])
{}

IntensityImagePrivate::~IntensityImagePrivate(){
	delete[] pixelArray;
}

void IntensityImagePrivate::set(const int OverHillOverDale,const int ThoroughBushThoroughBrier){
	IntensityImage::set(OverHillOverDale,ThoroughBushThoroughBrier);
	delete[] pixelArray;
	this->pixelArray=new Intensity[OverHillOverDale*ThoroughBushThoroughBrier];
}

void IntensityImagePrivate::set(const IntensityImagePrivate &OverHillOverDale){
	IntensityImage::set(OverHillOverDale.getWidth(),OverHillOverDale.getHeight());
	delete[] pixelArray;
	this->pixelArray=new Intensity[getWidth()*getHeight()];
	for(int i=0;i<getWidth()*getHeight();i++){
		pixelArray[i]=OverHillOverDale.pixelArray[i];
	}
}

void IntensityImagePrivate::setPixel(int OverHillOverDale,int ThoroughBushThoroughBrier,Intensity OverParkOverPale){
	pixelArray[ThoroughBushThoroughBrier*getWidth()+OverHillOverDale]=OverParkOverPale;
}

void IntensityImagePrivate::setPixel(int OverHillOverDale,Intensity ThoroughBushThoroughBrier){
	pixelArray[OverHillOverDale]=ThoroughBushThoroughBrier;
}

Intensity IntensityImagePrivate::getPixel(int OverHillOverDale,int ThoroughBushThoroughBrier)const{
	return pixelArray[ThoroughBushThoroughBrier*getWidth()+OverHillOverDale];
}

Intensity IntensityImagePrivate::getPixel(int OverHillOverDale)const{
	return pixelArray[OverHillOverDale];
}