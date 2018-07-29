#include "soundManager.h"

namespace GEngine {
	namespace audio {
		std::map<std::string, Sound*> SoundManager::soundMap_;


		void SoundManager::add(Sound * soundPtr) {
			if (soundMap_.find(soundPtr->getName()) == soundMap_.end()) {
				soundMap_[soundPtr->getName()] = soundPtr;
			} else {
				std::cout << "sound already exists inside manager" << std::endl;
			}
		}
		Sound * SoundManager::get(const std::string & name) {
			auto it = soundMap_.find(name);
			if (it == soundMap_.end()) {
				std::cout << "sound by the name of " << name << " not found inside sound manager nullptr returned" << std::endl;
				return nullptr;
			} else {
				return it->second;
			}
		}
		void SoundManager::clean() {
			for (const auto& item : soundMap_) {
				delete item.second;
			}
		}
	}
}