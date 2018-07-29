#pragma once

#include <string>

namespace GEngine {
	static std::string readFile(const char* filepath) {
		FILE* file;
		fopen_s(&file, filepath, "rt");
		if (file == NULL) {
			//error out if file does not open for what ever reason
			std::string fpath(filepath);
			fpath = "Following error opening " + fpath;
			perror(fpath.c_str());
		}
		fseek(file, 0, SEEK_END);
		long lenght = ftell(file);
		char* data = new char[lenght + 1];
		memset(data, 0, lenght + 1);		//set char array to zero
		fseek(file, 0, SEEK_SET);
		fread(data, 1, lenght, file);		//read file into buffer
		fclose(file);
		std::string result(data);			//create string with data
		delete[] data;
		return result;
	}
}