#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

struct Rectangle{
	double p1[3];
	double p2[3];
	double p3[3];
	double p4[3];
};


double getAngle132( double x1, double y1, double z1, 
                    double x2, double y2, double z2, 
                    double x3, double y3, double z3);


double getDistPP(double x1, double y1, double z1, 
                 double x2, double y2, double z2);

double getAngleInSphere(double x1, double y1, double z1, 
                        double x2, double y2, double z2);

void findmidArc(double x1,double y1,double z1,
                double x2,double y2,double z2, 
                double* midP);

void getCenterRect(struct Rectangle rect,double* center);

void devideRect(struct Rectangle rect, 
                struct Rectangle *rect1, 
                struct Rectangle *rect2, 
                struct Rectangle *rect3, 
                struct Rectangle *rect4);


int IsInRect(double *point,struct Rectangle* rect);

#endif