#include "area_stats.h"


int main(int argc, char *argv[]) {
	
	struct FourTree* Trees12 = (struct FourTree*)malloc(sizeof(struct FourTree)*12);

	int layer = 7;

//------------divide sphere use HealPix-----------//

/*---------------------1--------------------------*/ 
    int pn = 0;
    
    struct Rectangle rect;
    rect.p1[0]=sqrt(2)/2.;
	rect.p1[1]=sqrt(2)/2.;
	rect.p1[2]=0;
	
	rect.p2[0]=0;
	rect.p2[1]=cos(0.61547970867038737);
	rect.p2[2]=sin(0.61547970867038737);
	
	rect.p3[0]=-sqrt(2)/2.;
	rect.p3[1]=sqrt(2)/2.;
	rect.p3[2]=0;
	
	rect.p4[0]=0;
	rect.p4[1]=cos(0.61547970867038737);
	rect.p4[2]=-sin(0.61547970867038737);
	
	struct treeNode *head1 = (struct treeNode*)malloc(sizeof(struct treeNode));
	head1->parent = NULL;
	(Trees12+0)->head = head1;
	(Trees12+0)->layer = layer;
    divideIterate(rect,pn,layer, head1);

/*---------------------2--------------------------*/   
    pn = 0;
	rect.p1[0]=-sqrt(2)/2.;
	rect.p1[1]=sqrt(2)/2.;
	rect.p1[2]=0;
	
	rect.p2[0]=-cos(0.61547970867038737);
	rect.p2[1]=0;
	rect.p2[2]=sin(0.61547970867038737);
	
	rect.p3[0]=-sqrt(2)/2.;
	rect.p3[1]=-sqrt(2)/2.;
	rect.p3[2]=0;
	
	rect.p4[0]=-cos(0.61547970867038737);
	rect.p4[1]=0;
	rect.p4[2]=-sin(0.61547970867038737);
	
	struct treeNode *head2 = (struct treeNode*)malloc(sizeof(struct treeNode));
	head2->parent = NULL;
	(Trees12+1)->head = head2;
	(Trees12+1)->layer = layer;
    divideIterate(rect,pn,layer, head2);

/*---------------------3--------------------------*/   
    pn = 0;
	rect.p1[0]=-sqrt(2)/2.;
	rect.p1[1]=-sqrt(2)/2.;
	rect.p1[2]=0;
	
	rect.p2[0]=0;
	rect.p2[1]=-cos(0.61547970867038737);
	rect.p2[2]=sin(0.61547970867038737);
	
	rect.p3[0]=sqrt(2)/2.;
	rect.p3[1]=-sqrt(2)/2.;
	rect.p3[2]=0;
	
	rect.p4[0]=0;
	rect.p4[1]=-cos(0.61547970867038737);
	rect.p4[2]=-sin(0.61547970867038737);
	
	struct treeNode *head3 = (struct treeNode*)malloc(sizeof(struct treeNode));
	head3->parent = NULL;
	(Trees12+2)->head = head3;
	(Trees12+2)->layer = layer;
    divideIterate(rect,pn,layer, head3);

/*---------------------4--------------------------*/   
    pn = 0;
	rect.p1[0]=sqrt(2)/2.;
	rect.p1[1]=-sqrt(2)/2.;
	rect.p1[2]=0;
	
	rect.p2[0]=cos(0.61547970867038737);
	rect.p2[1]=0;
	rect.p2[2]=sin(0.61547970867038737);
	
	rect.p3[0]=sqrt(2)/2.;
	rect.p3[1]=sqrt(2)/2.;
	rect.p3[2]=0;
	
	rect.p4[0]=cos(0.61547970867038737);
	rect.p4[1]=0;
	rect.p4[2]=-sin(0.61547970867038737);
	
	struct treeNode *head4 = (struct treeNode*)malloc(sizeof(struct treeNode));
	head4->parent = NULL;
	(Trees12+3)->head = head4;
	(Trees12+3)->layer = layer;
    divideIterate(rect,pn,layer, head4);  
    
/*---------------------5--------------------------*/   
    pn = 0;
	rect.p1[0]=sqrt(2)/2.;
	rect.p1[1]=sqrt(2)/2.;
	rect.p1[2]=0;
	
	rect.p2[0]=0;
	rect.p2[1]=cos(0.61547970867038737);
	rect.p2[2]=sin(0.61547970867038737);
	
	rect.p3[0]=0;
	rect.p3[1]=0;
	rect.p3[2]=1;
	
	rect.p4[0]=cos(0.61547970867038737);
	rect.p4[1]=0;
	rect.p4[2]=sin(0.61547970867038737);
	
	struct treeNode *head5 = (struct treeNode*)malloc(sizeof(struct treeNode));
	head5->parent = NULL;
	(Trees12+4)->head = head5;
	(Trees12+4)->layer = layer;
    divideIterate(rect,pn,layer, head5); 
    
/*---------------------6--------------------------*/   
    pn = 0;
	rect.p1[0]=-sqrt(2)/2.;
	rect.p1[1]=sqrt(2)/2.;
	rect.p1[2]=0;
	
	rect.p2[0]=-cos(0.61547970867038737);
	rect.p2[1]=0;
	rect.p2[2]=sin(0.61547970867038737);
	
	rect.p3[0]=0;
	rect.p3[1]=0;
	rect.p3[2]=1;
	
	rect.p4[0]=0;
	rect.p4[1]=cos(0.61547970867038737);
	rect.p4[2]=sin(0.61547970867038737);
	
	struct treeNode *head6 = (struct treeNode*)malloc(sizeof(struct treeNode));
	head6->parent = NULL;
	(Trees12+5)->head = head6;
	(Trees12+5)->layer = layer;
    divideIterate(rect,pn,layer, head6); 
    
/*---------------------7--------------------------*/   
    pn = 0;
	rect.p1[0]=-sqrt(2)/2.;
	rect.p1[1]=-sqrt(2)/2.;
	rect.p1[2]=0;
	
	rect.p2[0]=0;
	rect.p2[1]=-cos(0.61547970867038737);
	rect.p2[2]=sin(0.61547970867038737);
	
	rect.p3[0]=0;
	rect.p3[1]=0;
	rect.p3[2]=1;
	
	rect.p4[0]=-cos(0.61547970867038737);
	rect.p4[1]=0;
	rect.p4[2]=sin(0.61547970867038737);
	
	struct treeNode *head7 = (struct treeNode*)malloc(sizeof(struct treeNode));
	head7->parent = NULL;
	(Trees12+6)->head = head7;
	(Trees12+6)->layer = layer;
    divideIterate(rect,pn,layer, head7); 
    
/*---------------------8--------------------------*/   
    pn = 0;
	rect.p1[0]=sqrt(2)/2.;
	rect.p1[1]=-sqrt(2)/2.;
	rect.p1[2]=0;
	
	rect.p2[0]=cos(0.61547970867038737);
	rect.p2[1]=0;
	rect.p2[2]=sin(0.61547970867038737);
	
	rect.p3[0]=0;
	rect.p3[1]=0;
	rect.p3[2]=1;
	
	rect.p4[0]=0;
	rect.p4[1]=-cos(0.61547970867038737);
	rect.p4[2]=sin(0.61547970867038737);
	
	struct treeNode *head8 = (struct treeNode*)malloc(sizeof(struct treeNode));
	head8->parent = NULL;
	(Trees12+7)->head = head8;
	(Trees12+7)->layer = layer;
    divideIterate(rect,pn,layer, head8);

/*---------------------9--------------------------*/   
    pn = 0;
	rect.p1[0]=sqrt(2)/2.;
	rect.p1[1]=sqrt(2)/2.;
	rect.p1[2]=0;
	
	rect.p2[0]=0;
	rect.p2[1]=cos(0.61547970867038737);
	rect.p2[2]=-sin(0.61547970867038737);
	
	rect.p3[0]=0;
	rect.p3[1]=0;
	rect.p3[2]=-1;
	
	rect.p4[0]=cos(0.61547970867038737);
	rect.p4[1]=0;
	rect.p4[2]=-sin(0.61547970867038737);
	
	struct treeNode *head9 = (struct treeNode*)malloc(sizeof(struct treeNode));
	head9->parent = NULL;
	(Trees12+8)->head = head9;
	(Trees12+8)->layer = layer;
    divideIterate(rect,pn,layer, head9); 
    
/*---------------------10--------------------------*/   
    pn = 0;
	rect.p1[0]=-sqrt(2)/2.;
	rect.p1[1]=sqrt(2)/2.;
	rect.p1[2]=0;
	
	rect.p2[0]=-cos(0.61547970867038737);
	rect.p2[1]=0;
	rect.p2[2]=-sin(0.61547970867038737);
	
	rect.p3[0]=0;
	rect.p3[1]=0;
	rect.p3[2]=-1;
	
	rect.p4[0]=0;
	rect.p4[1]=cos(0.61547970867038737);
	rect.p4[2]=-sin(0.61547970867038737);
	
	struct treeNode *head10 = (struct treeNode*)malloc(sizeof(struct treeNode));
	head10->parent = NULL;
	(Trees12+9)->head = head10;
	(Trees12+9)->layer = layer;
    divideIterate(rect,pn,layer, head10); 
    
/*---------------------11--------------------------*/   
    pn = 0;
	rect.p1[0]=-sqrt(2)/2.;
	rect.p1[1]=-sqrt(2)/2.;
	rect.p1[2]=0;
	
	rect.p2[0]=0;
	rect.p2[1]=-cos(0.61547970867038737);
	rect.p2[2]=-sin(0.61547970867038737);
	
	rect.p3[0]=0;
	rect.p3[1]=0;
	rect.p3[2]=-1;
	
	rect.p4[0]=-cos(0.61547970867038737);
	rect.p4[1]=0;
	rect.p4[2]=-sin(0.61547970867038737);
	
	struct treeNode *head11 = (struct treeNode*)malloc(sizeof(struct treeNode));
	head11->parent = NULL;
	(Trees12+10)->head = head11;
	(Trees12+10)->layer = layer;
    divideIterate(rect,pn,layer, head11); 


/*---------------------12--------------------------*/   
    pn = 0;
	rect.p1[0]=sqrt(2)/2.;
	rect.p1[1]=-sqrt(2)/2.;
	rect.p1[2]=0;
	
	rect.p2[0]=cos(0.61547970867038737);
	rect.p2[1]=0;
	rect.p2[2]=-sin(0.61547970867038737);
	
	rect.p3[0]=0;
	rect.p3[1]=0;
	rect.p3[2]=-1;
	
	rect.p4[0]=0;
	rect.p4[1]=-cos(0.61547970867038737);
	rect.p4[2]=-sin(0.61547970867038737);
	
	struct treeNode *head12 = (struct treeNode*)malloc(sizeof(struct treeNode));
	head12->parent = NULL;
	(Trees12+11)->head = head12;
	(Trees12+11)->layer = layer;
    divideIterate(rect,pn,layer, head12);
    
//------------------------division end-------------------------------------------//

	//y,z
	double ccd_pos_in_focus[30][2];
	init_CCD_pos_in_focus(ccd_pos_in_focus);
	
	int i,j;
	
	FILE *dat = fopen("../SM_config20171103_c5_290_1_mius.dat","r");
	int MAXLINE_STRING = 1000;
	char line[MAXLINE_STRING];
	char start[3] = "#";
	int datNum = 0;
	
	int uNumber1 = 0;
	int unUNumber1 = 0;
	
	int uNumber2 = 0;
	int unUNumber2 = 0;
	
	//int fileNum = 0;
	
	while(fgets(line, MAXLINE_STRING, dat)!=NULL){
		
		double lat,lon,n_time;
		int coverNum;
		char* p;
		p = strtok(line, " \n\t");
		if (p==NULL){
			continue;
		}
		
		// if(p==""){
		if( strcmp(p,"")==0 ){
			continue;
		}
		
		if(p[0] == start[0]){
			continue;
		}
		
		int cNum = 0;
		double deepFlag = -1;
		lon = -9999, lat = -9999;
		while (p != NULL && cNum<15) {
			if(cNum == 0){
				n_time = atof(p);
			}
			if(cNum == 1){
				lat = atof(p);
			}
			if(cNum == 2){
				lon = atof(p);
			}
			if(cNum == 4){
				coverNum = atof(p);
			}
			if(cNum == 14){
				deepFlag = atof(p);
			}
			cNum++;
			p = strtok(NULL, " \t\n");
		}

		if(n_time<0){
			continue;
		}
		
		if(cNum<15){
			continue;
		}
		datNum ++;
		
		struct searchNodes* r_nodes = (struct searchNodes*)malloc(sizeof(struct searchNodes));
	    r_nodes -> s_len = 0;
	    for(i = 0; i < 12; i ++){
			findSearchRange(lat, lon, (Trees12+i)->head, 0, (Trees12+i)->layer, r_nodes);	
		}
		
		coverNum = 1;
		int isUlity = -1;
		for(i = 0; i < 4; i ++){
			struct Rectangle* ccdpos = (struct Rectangle*)malloc(sizeof(struct Rectangle));
			
			computCCDPos(lat, lon,ccd_pos_in_focus[i][0], ccd_pos_in_focus[i][1], ccdpos,0);
			for(j =0; j < r_nodes->s_len; j ++){
				if(IsInRect(r_nodes->s_nodes[j]->midPoint,ccdpos) == 1){
					r_nodes->s_nodes[j]->band[0]+=coverNum;
					if (deepFlag < 0){
						if(r_nodes->s_nodes[j]->band[0]<=4){
							isUlity = 1;
						}
					}else{
						if(r_nodes->s_nodes[j]->band[0]<=16){
							isUlity = 1;
						}
					}
				}
			}
		}
		
		for(i = 4; i < 6; i ++){
			struct Rectangle* ccdpos = (struct Rectangle*)malloc(sizeof(struct Rectangle));
			
			computCCDPos(lat, lon,ccd_pos_in_focus[i][0], ccd_pos_in_focus[i][1], ccdpos,0);
			for(j =0; j < r_nodes->s_len; j ++){
				if(IsInRect(r_nodes->s_nodes[j]->midPoint,ccdpos) == 1){
					r_nodes->s_nodes[j]->band[1]+=coverNum;
					if (deepFlag < 0){
						if(r_nodes->s_nodes[j]->band[1]<=2){
							isUlity = 1;
						}
					}else{
						if(r_nodes->s_nodes[j]->band[1]<=8){
							isUlity = 1;
						}
					}
				}
			}
		}
		
		for(i = 6; i < 8; i ++){
			struct Rectangle* ccdpos = (struct Rectangle*)malloc(sizeof(struct Rectangle));
			computCCDPos(lat, lon,ccd_pos_in_focus[i][0], ccd_pos_in_focus[i][1], ccdpos,0);
			for(j =0; j < r_nodes->s_len; j ++){
				if(IsInRect(r_nodes->s_nodes[j]->midPoint,ccdpos) == 1){
					r_nodes->s_nodes[j]->band[2]+=coverNum;
					if (deepFlag < 0){
						if(r_nodes->s_nodes[j]->band[2]<=2){
							isUlity = 1;
						}
					}else{
						if(r_nodes->s_nodes[j]->band[2]<=8){
							isUlity = 1;
						}
					}
				}
			}
		}
		
		for(i = 8; i < 10; i ++){
			struct Rectangle* ccdpos = (struct Rectangle*)malloc(sizeof(struct Rectangle));
			
			computCCDPos(lat, lon,ccd_pos_in_focus[i][0], ccd_pos_in_focus[i][1], ccdpos,0);
			for(j =0; j < r_nodes->s_len; j ++){
				if(IsInRect(r_nodes->s_nodes[j]->midPoint,ccdpos) == 1){
					r_nodes->s_nodes[j]->band[3]+=coverNum;
					if (deepFlag < 0){
						if(r_nodes->s_nodes[j]->band[3]<=2){
							isUlity = 1;
						}
					}else{
						if(r_nodes->s_nodes[j]->band[3]<=8){
							isUlity = 1;
						}
					}
				}
			}
		}
		
		for(i = 10; i < 12; i ++){
			struct Rectangle* ccdpos = (struct Rectangle*)malloc(sizeof(struct Rectangle));
			
			computCCDPos(lat, lon,ccd_pos_in_focus[i][0], ccd_pos_in_focus[i][1], ccdpos,0);
			for(j =0; j < r_nodes->s_len; j ++){
				if(IsInRect(r_nodes->s_nodes[j]->midPoint,ccdpos) == 1){
					r_nodes->s_nodes[j]->band[4]+=coverNum;
					if (deepFlag < 0){
						if(r_nodes->s_nodes[j]->band[4]<=2){
							isUlity = 1;
						}
					}else{
						if(r_nodes->s_nodes[j]->band[4]<=8){
							isUlity = 1;
						}
					}
				}
			}
		}
		
		for(i = 12; i < 14; i ++){
			struct Rectangle* ccdpos = (struct Rectangle*)malloc(sizeof(struct Rectangle));
			
			computCCDPos(lat, lon,ccd_pos_in_focus[i][0], ccd_pos_in_focus[i][1], ccdpos,0);
			
			for(j =0; j < r_nodes->s_len; j ++){
				if(IsInRect(r_nodes->s_nodes[j]->midPoint,ccdpos) == 1){
					r_nodes->s_nodes[j]->band[5]+=coverNum;
					if (deepFlag < 0){
						if(r_nodes->s_nodes[j]->band[5]<=2){
							isUlity = 1;
						}
					}else{
						if(r_nodes->s_nodes[j]->band[5]<=8){
							isUlity = 1;
						}
					}
				}
			}
		}
		
		for(i = 14; i < 18; i ++){
			struct Rectangle* ccdpos = (struct Rectangle*)malloc(sizeof(struct Rectangle));
			
			computCCDPos(lat, lon,ccd_pos_in_focus[i][0], ccd_pos_in_focus[i][1], ccdpos,0);
			for(j =0; j < r_nodes->s_len; j ++){
				if(IsInRect(r_nodes->s_nodes[j]->midPoint,ccdpos) == 1){
					r_nodes->s_nodes[j]->band[6]+=coverNum;
					if (deepFlag < 0){
						if(r_nodes->s_nodes[j]->band[6]<=4){
							isUlity = 1;
						}
					}else{
						if(r_nodes->s_nodes[j]->band[6]<=16){
							isUlity = 1;
						}
					}
				}
			}
		}
		
		for(i = 18; i < 22; i ++){
			struct Rectangle* ccdpos = (struct Rectangle*)malloc(sizeof(struct Rectangle));
			
			computCCDPos(lat, lon,ccd_pos_in_focus[i][0], ccd_pos_in_focus[i][1], ccdpos,0);
			for(j =0; j < r_nodes->s_len; j ++){
				if(IsInRect(r_nodes->s_nodes[j]->midPoint,ccdpos) == 1){
					r_nodes->s_nodes[j]->band[7]+=coverNum;
					if (deepFlag < 0){
						if(r_nodes->s_nodes[j]->band[7]<=4){
							isUlity = 1;
						}
					}else{
						if(r_nodes->s_nodes[j]->band[7]<=16){
							isUlity = 1;
						}
					}
				}
			}
		}
		
		for(i = 22; i < 26; i ++){
			struct Rectangle* ccdpos = (struct Rectangle*)malloc(sizeof(struct Rectangle));
			
			computCCDPos(lat, lon,ccd_pos_in_focus[i][0], ccd_pos_in_focus[i][1], ccdpos,0);
			for(j =0; j < r_nodes->s_len; j ++){
				if(IsInRect(r_nodes->s_nodes[j]->midPoint,ccdpos) == 1){
					r_nodes->s_nodes[j]->band[8]+=coverNum;
					if (deepFlag < 0){
						if(r_nodes->s_nodes[j]->band[8]<=4){
							isUlity = 1;
						}
					}else{
						if(r_nodes->s_nodes[j]->band[8]<=16){
							isUlity = 1;
						}
					}
				}
			}
		}
		
		for(i = 26; i < 30; i ++){
			struct Rectangle* ccdpos = (struct Rectangle*)malloc(sizeof(struct Rectangle));
			
			computCCDPos(lat, lon,ccd_pos_in_focus[i][0], ccd_pos_in_focus[i][1], ccdpos,0);
			for(j =0; j < r_nodes->s_len; j ++){
				if(IsInRect(r_nodes->s_nodes[j]->midPoint,ccdpos) == 1){
					r_nodes->s_nodes[j]->band[9]+=coverNum;
					if (deepFlag < 0){
						if(r_nodes->s_nodes[j]->band[9]<=4){
							isUlity = 1;
						}
					}else{
						if(r_nodes->s_nodes[j]->band[9]<=16){
							isUlity = 1;
						}
					}
				}
			}
		}
		
		double coor_z = 1000000 * sin(lat * 2 * M_PI / 360);
		double coor_x = 1000000 * cos(lat * 2 * M_PI / 360) * cos(lon * 2 * M_PI / 360);
		double coor_y = 1000000 * cos(lat * 2 * M_PI / 360) * sin(lon * 2 * M_PI / 360);
		
		double t_coor[3] = { coor_x, coor_y, coor_z };
		double r_coor[3];
		CoordinateSpin(t_coor, r_coor, -23.4522, 3);
		double ll_coor[2];
		Cartesian2Equatorial(r_coor, ll_coor);

		double bn = 57.2957795
			* asin(
					-0.867666 * cos(ll_coor[0] / 57.2957795) * cos(ll_coor[1] / 57.2957795)
							- 0.1980764 * sin(ll_coor[0] / 57.2957795) * cos(ll_coor[1] / 57.2957795)
							+ 0.455984 * sin(ll_coor[1] / 57.2957795));
							
		if(fabs(bn)>=20 && fabs(lat)>=20){
			if (isUlity >0){
				uNumber1 ++;
			}else{
				unUNumber1 ++;
			}
		}else{
			if (isUlity >0){
				uNumber2 ++;
			}else{
				unUNumber2 ++;
			}
		}
		
		free(r_nodes);
	}
	
	printf("%d    %d    %d    %d \n",uNumber1,unUNumber1,uNumber2,unUNumber2);
    
	FILE* fn = fopen("skycover_11107_m.dat","w");
	
	for(i = 0; i<12;i ++){
		searchTrees((Trees12+i)->head, 0, layer, fn);
	}
	fclose(fn);
}
