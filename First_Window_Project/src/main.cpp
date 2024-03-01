//Our setup for now is a bit unique so here is an example of how to include the SDL libraries in our projects
#define SDL_MAIN_HANDLED
#include "..\..\SDL2\headers\SDL.h"
//#include "..\..\SDL2\headers\SDL_image.h"

#include <iostream>

using namespace std;

namespace SDL_globals{
    const int SCREEN_WIDTH = 1200;
    const int SCREEN_HEIGHT = 800;

    //The window we'll be rendering to
    SDL_Window* window = NULL;

    //surface contained by the window
    SDL_Surface* screen_surface = NULL;

    //image surfaces
    SDL_Surface* background_surface = NULL;
    SDL_Surface* image_surface = NULL;
}
using namespace SDL_globals;

int init_window();
void game_loop();
void draw_image(string image_path);



int main(int argc, char* args[]){
    cout<< "main is running" << endl;

    init_window();
    draw_image("media/farm_background.bmp");

    game_loop();



    return 0;
}

int init_window(){
    int error = SDL_Init(SDL_INIT_VIDEO);
    if(error < 0){
        cout << "SDL Init returned error code: " << SDL_GetError() << endl;
        return error;
    }
    //window maker
    window = SDL_CreateWindow("Animal Farm", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if(window == NULL){
        cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
        return -2;
    }

    screen_surface = SDL_GetWindowSurface(window);
    return error;
}

void game_loop(){
    SDL_Event e;
    bool quit = false;

    //This loop handles sdl events
    //for the most part it is not implemented here but merly keeping the window from locking up
    //and making it so it responds when you click on the close button.
    while(quit == false){
        while(SDL_PollEvent(&e)){
            if(e.type == SDL_QUIT){
                quit = true;
            }

        }
    }
    SDL_DestroyWindow(window);
    SDL_Quit();

}

void draw_image(string image_path){
    //loads the image from the image path onto an sdl surface
    image_surface = SDL_LoadBMP(image_path.c_str());

    // copies that surface over to the window's surface
    SDL_BlitSurface(image_surface, NULL, screen_surface, NULL);
    // once your finished getting the window surface ready it is time to update the live window so changes are viewd.
    SDL_UpdateWindowSurface(window);
}
