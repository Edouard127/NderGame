#include <stdio.h>
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
#include <fstream>
#include <SDL2/SDL_image.h>
#include <string>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL.h>
#include <QtGui/QColor>
using namespace std;
SDL_Window *window = NULL;
SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
SDL_Surface *image = IMG_Load("a.PNG");
SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);
#ifdef __MINGW32__
#undef main
#endif


SDL_Rect corps[200];
int taille;
const int Cell_Size = 16; //La grille de jeu
const int Grid_Size = 16;
int x = corps[0].x;
int y = corps[0].y;
int dir;
int c = 0;
int r = 0;
int pvj = 100; //pvjoueur
int pvb = 100; //pvboss
int choix; //choix d'armure
int moveX = (Cell_Size*Grid_Size)/2, moveY = (Cell_Size*Grid_Size)/2; //les touche moveX, moveY
int random(int min, int max){
    return rand() % (max-min+1)+min;
}

SDL_Rect drawSquare(SDL_Renderer* renderer,  int x, int y, int w, Uint8 r, Uint8 g, Uint8 b){ //Un bordel de carré
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_Rect carre;
    carre.x = x;
    carre.y = y;
    carre.h = w;
    carre.w = w;
    SDL_RenderFillRect(renderer, &carre);
    return carre;
}

SDL_Rect placeBoss(int x, int y){ //CE qui place le boss

    SDL_Rect carre;
    carre = drawSquare(renderer, x, y, Cell_Size, 255, 0, 0);
    drawSquare(renderer, c, r, Cell_Size, 0, 0, 255);
    return carre;
}




void drawCell(int colonne, int range){ //J'me souvien meme plus pourquoi c'est la

    c = colonne*Cell_Size;
    r = range*Cell_Size;

}



//main
int main(int argc, char* args[])
{
   ifstream fichier("sav.sav");

   if(fichier)
   {
      //L'ouverture s'est bien passée, on peut donc lire
       printf("La sauvegarde a bien ete lu\n");

      string ligne; //Une variable pour stocker les lignes lues

      while(getline(fichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
      {
          taille = fichier.tellg();
          fichier.seekg(0, ios::end);
         cout << ligne << endl;



         cout << "Taille du fichier : " << taille << " octets." << endl;

      }
   }
   else
   {
      cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
   }





    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    int save = 3;
    int Oui = 1;//les choix pour le jeu
    int Non = 0;//les choix pour le jeu
    int enter = Oui | Non | save;//les choix pour le jeu
    int attack = random(0, Grid_Size-1); //Le nombre de dégat
    int bossX = random(0, Grid_Size-1); //Position du boss
    int bossY = random(0, Grid_Size-1); //Position du boss

    window = SDL_CreateWindow("NderBotBeta", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,Cell_Size * Grid_Size,Cell_Size * Grid_Size, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);



    IMG_Init(IMG_INIT_PNG);
        texture = IMG_LoadTexture(renderer, "a.png");
        const char* SDL_GetError(void);
        if(texture == NULL)
        {
            printf("Erreur [Debug] > %s\n", SDL_GetError());
        }
        if(renderer == NULL)
        {
            printf("Erreur [Debug] > %s\n", SDL_GetError());
        }
        if(window == NULL)
        {
            printf("Erreur [Debug] > %s\n", SDL_GetError());
        }



            SDL_RenderCopy(renderer, texture, NULL, NULL);
            SDL_RenderPresent(renderer);
            SDL_Delay(1000);
            SDL_RenderClear(renderer);




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
                if(q.key.keysym.sym == SDLK_f)
                {
                string const enderSav("sav.sav");
                ofstream ecritFicher(enderSav.c_str());
                if(ecritFicher)
                {


                    printf("Ecriture de la sauvegarde\n");
                    ecritFicher << "//Sauvegarde du jeu\\" << endl;
                    ecritFicher << "pvj == " << pvj << endl;

                    ecritFicher << "choix armure == " "NULL" << endl;





                }
                else
                {
                    printf("[DEBUG] > %s", SDL_GetError());
                }
                }





                    if(moveX == (bossX*Cell_Size) && moveY == (bossY*Cell_Size)){



                        printf("Voulez vous contre le boss ?\n");
                        scanf("%i", &enter);
                        if(enter == Oui){ //Si la réponse est oui, le jeu commence





                             Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);


                            Mix_Music *backgroundSound = Mix_LoadMUS("battle.mp3");

                            Mix_PlayMusic(backgroundSound, -1);
                            if(SDL_Init(SDL_INIT_VIDEO) < 0)
                                {
                                    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
                                    return EXIT_FAILURE;
                                }



                            int combat = 1; //Pour la loop
                            int attaque;
                            int Fer = 2;
                            int Platine = 4;
                            int Diamant = 6;
                            int bf;
                            int cp;
                            int lt;
                            int ls;
                            int taille;
//                            int feu;
//                            int glace;
//                            int EnderBoss;
                              int monstre;
//                            attack = random(2, Grid_Size-1);
//                            if(attack <= 4)
//                            {
//                                monstre = feu;
//                            }
//                            else if(attack == 10)
//                            {
//                                monstre = EnderBoss;
//                            }
//                            else {
//                                monstre = glace;
//                            }

                            printf("Parfait\n");
                            printf("Vous vous combattez contre le boss%i", monstre);
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



                                attack = random(0, Grid_Size-1); //Redéfini attack
                                int pvrj = pvj -= attack; //pvjr = pvrestantjoueur
                                int pvrb = pvb -= attack; //pvrb = pvrestantboss




                            printf("Le boss vous attaque et vous enleve %ipv\n\n", attack);
                            attack = random(10, Grid_Size-1);
                            SDL_Delay(500);
                            pvrj -= attack;
                            pvrj += choix; //Va remettre des pv en fonction de l'armure
                            printf("Il vous reste %ipv\n\n", pvrj);
                            printf("Choisissez votre attaque: Boule de feu(bf)%i, Coup de point(cp)%i,\nLame Tranchante(lt)%i, Lance de sandwich(ls)%i", bf, cp, lt, ls);
                            scanf("%i", &attaque);


                            printf("Vous utilisez l'attaque%i Et vous lui enlever%i\n\n", attaque, attack);
                            if(attaque == lt)
                            {
                                printf("Ce n'est pas tres efficace :/");
                                SDL_Delay(500);
                                printf("Mais le monstre de %i a aime le repas, +10 de coolitude", monstre);
                            }
                            attack = random(10, Grid_Size-1);
                            pvrb -= attack;
                            printf("Il reste %ipv au boss\n\n", pvrb);
                            SDL_Delay(1000);
                            if(pvrj < 1){ //DE ICI!!!!!!!!!!!!!!!!
                                printf("Bravo tu as gagne\n\n");
                                combat = 0;
                                placeBoss(bossX*Cell_Size, bossY*Cell_Size);
                            }
                            else if(pvrb < 1){
                                printf("Tu as perdu :'(\n");
                                combat = 0;

                            } //A ICI!!!!!!!!!!!!!!!!!!, y'a un bug, sa arrete le jeu en disant tu as reussi quand sa atteint les nombres négatifs

                            }
                        }
                        else if(enter == Non)
                            printf("Bon ben\n");

                       Mix_HaltMusic();
                       Mix_CloseAudio();
                    }
                }



            else if(q.type == SDL_QUIT)
            {
                loop = 0;
            }

        }






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

    return EXIT_SUCCESS;
}
