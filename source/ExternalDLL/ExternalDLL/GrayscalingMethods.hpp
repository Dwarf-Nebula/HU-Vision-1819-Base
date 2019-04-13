#ifndef GRAYSCALINGMETHODS_HPP
#define GRAYSCALINGMETHODS_HPP

class GrayscalingMethods {
	public:
		// Return the max color value
		int max(const int &r, const int &g, const int &b);
		
		// Return the min color value
		int min(const int &r, const int &g, const int &b);
		
		// (R + B + G) / 3
		int regular(const int &r, const int &g, const int &b);
		
		// ((R * 0.3) + ( G * 0.59) + (B * 0.11))
		int luminance(const int &r, const int &g, const int &b);
		
		// (max(R, G, B) + min(R, G, B)) / 2
		int desaturation(const int &r, const int &g, const int &b);
		
		// max(R, G, B)
		int max_decomposition(const int &r, const int &g, const int &b);
		
		// min(R, G, B)
		int min_decomposition(const int &r, const int &g, const int &b);
};

#endif // GRAYSCALINGMETHODS_HPP
