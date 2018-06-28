#ifndef _CCD_H_
#define _CCD_H_

// ccd position
// x,y----distance from center(lat,lon),left-down
void computCCDPos(double lat, double lon,double y, double z, struct Rectangle* ccdpos, int isGrim);
// void init_CCD_pos_in_focus( double** ccd_pos_in_focus );
void init_CCD_pos_in_focus( double ccd_pos_in_focus[30][2] );

#endif
