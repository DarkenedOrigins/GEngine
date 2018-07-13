#pragma once

#include <Windows.h>

namespace GEngine {
	class Timer {

	private:
		LARGE_INTEGER start_;
		double freq_;
	public:
		Timer() {
			LARGE_INTEGER freq;
			QueryPerformanceFrequency(&freq);
			freq_ = 1.0 / freq.QuadPart;
			QueryPerformanceCounter(&start_);
		}
		void reset() {
			QueryPerformanceCounter(&start_);
		}
		float elasped() {
			LARGE_INTEGER cur;
			QueryPerformanceCounter(&cur);
			unsigned __int64 cycles = cur.QuadPart - start_.QuadPart;
			return (float)(cycles * freq_);
		}
	};
}
