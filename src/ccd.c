#include "area_stats.h"

// ccd position
// x,y----distance from center(lat,lon),left-down
void computCCDPos(	double lat, 
					double lon,
					double y, 
					double z, 
					struct Rectangle* ccdpos, 
					int isGrim){
//	what is isGrim?
	double ccd_z = 0.0924/28.0;
	double ccd_y = 0.0922/28.0;
	if (isGrim == 1){
		ccd_y = ccd_y*0.9552843545350902;
	}
	double p1[3],p2[3],p3[3],p4[3],p11[3],p22[3],p33[3],p44[3];
	
	double py = y;
	double pz = z;
	
	p1[0]=sqrt(1 - py*py-pz*pz);
	p1[1]=py;
	p1[2]=pz;
	rotateByAxisY(p1,lat *M_PI/180, p11);
	rotateByAxisZ(p11,-lon *M_PI/180,ccdpos->p1);
	
	py = y+ccd_y;
	pz = z;
	p2[0]=sqrt(1 - py*py-pz*pz);
	p2[1]=py;
	p2[2]=pz;
	rotateByAxisY(p2,lat *M_PI/180, p22);
	rotateByAxisZ(p22,-lon *M_PI/180,ccdpos->p2);
	
	
	py = y+ccd_y;
	pz = z+ccd_z;
	p3[0]=sqrt(1 - py*py-pz*pz);
	p3[1]=py;
	p3[2]=pz;
	rotateByAxisY(p3,lat *M_PI/180, p33);
	rotateByAxisZ(p33,-lon *M_PI/180,ccdpos->p3);
	
	py = y;
	pz = z+ccd_z;
	p4[0]=sqrt(1 - py*py-pz*pz);
	p4[1]=py;
	p4[2]=pz;
	rotateByAxisY(p4,lat *M_PI/180, p44);
	rotateByAxisZ(p44,-lon *M_PI/180,ccdpos->p4);
}

void init_CCD_pos_in_focus( double ccd_pos_in_focus[30][2] ){
//void init_CCD_pos_in_focus( double** ccd_pos_in_focus ){
	//----------------NUV  4----------------------//
	ccd_pos_in_focus[0][0] =   0.0030/28.;
	ccd_pos_in_focus[0][1] =  -0.1475/28.;
	ccd_pos_in_focus[1][0] =   0.0030/28.;
	ccd_pos_in_focus[1][1] =  -0.0462/28.;
	ccd_pos_in_focus[2][0] =  -0.0952/28.;
	ccd_pos_in_focus[2][1] =  -0.0462/28.;
	ccd_pos_in_focus[3][0] =  -0.0952/28.;
	ccd_pos_in_focus[3][1] =   0.0551/28.;
	//------------------------------------------//
	
	//--------------------u  2---------------------//
	ccd_pos_in_focus[4][0] = -0.0952/28.;
	ccd_pos_in_focus[4][1] = -0.1475/28.;
	
	ccd_pos_in_focus[5][0] =  0.0030/28.;
	ccd_pos_in_focus[5][1] =  0.0551/28.;
	//------------------------------------------//
	
	//--------------------g  2---------------------//
	ccd_pos_in_focus[6][0] =  0.1012/28.;
	ccd_pos_in_focus[6][1] = -0.0462/28.;
	
	ccd_pos_in_focus[7][0] = -0.1934/28.;
	ccd_pos_in_focus[7][1] = -0.0462/28.;
	//------------------------------------------//
	
	//--------------------r  2---------------------//
	ccd_pos_in_focus[8][0] = -0.1934/28.;
	ccd_pos_in_focus[8][1] = -0.1475/28.;
	
	ccd_pos_in_focus[9][0] =  0.1012/28.;
	ccd_pos_in_focus[9][1] =  0.0551/28.;
	//------------------------------------------//
	
	//--------------------i  2---------------------//
	ccd_pos_in_focus[10][0] =  0.1012/28.;
	ccd_pos_in_focus[10][1] = -0.1475/28.;
	
	ccd_pos_in_focus[11][0] = -0.1934/28.;
	ccd_pos_in_focus[11][1] =  0.0551/28.;
	//------------------------------------------//
	
	//--------------------z  2---------------------//
	ccd_pos_in_focus[12][0] = -0.0952/28.;
	ccd_pos_in_focus[12][1] = -0.2488/28.;
	
	ccd_pos_in_focus[13][0] =  0.0030/28.;
	ccd_pos_in_focus[13][1] =  0.1564/28.;
	//------------------------------------------//
	
	//--------------------Y  4---------------------//
	ccd_pos_in_focus[14][0] =  0.1012/28.;
	ccd_pos_in_focus[14][1] = -0.2488/28.;
	
	ccd_pos_in_focus[15][0] =  0.0030/28.;
	ccd_pos_in_focus[15][1] = -0.2488/28.;
	
	ccd_pos_in_focus[16][0] = -0.0952/28.;
	ccd_pos_in_focus[16][1] =  0.1564/28.;
	
	ccd_pos_in_focus[17][0] = -0.1934/28.;
	ccd_pos_in_focus[17][1] =  0.1564/28.;
	//------------------------------------------//
	
	//--------------------GU  4---------------------//
	ccd_pos_in_focus[18][0] =  0.2054/28.;
	ccd_pos_in_focus[18][1] = -0.0462/28.;
	
	ccd_pos_in_focus[19][0] =  0.2054/28.;
	ccd_pos_in_focus[19][1] =  0.0551/28.;
	
	ccd_pos_in_focus[20][0] = -0.2976/28.;
	ccd_pos_in_focus[20][1] = -0.1475/28.;
	
	ccd_pos_in_focus[21][0] = -0.2976/28.;
	ccd_pos_in_focus[21][1] = -0.0462/28.;
	//------------------------------------------//
	
	//--------------------GV  4---------------------//
	ccd_pos_in_focus[22][0] =  0.2054/28.;
	ccd_pos_in_focus[22][1] = -0.2488/28.;
	
	ccd_pos_in_focus[23][0] =  0.2054/28.;
	ccd_pos_in_focus[23][1] = -0.1475/28.;
	
	ccd_pos_in_focus[24][0] = -0.2976/28.;
	ccd_pos_in_focus[24][1] =  0.0551/28.;
	
	ccd_pos_in_focus[25][0] = -0.2976/28.;
	ccd_pos_in_focus[25][1] =  0.1564/28.;
	//------------------------------------------//
	
	//--------------------GI  4---------------------//
	ccd_pos_in_focus[26][0] = -0.1994/28.;
	ccd_pos_in_focus[26][1] = -0.2488/28.;
	
	ccd_pos_in_focus[27][0] = -0.2976/28.;
	ccd_pos_in_focus[27][1] = -0.2488/28.;
	
	ccd_pos_in_focus[28][0] =  0.2054/28.;
	ccd_pos_in_focus[28][1] =  0.1564/28.;
	
	ccd_pos_in_focus[29][0] =  0.1072/28.;
	ccd_pos_in_focus[29][1] =  0.1564/28.;
	//------------------------------------------//
}
