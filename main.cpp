#include <SDL2/SDL.h>

#include <cstdio>

int main(int argc, char** argv)
{
    /* Initialisation simple */
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return -1;
    }

    {
        /* Création de la fenêtre */
        SDL_Window* pWindow = nullptr;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  640,
                                                                  480,
                                                                  SDL_WINDOW_SHOWN);

        if( pWindow )
        {

            SDL_Renderer* renderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);

            // Select the color for drawing. It is set to red here.
            SDL_SetRenderDrawColor(renderer, 128, 0, 0, 255);

            SDL_Rect rect;
            rect.x = 50;
            rect.y = 50;
            rect.w = 100;
            rect.h = 100;


            // Clear the entire screen to our selected color.
            SDL_RenderClear(renderer);

            SDL_SetRenderDrawColor(renderer, 128, 255, 0, 255);
            SDL_RenderFillRect(renderer, &rect);

            SDL_RenderPresent(renderer);

            ///SDL_Delay(3000); /* Attendre trois secondes, que l'utilisateur voie la fenêtre */
            SDL_Event event;
            while(true)
            {
                SDL_WaitEvent(&event);
                if(event.type == SDL_QUIT)
                    break;
            }



            SDL_DestroyWindow(pWindow);
        }
        else
        {
            fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
        }
    }

    SDL_Quit();

    return 0;
}
