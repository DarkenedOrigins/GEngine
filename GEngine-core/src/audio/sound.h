#pragma once

#include <iostream>
#include <SFML/Audio.hpp>

namespace GEngine {
	namespace audio {
		class Sound {
		private:
			std::string name_;
			std::string filePath_;
			sf::Music* musicPtr_;
			sf::Time playOffset_;
			bool playing_;
			float volume_;

		public:
			Sound(const std::string& name, const std::string& filePath);
			~Sound();

			void play();
			void loop();
			void stopLoop();
			void pause();
			void resume();
			void stop();

			void setVolume(float vol);

			inline const bool isPlaying() const { return playing_; }
			inline const float getVolume() const { return volume_; }
			inline const std::string& getName() const { return name_; }
			inline const std::string& getFilePath() const { return filePath_; }

		};
	}
}
