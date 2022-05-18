#ifndef _SoundCreator_H_
#define _SoundCreator_H_
 
#include <SDL.h>
#include <SDL_mixer.h>
#include <vector>
 
class SoundCreator 
{
    public:
        static SoundCreator SoundControl;
 
        std::vector<Mix_Chunk*> SoundList;
 
        SoundCreator();
 
        int OnLoad(char* File);
 
        void OnCleanup();

        void Play(int ID);
};
 
#endif