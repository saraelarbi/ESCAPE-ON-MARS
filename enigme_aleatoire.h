#ifndef  ALEATOIRE_H_INCLUDED 
#define ALEATOIRE_H_INCLUDED
typedef struct 
{
    SDL_Surface *text;
    SDL_Rect positiontext;
}texte;



int enigme(SDL_Surface* screen,TTF_Font *police);



#endif
