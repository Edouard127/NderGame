#include <stdio.h>
#include <time.h>
#include <iostream>
//#include <guy.h>
//#include <window.h>
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

}
//main
int main()
{


    int Oui = 1;
    int Non = 0;
    int enter = Oui | Non;
    int attack = random(0, Grid_Size-1);
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
                }



                    if(moveX == (bossX*Cell_Size) && moveY == (bossY*Cell_Size)){
                        printf("Voulez vous contre le boss ?\n");
                        scanf("%i", &enter);
                        if(enter == Oui){

                            int pvj = 100;
                            int pvb = 100;
                            int choix;
                            int combat = 1;
                            int Fer = 2;
                            int Platine = 4;
                            int Diamant = 6;

                            printf("Parfait\n");
                            printf("Choisissez votre armure\nFer\nPlatine\nDiamant");
                            scanf("%i", &choix);
                            if(choix == Fer){
                                printf("Votre armure: Fer");
                            }
                            else if(choix == Platine){
                                printf("Votre armure: Platine");
                            }
                            else if(choix == Diamant)
                                printf("Votre armure: Diamant");
                            while(combat){
                                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                                attack = random(0, Grid_Size-1);
                                int pvrj = pvj -= attack;
                                int pvrb = pvb -= attack;

                            SDL_Delay(500);
                            printf("Le boss vous attaque et vous enleve %ipv\n\n", attack);
                            attack = random(10, Grid_Size-1);
                            SDL_Delay(500);
                            pvrj -= attack;
                            printf("Il vous reste %ipv\n\n", pvrj);
                            pvrj += choix;
                            printf("Vous attaquez le boss et vous lui enlevez %i\n\n", attack);
                            attack = random(10, Grid_Size-1);
                            pvrb -= attack;
                            printf("Il reste %ipv au boss\n\n", pvrb);
                            SDL_Delay(1000);
                            if(pvrj < 1){
                                printf("Bravo tu as gagne\n\n");
                                combat = 0;
                                placeBoss(bossX*Cell_Size, bossY*Cell_Size);
                            }
                            else if(pvrb < 1){
                                printf("Tu as perdu :'(\n");
                                combat = 0;
                                loop = 0;
                            }

                            }
                        }
                        else if(enter == Non)
                            printf("Bon ben\n");
                        if(enter != Oui or Non){
                            printf("Repete svp");
                        }

                    }


            }
            else if(q.type == SDL_QUIT)
            {
                loop = 0;
            }

        }
        int combat = 1;

        clock_t nowClock = clock();
        clock_t ecouleClock = nowClock - avantClock;
        float tempssecond = float(ecouleClock) / float(CLOCKS_PER_SEC);





        SDL_SetRenderDrawColor(renderer, 0, 0 ,0, 255);
        SDL_RenderClear(renderer);
        //boss
        placeBoss(bossX*Cell_Size, bossY*Cell_Size);
        if(combat == 1){
            placeBoss(bossX*Cell_Size, bossY*Cell_Size);
        }
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
