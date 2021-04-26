#ifndef DRAW_H
#define DRAW_H

#include "model.h"

#ifndef GL_EXT_texture_edge_clamp
#define GL_EXT_CLAMP_TO_EDGE                 0x812F
#endif



/**
* Draw the model.
*/
void draw_model(const struct Model* model);

/**
* Draw the triangles of the model.
*/
void draw_triangles(const struct Model* model);

/**
* Draws the ground
*/
void draw_ground(int ground);



/**
* Calls draw_windmills and draw_teapot_for_light
*/
void draw_entities(World world);
#endif // DRAW_H

