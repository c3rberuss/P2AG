
#include <iostream>
#include <tuple>
#ifndef GLIBRARY_LIBRARY_H
#define GLIBRARY_LIBRARY_H


void drawLineStripVerical2d(float x1, float y1, float length, float border);
void drawLineStripHorizontal2d(float x1, float y1, float length, float border);

void drawPlane2d(float height, float width, float border);
void drawLine2d(float x1, float y1, float x2, float y2, float border);
void drawCircleBorder2d(float radius, float h, float k, float border, float n_points);
void drawCircleSolid2d(float radius, float h, float k, float n_points);
void drawRectangleBorder2d(float x, float y, float height, float width, float border);
void drawRectangleSolid2d(float x, float y, float height, float width);

void drawTriangleBorder2d(float x, float y, float base, float height, float border);
void drawTriangleSolid2d(float x, float y, float base, float height);


void drawCircleSegmentLine2d(float radius, float h, float k, float degree_segment, float start_degree, float n_points,
                             float border);
void drawCircleSegmentSolid2d(float radius, float h, float k, float degree_segment, float start_degree, float n_points);

void drawLineAngle2d(float x, float y, float large, float angle, float border);

void drawRectangleBorderAngle2d(float x, float y, float height, float width, float angle,float border);
void drawRectangleSolidAngle2d(float x, float y, float height, float width, float angle);

void drawText(char *string, float x, float y, void *font);

void drawDisk2d(float radius, float h, float k, float width, float n_segments);

void setOrtho(int quadrants, double width, double height, double z);

void drawRectanglesSolid2d( std::tuple< std::tuple< float, float, float, float>> dims );

int factorial(int n);

int combination(int n, int p );

void bezier(float x[], float y[], float n, float increment);

std::tuple<float, float, float, float> drawLineAnglePoints2d(float x, float y, float large, float angle);
std::tuple<float, float, float, float> bezierPoints(float x[], float y[], float n, float increment);


#endif