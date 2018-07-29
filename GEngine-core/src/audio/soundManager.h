#pragma once

#include <map>
#include "sound.h"

namespace GEngine {
	namespace audio {
		class SoundManager {
		private:
			static std::map<std::string, Sound*> soundMap_;

		public:
			static void add(Sound* soundPtr);
			static Sound* get(const std::string& name);
			static void clean();

		private:
			SoundManager() {}
		};
	}
}


