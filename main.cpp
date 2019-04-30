#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include "include/materials.h"
#include "include/glibrary.h"



/////////////////////////////////////////
//           HECHO POR:                //
//                                     //
// JONATAN JOSUÉ BERMÚDEZ AMAYA        //
//                                     //
//     BA16010                         //
/////////////////////////////////////////



GLfloat X = 0.0f; // Translate screen to x direction (left or right)
GLfloat Y = 0.0f; // Translate screen to y direction (up or down)
GLfloat Z = 0.0f; // Translate screen to z direction (zoom in or out)
GLfloat rotX = 18.0f; // Rotate screen on x axis
GLfloat rotY = -37.0f; // Rotate screen on y axis
GLfloat rotZ = 0.0f; // Rotate screen on z axis
GLfloat rotLx = 0.0f; // Translate screen by using the glulookAt function (left or right)
GLfloat rotLy = 0.0f; // Translate screen by using the glulookAt function (up or down)
GLfloat rotLz = 0.0f; // Translate screen by using the glulookAt function (zoom in or out)


GLfloat  pala = 0.0f;
GLfloat  largo_cableZ = -100.0f;
GLfloat largo_cableY = 15.0f;


void setMaterial(short name){

    glMaterialfv(GL_FRONT, GL_AMBIENT, materials_data[name][0]);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materials_data[name][1]);
    glMaterialfv(GL_FRONT, GL_SPECULAR, materials_data[name][2]);
    glMaterialfv(GL_FRONT, GL_SHININESS, materials_data[name][3]);

}




// Initialize the OpenGL window
void init(void)
{

    GLfloat light_position[] = { -10, 50, 100, 0.0 };
    GLfloat light2_position[] = { 0, 100, -100, 0.0 };

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT1, GL_POSITION, light2_position);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}


void materiales(){

    glClearColor(0.5, 0.5, 0.5, 1);
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the Color Buffer
    glMatrixMode(GL_MODELVIEW_MATRIX);
    glLoadIdentity();

    //18, -37

    glRotatef(rotX,1.0,0.0,0.0); // Rotate on x
    glRotatef(rotY,0.0,1.0,0.0); // Rotate on y
    glRotatef(rotZ,0.0,0.0,1.0); // Rotate on z
    glTranslatef(X, Y, Z); 	// Translates the screen left or right,


    glPushMatrix();
    setMaterial(bronze);
    //glRotatef(15, 1, 0, 0);
    //glRotatef(-15, 0, 1, 0);
    glBegin(GL_QUADS);

    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, -100);
    glVertex3f(50, 0, -100);
    glVertex3f(50, 0, 0);
    glPopMatrix();

    //laterales
    glPushMatrix();
    setMaterial(emerald);

    glVertex3f(1, 0, 0);
    glVertex3f(1, 0, -100);
    glVertex3f(1, -10, -100);
    glVertex3f(1, -10, 0);

    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, -100);
    glVertex3f(0, -10, -100);
    glVertex3f(0, -10, 0);

    glPopMatrix();




    glPushMatrix();

    //lateral derecho
    setMaterial(emerald);

    glVertex3f(49, 0, 0);
    glVertex3f(49, 0, -100);
    glVertex3f(49, -10, -100);
    glVertex3f(49, -10, 0);


    glVertex3f(50, 0, 0);
    glVertex3f(50, 0, -100);
    glVertex3f(50, -10, -100);
    glVertex3f(50, -10, 0);
    glPopMatrix();


    glPushMatrix();
    setMaterial(red_plastic);

    //parte frontal

    glVertex3f(0, 0, 0);
    glVertex3f(50, 0, 0);
    glVertex3f(50, -10, 0);
    glVertex3f(0, -10, 0);


    //parte trasera

    glVertex3f(0, 0, -100);
    glVertex3f(0, 10, -100);
    glVertex3f(50, 10, -100);
    glVertex3f(50, 0, -100);

    glPopMatrix();

    glPushMatrix();

    setMaterial(black_plastic);

    glVertex3f(50, 0, -100);
    glVertex3f(50, 10, -100);
    glVertex3f(50, 10, -103);
    glVertex3f(50, 0, -103);


    glVertex3f(0, 0, -100);
    glVertex3f(0, 10, -100);
    glVertex3f(0, 10, -103);
    glVertex3f(0, 0, -103);


    glVertex3f(50, 10, -100);
    glVertex3f(50, 10, -103);
    glVertex3f(0, 10, -103);
    glVertex3f(0, 10, -100);


    glPopMatrix();

    glEnd();



    //ruedas
    setMaterial(cyan_plastic);

    glPushMatrix();
    glTranslatef(53, -10, -90);
    glRotatef(90, 0, 1, 0);
    glutSolidTorus(4, 6, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3, -10, -90);
    glRotatef(90, 0, 1, 0);
    glutSolidTorus(4, 6, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(53, -10, 0);
    glRotatef(90, 0, 1, 0);
    glutSolidTorus(4, 6, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3, -10, 0);
    glRotatef(90, 0, 1, 0);
    glutSolidTorus(4, 6, 100, 100);
    glPopMatrix();


    setMaterial(obsidian);

    glPushMatrix();
    glTranslatef(54, -10, 0);
    glutSolidCube(8);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(54, -10, -90);
    glutSolidCube(8);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-3, -10, -90);
    glutSolidCube(8);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3, -10, 0);
    glutSolidCube(8);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    setMaterial(green_plastic);

    glTranslatef(0, -10, 0);
    glRotatef(90, 0, 1, 0);
    gluCylinder(gluNewQuadric(), 3, 3, 50, 50, 50);

    glPopMatrix();


    //

    glPushMatrix();
    setMaterial(yellow_plastic);

    glTranslatef(50, 0, 0);
    drawRectangleSolidAngle2d(0, 0, 5, 100, 90);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(50, 0, -5);
    drawRectangleSolidAngle2d(0, 0, 5, 100, 90);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(50, 0, 0);
    glRotatef(-90, 0, 1, 0);
    drawRectangleSolidAngle2d(0, 0, 5, 100, 90);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(45, 0, 0);
    glRotatef(-90, 0, 1, 0);
    drawRectangleSolidAngle2d(0, 0, 5, 100, 90);
    glPopMatrix();


    glPushMatrix();

    glTranslatef(5, 0, 0);
    drawRectangleSolidAngle2d(0, 0, 5, 100, 90);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(5, 0, -5);
    drawRectangleSolidAngle2d(0, 0, 5, 100, 90);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(5, 0, 0);
    glRotatef(-90, 0, 1, 0);
    drawRectangleSolidAngle2d(0, 0, 5, 100, 90);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glRotatef(-90, 0, 1, 0);
    drawRectangleSolidAngle2d(0, 0, 5, 100, 90);
    glPopMatrix();



    glPushMatrix();

    glTranslatef(5, 70, 0);
    drawRectangleSolidAngle2d(0, 0, 5, 40, 0);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(5, 70, -5);
    drawRectangleSolidAngle2d(0, 0, 5, 40, 0);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(5, 75, 0);
    glRotatef(-90, 1, 0, 0);
    drawRectangleSolidAngle2d(0, 0, 5, 40, 0);

    glPopMatrix();

    glPushMatrix();
    setMaterial(black_plastic);
    glBegin(GL_LINES);
    glVertex3f(5, 50, 0);
    glVertex3f(22.5, 5, 0);

    glVertex3f(45, 50, 0);
    glVertex3f(25, 5, 0);

    glVertex3f(47.5, 0, 0);
    glVertex3f(25, largo_cableY, largo_cableZ);

    glVertex3f(2.5, 0, 0);
    glVertex3f(25, largo_cableY, largo_cableZ);


    glVertex3f(47.5, 100, 0);
    glVertex3f(25, largo_cableY, largo_cableZ);

    glVertex3f(2.5, 100, 0);
    glVertex3f(25, largo_cableY, largo_cableZ);
    glEnd();
    glPopMatrix();



    //brazo catapulta

    ///////////////////////////////////////////////////////////////////////////////////////////


    glRotatef(pala, 1, 0, 0);

    glPushMatrix();

    //derecha
    setMaterial(yellow_plastic);
    glTranslatef(27.5, 0, 0);
    glRotatef(90, 0, 1, 0);
    drawRectangleSolidAngle2d(0, 0, 5, 110, 7);
    glPopMatrix();

    //izquierda
    glPushMatrix();
    glTranslatef(22.5, 0, 0);
    glRotatef(90, 0, 1, 0);
    drawRectangleSolidAngle2d(0, 0, 5, 110, 7);
    glPopMatrix();

    //abajo
    glPushMatrix();
    glTranslatef(27.5, 0, 0);
    glRotatef(-83, 1, 0, 0);
    drawRectangleSolidAngle2d(0, 0, 5, 110, 90);
    glPopMatrix();

    //arriba
    glPushMatrix();
    glTranslatef(27.5, 5, 0);
    glRotatef(-83, 1, 0, 0);
    drawRectangleSolidAngle2d(0, 0, 5, 110, 90);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(22.5, 0, 0);
    drawRectangleSolidAngle2d(0,0, 5, 5, 0);
    glPopMatrix();


    glPushMatrix();
    setMaterial(red_plastic);
    glTranslatef(25, 20, -107);
    glRotatef(90, 1, 0, 0);
    glutSolidCone(8, 10, 50, 50);
    glPopMatrix();



    /////////////////////////////////////////////////////////////////////////////////////////7


    glutSwapBuffers();
    glFlush();

}


// This function is called whenever the window size is changed
void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h); // Set the viewport
    glMatrixMode (GL_PROJECTION); 	// Set the Matrix mode
    glLoadIdentity ();
    glOrtho(-50,150,-50,150,-150,150);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //gluLookAt (rotLx, rotLy, 15.0 + rotLz, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

// This function is used for the navigation keys
void keyboard (unsigned char key, int x, int y)
{
    switch (key) {   // x,X,y,Y,z,Z uses the glRotatef() function
        case 'x': // Rotates screen on x axis
            rotX -= 0.5f;
            break;
        case 'X': // Opposite way
            rotX += 0.5f;
            break;
        case 'y': // Rotates screen on y axis
            rotY -= 0.5f;
            break;
        case 'Y': // Opposite way
            rotY += 0.5f;
            break;
        case 'z': // Rotates screen on z axis
            rotZ -= 0.5f;
            break;
        case 'Z': // Opposite way
            rotZ += 0.5f;
            break;
        case 'o': // Default, resets the translations vies from starting view
            X = Y = 0.0f;
            Z = 0.0f;
            rotX = 18.0f;
            rotY = -37.0f;
            rotZ = 0.0f;
            rotLx = 0.0f;
            rotLy = 0.0f;
            rotLz = 0.0f;
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluLookAt(rotLx, rotLy, 15.0f + rotLz, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
            break;

        case 'F':
        case 'f':

            largo_cableY+=0.58f;
            largo_cableZ+=0.56f;

            if(pala<=73.0 ){
                pala += 0.5f;
            }else{
                largo_cableY-=0.58f;
                largo_cableZ-=0.56f;
            }

            break;

        case 'E':
        case 'e':
            if( pala >= 0){
                pala-=0.5f;
                largo_cableY-=0.58f;
                largo_cableZ-=0.56f;
            }
            break;

    }
    glutPostRedisplay(); // Redraw the scene
}


// Main entry point of the program
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_RGB | GLUT_DEPTH); 	// Setup display mode to
    // double buffer and RGB color
    glutInitWindowSize (600,600); // Set the screen size
    glutCreateWindow("Parcial #2");
    init ();
    glutReshapeFunc(reshape);
    glutDisplayFunc(materiales);
    glutKeyboardFunc(keyboard); // set window's key callback
    glutMainLoop();

    return 0;
}