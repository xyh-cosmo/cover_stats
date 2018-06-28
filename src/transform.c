#include "area_stats.h"

void Cartesian2Equatorial(double* carCoor, double* eCoor) {
    double x1 = carCoor[0], x2 = carCoor[1], x3 = carCoor[2];
    double r = sqrt(x1*x1+x2*x2+x3*x3);
    double theta = asin(x3/r);

    *(eCoor+1) = theta*180./M_PI;
    *(eCoor+0) = atan(x2/(r*cos(theta)+x1)) *360./M_PI;

//  ra只能是正数！
    if( *eCoor < 0 )
        *eCoor += 360.;
}

/**
 * 坐标变化沿某一平面旋转angle，angle单位为 度
 * coorO表示原始坐标
 * coorR存储变换后的结果
 * flag 标识 1：x-y 平面 2： x-z平面 3：y-z 平面
 * 转动方向为：例如x-y平面，逆时针转动
 */
void CoordinateSpin(double coorO[3], double coorR[3], double angle, int flag) {
	double arcAngle = angle * 2 * M_PI / 360.0;
	if (flag > 3 || flag < 1) {
		return;
	}
	if (flag == 1) {
		coorR[0] = coorO[0] * cos(arcAngle) + coorO[1] * sin(arcAngle);
		coorR[1] = coorO[0] * (-sin(arcAngle)) + coorO[1] * cos(arcAngle);
		coorR[2] = coorO[2];
	}
	if (flag == 2) {
		coorR[0] = coorO[0] * cos(arcAngle) + coorO[2] * sin(arcAngle);
		coorR[1] = coorO[1];
		coorR[2] = coorO[0] * (-sin(arcAngle)) + coorO[2] * cos(arcAngle);
	}
	if (flag == 3) {
		coorR[0] = coorO[0];
		coorR[1] = coorO[1] * cos(arcAngle) + coorO[2] * sin(arcAngle);
		coorR[2] = coorO[1] * (-sin(arcAngle)) + coorO[2] * cos(arcAngle);
	}
}

void rotateByAxisZ(double* coor,double theta,double* coor_new){
	coor_new[0] = coor[0]*cos(theta)+coor[1]*sin(theta);
	coor_new[1] = -sin(theta)*coor[0]+cos(theta)*coor[1];
	coor_new[2] = coor[2];
}
	
void rotateByAxisY(double *coor,double theta, double *coor_new){
	coor_new[0] = cos(theta)*coor[0]-sin(theta)*coor[2];
	coor_new[1] = coor[1];
	coor_new[2] = sin(theta)*coor[0]+cos(theta)*coor[2];
}

void rotateByAxisX(double* coor,double theta,double* coor_new){
	coor_new[0] = coor[0];
	coor_new[1] = cos(theta)*coor[1]+sin(theta)*coor[2];
	coor_new[2] = -sin(theta)*coor[1]+cos(theta)*coor[2];
}
