//Semestre 2017 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************			Arreola Camacho Marcela			******//
//*************		   Burgos Villa Luis Fernando		******//
//*************		  Morales Anaya Norman Rodrigo		******//
//*************		Reséndiz Rodríguez Juan Bernardo	******//	
//************************************************************//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"

CFiguras fig;

float anglevar = 0.0;
int w = 500, h = 500;
int frame=0,time,timebase=0;
int deltaTime = 0;


CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 


//GLfloat Diffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

CTexture text1;
CTexture text2;
CTexture text3;	//Flecha

CTexture tree;
CTexture pisoGarage;
CFiguras sky;

/*void arbol()
{
	glPushMatrix();
					glDisable(GL_LIGHTING);
					glEnable( GL_ALPHA_TEST );
					//glDisable(GL_DEPTH_TEST);   // Turn Depth Testing Off
					glAlphaFunc( GL_GREATER, 0.1 );
					//glEnable(GL_BLEND);     // Turn Blending On
					//glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
					glBindTexture(GL_TEXTURE_2D, tree.GLindex);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(45, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(-45, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(90, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
					glDisable( GL_ALPHA_TEST );
					//glDisable(GL_BLEND);        // Turn Blending Off
					//glEnable(GL_DEPTH_TEST);    // Turn Depth Testing On
					glEnable(GL_LIGHTING);
				
			glPopMatrix();
}*/

//Funciones para Estructuras de Casa
void murover(float largo, GLuint textizqmur, GLuint textdermur, GLuint textsupmur, GLuint textinfmur) {

	GLfloat vertice[8][3] = {
		{ 0.5*largo ,-1.3, 0.04},    //Coordenadas Vértice 0 V0
		{ -0.5*largo ,-1.3 , 0.04 },    //Coordenadas Vértice 1 V1
		{ -0.5*largo ,-1.3 , -0.04 },    //Coordenadas Vértice 2 V2
		{ 0.5*largo ,-1.3 , -0.04 },    //Coordenadas Vértice 3 V3
		{ 0.5*largo ,1.3 , 0.04 },    //Coordenadas Vértice 4 V4
		{ 0.5*largo ,1.3 , -0.04 },    //Coordenadas Vértice 5 V5
		{ -0.5*largo ,1.3 , -0.04 },    //Coordenadas Vértice 6 V6
		{ -0.5*largo ,1.3 , 0.04 },    //Coordenadas Vértice 7 V7
	};

	glBegin(GL_POLYGON);  //Bottom
		glNormal3f(0.0f, -1.0f, 0.0f);
		glVertex3fv(vertice[0]);
		glVertex3fv(vertice[1]);
		glVertex3fv(vertice[2]);
		glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
		glNormal3f(0.0f, 1.0f, 0.0f);
		glVertex3fv(vertice[4]);
		glVertex3fv(vertice[5]);
		glVertex3fv(vertice[6]);
		glVertex3fv(vertice[7]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textizqmur);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
		glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
		glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
		glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textinfmur);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
		glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
		glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
		glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textdermur);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
		glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
		glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textsupmur);   // choose the texture to use.
	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
		glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
		glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glEnd();
}

void placaver(float largo, GLuint textizqmur, GLuint textdermur, GLuint textsupmur, GLuint textinfmur) {

	GLfloat vertice[8][3] = {
		{ 0.5*largo ,-0.25, 0.04 },    //Coordenadas Vértice 0 V0
		{ -0.5*largo ,-0.25 , 0.04 },    //Coordenadas Vértice 1 V1
		{ -0.5*largo ,-0.25 , -0.04 },    //Coordenadas Vértice 2 V2
		{ 0.5*largo ,-0.25 , -0.04 },    //Coordenadas Vértice 3 V3
		{ 0.5*largo ,0.25 , 0.04 },    //Coordenadas Vértice 4 V4
		{ 0.5*largo ,0.25 , -0.04 },    //Coordenadas Vértice 5 V5
		{ -0.5*largo ,0.25 , -0.04 },    //Coordenadas Vértice 6 V6
		{ -0.5*largo ,0.25 , 0.04 },    //Coordenadas Vértice 7 V7
	};

	glBegin(GL_POLYGON);  //Bottom
		glNormal3f(0.0f, -1.0f, 0.0f);
		glVertex3fv(vertice[0]);
		glVertex3fv(vertice[1]);
		glVertex3fv(vertice[2]);
		glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
		glNormal3f(0.0f, 1.0f, 0.0f);
		glVertex3fv(vertice[4]);
		glVertex3fv(vertice[5]);
		glVertex3fv(vertice[6]);
		glVertex3fv(vertice[7]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textizqmur);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
		glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
		glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
		glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textinfmur);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Right
		glNormal3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
		glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
		glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
		glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textdermur);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Back
		glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
		glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
		glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textsupmur);   // choose the texture to use.
	glBegin(GL_POLYGON);  //Left
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
		glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
		glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glEnd();
}

void murohor(float largo, GLuint textizqmur, GLuint textdermur, GLuint textsupmur, GLuint textinfmur) {

	GLfloat vertice[8][3] = {
		{ 0.04 ,-1.3, 0.5*largo },    //Coordenadas Vértice 0 V0
		{ -0.04 ,-1.3 , 0.5*largo },    //Coordenadas Vértice 1 V1
		{ -0.04 ,-1.3 , -0.5*largo },    //Coordenadas Vértice 2 V2
		{ 0.04 ,-1.3 , -0.5*largo },    //Coordenadas Vértice 3 V3
		{ 0.04 ,1.3 , 0.5*largo },    //Coordenadas Vértice 4 V4
		{ 0.04 ,1.3 , -0.5*largo },    //Coordenadas Vértice 5 V5
		{ -0.04 ,1.3 , -0.5*largo },    //Coordenadas Vértice 6 V6
		{ -0.04 ,1.3 , 0.5*largo },    //Coordenadas Vértice 7 V7
	};

	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
		glVertex3fv(vertice[0]);
		glVertex3fv(vertice[1]);
		glVertex3fv(vertice[2]);
		glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
		glVertex3fv(vertice[4]);
		glVertex3fv(vertice[5]);
		glVertex3fv(vertice[6]);
		glVertex3fv(vertice[7]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textizqmur);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
		glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
		glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
		glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textinfmur);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
		glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
		glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
		glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textdermur);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
		glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
		glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textsupmur);   // choose the texture to use.
	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
		glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
		glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glEnd();
}

void placahor(float largo, GLuint textizqmur, GLuint textdermur, GLuint textsupmur, GLuint textinfmur) {

	GLfloat vertice[8][3] = {
		{ 0.04 ,-0.25, 0.5*largo },    //Coordenadas Vértice 0 V0
		{ -0.04 ,-0.25 , 0.5*largo },    //Coordenadas Vértice 1 V1
		{ -0.04 ,-0.25 , -0.5*largo },    //Coordenadas Vértice 2 V2
		{ 0.04 ,-0.25 , -0.5*largo },    //Coordenadas Vértice 3 V3
		{ 0.04 ,0.25 , 0.5*largo },    //Coordenadas Vértice 4 V4
		{ 0.04 ,0.25 , -0.5*largo },    //Coordenadas Vértice 5 V5
		{ -0.04 ,0.25 , -0.5*largo },    //Coordenadas Vértice 6 V6
		{ -0.04 ,0.25 , 0.5*largo },    //Coordenadas Vértice 7 V7
	};

	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
		glVertex3fv(vertice[0]);
		glVertex3fv(vertice[1]);
		glVertex3fv(vertice[2]);
		glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
		glVertex3fv(vertice[4]);
		glVertex3fv(vertice[5]);
		glVertex3fv(vertice[6]);
		glVertex3fv(vertice[7]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textizqmur);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
		glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
		glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
		glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textinfmur);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Right
		glNormal3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
		glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
		glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
		glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textdermur);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Back
		glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
		glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
		glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textsupmur);   // choose the texture to use.
	glBegin(GL_POLYGON);  //Left
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
		glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
		glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glEnd();
}

void pisocuadrado(float largo, float ancho, GLuint textpiso) {

	GLfloat vertice[4][3] = {
		{ 0.5*largo ,-1.3, 0.5*ancho},    //Coordenadas Vértice 0 V0
		{ -0.5*largo,-1.3, 0.5*ancho },    //Coordenadas Vértice 1 V1
		{ -0.5*largo ,-1.3, -0.5*ancho },    //Coordenadas Vértice 2 V2
		{ 0.5*largo ,-1.3, -0.5*ancho },    //Coordenadas Vértice 3 V3
	};

	glBindTexture(GL_TEXTURE_2D, textpiso);   // choose the texture to use.
	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
		glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
		glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
		glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

}

void pisoenl() {

}
void garage(GLvoid) {
	glPushMatrix(); //Garage
		pisocuadrado(6.0, 6.0, pisoGarage.GLindex); //FLOOR
		glPushMatrix();
			glTranslatef(0.0, 0.0, 3.0);
			murover(6.0, 0.0, 0.0, 0.0, 0.0); //FRONT
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-3.0, 0.0, 0.0);
			murohor(6.0, 0.0, 0.0, 0.0, 0.0); //LEFT
		glPopMatrix();
		glPushMatrix();
			glTranslatef(3.0, 0.0, 0.0);
			murohor(6.0, 0.0, 0.0, 0.0, 0.0); //RIGHT
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.0, 0.0, -3.0);
			murover(6.0, 0.0, 0.0, 0.0, 0.0); //BACK
		glPopMatrix();
	glPopMatrix();
}
//Construcción de Casa
void casa( GLvoid ) {

	glPushMatrix();
		glPushMatrix();
			glTranslatef(0.49, 0.0, 9.45);
			murover(0.38, 0.0, 0.0, 0.0, 0.0); //FRONT1 
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-0.2, 1.05, 9.45);
			placaver(1.0, 0.0, 0.0, 0.0, 0.0); //FRONT PLACA 
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-2.995, 0.0, 9.45);
			murover(4.59, 0.0, 0.0, 0.0, 0.0); //FRONT2 
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-5.25, 0.0, 4.8);
			murohor(9.38, 0.0, 0.0, 0.0, 0.0); //LEFT1 
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-5.25, 1.05, -0.39);
			placahor(1.0, 0.0, 0.0, 0.0, 0.0); //LEFT PLACA 
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-5.25, 0.0, -0.99);
			murohor(0.20, 0.0, 0.0, 0.0, 0.0); //LEFT2 
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-5.25, 0.0, -5.20);
			murohor(8.22, 0.0, 0.0, 0.0, 0.0); //LEFT3 
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-5.09, 0.0, -9.34);
			murover(0.40, 0.0, 0.0, 0.0, 0.0); //BACK1 
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-4.19, 1.05, -9.34);
			placaver(1.40, 0.0, 0.0, 0.0, 0.0); //BACK PLACA1
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-2.39, 0.0, -9.34);
			murover(2.20, 0.0, 0.0, 0.0, 0.0); //BACK2 
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-1.04, 0.0, -9.34);
			murover(0.50, 0.0, 0.0, 0.0, 0.0); //BACK3 
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-0.29, 1.05, -9.34);
			placaver(1.0, 0.0, 0.0, 0.0, 0.0); //BACK PLACA2 
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.46, 0.0, -9.34);
			murover(0.50, 0.0, 0.0, 0.0, 0.0); //BACK4 
		glPopMatrix();
		glPushMatrix();
			glTranslatef(1.46, 0.0, -9.34);
			murover(1.50, 0.0, 0.0, 0.0, 0.0); //BACK5 
		glPopMatrix();
		glPushMatrix();
			glTranslatef(3.735, 0.0, -9.34);
			murover(3.05, 0.0, 0.0, 0.0, 0.0); //BACK6 
		glPopMatrix();
		glPushMatrix();
			glTranslatef(5.22, 0.0, -6.850);
			murohor(4.9, 0.0, 0.0, 0.0, 0.0); //RIGHT1 
		glPopMatrix();
		glPushMatrix();
			glTranslatef(5.22, 0.0, -2.7);
			murohor(3.40, 0.0, 0.0, 0.0, 0.0); //RIGHT2 
		glPopMatrix();
		glPushMatrix();
			glTranslatef(5.22, 0.0, -0.25);
			murohor(1.50, 0.0, 0.0, 0.0, 0.0); //RIGHT3 
		glPopMatrix();
		glPushMatrix();
			glTranslatef(5.22, 0.0, 1.375);
			murohor(1.75, 0.0, 0.0, 0.0, 0.0); //RIGHT4 
		glPopMatrix();
		glPushMatrix();
			glTranslatef(5.22, 0.0, 4.05);
			murohor(3.60, 0.0, 0.0, 0.0, 0.0); //RIGHT5 
		glPopMatrix();
		glPushMatrix();
			glTranslatef(2.97, 0.0, 5.89);
			murover(4.58, 0.0, 0.0, 0.0, 0.0); //FRONT3 
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.64, 0.0, 7.63);
			murohor(3.56, 0.0, 0.0, 0.0, 0.0); //RIGHT6 
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-3.21, 0.0, 4.05);
			pisocuadrado(4.0, 10.8, 0.0); //FLOOR LIVING-DINNING ROOM - KITCHEN
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-0.265, 0.0, 0.05);
			pisocuadrado(1.890, 18.8, 0.0); //FLOOR AISLE
		glPopMatrix();
	glPopMatrix();
}

//Funciones de Muebles
void escritorio1(float x, float y, float z) {
	glPushMatrix();
		glPushMatrix();
			glTranslatef(x, y, z);
			fig.prisma(0.05, 3.0, 1.0, 0);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-1.4 + x, -1.0 + y, 0.0 + z);
			fig.prisma(2.0, 0.1, 1.0, 0);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(1.4 + x, -1.0 + y, 0.0 + z);
			fig.prisma(2.0, 0.1, 1.0, 0);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.0 + x, -0.3 + y, 0.0 + z);
			fig.prisma(0.5, 2.5, 0.8, 0);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.0 + x, -0.5 + y, 0.0 + z);
			fig.prisma(1.0, 2.7, 0.05, 0);
		glPopMatrix();
	glPopMatrix();
}

void silla1() {
	glPushMatrix();
		fig.prisma(1.0, 0.2, 1.0, 0);
	glPopMatrix();

}
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable ( GL_COLOR_MATERIAL );
	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);
	//glPolygonMode(GL_BACK, GL_LINE);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
    
    text1.LoadBMP("01.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	text3.LoadTGA("city/arrow.tga");
	text3.BuildGLTexture();
	text3.ReleaseImage();

	tree.LoadTGA("tree01.tga");
	tree.BuildGLTexture();
	tree.ReleaseImage();

	pisoGarage.LoadTGA("TexturasFinal/Garage/pisoGarage.tga");
	pisoGarage.BuildGLTexture();
	pisoGarage.ReleaseImage();

	//END NEW//////////////////////////////

	objCamera.Position_Camera(0,2.5f,3, 0,2.5f,0, 0, 1, 0);

}


void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	
		
	glPushMatrix();
		glRotatef(g_lookupdown,1.0f,0,0);

		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);
	

		glPushMatrix();		
			glPushMatrix(); //Creamos cielo
				glDisable(GL_LIGHTING);
				glTranslatef(0,60,0);
				glColor3f(1.0,1.0,1.0);
				sky.skybox(130.0, 130.0, 130.0,text1.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glBegin(GL_LINES);
				glVertex3f(0.0, 0.0, 0.0);
				glVertex3f(100.0, 0.0, 0.0);
				glVertex3f(0.0, 0.0, 0.0);
				glVertex3f(0.0, 100.0, 0.0);
				glVertex3f(0.0, 0.0, 0.0);
				glVertex3f(0.0, 0.0, 100.0);
			glEnd();

			casa();

		glPopMatrix();
	glPopMatrix();
	glutSwapBuffers ( );

}

void animacion()
{
	anglevar += 0.1;

	glutPostRedisplay();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {

		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.2 );
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.2));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.4));
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED+0.4 );
			break;

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }

  glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View( CAMERASPEED);
		break;

    default:
		break;
  }
  glutPostRedisplay();
}

int main ( int argc, char** argv )   // Main Function
{

  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Colores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Proyecto Final"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );


  glutMainLoop        ( );          // 

  return 0;
}
