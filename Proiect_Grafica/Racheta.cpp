/*
Programul afiseaza un cub care se roteste
*/
#include "glos.h"
#include <math.h>
#include "gl.h"
#include "glu.h"
#include "glaux.h"

void myinit(void);
void CALLBACK display(void);
void CALLBACK myReshape(GLsizei w, GLsizei h);
void CALLBACK IdleFunction(void);
static GLfloat alfa = 10;
static GLfloat x = 0;
static GLfloat y = 0;
static GLfloat z = 0;

void myinit(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(0.0, 1.0, 0.0);
    //glEnable(GL_DEPTH_TEST);
}
void CALLBACK MutaStanga()
{
    x = x + 10;
}

void CALLBACK DeseneazaPicior()
{
    glBegin(GL_QUADS);
    {
        glVertex3f(0.0f, 0.0f, 0.0f); //prima componenta fata 
        glVertex3f(0.0f, 25.0f, 0.0f);
        glVertex3f(25.0f, 0.0f, 0.0f);
        glVertex3f(28.0f, -10.0f, 0.0f);
        
        glVertex3f(28.0f, -10.0f, 0.0f); //prima componenta dreapta
        glVertex3f(25.0f, 0.0f, 0.0f);
        glVertex3f(25.0f, 0.0f, -3.0f);
        glVertex3f(28.0f, -10.0f, -3.0f);
       
        glVertex3f(0.0f, 0.0f, -3.0f); //prima componenta stanga
        glVertex3f(0.0f, 25.0f, -3.0f);
        glVertex3f(0.0f, 25.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);
        
        glVertex3f(0.0f, 0.0f, 0.0f); //prima componenta jos
        glVertex3f(28.0f, -10.0f, 0.0f);
        glVertex3f(28.0f, -10.0f, -3.0f);
        glVertex3f(0.0f, 0.0f, -3.0f);
        
        glVertex3f(25.0f, 0.0f, 0.0f); //prima componenta sus
        glVertex3f(0.0f, 25.0f, 0.0f);
        glVertex3f(0.0f, 25.0f, -3.0f);
        glVertex3f(25.0f, 0.0f, -3.0f);
        
        glVertex3f(28.0f, -10.0f, -3.0f); //prima componenta spate
        glVertex3f(25.0f, 0.0f, -3.0f);
        glVertex3f(0.0f, 25.0f, -3.0f);
        glVertex3f(0.0f, 0.0f, -3.0f);

        ///--------------------------------------------------------------------------------------------------------///


          
        glVertex3f(12.0f, -40.0f, 0.0f);   //a doua componenta fata
        glVertex3f(15.0f, -3.0f, 0.0f);
        glVertex3f(28.0f, -10.0f, 0.0f);
        glVertex3f(13.0f, -40.0f, 0.0f);
        
        glVertex3f(12.0f, -40.0f, 0.0f);  //a doua componenta dreapta
        glVertex3f(28.0f, -10.0f, 0.0f);
        glVertex3f(28.0f, -10.0f, -3.0f);
        glVertex3f(13.0f, -40.0f, 0.0f);
        
        glVertex3f(13.0f, -40.0f, -3.0f);  //a doua componenta stanga
        glVertex3f(15.0f, -3.0f, -3.0f);
        glVertex3f(15.0f, -3.0f, 0.0f);
        glVertex3f(12.0f, -40.0f, 0.0f);
        
        
        glVertex3f(12.0f, -40.0f, 0.0f);  //a doua componenta jos
        glVertex3f(13.0f, -40.0f, 0.0f);
        glVertex3f(13.0f, -40.0f, -3.0f);
        glVertex3f(12.0f, -40.0f, -3.0f);
        
        glVertex3f(13.0f, -40.0f, -3.0f);  //a doua componenta spate
        glVertex3f(28.0f, -10.0f, -3.0f);
        glVertex3f(15.0f, -3.0f, -3.0f);
        glVertex3f(12.0f, -40.0f, -3.0f);
        }
    glEnd();
}

void CALLBACK Baza()
{
    GLdouble eqn1[4] = { -1.0, 1.0, 1.0, 0.0 };
    glClipPlane(GL_CLIP_PLANE0, eqn1);
    glEnable(GL_CLIP_PLANE0);
    auxSolidCone(25, 40);
    glDisable(GL_CLIP_PLANE0);
}

void CALLBACK display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    //
    
    glRotatef(alfa, 1, 1, 1);

    /*
    glPushMatrix();
    glPushMatrix();
    glColor3f(0.9, 0.0, 0.0);
    //glTranslatef(-5, 40.0, 0.0);
    glRotatef(270, 1, 0, 0);
    auxSolidCone(25,40);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.9, 0.9, 0.9);
   // glTranslatef(-5, -60.0, 0.0);
    auxSolidCylinder(25, 100);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.6, 0.6, 0.6);
     glTranslatef(0, -20.0, 0.0);
    auxSolidSphere(10);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2, 0.2, 0.2);
    glTranslatef(0, -20.0, 0.0);
    auxSolidSphere(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(0, -20.0, 0.0);
    auxSolidSphere(6);
    glPopMatrix();
   
   //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(0.2, 0.2, 0.2);
    glPushMatrix();
    glTranslatef(20, -95.0, 0.0);
    DeseneazaPicior();
    glPopMatrix();

    glPushMatrix();
    glRotatef(120,0,1,0);
    glTranslatef(20, -95.0, 0.0);
    DeseneazaPicior();
    glPopMatrix();

    glPushMatrix();
    glRotatef(230, 0, 1, 0);
    glTranslatef(20, -95.0, 0.0);
    DeseneazaPicior();
    glPopMatrix();
    */
    glPushMatrix();
    Baza();
    glPopMatrix();

    glPopMatrix();
    
    glFlush();
}

void CALLBACK IdleFunction(void)
{
    //glRotatef(0, 0, 1, 0);
    //display();
    //Sleep(300);
}

void CALLBACK myReshape(GLsizei w, GLsizei h)
{
    if (!h) return;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-160.0, 160.0, -160.0 * (GLfloat)h / (GLfloat)w,
            160.0 * (GLfloat)h / (GLfloat)w, -200.0, 200.0);
    else
        glOrtho(-160.0 * (GLfloat)w / (GLfloat)h,
            160.0 * (GLfloat)w / (GLfloat)h, -160.0, 160.0, -200.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    auxInitDisplayMode(AUX_SINGLE | AUX_RGB);
    auxInitPosition(0, 0, 900, 600);
    auxInitWindow("Racheta");
    myinit();
    auxKeyFunc(AUX_LEFT, MutaStanga);
    auxReshapeFunc(myReshape);
    auxIdleFunc(IdleFunction);
    auxMainLoop(display);
    return(0);
}