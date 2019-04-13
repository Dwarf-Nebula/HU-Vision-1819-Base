#include "GrayscalingMethods.hpp"


int GrayscalingMethods::max(const int &r, const int &g, const int &b) {
	int mx = r;
	if (g > mx) {
		mx = g;
	}
	if (b > mx) {
		return b;
	}
	return mx;
}
int GrayscalingMethods::min(const int &r, const int &g, const int &b) {
	int mn = r;
	if (g < r) {
		mn = g;
	}
	if (b < mn) {
		return b;
	}
	return mn;
}
int GrayscalingMethods::regular(const int &r, const int &g, const int &b) {
	return (r + g + b) / 3;
}
int GrayscalingMethods::luminance(const int &r, const int &g, const int &b){
	return ((r * 0.3) + (g * 0.59) + (b * 0.11));
}
int GrayscalingMethods::desaturation(const int &r, const int &g, const int &b) {
	return (max(r, g, b) + min(r, g, b)) / 2;
}
int GrayscalingMethods::max_decomposition(const int &r, const int &g, const int &b) {
	return max(r, g, b);
}
int GrayscalingMethods::min_decomposition(const int &r, const int &g, const int &b) {
	return min(r, g, b);
}