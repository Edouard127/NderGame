#ifndef _SURFACE_H
#define _SURFACE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


// This function load a image file to a surface
// Set bCKey with colorkey (R,G,B) to clear a color on the image
// Set alpha value for transparency 0(No transparent) ~ 255(Ivisible)
inline SDL_Surface *ImgLoader(char *file,bool bCKey, int r , int g , int b , int alpha)
{
    SDL_Surface *pic;
    pic = IMG_Load(file); // From SDL_image.h , load the image to pic
    // Log error message into stderr.txt if happened
    if(pic==NULL) fprintf(stderr,"Missing image %s : %s\n",file,IMG_GetError());
    if( bCKey ) {
        // Sets the color key (transparent pixel) in a blittable surface and RLE acceleration.
        SDL_SetColorKey(pic,SDL_SRCCOLORKEY|SDL_RLEACCEL,SDL_MapRGB(pic->format,r,g,b));
         }
    if(alpha) SDL_SetAlpha(pic, SDL_SRCALPHA|SDL_RLEACCEL , 255 - alpha);
    // This function takes a surface and copies it to a new surface of the
    // pixel format and colors of the video framebuffer, suitable for fast
    // blitting onto the display surface.
    pic = SDL_DisplayFormat(pic);
    return (pic);
}

#endif // SURFACE_H
