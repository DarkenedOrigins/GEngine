#include "sound.h"

GEngine::audio::Sound::Sound(const std::string & name, const std::string & filePath) : name_(name), filePath_(filePath), playing_(false), volume_(100) {
	musicPtr_ = new sf::Music();
	playOffset_ = sf::Time::Zero;
	if (!musicPtr_->openFromFile(filePath)) {
		delete musicPtr_;
		musicPtr_ = nullptr;
		std::cout << "error when trying to open file at: " << filePath << "make sure file is either a .wav or .ogg and that file exists at path" << std::endl;
	}
}

GEngine::audio::Sound::~Sound() {
	delete musicPtr_;
}

void GEngine::audio::Sound::play() {
	if (playing_) {
		return;
	}
	musicPtr_->play();
	playing_ = true;
}

void GEngine::audio::Sound::loop() {
	musicPtr_->setLoop(true);
}

void GEngine::audio::Sound::stopLoop() {
	musicPtr_->setLoop(false);
}

void GEngine::audio::Sound::pause() {
	playOffset_ = musicPtr_->getPlayingOffset();
	musicPtr_->pause();
	playing_ = false;
}

void GEngine::audio::Sound::resume() {
	if (playing_) {
		return;
	}
	musicPtr_->play();
	musicPtr_->setPlayingOffset(playOffset_);
	playing_ = true;
}

void GEngine::audio::Sound::stop() {
	musicPtr_->stop();
	playing_ = false;
}

void GEngine::audio::Sound::setVolume(float vol) {
	musicPtr_->setVolume(vol);
	volume_ = vol;
}
