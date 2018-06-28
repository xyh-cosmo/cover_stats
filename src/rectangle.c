#include "area_stats.h"

double getAngle132( double x1, double y1, double z1, 
                    double x2, double y2, double z2, 
                    double x3, double y3, double z3){
	double x11 = x1-x3;
	double y11 = y1-y3;
	double z11 = z1-z3;
	
	double x22 = x2-x3;
	double y22 = y2-y3;
	double z22 = z2-z3;
	double tt = sqrt((x11*x11 + y11*y11 + z11* z11) * (x22*x22 + y22*y22 + z22*z22));
	if(tt==0){
		return -1;
	}
		

	double cosValue = (x11*x22+y11*y22+z11*z22)/tt;
	if (cosValue > 1){
		cosValue = 1;
	}
		
	if (cosValue < -1){
		cosValue = -1;
	}
		
	double angle = acos(cosValue);
	return angle * 360 / (2 * M_PI);
	
}


double getDistPP(double x1, double y1, double z1, 
                 double x2, double y2, double z2){
	double x11 = x1-x2;
	double y11 = y1-y2;
	double z11 = z1-z2;

	double dist = sqrt((x11*x11 + y11*y11 + z11* z11));
	
	return dist;
}

double getAngleInSphere(double x1, double y1, double z1, 
                        double x2, double y2, double z2){
	double tt = sqrt((x1*x1 + y1*y1 + z1* z1) * (x2*x2 + y2*y2 + z2*z2));
	if(tt==0){
		return -1;
	}
	double cosValue = (x1*x2+y1*y2+z1*z2)/tt;

	if (cosValue > 1){
		cosValue = 1;
	}
	if (cosValue < -1){
		cosValue = -1;
	}
	double angle = acos(cosValue);
	return angle;
}

void findmidArc(double x1,double y1,double z1,
                double x2,double y2,double z2, 
                double* midP){
	double a_sphere = getAngleInSphere(x1,y1,z1,x2,y2,z2);
	
	double ratio = 0;
	if (fabs(a_sphere-M_PI)>0.00001){
		ratio = 1/cos(a_sphere*0.5);
	}

	double x_m = (x1+x2)/2.0;
	double y_m = (y1+y2)/2.0;
	double z_m = (z1+z2)/2.0;
	
	midP[0] = x_m*ratio;
	midP[1] = y_m*ratio;
	midP[2] = z_m*ratio;
}

void getCenterRect(struct Rectangle rect,double* center){
	double mid1[3],mid2[3],mid3[3],mid4[3],mid13[3],mid24[3];
	findmidArc(rect.p1[0],rect.p1[1],rect.p1[2],rect.p2[0],rect.p2[1],rect.p2[2],mid1);
	findmidArc(rect.p2[0],rect.p2[1],rect.p2[2],rect.p3[0],rect.p3[1],rect.p3[2],mid2);
	findmidArc(rect.p3[0],rect.p3[1],rect.p3[2],rect.p4[0],rect.p4[1],rect.p4[2],mid3);
	findmidArc(rect.p4[0],rect.p4[1],rect.p4[2],rect.p1[0],rect.p1[1],rect.p1[2],mid4);
	
	findmidArc(mid1[0],mid1[1],mid1[2],mid3[0],mid3[1],mid3[2],mid13);
	findmidArc(mid2[0],mid2[1],mid2[2],mid4[0],mid4[1],mid4[2],mid24);
	center[0] = (mid13[0]+mid24[0])/2.0;
	center[1] = (mid13[1]+mid24[1])/2.0;
	center[2] = (mid13[2]+mid24[2])/2.0;
}

void devideRect(struct Rectangle rect, 
                struct Rectangle *rect1, 
                struct Rectangle *rect2, 
                struct Rectangle *rect3, 
                struct Rectangle *rect4){
	double mid1[3],mid2[3],mid3[3],mid4[3],mid13[3],mid24[3],mid[3];
	findmidArc(rect.p1[0],rect.p1[1],rect.p1[2],rect.p2[0],rect.p2[1],rect.p2[2],mid1);
	findmidArc(rect.p2[0],rect.p2[1],rect.p2[2],rect.p3[0],rect.p3[1],rect.p3[2],mid2);
	findmidArc(rect.p3[0],rect.p3[1],rect.p3[2],rect.p4[0],rect.p4[1],rect.p4[2],mid3);
	findmidArc(rect.p4[0],rect.p4[1],rect.p4[2],rect.p1[0],rect.p1[1],rect.p1[2],mid4);
	
	findmidArc(mid1[0],mid1[1],mid1[2],mid3[0],mid3[1],mid3[2],mid13);
	findmidArc(mid2[0],mid2[1],mid2[2],mid4[0],mid4[1],mid4[2],mid24);
	
	mid[0] = (mid13[0]+mid24[0])/2.0;
	mid[1] = (mid13[1]+mid24[1])/2.0;
	mid[2] = (mid13[2]+mid24[2])/2.0;
	rect1->p1[0] = rect.p1[0];
	rect1->p1[1] = rect.p1[1];
	rect1->p1[2] = rect.p1[2];
	
	rect1->p2[0] = mid1[0];
	rect1->p2[1] = mid1[1];
	rect1->p2[2] = mid1[2];
	
	rect1->p3[0] = mid[0];
	rect1->p3[1] = mid[1];
	rect1->p3[2] = mid[2];
	
	rect1->p4[0] = mid4[0];
	rect1->p4[1] = mid4[1];
	rect1->p4[2] = mid4[2];
	
	rect2->p1[0] = rect.p2[0];
	rect2->p1[1] = rect.p2[1];
	rect2->p1[2] = rect.p2[2];
	
	rect2->p2[0] = mid2[0];
	rect2->p2[1] = mid2[1];
	rect2->p2[2] = mid2[2];
	
	rect2->p3[0] = mid[0];
	rect2->p3[1] = mid[1];
	rect2->p3[2] = mid[2];
	
	rect2->p4[0] = mid1[0];
	rect2->p4[1] = mid1[1];
	rect2->p4[2] = mid1[2];
	
	rect3->p1[0] = rect.p3[0];
	rect3->p1[1] = rect.p3[1];
	rect3->p1[2] = rect.p3[2];
	
	rect3->p2[0] = mid3[0];
	rect3->p2[1] = mid3[1];
	rect3->p2[2] = mid3[2];
	
	rect3->p3[0] = mid[0];
	rect3->p3[1] = mid[1];
	rect3->p3[2] = mid[2];
	
	rect3->p4[0] = mid2[0];
	rect3->p4[1] = mid2[1];
	rect3->p4[2] = mid2[2];
	
	rect4->p1[0] = rect.p4[0];
	rect4->p1[1] = rect.p4[1];
	rect4->p1[2] = rect.p4[2];
	
	rect4->p2[0] = mid4[0];
	rect4->p2[1] = mid4[1];
	rect4->p2[2] = mid4[2];
	
	rect4->p3[0] = mid[0];
	rect4->p3[1] = mid[1];
	rect4->p3[2] = mid[2];
	
	rect4->p4[0] = mid3[0];
	rect4->p4[1] = mid3[1];
	rect4->p4[2] = mid3[2];	
}

int IsInRect(double *point,struct Rectangle* rect){
	
	//printf("%f    %f    %f\n",rect->p1[0]-point[0],rect->p1[0]-point[1],rect->p1[0]-point[2]);
	
	double a1,a2,a3,b1,b2,b3,vec[4][3];
	
	//p1
	a1 = rect->p1[0]-point[0];
	a2 = rect->p1[1]-point[1];
	a3 = rect->p1[2]-point[2];
	
	b1 = rect->p2[0]-point[0];
	b2 = rect->p2[1]-point[1];
	b3 = rect->p2[2]-point[2];
	
	vec[0][0]=a2*b3-a3*b2;
	vec[0][1]=a3*b1-a1*b3;
	vec[0][2]=a1*b2-a2*b1;
	
	//p2
	a1 = rect->p2[0]-point[0];
	a2 = rect->p2[1]-point[1];
	a3 = rect->p2[2]-point[2];
	
	b1 = rect->p3[0]-point[0];
	b2 = rect->p3[1]-point[1];
	b3 = rect->p3[2]-point[2];
	
	vec[1][0]=a2*b3-a3*b2;
	vec[1][1]=a3*b1-a1*b3;
	vec[1][2]=a1*b2-a2*b1;
	
	//p3
	a1 = rect->p3[0]-point[0];
	a2 = rect->p3[1]-point[1];
	a3 = rect->p3[2]-point[2];
	
	b1 = rect->p4[0]-point[0];
	b2 = rect->p4[1]-point[1];
	b3 = rect->p4[2]-point[2];
	
	vec[2][0]=a2*b3-a3*b2;
	vec[2][1]=a3*b1-a1*b3;
	vec[2][2]=a1*b2-a2*b1;
	
	//p3
	a1 = rect->p4[0]-point[0];
	a2 = rect->p4[1]-point[1];
	a3 = rect->p4[2]-point[2];
	
	b1 = rect->p1[0]-point[0];
	b2 = rect->p1[1]-point[1];
	b3 = rect->p1[2]-point[2];
	
	vec[3][0]=a2*b3-a3*b2;
	vec[3][1]=a3*b1-a1*b3;
	vec[3][2]=a1*b2-a2*b1;
	
	int i = 0;
	int reFlag = 1;
	
	//double flag[4];
	double scale = 100000000;
	double flag1 = (vec[0][0]*vec[1][0]+vec[0][1]*vec[1][1]+vec[0][2]*vec[1][2])*scale;
	//printf("flag %f \n",flag1);
	
	for(i=1;i<4;i++){
		double flagn = (vec[i][0]*vec[(i+1)%4][0]+vec[i][1]*vec[(i+1)%4][1]+vec[i][2]*vec[(i+1)%4][2])*scale;
		//printf("flagn %f \n",flagn);
		if(flag1*flagn < 0){
			reFlag = 0;
			break;
		}
	}

	return reFlag;
}
