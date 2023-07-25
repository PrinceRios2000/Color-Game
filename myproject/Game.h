#include <SDL2/SDL.h>
#include <stdio.h>

#pragma once

class Game {
    private:
        SDL_Window* window;
        SDL_Surface* screenSurface;
        bool quit;
        int screenWidth;
        int screenHeight;
    public:
        Game();
        void Run();
        void PollEvents();
        void UpdateWindow(int r, int g, int b);
        void QuitGame();
};

#include "Game.cpp"