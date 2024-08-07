#include <iostream>
#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 800, SCREEN_HEIGHT = 600;

int main( int argc, char *argv[] ){
   
   SDL_Window* window = NULL;

   SDL_Renderer* renderer = NULL;

   SDL_Surface* screenSurface = NULL; 

   std::cout << "Rendering...";

   if( SDL_Init ( SDL_INIT_EVERYTHING ) < 0 )
   {
        printf( "SDL could not initialized! SDL_Error: %s\n", SDL_GetError() );
   }
   else
   {
        window = SDL_CreateWindow( "Physics Engine 1.0", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if( window == NULL || renderer == NULL)
        {

            printf( "Window/renderer could not be created! SDL_ERROR: %s\n", SDL_GetError() );


        }else
        {
            screenSurface = SDL_GetWindowSurface( window );

            SDL_FillRect ( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0&0xFF, 0&0xFF, 0&0xFF ) );


            SDL_UpdateWindowSurface( window );

            SDL_RenderSetLogicalSize( renderer, 200, 200 );

            SDL_Event e; bool quit = false; 
            while ( quit == false )
            { 
                while( SDL_PollEvent( &e ) )
                { 
                    if( e.type == SDL_QUIT ) 
                    {
                        quit = true;
                    } 
                }

                std::cout << "Rendering...";

                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0 );
                SDL_RenderClear( renderer );

                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255 );
                //SDL_RenderSetScale( renderer, 1.0, 1.0 );
                SDL_RenderDrawPoint(renderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

                SDL_RenderPresent( renderer );
            }

        }

    }
    

    SDL_DestroyWindow( window );

    SDL_DestroyRenderer( renderer );

    SDL_Quit();

    return 0;
}
