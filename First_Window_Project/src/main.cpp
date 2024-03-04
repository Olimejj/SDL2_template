//Our setup for now is a bit unique so here is an example of how to include the SDL libraries in our projects
#define SDL_MAIN_HANDLED
#include "../../SDL2/headers/SDL.h"
//#include "..\..\SDL2\headers\SDL_image.h"

#include <iostream>
#include <string>

using namespace std;

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 800;

//The window we'll be render to
SDL_Window* window = NULL;
//surface contained by the window
SDL_Surface* screen_surface = NULL;

SDL_Surface* image_surface = NULL;

int init_window();
void game_loop();
void draw_image(string image_path);

int main(int argc, char* args[]){
    cout << "main is running" << endl;

    init_window();
    draw_image("media/farm_background.bmp");
    game_loop();

}

int init_window(){
    int err = SDL_Init(SDL_INIT_VIDEO);
    if(err < 0){
        cout << "SDL Init returned error code: " << SDL_GetError() << endl;
        return err;
    }
    window = SDL_CreateWindow("Demo",  SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN); 

    if(window == NULL){
        cout << "SDL create window returned error code: " << SDL_GetError() << endl;
        return -2;
    }

    screen_surface = SDL_GetWindowSurface(window);

    return err;

}

void game_loop(){
    SDL_Event e;
    bool quit = false;

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
    image_surface = SDL_LoadBMP(image_path.c_str());

    SDL_BlitSurface(image_surface, NULL, screen_surface, NULL);

    SDL_UpdateWindowSurface(window);

}
