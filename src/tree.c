#include "area_stats.h"

void divideIterate(struct Rectangle rect, int pn,int layer, struct treeNode *tn){
	
	double mid[3];
	getCenterRect(rect,mid);
	tn->midPoint[0] = mid[0];
	tn->midPoint[1] = mid[1];
	tn->midPoint[2] = mid[2];
	int i = 0;
	for(i=0;i<10;i ++){
		tn->band[i] = 0;
	}

	double angle1 = getAngleInSphere(mid[0],mid[1],mid[2],rect.p1[0],rect.p1[1],rect.p1[2]);
	double angle2 = getAngleInSphere(mid[0],mid[1],mid[2],rect.p2[0],rect.p2[1],rect.p2[2]);
	double angle3 = getAngleInSphere(mid[0],mid[1],mid[2],rect.p3[0],rect.p3[1],rect.p3[2]);
	double angle4 = getAngleInSphere(mid[0],mid[1],mid[2],rect.p4[0],rect.p4[1],rect.p4[2]);
	
	double anglef = angle1;
	if(anglef<angle2){
		anglef = angle2;
	}
	if(anglef<angle3){
		anglef = angle3;
	}
	if(anglef<angle4){
		anglef = angle4;
	}
	anglef += 1/180.*M_PI;
	tn->radius = sqrt(2-2*cos(anglef));
	
	//printf("%f\n",tn->radius);
	
	if (pn == layer){
		tn->child1 = NULL;
		tn->child2 = NULL;
		tn->child3 = NULL;
		tn->child4 = NULL;
		return;
	}
	
	struct Rectangle *rect1 = (struct Rectangle*)malloc(sizeof(struct Rectangle)*1);
	struct Rectangle *rect2 = (struct Rectangle*)malloc(sizeof(struct Rectangle)*1);
	struct Rectangle *rect3 = (struct Rectangle*)malloc(sizeof(struct Rectangle)*1);
	struct Rectangle *rect4 = (struct Rectangle*)malloc(sizeof(struct Rectangle)*1);
	devideRect(rect,rect1,rect2,rect3,rect4);
	
	pn ++;
	struct treeNode* cNode1 = (struct treeNode*) malloc(sizeof(struct treeNode));
	cNode1->parent = tn;
	tn->child1 = cNode1;
	divideIterate(*rect1, pn,layer, cNode1);
	
	struct treeNode* cNode2 = (struct treeNode*) malloc(sizeof(struct treeNode));
	cNode2->parent = tn;
	tn->child2 = cNode2;
	divideIterate(*rect2, pn,layer, cNode2);
	
	struct treeNode* cNode3 = (struct treeNode*) malloc(sizeof(struct treeNode));
	cNode3->parent = tn;
	tn->child3 = cNode3;
	divideIterate(*rect3, pn,layer, cNode3);
	
	struct treeNode* cNode4 = (struct treeNode*) malloc(sizeof(struct treeNode));
	cNode4->parent = tn;
	tn->child4 = cNode4;
	divideIterate(*rect4, pn,layer, cNode4);
	
	free(rect1);
	free(rect2);
	free(rect3);
	free(rect4);
}

void searchTrees(struct treeNode* node, int nLayer, int searchLayer, FILE* fn){
	if (nLayer == searchLayer){
		double eqCoor[2];
		if( node->band[0]==0
		&&	node->band[1]==0
		&&	node->band[2]==0
		&&	node->band[3]==0
		&&	node->band[4]==0
		&&	node->band[5]==0
		&&	node->band[6]==0
		&&	node->band[7]==0
		&&	node->band[8]==0
		&&	node->band[9]==0 ){
			
		}else{
			Cartesian2Equatorial(node->midPoint, eqCoor);
			fprintf(fn,"%f    %f    %d    %d    %d    %d    %d    %d    %d    %d    %d    %d\n",
					eqCoor[0],eqCoor[1],
					node->band[0], node->band[1], 
					node->band[2], node->band[3], 
					node->band[4], node->band[5], 
					node->band[6], node->band[7], 
					node->band[8], node->band[9]);
		}
		
		return;
	}
	nLayer ++;
	struct treeNode* ch1 = node->child1;
	if(ch1 == NULL){
		return;
	}else{
		searchTrees(ch1, nLayer, searchLayer, fn);
	}
	
	struct treeNode* ch2 = node->child2;
	if(ch2 == NULL){
		return;
	}else{
		searchTrees(ch2, nLayer, searchLayer, fn);
	}
	
	struct treeNode* ch3 = node->child3;
	if(ch3 == NULL){
		return;
	}else{
		searchTrees(ch3, nLayer, searchLayer, fn);
	}
	
	struct treeNode* ch4 = node->child4;
	if(ch4 == NULL){
		return;
	}else{
		searchTrees(ch4, nLayer, searchLayer, fn);
	}
}

void freeNode(struct treeNode* node){
	if(node->parent != NULL){
		freeNode(node->parent);
	}
	if(node->child1 != NULL){
		freeNode(node->child1);
	}
	if(node->child2 != NULL){
		freeNode(node->child2);
	}
	if(node->child3 != NULL){
		freeNode(node->child3);
	}
	if(node->child4 != NULL){
		freeNode(node->child4);
	}
	free(node);
}

void freeTrees(struct FourTree * trees){
	if (trees->head != NULL){
		freeNode(trees->head);
	}
	free(trees);
}

void findSearchRange(double lat, double lon, struct treeNode *node, int pn, int layer, struct searchNodes* r_nodes){
	double px = cos(lat / 57.2957795) * cos(lon / 57.2957795);
	double py = cos(lat / 57.2957795) * sin(lon / 57.2957795);
	double pz = sin(lat / 57.2957795);
	
	double dist = getDistPP(px,py,pz,node->midPoint[0],node->midPoint[1],node->midPoint[2]);
	if (dist > node->radius){
		return;
	}
	if (pn == layer){
		r_nodes-> s_nodes[r_nodes->s_len] = node;
		r_nodes-> s_len ++;
		return;
	}
	pn ++;
	struct treeNode *ch1 = node->child1;
	if (ch1 == NULL){
		return;
	}
	findSearchRange(lat, lon, ch1, pn, layer,r_nodes);
	
	struct treeNode *ch2 = node->child2;
	if (ch2 == NULL){
		return;
	}
	findSearchRange(lat, lon, ch2, pn, layer, r_nodes);
	
	struct treeNode *ch3 = node->child3;
	if (ch3 == NULL){
		return;
	}
	findSearchRange(lat, lon, ch3, pn, layer, r_nodes);
	
	struct treeNode *ch4 = node->child4;
	if (ch4 == NULL){
		return;
	}
	findSearchRange(lat, lon, ch4, pn, layer, r_nodes);
}
