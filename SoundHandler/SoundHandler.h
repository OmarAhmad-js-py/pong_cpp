#ifndef PONG_SOUNDHANDLER_H
#define PONG_SOUNDHANDLER_H

#include <SFML/Audio.hpp>
#include <list>
#include <map>

using namespace std;
using namespace sf;

enum GameSoundKeys {
  BOUNCE
};

extern std::map<GameSoundKeys, std::string> GameSounds;

class SoundHandler {
public:
  SoundHandler();
  ~SoundHandler();
  static SoundHandler &getInstance();

  void loadSound(const string &path);
  SoundBuffer &getSound(const string &path);

  void playSound(const string &path);
  void playMusic(const string &path);
  void stopMusic();

private:
  map<string, SoundBuffer> sounds;
  list<Sound*> playing_sounds;
  Music *background_music = nullptr;
};


#endif//PONG_SOUNDHANDLER_H
