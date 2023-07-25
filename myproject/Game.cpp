#include "Game.h"

Game::Game() {
    SDL_Init(SDL_INIT_VIDEO);
    this->screenWidth = 640;
    this->screenHeight = 480;
    this->window = SDL_CreateWindow( "SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->screenWidth, this->screenHeight, SDL_WINDOW_SHOWN );
    this->screenSurface = SDL_GetWindowSurface( this->window );
    this->quit = false;
}

void Game::Run() {
    // Fill the surface crimson
    SDL_FillRect( this->screenSurface, NULL, SDL_MapRGB( this->screenSurface->format, 0x8B, 0x0, 0x0) );
    // Update the surface
    SDL_UpdateWindowSurface( this->window );
    while (!this->quit) {
        PollEvents();
    }
    QuitGame();
}

void Game::PollEvents() {
    SDL_Event e;
    while( SDL_PollEvent( &e ) )
    {
        if( e.type == SDL_QUIT )
            this->quit = true;
        if( e.key.state == SDL_PRESSED)
        {
            switch (e.key.keysym.sym)
            {
                // Case 1: Right key is pressed, show brown
                case SDLK_RIGHT:
                    UpdateWindow(0xD2, 0x69, 0x1E);
                    break;
                // Case 2: Left key is pressed, show blue 
                case SDLK_LEFT:
                    UpdateWindow(0x1E, 0x90, 0xFF);
                    break;
                // Case 3: Up key is pressed, show green
                case SDLK_UP:
                    UpdateWindow(0x32, 0xCD, 0x32);
                    break;
                // Case 4: Down key is pressed, show purple
                case SDLK_DOWN:
                    UpdateWindow(0x80, 0x0, 0x80);
                    break;
                // Case 5: Any other key is pressed, show white
                default:
                    UpdateWindow(0xF0, 0xF8, 0xFF);
                    break;
            }
        }
    }
}

void Game::UpdateWindow(int r, int g, int b) {   
    // Fill the surface white
    SDL_FillRect( this->screenSurface, NULL, SDL_MapRGB( this->screenSurface->format, r, g, b) );
    // Update the surface
    SDL_UpdateWindowSurface( this->window );
}

void Game::QuitGame() {
    // Destroy window
	SDL_DestroyWindow( this->window );
	// Quit SDL subsystems
	SDL_Quit();
}