#include <stdio.h>
#include <time.h>
#include <iostream>

#include <SDL2/SDL.h>
#ifdef __MINGW32__
#undef main
#endif

using namespace std;
SDL_Window* window;
SDL_Renderer* renderer;
SDL_Rect corps[200];

const int Cell_Size = 16;
const int Grid_Size = 16;
int x = corps[0].x;
int y = corps[0].y;
int dir;
int c = 0;
int r = 0;
int moveX = (Cell_Size*Grid_Size)/2, moveY = (Cell_Size*Grid_Size)/2;
int random(int min, int max){
    return rand() % (max-min+1)+min;
}

SDL_Rect drawSquare(SDL_Renderer* renderer,  int x, int y, int w, Uint8 r, Uint8 g, Uint8 b){
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_Rect carre;
    carre.x = x;
    carre.y = y;
    carre.h = w;
    carre.w = w;
    SDL_RenderFillRect(renderer, &carre);
    return carre;
}

SDL_Rect placeBoss(int x, int y){

    SDL_Rect carre;
    carre = drawSquare(renderer, x, y, Cell_Size, 255, 0, 0);
    drawSquare(renderer, c, r, Cell_Size, 0, 0, 255);
    return carre;
}



clock_t avantClock = 0;
void drawCell(int colonne, int range){

    c = colonne*Cell_Size;
    r = range*Cell_Size;

    drawSquare(renderer, c, r, Cell_Size, 0, 0, 255);
}
//main
int main()
{
    int bossX = random(0, Grid_Size-1);
    int bossY = random(0, Grid_Size-1);
    window = SDL_CreateWindow("NderBotBeta", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,Cell_Size * Grid_Size,Cell_Size * Grid_Size, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


    srand(time(0));
    int loop = 1;
    SDL_Event q;
    while(loop)
    {
        while(SDL_PollEvent(&q))
        {
            if(q.type == SDL_KEYDOWN)
            {
                if(q.key.keysym.sym == SDLK_ESCAPE)
                    loop = 0;
                else if(q.key.keysym.sym == SDLK_w){
                    moveY-= Cell_Size;
                }
                else if(q.key.keysym.sym == SDLK_a){
                    moveX-= Cell_Size;
                }
                else if(q.key.keysym.sym == SDLK_s){
                    moveY+= Cell_Size;
                }
                else if(q.key.keysym.sym == SDLK_d){
                    moveX+= Cell_Size;



                    if(moveX == (bossX*Cell_Size) && moveY == (bossY*Cell_Size)){
                        SDL_CreateWindow("NderBotBeta", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,Cell_Size * Grid_Size,Cell_Size * Grid_Size, SDL_WINDOW_SHOWN);
            }
                }
            }
            else if(q.type == SDL_QUIT)
            {
                loop = 0;
            }

        }

        clock_t nowClock = clock();
        clock_t ecouleClock = nowClock - avantClock;
        float tempssecond = float(ecouleClock) / float(CLOCKS_PER_SEC);




        SDL_SetRenderDrawColor(renderer, 0, 0 ,0, 255);
        SDL_RenderClear(renderer);
        //boss
        placeBoss(bossX*Cell_Size, bossY*Cell_Size);
        //bonhomme

        corps[0].x = moveX;
        corps[0].y = moveY;
        corps[0].w = Cell_Size;
        corps[0].h = Cell_Size;
        SDL_RenderFillRect(renderer, &corps[0]);
        SDL_RenderPresent(renderer);
    }

    //if(q.type != SDL_QUIT && SDL_Quit == false)
    return EXIT_SUCCESS;
}
