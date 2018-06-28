#include <stdlib.h>

#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

void Cartesian2Equatorial(double* carCoor, double* eCoor);

/**
 * 坐标变化沿某一平面旋转angle，angle单位为 度
 * coorO表示原始坐标
 * coorR存储变换后的结果
 * flag 标识 1：x-y 平面 2： x-z平面 3：y-z 平面
 * 转动方向为：例如x-y平面，逆时针转动
 */
void CoordinateSpin(double coorO[3], double coorR[3], double angle, int flag);

void rotateByAxisZ(double* coor,double theta,double* coor_new);
	
void rotateByAxisY(double *coor,double theta, double *coor_new);

void rotateByAxisX(double* coor,double theta,double* coor_new);


#endif