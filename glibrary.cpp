#include "glibrary.h"
#include <iostream>
#include <GL/glut.h>
#include <math.h>
#include <tuple>
#include <cstring>


void drawLine2d(float x1, float y1, float x2, float y2, float border){


    glLineWidth(border);
    glBegin(GL_LINES);

    glVertex2f(x1, y1);
    glVertex2f(x2, y2);

    glEnd();

}

void drawCircleBorder2d(float radius, float h, float k, float border, float n_points){

    glLineWidth(border);
    glBegin(GL_LINE_LOOP);


    for( float angle = 0; angle <= 360; angle+=(360/n_points) ){


        glVertex2f((radius * cos(angle * (M_PI/ 180))) + h,(radius * sin(angle * (M_PI/ 180)))+k);

    }

    glEnd();

}


void drawCircleSolid2d(float radius, float h, float k, float n_points){

    glBegin(GL_POLYGON);

    for( float angle = 0; angle <= 360; angle+=(360/n_points) ){

        glVertex2f((radius * cos(angle * (M_PI/ 180))) + h,(radius * sin(angle * (M_PI/ 180)))+k);

    }

    glEnd();

}


void drawRectangleBorder2d(float x, float y, float height, float width, float border){


    glLineWidth(border);
    glBegin(GL_LINE_LOOP);

    glVertex2f(x, y);
    glVertex2f(x, y+height);
    glVertex2f(x+width, y+height);
    glVertex2f(x+width, y);

    glEnd();

}


void drawRectangleSolid2d(float x, float y, float height, float width){

    glBegin(GL_QUADS);

    glVertex2f(x, y);
    glVertex2f(x, y+height);
    glVertex2f(x+width, y+height);
    glVertex2f(x+width, y);

    glEnd();

}

void drawCircleSegmentLine2d(float radius, float h, float k, float degree_segment, float start_degree, float n_points,
                             float border){

    glLineWidth(border);
    glBegin(GL_LINE_STRIP);

    for( float angle = start_degree; angle <= degree_segment+start_degree; angle+=(degree_segment/n_points) ){

        glVertex2f((radius * cos(angle * (M_PI/ 180))) + h,(radius * sin(angle * (M_PI/ 180)))+k);

    }

    glEnd();

}


void drawCircleSegmentSolid2d(float radius, float h, float k, float degree_segment, float start_degree, float n_points){

    glBegin(GL_POLYGON);

    glVertex2f(h,k);
    for( float angle = start_degree; angle <= degree_segment+start_degree; angle+=(degree_segment/n_points) ){

        glVertex2f((radius * cos(angle * (M_PI/ 180))) + h,(radius * sin(angle * (M_PI/ 180)))+k);

    }

    glEnd();

}

void drawTriangleBorder2d(float x, float y, float base, float height, float border) {

    float base_ = base / 2;

    glBegin(GL_LINE_LOOP);

    glVertex2f(x-base_, y);
    glVertex2f(x+base_, y);
    glVertex2f(x, y+height);

    glEnd();

}

void drawTriangleSolid2d(float x, float y, float base, float height) {

    float base_ = base / 2;

    glBegin(GL_TRIANGLES);

    glVertex2f(x-base_, y);
    glVertex2f(x+base_, y);
    glVertex2f(x, y+height);

    glEnd();

}

void drawLineAngle2d(float x, float y, float large, float angle, float border) {

    glLineWidth(border);
    glBegin(GL_LINES);

    glVertex2f(x, y);
    glVertex2f( (large * cos( angle * (M_PI / 180) ))+x,  (large * sin( angle * (M_PI / 180) ))+y);

    glEnd();

}

void drawRectangleBorderAngle2d(float x, float y, float height, float width, float angle, float border) {


    glLineWidth(border);
    glBegin(GL_LINE_LOOP);

    glVertex2f(x, y);//OK


    float tmp_x = (height * cos( (angle + 90) * (M_PI / 180) ))+x;
    float tmp_y = (height * sin( (angle + 90) * (M_PI / 180) ))+y;

    glVertex2f( tmp_x,  tmp_y); //OK

    glVertex2f( (width * cos( angle  * (M_PI / 180) ))+tmp_x,  (width * sin( angle * (M_PI / 180) ))+tmp_y);

    glVertex2f( (width * cos( angle * (M_PI / 180) ))+x,  (width * sin( angle * (M_PI / 180) ))+y);

    glEnd();


}

void drawRectangleSolidAngle2d(float x, float y, float height, float width, float angle) {

    glBegin(GL_QUADS);

    glVertex2f(x, y);//OK


    float tmp_x = (height * cos( (angle + 90) * (M_PI / 180) ))+x;
    float tmp_y = (height * sin( (angle + 90) * (M_PI / 180) ))+y;

    glVertex2f( tmp_x,  tmp_y); //OK

    glVertex2f( (width * cos( angle  * (M_PI / 180) ))+tmp_x,  (width * sin( angle * (M_PI / 180) ))+tmp_y);

    glVertex2f( (width * cos( angle * (M_PI / 180) ))+x,  (width * sin( angle * (M_PI / 180) ))+y);

    glEnd();
}

void drawPlane2d(float height, float width, float border) {

    glBegin(GL_LINES);

    glLineWidth(border);

    glVertex2f(0, -1*height);
    glVertex2f(0, height);
    glVertex2f(-1*width, 0);
    glVertex2f(width, 0);

    glEnd();

}

void drawLineStripVerical2d(float x1, float y1, float length, float border) {

    glLineWidth(border);
    glBegin(GL_LINES);

    glVertex2f(x1, y1);

    for( float y = y1; y<= length; y+=0.1 ){

        glVertex2f(x1, y);

    }

    glEnd();

}

void drawLineStripHorizontal2d(float x1, float y1, float length, float border) {

    glLineWidth(border);
    glBegin(GL_LINES);

    glVertex2f(x1, y1);

    for( float x = x1; x<= length; x+=0.1 ){

        glVertex2f(x, y1);

    }

    glEnd();

}


void drawText(char *string, float x, float y, void *font){

    int len = strlen(string);
    glRasterPos2d(x, y);
    for (int i = 0; i <= len; i++ ) {
        glutBitmapCharacter(font, string[i]);
    }

}

void drawDisk2d(float radius, float h, float k, float width, float n_segments) {


    glBegin(GL_QUAD_STRIP);

    for( float angle = 0; angle <= 365; angle+=(360/n_segments) ){

        glVertex2f((radius * cos(angle * (M_PI/ 180))) + h,(radius * sin(angle * (M_PI/ 180)))+k);
        glVertex2f(((radius + width) * cos(angle * (M_PI/ 180))) + h,((radius + width) * sin(angle * (M_PI/ 180)))+k);

    }

    glEnd();

}

void setOrtho(int quadrants, double width, double height, double z) {

    switch( quadrants ){

        case 1:
            glOrtho(0, width, 0, height, -z, z);
            break;
        case 2:
            glOrtho(-width, 0, 0, height, -z, z);
            break;
        case 3:
            glOrtho(-width, 0, -height, 0, -z, z);
            break;
        case 4:
            glOrtho(0, width, -height, 0, -z, z);
            break;
        case 12:
            glOrtho(-width, width, 0, height, -z, z);
            break;
        case 21:
            glOrtho(-width, width, 0, height, -z, z);
            break;
        case 34:
            glOrtho(-width, width, -height, 0, -z, z);
            break;
        case 43:
            glOrtho(-width, width, -height, 0, -z, z);
            break;
        case 23:
            glOrtho(-width, 0, -height, height, -z, z);
            break;
        case 32:
            glOrtho(-width, 0, -height, height, -z, z);
            break;
        case 14:
            glOrtho(0, width, -height, height, -z, z);
            break;
        case 41:
            glOrtho(0, width, -height, height, -z, z);
            break;
        default:
            glOrtho(-width, width, -height, height, -z, z);
            break;
    }

}


int factorial(int n)
{
    if(n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}

int combination(int n, int p ){

    return factorial(n) / ( factorial(p) * factorial( n - p ) );

}

void bezier(float x[], float y[], float n, float increment){

    float x_aux  = 0;
    float y_aux = 0;

    n-=1;

    for( float t = 0.0; t<1; t+=increment) {

        x_aux = 0.0;
        y_aux = 0.0;

        for (int i = 0; i <= n; i++) {

            x_aux += combination(n, i) * x[i] * pow((1 - t), n - i) * pow(t, i);
            //std::cout<<"i - x: "<<i<<std::endl;

        }

        for (int i = 0; i <= n; i++) {

            y_aux += combination(n, i) * y[i] * pow((1 - t), n - i) * pow(t, i);
            //std::cout<<"i - y: "<<i<<std::endl;

        }

        glVertex2f(x_aux, y_aux);

    }

}

std::tuple<float, float, float, float> drawLineAnglePoints2d(float x, float y, float large, float angle) {


    glVertex2f(x, y);

    float x2 = (large * cos( angle * (M_PI / 180) ))+x;
    float y2 = (large * sin( angle * (M_PI / 180) ))+y;

    glVertex2f( x2, y2);

    return { x,y, x2, y2};
}

std::tuple<float, float, float, float> bezierPoints(float *x, float *y, int n, float increment) {

    float x_aux  = 0;
    float y_aux = 0;

    n-=1;

    for( float t = 0.0; t<1; t+=increment) {

        x_aux = 0.0;
        y_aux = 0.0;

        for (int i = 0; i <= n; i++) {

            x_aux += combination(n, i) * x[i] * pow((1 - t), n - i) * pow(t, i);
            //std::cout<<"i - x: "<<i<<std::endl;

        }

        for (int i = 0; i <= n; i++) {

            y_aux += combination(n, i) * y[i] * pow((1 - t), n - i) * pow(t, i);
            //std::cout<<"i - y: "<<i<<std::endl;

        }

        glVertex2f(x_aux, y_aux);

    }

    return { x[0],y[0], x[n], y[n]};
}

