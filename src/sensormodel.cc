
#include <stdlib.h>
#include <stdio.h>

#include "../inc/map.h"
#include "../inc/sensormodel.h"


/* 
   Mapstruct is defined in map.h 

   res is the width and height of each cell of the map in mm

   theta is in degrees

   dx and dy are in mm

   a is in degrees

   r is in mm
*/
   


float sensormodel(MapStruct *map,
		  int res,
		  int row,int col,
		  int theta,
		  int dx, int dy,
		  int a,int r)
{
  // this is here just to give it something to do.  
  return (row*col)/(float)(map->width*map->height);
}



