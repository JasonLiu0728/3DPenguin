/***********************************************************


***********************************************************/

#ifndef __PARTS_H__
#define __PARTS_H__

#include <GL/gl.h>

//------------------- Unit Head Definition ---------------------------

// Draw a unit head, centered at the current location
void drawHead()
{
	glBegin(GL_QUADS);
		// draw front face
		glNormal3f( 0.0,  0.099504,  0.99504); // normalized
		glVertex3f(-1.0, -1.0,  1.0);
		glVertex3f( 1.0, -1.0,  1.0);
		glVertex3f( 0.8,  1.0,  0.8);
		glVertex3f(-0.8,  1.0,  0.8);

		// draw back face
		glNormal3f( 0.0,  0.099504, -0.99504); // normalized
		glVertex3f( 1.0, -1.0, -1.0);
		glVertex3f(-1.0, -1.0, -1.0);
		glVertex3f(-0.8,  1.0, -0.8);
		glVertex3f( 0.8,  1.0, -0.8);

		// draw left face
		glNormal3f(-0.99504,  0.099504,  0.0); // normalized
		glVertex3f(-1.0, -1.0, -1.0);
		glVertex3f(-1.0, -1.0,  1.0);
		glVertex3f(-0.8,  1.0,  0.8);
		glVertex3f(-0.8,  1.0, -0.8);

		// draw right face
		glNormal3f( 0.99504,  0.099504,  0.0); // normalized
		glVertex3f( 1.0, -1.0, -1.0);
		glVertex3f( 1.0, -1.0,  1.0);
		glVertex3f( 0.8,  1.0,  0.8);
		glVertex3f( 0.8,  1.0, -0.8);

		// draw top
		glNormal3f( 0.0,  1.0,  0.0);
		glVertex3f(-0.8,  1.0,  0.8);
		glVertex3f( 0.8,  1.0,  0.8);
		glVertex3f( 0.8,  1.0, -0.8);
		glVertex3f(-0.8,  1.0, -0.8);

		// draw bottom
		glNormal3f( 0.0, -1.0,  0.0);
		glVertex3f(-1.0, -1.0, -1.0);
		glVertex3f( 1.0, -1.0, -1.0);
		glVertex3f( 1.0, -1.0,  1.0);
		glVertex3f(-1.0, -1.0,  1.0);
	glEnd();
}

//------------------- Unit Head Definition ---------------------------

//------------------- Unit Beak Definition ---------------------------

void drawUpperBeak()
{
	glBegin(GL_QUADS);
		// draw front face
		glNormal3f( 0.0,  0.707,  0.707); // normalized
		glVertex3f(-1.0,  0.0,  1.0);
		glVertex3f( 1.0,  0.0,  1.0);
		glVertex3f( 1.0,  1.0,  0.0);
		glVertex3f(-0.8,  1.0,  0.0);

		// draw back face
		glNormal3f( 0.0,  0.707,  -0.707); // normalized
		glVertex3f( 1.0,  0.0, -1.0);
		glVertex3f(-1.0,  0.0, -1.0);
		glVertex3f(-0.8,  1.0,  0.0);
		glVertex3f( 1.0,  1.0,  0.0);

		// draw left face
		glNormal3f(-1.0,  0.0,  0.0);
		glVertex3f(-1.0,  0.0, -1.0);
		glVertex3f(-1.0,  0.0,  1.0);
		glVertex3f(-0.8,  1.0,  0.0);
		glVertex3f(-0.8,  1.0,  0.0);

		// draw right face
		glNormal3f( 1.0,  0.0,  0.0);
		glVertex3f( 1.0,  0.0, -1.0);
		glVertex3f( 1.0,  0.0,  1.0);
		glVertex3f( 1.0,  1.0,  0.0);
		glVertex3f( 1.0,  1.0,  0.0);

		// draw bottom
		glNormal3f( 0.0, -1.0,  0.0);
		glVertex3f(-1.0,  0.0, -1.0);
		glVertex3f( 1.0,  0.0, -1.0);
		glVertex3f( 1.0,  0.0,  1.0);
		glVertex3f(-1.0,  0.0,  1.0);
	glEnd();
}

void drawLowerBeak()
{
	glBegin(GL_QUADS);
		// draw front face
		glNormal3f( 0.0, -0.707,  0.707); // normalized
		glVertex3f( 1.0, -1.0,  0.0);
		glVertex3f(-0.8, -1.0,  0.0);
		glVertex3f(-1.0,  0.0,  1.0);
		glVertex3f( 1.0,  0.0,  1.0);

		// draw back face
		glNormal3f( 0.0, -0.707, -0.707); // normalized
		glVertex3f( 1.0, -1.0,  0.0);
		glVertex3f(-0.8, -1.0,  0.0);
		glVertex3f(-1.0,  0.0, -1.0);
		glVertex3f( 1.0,  0.0, -1.0);

		// draw left face
		glNormal3f(-1.0,  0.0,  0.0);
		glVertex3f(-0.8, -1.0,  0.0);
		glVertex3f(-0.8, -1.0,  0.0);
		glVertex3f(-1.0,  0.0, -1.0);
		glVertex3f(-1.0,  0.0,  1.0);

		// draw right face
		glNormal3f( 1.0,  0.0,  0.0);
		glVertex3f( 1.0, -1.0,  0.0);
		glVertex3f( 1.0, -1.0,  0.0);
		glVertex3f( 1.0,  0.0, -1.0);
		glVertex3f( 1.0,  0.0,  1.0);

		// draw top
		glNormal3f( 0.0, -1.0,  0.0);
		glVertex3f(-0.8,  0.0,  0.8);
		glVertex3f( 0.8,  0.0,  0.8);
		glVertex3f( 0.8,  0.0, -0.8);
		glVertex3f(-0.8,  0.0, -0.8);

	glEnd();
}

//------------------- Unit Beak Definition ---------------------------

//------------------- Unit Body Definition ---------------------------

// Draw a unit body, centered at the current location
void drawBody()
{
	glBegin(GL_QUADS);
		// draw front face
		glNormal3f( 0.0,  0.099504,  0.99504); // normalized
		glVertex3f(-1.0, -1.0,  1.0);
		glVertex3f( 1.0, -1.0,  1.0);
		glVertex3f( 0.7,  1.0,  0.8);
		glVertex3f(-0.7,  1.0,  0.8);

		// draw back face
		glNormal3f( 0.0,  0.099504, -0.99504); // normalized
		glVertex3f( 1.0, -1.0, -1.0);
		glVertex3f(-1.0, -1.0, -1.0);
		glVertex3f(-0.7,  1.0, -0.8);
		glVertex3f( 0.7,  1.0, -0.8);

		// draw left face
		glNormal3f(-0.98894,  0.14834,  0.0); // normalized
		glVertex3f(-1.0, -1.0, -1.0);
		glVertex3f(-1.0, -1.0,  1.0);
		glVertex3f(-0.7,  1.0,  0.8);
		glVertex3f(-0.7,  1.0, -0.8);

		// draw right face
		glNormal3f( 0.98894,  0.14834,  0.0); // normalized
		glVertex3f( 1.0, -1.0, -1.0);
		glVertex3f( 1.0, -1.0,  1.0);
		glVertex3f( 0.7,  1.0,  0.8);
		glVertex3f( 0.7,  1.0, -0.8);

		// draw top
		glNormal3f( 0.0,  1.0,  0.0);
		glVertex3f(-0.7,  1.0,  0.8);
		glVertex3f( 0.7,  1.0,  0.8);
		glVertex3f( 0.7,  1.0, -0.8);
		glVertex3f(-0.7,  1.0, -0.8);

		// draw bottom
		glNormal3f( 0.0, -1.0,  0.0);
		glVertex3f(-1.0, -1.0, -1.0);
		glVertex3f( 1.0, -1.0, -1.0);
		glVertex3f( 1.0, -1.0,  1.0);
		glVertex3f(-1.0, -1.0,  1.0);
	glEnd();
}

//------------------- Unit Body Definition ---------------------------

//------------------- Unit Shoulder Definition ---------------------------

// Draw a unit body, centered at the current location
void drawShoulder()
{
	glBegin(GL_QUADS);
		// draw front face
		glNormal3f( 0.0,  0.0,  1.0);
		glVertex3f(-1.0, -1.0,  1.0);
		glVertex3f( 0.7, -1.0,  1.0);
		glVertex3f( 1.0,  0.8,  1.0);
		glVertex3f(-1.0,  1.0,  1.0);

		// draw back face
		glNormal3f( 0.0,  0.0, -1.0);
		glVertex3f( 0.7, -1.0, -1.0);
		glVertex3f(-1.0, -1.0, -1.0);
		glVertex3f(-1.0,  1.0, -1.0);
		glVertex3f( 1.0,  0.8, -1.0);

		// draw left face
		glNormal3f(-1.0,  0.0,  0.0);
		glVertex3f(-1.0, -1.0, -1.0);
		glVertex3f(-1.0, -1.0,  1.0);
		glVertex3f(-1.0,  1.0,  1.0);
		glVertex3f(-1.0,  1.0, -1.0);

		// draw right face
		glNormal3f( 1.0,  0.0,  0.0);
		glVertex3f( 0.7, -1.0,  1.0);
		glVertex3f( 0.7, -1.0, -1.0);
		glVertex3f( 1.0,  0.8, -1.0);
		glVertex3f( 1.0,  0.8,  1.0);

		// draw top
		glNormal3f( 0.0,  1.0,  0.0);
		glVertex3f(-1.0,  1.0,  1.0);
		glVertex3f( 1.0,  0.8,  1.0);
		glVertex3f( 1.0,  0.8, -1.0);
		glVertex3f(-1.0,  1.0, -1.0);

		// draw bottom
		glNormal3f( 0.0, -1.0,  0.0);
		glVertex3f(-1.0, -1.0, -1.0);
		glVertex3f( 0.7, -1.0, -1.0);
		glVertex3f( 0.7, -1.0,  1.0);
		glVertex3f(-1.0, -1.0,  1.0);
	glEnd();
}

//------------------- Unit Shoulder Definition ---------------------------

//------------------- Unit Elbow Definition ---------------------------
// Draw a unit elbow, centered at the current location
void drawElbow()
{
	glBegin(GL_QUADS);
		// draw front face
		glNormal3f( 0.0,  0.0,  1.0);
		glVertex3f(-1.0, -1.0,  1.0);
		glVertex3f( 1.0, -0.7,  1.0);
		glVertex3f( 1.0,  1.0,  1.0);
		glVertex3f(-1.0,  1.0,  1.0);

		// draw back face
		glNormal3f( 0.0,  0.0, -1.0);
		glVertex3f( 1.0, -0.7, -1.0);
		glVertex3f(-1.0, -1.0, -1.0);
		glVertex3f(-1.0,  1.0, -1.0);
		glVertex3f( 1.0,  1.0, -1.0);

		// draw left face
		glNormal3f(-1.0,  0.0,  0.0);
		glVertex3f(-1.0, -1.0, -1.0);
		glVertex3f(-1.0, -1.0,  1.0);
		glVertex3f(-1.0,  1.0,  1.0);
		glVertex3f(-1.0,  1.0, -1.0);

		// draw right face
		glNormal3f( 1.0,  0.0,  0.0);
		glVertex3f( 1.0, -0.7,  1.0);
		glVertex3f( 1.0, -0.7, -1.0);
		glVertex3f( 1.0,  1.0, -1.0);
		glVertex3f( 1.0,  1.0,  1.0);

		// draw top
		glNormal3f( 0.0,  1.0,  0.0);
		glVertex3f(-1.0,  1.0,  1.0);
		glVertex3f( 1.0,  1.0,  1.0);
		glVertex3f( 1.0,  1.0, -1.0);
		glVertex3f(-1.0,  1.0, -1.0);

		// draw bottom
		glNormal3f( 0.0, -1.0,  0.0);
		glVertex3f(-1.0, -1.0, -1.0);
		glVertex3f( 1.0, -0.7, -1.0);
		glVertex3f( 1.0, -0.7,  1.0);
		glVertex3f(-1.0, -1.0,  1.0);
	glEnd();
}
//------------------- Unit Elbow Definition ---------------------------

//------------------- Unit Hip Definition ---------------------------

// Draw a unit body, centered at the current location
void drawHip()
{
	glBegin(GL_QUADS);
		// draw front face
		glNormal3f( 0.0,  0.0,  1.0);
		glVertex3f(-1.0, -1.0,  1.0);
		glVertex3f( 1.0, -1.0,  1.0);
		glVertex3f( 1.0,  1.0,  1.0);
		glVertex3f(-1.0,  1.0,  1.0);

		// draw back face
		glNormal3f( 0.0,  0.0, -1.0);
		glVertex3f( 1.0, -1.0, -1.0);
		glVertex3f(-1.0, -1.0, -1.0);
		glVertex3f(-1.0,  1.0, -1.0);
		glVertex3f( 1.0,  1.0, -1.0);

		// draw left face
		glNormal3f(-1.0,  0.0,  0.0);
		glVertex3f(-1.0, -1.0, -1.0);
		glVertex3f(-1.0, -1.0,  1.0);
		glVertex3f(-1.0,  1.0,  1.0);
		glVertex3f(-1.0,  1.0, -1.0);

		// draw right face
		glNormal3f( 1.0,  0.0,  0.0);
		glVertex3f( 1.0, -1.0,  1.0);
		glVertex3f( 1.0, -1.0, -1.0);
		glVertex3f( 1.0,  1.0, -1.0);
		glVertex3f( 1.0,  1.0,  1.0);

		// draw top
		glNormal3f( 0.0,  1.0,  0.0);
		glVertex3f(-1.0,  1.0,  1.0);
		glVertex3f( 1.0,  1.0,  1.0);
		glVertex3f( 1.0,  1.0, -1.0);
		glVertex3f(-1.0,  1.0, -1.0);

		// draw bottom
		glNormal3f( 0.0, -1.0,  0.0);
		glVertex3f(-1.0, -1.0, -1.0);
		glVertex3f( 1.0, -1.0, -1.0);
		glVertex3f( 1.0, -1.0,  1.0);
		glVertex3f(-1.0, -1.0,  1.0);
	glEnd();
}

//------------------- Unit Hip Definition ---------------------------

//------------------- Unit Knee Definition ---------------------------

// Draw a unit body, centered at the current location
void drawKnee()
{
	glBegin(GL_QUADS);
		// draw front face
		glNormal3f( 0.44721,  0.0,  0.89443); // normalized
		glVertex3f(-1.0, -1.0,  1.0);
		glVertex3f( 1.0, -1.0,  0.0);
		glVertex3f( 1.0,  1.0,  0.0);
		glVertex3f(-1.0,  1.0,  1.0);

		// draw back face
		glNormal3f( 0.44721,  0.0, -0.89443); // normalized
		glVertex3f( 1.0, -1.0,  0.0);
		glVertex3f(-1.0, -1.0, -1.0);
		glVertex3f(-1.0,  1.0, -1.0);
		glVertex3f( 1.0,  1.0,  0.0);

		// draw left face
		glNormal3f(-1.0,  0.0,  0.0);
		glVertex3f(-1.0, -1.0, -1.0);
		glVertex3f(-1.0, -1.0,  1.0);
		glVertex3f(-1.0,  1.0,  1.0);
		glVertex3f(-1.0,  1.0, -1.0);

		// draw right face
		glNormal3f( 1.0,  0.0,  0.0);
		glVertex3f( 1.0, -1.0,  0.0);
		glVertex3f( 1.0, -1.0,  0.0);
		glVertex3f( 1.0,  1.0,  0.0);
		glVertex3f( 1.0,  1.0,  0.0);

		// draw top
		glNormal3f( 0.0,  1.0,  0.0);
		glVertex3f(-1.0,  1.0,  1.0);
		glVertex3f( 1.0,  1.0,  0.0);
		glVertex3f( 1.0,  1.0,  0.0);
		glVertex3f(-1.0,  1.0, -1.0);

		// draw bottom
		glNormal3f( 0.0, -1.0,  0.0);
		glVertex3f(-1.0, -1.0, -1.0);
		glVertex3f( 1.0, -1.0,  0.0);
		glVertex3f( 1.0, -1.0,  0.0);
		glVertex3f(-1.0, -1.0,  1.0);
	glEnd();
}

//------------------- Unit Knee Definition ---------------------------

//------------------- Unit Cube Definition ---------------------------

// Draw a unit cube, centered at the current location
// README: Helper code for drawing a cube
void drawCube()
{
	glBegin(GL_QUADS);
		// draw front face
		glVertex3f(-1.0, -1.0, 1.0);
		glVertex3f( 1.0, -1.0, 1.0);
		glVertex3f( 1.0,  1.0, 1.0);
		glVertex3f(-1.0,  1.0, 1.0);

		// draw back face
		glVertex3f( 1.0, -1.0, -1.0);
		glVertex3f(-1.0, -1.0, -1.0);
		glVertex3f(-1.0,  1.0, -1.0);
		glVertex3f( 1.0,  1.0, -1.0);

		// draw left face
		glVertex3f(-1.0, -1.0, -1.0);
		glVertex3f(-1.0, -1.0,  1.0);
		glVertex3f(-1.0,  1.0,  1.0);
		glVertex3f(-1.0,  1.0, -1.0);

		// draw right face
		glVertex3f( 1.0, -1.0,  1.0);
		glVertex3f( 1.0, -1.0, -1.0);
		glVertex3f( 1.0,  1.0, -1.0);
		glVertex3f( 1.0,  1.0,  1.0);

		// draw top
		glVertex3f(-1.0,  1.0,  1.0);
		glVertex3f( 1.0,  1.0,  1.0);
		glVertex3f( 1.0,  1.0, -1.0);
		glVertex3f(-1.0,  1.0, -1.0);

		// draw bottom
		glVertex3f(-1.0, -1.0, -1.0);
		glVertex3f( 1.0, -1.0, -1.0);
		glVertex3f( 1.0, -1.0,  1.0);
		glVertex3f(-1.0, -1.0,  1.0);
	glEnd();
}

//------------------- Unit Cube Definition ---------------------------

#endif // __PARTS_H__
