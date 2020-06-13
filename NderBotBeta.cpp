#include <stdio.h>
#include <time.h>
#include <ios>
#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
#include <fstream>
#include <SDL2/SDL_net.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL.h>
#include <QtGui/QColor>
#include <time.h>
using namespace std;
SDL_Window *window = NULL;
SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
SDL_Surface *image = IMG_Load("a.PNG");
SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);
TTF_Font *police = NULL;
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

SDL_Rect placeBoss(int x, int y){ //Ce qui place le boss

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
int main(void)
{
    srand(time(0));


   ifstream lireFichier("save.h"); //lire
   if(lireFichier)
   {

      //L'ouverture s'est bien passée, on peut donc lire
       printf("La sauvegarde a bien ete lu\n");

      string ligne; //Une variable pour stocker les lignes lues

      while(getline(lireFichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
      {
          taille = lireFichier.tellg();
          cout << ligne << endl;





      }
      cout << "Le fichier fait " << taille << " octets" << endl;



   }

   else
   {
      cout << "[DEBUG]: Impossible de trouver le ficher ou il est deja ouvert" << endl;
      cout << "[DEBUG]: Veuillez sauvegarder ou fermer le ficher ouvert" << endl;

   }





    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    bool Oui = 0;//les choix pour le jeu
    int command = 0;
    int choix_mine = rand() % 15;

    int enter;//les choix pour le jeu
    int attack = random(0, Grid_Size-1); //Le nombre de dégat
    int bossX = random(0, Grid_Size-1); //Position du boss
    int bossY = random(0, Grid_Size-1); //Position du boss
    int mana = 30;
    int power = 0;
    int level = 0;
    int pvj = 109; //pvjoueur
    int pvb = 109; //pvboss
    int pvrj = pvj -= attack; //pvjr = pvrestantjoueur
    int pvrb = pvb -= attack; //pvrb = pvrestantboss
    int stone = 0; int r_stone = 0;
    int pp = 0; int r_pp = 1;
    int am = 0; int r_am = 2;
    int iron = 0; int r_iron = 3;
    int gold = 0; int r_gold = 4;
    int obsi = 0; int r_obsi = 5;
    int ruby = 0; int r_ruby = 6;
    int emerald = 0; int r_emerald = 7;
    int sapphire = 0; int r_sapphire = 8;
    int cobalt = 0; int r_cobalt = 9;
    int mithril = 0; int r_mithril = 10;
    int adamantite = 0; int r_adamantite = 11;
    int coal = 0; int r_coal = 12;
    int uranium = 0; int r_uranium = 13;
    int plutonium = 0; int r_plutonium = 14;
    int pick = 0;
    int sword = 0;
    int shield = 0;
    int fight_level = 0;
    int golem = 0;
    int house = 0;
    int ring = 0;
    int gen = 0;
    int fish = 0;
    int mine = 0;
    int mi = 0;
    int mineall = 0;
    int mia = 0;
    int craft = 0;
    clock_t avantClock = 0;
    clock_t nowClock = clock();
            clock_t ecouleClock = nowClock - avantClock;
            float tempssecond = float(ecouleClock) / float(CLOCKS_PER_SEC);

    window = SDL_CreateWindow("NderBot", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,Cell_Size * Grid_Size,Cell_Size * Grid_Size, SDL_WINDOW_SHOWN);
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
                if(q.key.keysym.sym == SDLK_c)
                {
                    enter = 1;
                    cout << "Commande possible: mine [mi], mineall[mia], craft [arguments]\n" << endl;
                    cin >> enter;
                    if(enter == (mine or mi) && enter == 1)
                    {
                        if(choix_mine == r_stone)
                        {
                             stone += random(20, 100*pick);
                        }
                        else if(choix_mine == r_pp)
                        {
                             pp += random(1, 2*pick);
                        }
                        else if(choix_mine == r_am)
                        {
                             am += random(1, 2*pick);
                        }
                        else if(choix_mine == r_iron)
                        {
                             iron += random(20, 30*pick);
                        }
                        else if(choix_mine == r_gold)
                        {
                             gold += random(20, 25*pick);
                        }
                        else if(choix_mine == r_obsi)
                        {
                             obsi += random(20, 20*pick);
                        }
                        else if(choix_mine == r_ruby)
                        {
                             ruby += random(20, 20*pick);
                        }
                        else if(choix_mine == r_emerald)
                        {
                             emerald += random(20, 20*pick);
                        }
                        else if(choix_mine == r_sapphire)
                        {
                             sapphire += random(20, 20*pick);
                        }
                        else if(choix_mine == r_cobalt)
                        {
                             cobalt += random(20, 20*pick);
                        }
                        else if(choix_mine == r_mithril)
                        {
                             mithril += random(20, 20*pick);
                        }
                        else if(choix_mine == r_adamantite)
                        {
                             adamantite += random(20, 20*pick);
                        }
                        else if(choix_mine == r_coal)
                        {
                             coal += random(5, 10*pick);
                        }
                        else if(choix_mine == r_uranium)
                        {
                             uranium += random(5, 8*pick);
                        }
                        else if(choix_mine == r_plutonium)
                        {
                             plutonium += random(4, 6*pick);
                        }
                        enter = 0;
                    }
                        enter = 1;




                    if(enter == (mineall or mia) && enter == 1)
                    {
                        stone += random(mana, mana*mana);
                        pp += random(mana, mana*mana);
                        am += random(mana, mana*mana);
                        iron += random(mana, mana*mana);
                        gold += random(mana, mana*mana);
                        obsi += random(mana, mana*mana);
                        ruby += random(mana, mana*mana);
                        emerald += random(mana, mana*mana);
                        sapphire += random(mana, mana*mana);
                        cobalt += random(mana, mana*mana);
                        mithril += random(mana, mana*mana);
                        adamantite += random(mana, mana*mana);
                        coal += random(mana, mana*mana);
                        uranium += random(mana, mana*mana);
                        plutonium += random(mana, mana*mana);
                        mana -= mana;
                    }

                }


                if(q.key.keysym.sym == SDLK_f)
                {

                    string const enderSav("save.h"); //ecrire
                    ofstream ecritFichier(enderSav.c_str());
                if(ecritFichier)
                {


                    printf("Ecriture de la sauvegarde\n");
                    ecritFichier << "//Sauvegarde du jeu\\" << endl;
                    ecritFichier << "//Experience du joueur\\" << endl;
                    ecritFichier << "int pvj = " << pvj << ";" << endl;
                    ecritFichier << "int mana = " << mana << ";" << endl;
                    ecritFichier << "int power = " << power << ";" << endl;
                    ecritFichier << "int level = " << level << ";" << endl;
                    ecritFichier << "//Ressource joueur\\" << ";" << endl;
                    ecritFichier << "int stone = " << stone << ";" << endl;
                    ecritFichier << "int iron = " <<iron << ";" << endl;
                    ecritFichier << "int pp = " << pp << ";" << endl;
                    ecritFichier << "int gold = " << gold << ";" << endl;
                    ecritFichier << "int am = " << am << ";" << endl;
                    ecritFichier << "int obsi = " << obsi << ";" << endl;
                    ecritFichier << "int ruby = " << ruby << ";" << endl;
                    ecritFichier << "int cobalt = " << cobalt << ";" << endl;
                    ecritFichier << "int coal = " << coal << ";" << endl;
                    ecritFichier << "int emerald = " << emerald << ";" << endl;
                    ecritFichier << "int mithril = " << mithril << ";" << endl;
                    ecritFichier << "int uranium = " << uranium << ";" << endl;
                    ecritFichier << "int sapphire = " << sapphire << ";" << endl;
                    ecritFichier << "int adamantite = " << adamantite << ";" << endl;
                    ecritFichier << "int plutonium = " << plutonium << ";" << endl;
                    ecritFichier << "int pick = " << pick << ";" << endl;
                    ecritFichier << "int house = " << house << ";" << endl;
                    ecritFichier << "int gen = " << gen << ";" << endl;
                    ecritFichier << "int fish = " << fish << ";" << endl;
                    ecritFichier << "//Emplacement du joueur" << endl;
                    ecritFichier << "int moveX = " << moveX << ";" << endl;
                    ecritFichier << "int moveY = " << moveY << ";" << endl;
                    ecritFichier << "//Emplacement du boss" << endl;
                    ecritFichier << "int bossX = " << bossX << ";" << endl;
                    ecritFichier << "int bossY = " << bossY << ";" << endl;








                }
                else
                {
                    printf("[DEBUG] > %s", SDL_GetError());
                }

                }
                if(q.key.keysym.sym == SDLK_e)
                {
                    printf("Ton inventaire\nMana %i ||| PV %i ||| Energie %i\n--------------------\n", mana, pvrj, power);
                    printf("Level %i\n--------------------\n", level);
                    printf("Stone %i ||| Iron %i\n--------------------\nPerfect Prism %i ||| Gold %i\n--------------------\n", stone, iron, pp, gold);
                    SDL_Delay(100);
                    printf("Antimatter %i ||| Obsidian %i\n--------------------\n", am, obsi);
                    printf("Ruby %i ||| Cobalt %i ||| Coal %i\n--------------------\n", ruby, cobalt, coal);
                    printf("Emerald %i ||| Mithril %i ||| Uranium %i\n--------------------\n", emerald, mithril, uranium);
                    printf("Sapphire %i ||| Adamantite %i ||| Plutonium %i\n--------------------\n", sapphire, adamantite, plutonium);
                    printf("Pickaxe - Level %i ||| House - Level %i ||| Ring - Level %i\n--------------------\n", pick, house, ring);
                    printf("Generator - Level %i ||| Fishing Rod - Level %i\n--------------------\n", gen, fish);
                }
                if(tempssecond >= 30)
                {
                    mana += 1;
                }





                    if(moveX == (bossX*Cell_Size) && moveY == (bossY*Cell_Size)){
                        Oui = 1;



                        cout << "Voulez vous combattre le boss ? (T'es oblige mdr)" << endl;
                        scanf("%i", &enter);
                        if(Oui){ //Si la réponse est oui, le jeu commence






//                             Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);


//                            Mix_Music *backgroundSound = Mix_LoadMUS("battle.mp3");

//                            Mix_PlayMusic(backgroundSound, -1);
//                            if(SDL_Init(SDL_INIT_VIDEO) < 0)
//                                {
//                                    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
//                                    return EXIT_FAILURE;
//                                }







                            int boss = 0;


                            SDL_Delay(500);
                            cout << "Vous vous combattez contre le boss\n " << boss << endl;

                            while(Oui){



                                attack = random(0, Grid_Size-1); //Redéfini attack





                            cout << "Le boss vous attaque et vous enleve " << attack << "pv\n" << endl;


                            attack = random(10, Grid_Size-1);

                            pvrj -= attack;
                            pvrj += choix; //Va remettre des pv en fonction de l'armure
                            cout << "Il vous reste " << pvrj << " pv\n" << endl;

                            cout << "Vous attaquez le boss " << boss << " et enlevez " << attack << " au boss\n" << endl;


                            attack = random(10, Grid_Size-1);
                            pvrb -= attack;
                            cout << "Il reste " << pvrb << " pv au boss\n" << endl;



                            if(pvrj < 1){
                                cout << "Tu as perdu(e)" << endl;
                                Oui = 0;
                                placeBoss(bossX*Cell_Size, bossY*Cell_Size);
                            }
                            else if(pvrb < 1){
                                cout << "Tu as gagne(e)" << endl;
                                Oui = 0;


                            }
                            }
                        }

//                        else if(enter == easter)
//                    {
//                            Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);


//                           Mix_Music *backgroundSound = Mix_LoadMUS("battle.mp3");

//                           Mix_PlayMusic(backgroundSound, -1);
//                     }



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
