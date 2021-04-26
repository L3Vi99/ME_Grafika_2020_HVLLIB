#include "draw.h"
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

GLuint displayList1;
GLuint displayList2;
double rotateAngle = 0;

void draw_model(const struct Model* model)
{
	draw_triangles(model);
	draw_quads(model);
}

void draw_triangles(const struct Model* model)
{
	int i, k;
	int vertex_index, texture_index, normal_index;
	double x, y, z, normal_x, normal_y, normal_z, u, v;

	glBegin(GL_TRIANGLES);

	for (i = 0; i < model->n_triangles; ++i) {
		for (k = 0; k < 3; ++k) {
			normal_index = model->triangles[i].points[k].normal_index;
			normal_x = model->normals[normal_index].x;
			normal_y = model->normals[normal_index].y;
			normal_z = model->normals[normal_index].z;
			glNormal3d(normal_x, normal_y, normal_z);

			vertex_index = model->triangles[i].points[k].vertex_index;
			x = model->vertices[vertex_index].x;
			y = model->vertices[vertex_index].y;
			z = model->vertices[vertex_index].z;
            switch(k){
            case 0:
                glTexCoord2f(0, 0);
                break;
            case 1:
                glTexCoord2f(0.1*z, 0);
                break;
            case 2:
                glTexCoord2f(0, 0.01);
                break;
            }
			glVertex3d(x, y, z);

		}
	}

	glEnd();
}


void draw_quads(const struct Model* model)
{
    int i, k;
    int vertex_index, texture_index, normal_index;
    double x, y, z, u, v;

	glBegin(GL_QUADS);

    for (i = 0; i < model->n_quads; ++i) {
        for (k = 0; k < 4; ++k) {

            texture_index = model->quads[i].points[k].texture_index;
            u = model->texture_vertices[texture_index].u;
            v = model->texture_vertices[texture_index].v;
            // NOTE: The 1-v is model file specific!
            glTexCoord2f(u, 1-v);

            vertex_index = model->quads[i].points[k].vertex_index;
            x = model->vertices[vertex_index].x;
            y = model->vertices[vertex_index].y;
            z = model->vertices[vertex_index].z;
            glVertex3d(x, y, z);
        }
    }    

    glEnd();
}



void draw_grandfatherclock(World world) 
{

			glPushMatrix();
				glTranslatef(0, 0, -150);

				glCallList(displayList1);
				glPushMatrix();
					
					glCallList(displayList2);
				glPopMatrix();
			glPopMatrix();
}






