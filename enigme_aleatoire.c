#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include </usr/include/SDL/SDL.h>
#include </usr/include/SDL/SDL_ttf.h>
#include </usr/include/SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "aleatoire.h"

    int enigme(SDL_Surface *screen,TTF_Font *police)
{
    int num[8], i, affich[4], c, lvl = 0, continuer = 1, f = 0;
   // TTF_Font *police=NULL;
    SDL_Surface *texte[8], *background, *bout[4], *finish[2];
    SDL_Rect position[8], pos, bouton[4], cont;
    SDL_Color couleurblanc = {255, 255, 255};
    SDL_Event event, event2;
    char rep[8][5];
    srand(time(NULL));
    num[0] = rand() % 5 + 1;
    for (i = 1; i < 4; i++)
    {
        num[i] = rand() % 20 + 2;
    }
    num[4] = ((num[1] + num[2]) * num[0]) - num[3];
    for (i = 5; i < 8; i++)
    {
        num[i] = rand() % 50 + 2;
    }
    affich[0] = rand() % 4 + 4;
    do
    {
        affich[1] = rand() % 4 + 4;
    } while (affich[0] == affich[1]);
    do
    {
        affich[2] = rand() % 4 + 4;
    } while (affich[0] == affich[2] || affich[1] == affich[2]);
    do
    {
        affich[3] = rand() % 4 + 4;
    } while (affich[0] == affich[3] || affich[1] == affich[3] || affich[2] == affich[3]);

    for (i = 0; i < 8; i++)
    {
        sprintf(rep[i], "%i", num[i]);
    }
    police = TTF_OpenFont("roboto.ttf", 50); //chargement police

    if (police == NULL)
    {
        printf("police erreur\n");
    }
    for (i = 0; i < 8; i++)

        texte[i] = TTF_RenderText_Blended(police, rep[i], couleurblanc); //chargement text

    background = IMG_Load("enigme.jpg");
    bout[0] = IMG_Load("bouton_enigme_notpressed.png");
    bout[1] = IMG_Load("bouton_enigmepressed.png");
    bout[2] = IMG_Load("bouton_continue_notpressed.png");
    bout[3] = IMG_Load("bouton_continuepressed.jpg");
    finish[0] = IMG_Load("enigme_win.png");
    finish[1] = IMG_Load("enigme_loss.png");

    position[1].x = 200;
    position[1].y = 150;
    position[2].x = 300;
    position[2].y = 150;
    position[0].x = 435;
    position[0].y = 150;
    position[3].x = 500;
    position[3].y = 150;
    position[4].x = 250;
    position[4].y = 350;
    position[5].x = 500;
    position[5].y = 350;
    position[6].x = 250;
    position[6].y = 225;
    position[7].x = 500;
    position[7].y = 225;
    cont.x = 450;
    cont.y = 380;


    for (i = 0; i < 4; i++)
    {
        bouton[i].x = position[4 + i].x - 75;
        bouton[i].y = position[4 + i].y;
    }
    pos.x = 0;
    pos.y = 0;
SDL_BlitSurface(background, NULL, screen, &pos);
    for (i = 0; i < 4; i++)
        SDL_BlitSurface(bout[0], NULL, screen, &bouton[i]);
    SDL_BlitSurface(texte[1], NULL, screen, &position[1]);
    SDL_BlitSurface(texte[2], NULL, screen, &position[2]);
    SDL_BlitSurface(texte[0], NULL, screen, &position[0]);
    SDL_BlitSurface(texte[3], NULL, screen, &position[3]);
    SDL_BlitSurface(texte[affich[0]], NULL, screen, &position[4]);
    SDL_BlitSurface(texte[affich[1]], NULL, screen, &position[5]);
    SDL_BlitSurface(texte[affich[2]], NULL, screen, &position[6]);
    SDL_BlitSurface(texte[affich[3]], NULL, screen, &position[7]);
    SDL_Flip(screen);
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_MOUSEMOTION:
            if (event.motion.x >= bouton[0].x && event.motion.x <= (bouton[0].x + 273) && event.motion.y >= bouton[0].y && event.motion.y <= bouton[0].y + 138)
            {
                SDL_BlitSurface(bout[1], NULL, screen, &bouton[0]);
                SDL_BlitSurface(bout[0], NULL, screen, &bouton[1]);
                SDL_BlitSurface(bout[0], NULL, screen, &bouton[2]);
                SDL_BlitSurface(bout[0], NULL, screen, &bouton[3]);
                SDL_BlitSurface(texte[affich[0]], NULL, screen, &position[4]);
                SDL_BlitSurface(texte[affich[1]], NULL, screen, &position[5]);
                SDL_BlitSurface(texte[affich[2]], NULL, screen, &position[6]);
                SDL_BlitSurface(texte[affich[3]], NULL, screen, &position[7]);
                SDL_Flip(screen);
            }
            else if (event.motion.x >= bouton[1].x && event.motion.x <= (bouton[1].x + 273) && event.motion.y >= bouton[1].y && event.motion.y <= bouton[1].y + 138)
            {
                SDL_BlitSurface(bout[0], NULL, screen, &bouton[0]);
                SDL_BlitSurface(bout[1], NULL, screen, &bouton[1]);
                SDL_BlitSurface(bout[0], NULL, screen, &bouton[2]);
                SDL_BlitSurface(bout[0], NULL, screen, &bouton[3]);
                SDL_BlitSurface(texte[affich[0]], NULL, screen, &position[4]);
                SDL_BlitSurface(texte[affich[1]], NULL, screen, &position[5]);
                SDL_BlitSurface(texte[affich[2]], NULL, screen, &position[6]);
                SDL_BlitSurface(texte[affich[3]], NULL, screen, &position[7]);
                SDL_Flip(screen);
            }
            else if (event.motion.x >= bouton[2].x && event.motion.x <= (bouton[2].x + 273) && event.motion.y >= bouton[2].y && event.motion.y <= bouton[2].y + 138)
            {
                SDL_BlitSurface(bout[0], NULL, screen, &bouton[0]);
                SDL_BlitSurface(bout[0], NULL, screen, &bouton[1]);
                SDL_BlitSurface(bout[1], NULL, screen, &bouton[2]);
                SDL_BlitSurface(bout[0], NULL, screen, &bouton[3]);
                SDL_BlitSurface(texte[affich[0]], NULL, screen, &position[4]);
                SDL_BlitSurface(texte[affich[1]], NULL, screen, &position[5]);
                SDL_BlitSurface(texte[affich[2]], NULL, screen, &position[6]);
                SDL_BlitSurface(texte[affich[3]], NULL, screen, &position[7]);
                SDL_Flip(screen);
            }
            else if (event.motion.x >= bouton[3].x && event.motion.x <= (bouton[3].x + 273) && event.motion.y >= bouton[3].y && event.motion.y <= bouton[3].y + 138)
            {
                SDL_BlitSurface(bout[0], NULL, screen, &bouton[0]);
                SDL_BlitSurface(bout[0], NULL, screen, &bouton[1]);
                SDL_BlitSurface(bout[0], NULL, screen, &bouton[2]);
                SDL_BlitSurface(bout[1], NULL, screen, &bouton[3]);
                SDL_BlitSurface(texte[affich[0]], NULL, screen, &position[4]);
                SDL_BlitSurface(texte[affich[1]], NULL, screen, &position[5]);
                SDL_BlitSurface(texte[affich[2]], NULL, screen, &position[6]);
                SDL_BlitSurface(texte[affich[3]], NULL, screen, &position[7]);
                SDL_Flip(screen);
            }
            else
            {
                SDL_BlitSurface(bout[0], NULL, screen, &bouton[0]);
                SDL_BlitSurface(bout[0], NULL, screen, &bouton[1]);
                SDL_BlitSurface(bout[0], NULL, screen, &bouton[2]);
                SDL_BlitSurface(bout[0], NULL, screen, &bouton[3]);
                SDL_BlitSurface(texte[affich[0]], NULL, screen, &position[4]);
                SDL_BlitSurface(texte[affich[1]], NULL, screen, &position[5]);
                SDL_BlitSurface(texte[affich[2]], NULL, screen, &position[6]);
                SDL_BlitSurface(texte[affich[3]], NULL, screen, &position[7]);
                SDL_Flip(screen);
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
            if (event.motion.x >= bouton[0].x && event.motion.x <= (bouton[0].x + 273) && event.motion.y >= bouton[0].y && event.motion.y <= bouton[0].y + 138)
            {
                c = 0;
                if (affich[c] == 4)
                {
                    SDL_BlitSurface(finish[0], NULL, screen, &pos);
                    SDL_BlitSurface(bout[2], NULL, screen, &cont);
                    SDL_Flip(screen);
                    lvl = 1;
                    f = 1;
                    while (f == 1)
                    {
                        SDL_WaitEvent(&event2);
                        switch (event2.type)
                        {
                        case SDL_MOUSEMOTION:
                            if (event2.motion.x >= cont.x && event2.motion.x <= (cont.x + 273) && event2.motion.y >= cont.y && event2.motion.y <= cont.y + 138)
                            {
                                SDL_BlitSurface(bout[3], NULL, screen, &cont);
                                SDL_Flip(screen);
                            }
                            else
                            {
                                SDL_BlitSurface(bout[2], NULL, screen, &cont);
                                SDL_Flip(screen);
                            }
                            break;
                        case SDL_MOUSEBUTTONDOWN:
                            if (event2.motion.x >= cont.x && event2.motion.x <= (cont.x + 273) && event2.motion.y >= cont.y && event2.motion.y <= cont.y + 138)
                            {
                                f = 0;
                                continuer = 0;
                            }
                        }
                    }
                }
                else
                {
                    lvl = 2;
                    SDL_BlitSurface(finish[1], NULL, screen, &pos);
                    SDL_BlitSurface(bout[2], NULL, screen, &cont);
                    SDL_Flip(screen);
                    f = 1;
                    while (f == 1)
                    {
                        SDL_WaitEvent(&event2);
                        switch (event2.type)
                        {
                        case SDL_MOUSEMOTION:
                            if (event2.motion.x >= cont.x && event2.motion.x <= (cont.x + 273) && event2.motion.y >= cont.y && event2.motion.y <= cont.y + 138)
                            {
                                SDL_BlitSurface(bout[3], NULL, screen, &cont);
                                SDL_Flip(screen);
                            }
                            else
                            {
                                SDL_BlitSurface(bout[2], NULL, screen, &cont);
                                SDL_Flip(screen);
                            }
                            break;
                        case SDL_MOUSEBUTTONDOWN:
                            if (event2.motion.x >= cont.x && event2.motion.x <= (cont.x + 273) && event2.motion.y >= cont.y && event2.motion.y <= cont.y + 138)
                            {
                                f = 0;
                                continuer = 0;
                            }
                        }
                    }
                }
            }
            else if (event.motion.x >= bouton[1].x && event.motion.x <= (bouton[1].x + 273) && event.motion.y >= bouton[1].y && event.motion.y <= bouton[1].y + 138)
            {
                c = 1;
                if (affich[c] == 4)
                {
                    SDL_BlitSurface(finish[0], NULL, screen, &pos);
                    SDL_BlitSurface(bout[2], NULL, screen, &cont);
                    SDL_Flip(screen);
                    lvl = 1;
                    f = 1;
                    while (f == 1)
                    {
                        SDL_WaitEvent(&event2);
                        switch (event2.type)
                        {
                        case SDL_MOUSEMOTION:
                            if (event2.motion.x >= cont.x && event2.motion.x <= (cont.x + 273) && event2.motion.y >= cont.y && event2.motion.y <= cont.y + 138)
                            {
                                SDL_BlitSurface(bout[3], NULL, screen, &cont);
                                SDL_Flip(screen);
                            }
                            else
                            {
                                SDL_BlitSurface(bout[2], NULL, screen, &cont);
                                SDL_Flip(screen);
                            }
                            break;
                        case SDL_MOUSEBUTTONDOWN:
                            if (event2.motion.x >= cont.x && event2.motion.x <= (cont.x + 273) && event2.motion.y >= cont.y && event2.motion.y <= cont.y + 138)
                            {
                                f = 0;
                                continuer = 0;
                            }
                        }
                    }
                }
                else
                {
                    lvl = 2;
                    SDL_BlitSurface(finish[1], NULL, screen, &pos);
                    SDL_BlitSurface(bout[2], NULL, screen, &cont);
                    SDL_Flip(screen);
                    f = 1;
                    while (f == 1)
                    {
                        SDL_WaitEvent(&event2);
                        switch (event2.type)
                        {
                        case SDL_MOUSEMOTION:
                            if (event2.motion.x >= cont.x && event2.motion.x <= (cont.x + 273) && event2.motion.y >= cont.y && event2.motion.y <= cont.y + 138)
                            {
                                SDL_BlitSurface(bout[3], NULL, screen, &cont);
                                SDL_Flip(screen);
                            }
                            else
                            {
                                SDL_BlitSurface(bout[2], NULL, screen, &cont);
                                SDL_Flip(screen);
                            }
                            break;
                        case SDL_MOUSEBUTTONDOWN:
                            if (event2.motion.x >= cont.x && event2.motion.x <= (cont.x + 273) && event2.motion.y >= cont.y && event2.motion.y <= cont.y + 138)
                            {
                                f = 0;
                                continuer = 0;
                            }
                        }
                    }
                }
            }
            else if (event.motion.x >= bouton[2].x && event.motion.x <= (bouton[2].x + 273) && event.motion.y >= bouton[2].y && event.motion.y <= bouton[2].y + 138)
            {
                c = 2;
                if (affich[c] == 4)
                {
                    SDL_BlitSurface(finish[0], NULL, screen, &pos);
                    SDL_BlitSurface(bout[2], NULL, screen, &cont);
                    SDL_Flip(screen);
                    lvl = 1;
                    f = 1;
                    while (f == 1)
                    {
                        SDL_WaitEvent(&event2);
                        switch (event2.type)
                        {
                        case SDL_MOUSEMOTION:
                            if (event2.motion.x >= cont.x && event2.motion.x <= (cont.x + 273) && event2.motion.y >= cont.y && event2.motion.y <= cont.y + 138)
                            {
                                SDL_BlitSurface(bout[3], NULL, screen, &cont);
                                SDL_Flip(screen);
                            }
                            else
                            {
                                SDL_BlitSurface(bout[2], NULL, screen, &cont);
                                SDL_Flip(screen);
                            }
                            break;
                        case SDL_MOUSEBUTTONDOWN:
                            if (event2.motion.x >= cont.x && event2.motion.x <= (cont.x + 273) && event2.motion.y >= cont.y && event2.motion.y <= cont.y + 138)
                            {
                                f = 0;
                                continuer = 0;
                            }
                        }
                    }
                }
                else
                {
                    lvl = 2;
                    SDL_BlitSurface(finish[1], NULL, screen, &pos);
                    SDL_BlitSurface(bout[2], NULL, screen, &cont);
                    SDL_Flip(screen);
                    f = 1;
                    while (f == 1)
                    {
                        SDL_WaitEvent(&event2);
                        switch (event2.type)
                        {
                        case SDL_MOUSEMOTION:
                            if (event2.motion.x >= cont.x && event2.motion.x <= (cont.x + 273) && event2.motion.y >= cont.y && event2.motion.y <= cont.y + 138)
                            {
                                SDL_BlitSurface(bout[3], NULL, screen, &cont);
                                SDL_Flip(screen);
                            }
                            else
                            {
                                SDL_BlitSurface(bout[2], NULL, screen, &cont);
                                SDL_Flip(screen);
                            }
                            break;
                        case SDL_MOUSEBUTTONDOWN:
                            if (event2.motion.x >= cont.x && event2.motion.x <= (cont.x + 273) && event2.motion.y >= cont.y && event2.motion.y <= cont.y + 138)
                            {
                                f = 0;
                                continuer = 0;
                            }
                        }
                    }
                }
            }
            else if (event.motion.x >= bouton[3].x && event.motion.x <= (bouton[3].x + 273) && event.motion.y >= bouton[3].y && event.motion.y <= bouton[3].y + 138)
            {
                c = 3;
                if (affich[c] == 4)
                {
                    SDL_BlitSurface(finish[0], NULL, screen, &pos);
                    SDL_BlitSurface(bout[2], NULL, screen, &cont);
                    SDL_Flip(screen);
                    lvl = 1;
                    f = 1;
                    while (f == 1)
                    {
                        SDL_WaitEvent(&event2);
                        switch (event2.type)
                        {
                        case SDL_MOUSEMOTION:
                            if (event2.motion.x >= cont.x && event2.motion.x <= (cont.x + 273) && event2.motion.y >= cont.y && event2.motion.y <= cont.y + 138)
                            {
                                SDL_BlitSurface(bout[3], NULL, screen, &cont);
                                SDL_Flip(screen);
                            }
                            else
                            {
                                SDL_BlitSurface(bout[2], NULL, screen, &cont);
                                SDL_Flip(screen);
                            }
                            break;
                        case SDL_MOUSEBUTTONDOWN:
                            if (event2.motion.x >= cont.x && event2.motion.x <= (cont.x + 273) && event2.motion.y >= cont.y && event2.motion.y <= cont.y + 138)
                            {
                                f = 0;
                                continuer = 0;
                            }
                        }
                    }
                }
                else
                {
                    lvl = 2;
                    SDL_BlitSurface(finish[1], NULL, screen, &pos);
                    SDL_BlitSurface(bout[2], NULL, screen, &cont);
                    SDL_Flip(screen);
                    f = 1;
                    while (f == 1)
                    {
                        SDL_WaitEvent(&event2);
                        switch (event2.type)
                        {
                        case SDL_MOUSEMOTION:
                            if (event2.motion.x >= cont.x && event2.motion.x <= (cont.x + 273) && event2.motion.y >= cont.y && event2.motion.y <= cont.y + 138)
                            {
                                SDL_BlitSurface(bout[3], NULL, screen, &cont);
                                SDL_Flip(screen);
                            }
                            else
                            {
                                SDL_BlitSurface(bout[2], NULL, screen, &cont);
                                SDL_Flip(screen);
                            }
                            break;
                        case SDL_MOUSEBUTTONDOWN:
                            if (event2.motion.x >= cont.x && event2.motion.x <= (cont.x + 273) && event2.motion.y >= cont.y && event2.motion.y <= cont.y + 138)
                            {
                                f = 0;
                                continuer = 0;
                            }
                        }
                    }
                }
            }
            break;
        }
    }
    for (i = 0; i < 8; i++)
        SDL_FreeSurface(texte[i]);
    for (i = 0; i < 4; i++)
        SDL_FreeSurface(bout[i]);
    for (i = 0; i < 2; i++)
        SDL_FreeSurface(finish[i]);
    SDL_FreeSurface(background);
    return lvl;
}
int main(int argc, char *argv[])
{
SDL_Init(SDL_INIT_VIDEO);
 TTF_Init();
 TTF_Font *police=NULL;
 SDL_Surface *screen=NULL;
    screen=SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if (!screen)
    {
        printf("unable to set 1920x1080 video: %s\n", SDL_GetError());
        return (-1);
    }
    SDL_WM_SetCaption("TEST ENIGMES", NULL);
SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 255, 135, 40));
 if (enigme(screen,police) == 1)
        {
      printf("you passed\n");
        }
//TTF_CloseFont(police);
TTF_Quit();
SDL_Quit();
return EXIT_SUCCESS;
}
