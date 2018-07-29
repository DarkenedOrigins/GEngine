#pragma once

#include <string>
#include <FreeImage.h>

namespace GEngine {
	static BYTE* load_image(const char* filepath, unsigned int* width, unsigned int* height) {
		FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
		FIBITMAP* dib = nullptr;
		fif = FreeImage_GetFileType(filepath);
		//fancy if statment that might not work lolz
		if (fif == FIF_UNKNOWN && (FreeImage_GetFIFFromFilename(filepath) == FIF_UNKNOWN)) {
			return nullptr;
		}
		if (FreeImage_FIFSupportsReading(fif)) {
			dib = FreeImage_Load(fif, filepath);
		}
		//check if null was returned
		if (!dib) {
			return nullptr;
		}
		BYTE* pixels = FreeImage_GetBits(dib);
		*width = FreeImage_GetWidth(dib);
		*height = FreeImage_GetHeight(dib);
		int bits = FreeImage_GetBPP(dib);
		int size = *width * *height * (bits / 8);
		BYTE* result = new BYTE[size];
		memcpy(result, pixels, size);
		FreeImage_Unload(dib);
		return result;
	}
}
