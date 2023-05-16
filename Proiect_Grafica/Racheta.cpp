
#include "glos.h"
#include <math.h>
#include "gl.h"
#include "glu.h"
#include "glaux.h"
#include "glut.h"

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
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING); // Enable lighting
    glEnable(GL_LIGHT0); // Enable light source 0

    GLfloat light_direction[] = { 0.0, 0.0, 1.0, 0.0 }; // Direction of the light source
    GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 }; // Diffuse color
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 }; // Specular color

    glLightfv(GL_LIGHT0, GL_POSITION, light_direction);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

    glShadeModel(GL_SMOOTH); // Enable smooth shading
    glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE); // Enable local viewer mode
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE); // Disable two-sided lighting

    glEnable(GL_NORMALIZE); // Enable automatic normalization of normals
    glCullFace(GL_BACK); // Enable back face culling
    glEnable(GL_COLOR_MATERIAL);
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

void CALLBACK Racheta(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    GLfloat material_diffuse[] = { 0.9, 0.9, 0.9, 1.0 }; // Diffuse color of the material
    GLfloat material_specular[] = { 1.0, 1.0, 1.0, 1.0 }; // Specular color of the material
    GLfloat material_shininess[] = { 50.0 }; // Shininess of the material

    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, material_shininess);

    glPushMatrix();
    glRotatef(alfa, 0, 1, 0);

    /*
   glPushMatrix();
   glRotatef(270, 1, 1, 0);
   Varf();
   glPopMatrix();*/

    glPushMatrix();



    glPushMatrix();
    glColor3f(0.9, 0.9, 0.9);
    glTranslatef(-5, 40.0, 0.0);
    auxSolidCylinder(25, 100);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.9, 0.0, 0.0);
    glTranslatef(-5, 41.0, 0.0);
    glRotatef(270, 1, 0, 0);
    auxSolidCone(25, 40);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2, 0.2, 0.2);
    glTranslatef(0, 20.0, 22.0);
    auxSolidSphere(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(0, 20.0, 26.0);
    auxSolidSphere(6);
    glPopMatrix();



    glPushMatrix();
    glColor3f(0.6, 0.6, 0.6);
    glTranslatef(0, 20.0, 20.0);
    auxSolidSphere(10);
    glPopMatrix();





    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(0.2, 0.2, 0.2);
    glPushMatrix();
    glTranslatef(20, -55.0, 0.0);
    DeseneazaPicior();
    glPopMatrix();

    glPushMatrix();
    glRotatef(120, 0, 1, 0);
    glTranslatef(20, -50.0, 0.0);
    DeseneazaPicior();
    glPopMatrix();

    glPushMatrix();
    glRotatef(230, 0, 1, 0);
    glTranslatef(20, -50.0, 0.0);
    DeseneazaPicior();
    glPopMatrix();

    glTranslatef(-1, -70.0, 0.0);
    glColor3f(0.7, 0.7, 0.7);
    glRotatef(270, 1, 0, 0);
    glPushMatrix();
    auxSolidCone(20, 40);
    glPopMatrix();
    glPopMatrix();

    ///////////////////////////////////   FOC //////////////////////////////////




    glColor3f(1.0, 0.5, 0.0);


    glPushMatrix();
    glTranslatef(0.0, -100.0, 0.0);


    glRotatef(270, 1, 0, 0);
    auxSolidCone(20, 40);

    glRotatef(200, 1, 0, 0);
    auxSolidCone(20, 40);

    glRotatef(30, 1, 0, 0);
    auxSolidCone(20, 40);

    glRotatef(-100, 1, 0, 0);
    auxSolidCone(20, 40);



    glPopMatrix();

    glFlush();

    glPopMatrix();
    glPopMatrix();

}

void CALLBACK Stele(void) {

    glColor3f(1.0, 1.0, 0.0);
    glPushMatrix();

    glTranslatef(50.0, -100.0, 0.0);
    auxSolidSphere(1);

    glPopMatrix();

    glFlush();

   

}




void CALLBACK display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    Racheta();
    Stele();
    
    
    glFlush();
}

void CALLBACK IdleFunction(void)
{   
   glRotatef(alfa, 0, 1, 0);
   Racheta();

    Sleep(50);
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