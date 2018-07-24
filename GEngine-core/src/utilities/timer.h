#pragma once

#define WINDOWS_TIMER (0)
#if WINDOWS_TIMER
#include <Windows.h>
#else
#include <chrono>
#endif

namespace GEngine {
	class Timer {

		#if WINDOWS_TIMER
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
		float elapsed() {
			LARGE_INTEGER cur;
			QueryPerformanceCounter(&cur);
			unsigned __int64 cycles = cur.QuadPart - start_.QuadPart;
			return (float)(cycles * freq_);
		}
		#else
	private:
		typedef std::chrono::high_resolution_clock HighResolutionClock;
		typedef std::chrono::duration<float, std::milli> milliseconds_type;
		std::chrono::time_point<HighResolutionClock> m_Start;
	public:
		Timer() {
			reset();
		}

		void reset() {
			m_Start = HighResolutionClock::now();
		}

		float elapsed() {
			return std::chrono::duration_cast<milliseconds_type>(HighResolutionClock::now() - m_Start).count() / 1000.0f;
		}
		#endif
	};
}
