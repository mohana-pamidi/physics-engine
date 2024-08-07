#include <iostream>
#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 640, SCREEN_HEIGHT = 480;

bool init();


int main( int argc, char *argv[] ){
   //SDL_Init(SDL_INIT_EVERYTHING);
   SDL_Window* window = NULL;

   SDL_Surface* screenSurface = NULL; 

   if( SDL_Init ( SDL_INIT_VIDEO ) < 0 )
   {
        printf( "SDL could not initialized! SDL_Erro: %s\n", SDL_GetError() );
   }
   else
   {
        window = SDL_CreateWindow( "Physics Engine 1.0", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if( window == NULL)
        {

            printf( "Window could not be created! SDL_ERROR: %s\n", SDL_GetError() );


        }else
        {
            screenSurface = SDL_GetWindowSurface( window );

            SDL_FillRect ( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0&0xFF, 0&0xFF, 0&0xFF ) );

            SDL_UpdateWindowSurface( window );

            SDL_Event e; bool quit = false; while ( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }

        }

    }

    SDL_DestroyWindow( window );

    SDL_Quit();

    return 0;
}
