#include "SoundHandler.h"
#include <iostream>

using namespace std;

std::map<GameSoundKeys, std::string> GameSounds = {
    {BOUNCE, "../assets/sounds/bounce.wav"}};

SoundHandler::SoundHandler() {
  string soundPaths[] = {
      "../assets/sounds/bounce.wav",
  };

  cout << "SoundHandler: Loading "
       << sizeof(soundPaths) / sizeof(soundPaths[0])
       << " sounds..." << endl;

  for (auto &sound: soundPaths) {
    cout << "SoundHandler: Loading sound: " << sound << endl;
    this->loadSound(sound);
  }

  cout << "SoundHandler: Sounds loaded" << endl;
}

SoundHandler::~SoundHandler() {
  for (auto sound: playing_sounds) {
    delete sound;
  }
}

SoundHandler &SoundHandler::getInstance() {
  static SoundHandler instance;
  return instance;
}

void SoundHandler::loadSound(const string &path) {
  sf::SoundBuffer buffer;
  if (!buffer.loadFromFile(path)) {
    throw runtime_error("Failed to load sound: " + path);
  }
  sounds[path] = buffer;
}

SoundBuffer &SoundHandler::getSound(const string &path) {
  auto it = sounds.find(path);
  if (it != sounds.end())
    return it->second;
  else
    throw runtime_error("Sound not loaded: " + path);
}

void SoundHandler::playSound(const string &path) {
  playing_sounds.remove_if([](const sf::Sound *s) {
    if (s->getStatus() != sf::Sound::Playing) {
      delete s; // Delete sound if not playing anymore
      return true;
    }
    return false;
  });

  auto *sound = new sf::Sound(this->getSound(path));
  cout << "SoundHandler: Playing sound: " << path << endl;
  sound->play();

  playing_sounds.push_back(sound);
}


void SoundHandler::playMusic(const string &path) {
  background_music = new Music();
  if (!background_music->openFromFile(path))
    throw runtime_error("Failed to load music: " + path);
  background_music->setLoop(true);
  background_music->play();
}

void SoundHandler::stopMusic() {
  if (background_music != nullptr) {
    background_music->stop();
    delete background_music;
    background_music = nullptr;
  }
}
