#ifndef MAP_H
#define MAP_H

#include <png.h>

/* A simple structure for accessing a PNG image */
typedef struct{
  int width,height;
  unsigned char **rows;
  png_structp png_ptr;
  png_infop info_ptr;
}MapStruct;


/* readmap will read a PNG file (used as a map) using argv[arg] as
   file name.  It does a lot of error checking and will exit if there
   are problems. */
MapStruct* readmap(char **argv,int arg);

/* These functions allocate and free a 2D array of floats */
float** allocate_float_map(int width, int height);
void free_float_map(float** mapdata,int height);

/* write_float_map scales the values in a float map to between 0 and
   255, then writes the data as a Portable Gray Map pgm file.
   Filename should end in ".pgm" when this function is called. */
void write_float_map(char *filename,float **data,int width,int height,int autoscale);

#endif

