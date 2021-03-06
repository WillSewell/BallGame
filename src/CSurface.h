#ifndef _CSURFACE_H_
    #define _CSURFACE_H_

#include <SDL/SDL.h>

class CSurface {
    public:
        CSurface();

    public:
        static SDL_Surface* OnLoad(const char* File);
        static bool OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y);
};

#endif
