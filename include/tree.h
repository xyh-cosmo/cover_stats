#include <stdlib.h>
#include <stdio.h>

#ifndef _TREE4_H_
#define _TREE4_H_

struct treeNode{
	struct treeNode* parent;
	struct treeNode* child1;
	struct treeNode* child2;
	struct treeNode* child3;
	struct treeNode* child4;
	
	int band[10];
	double midPoint[3];
	double radius;
};

struct FourTree{
	struct treeNode *head;
	int layer;
};


struct searchNodes{
	struct treeNode* s_nodes[20000];
	int s_len;
};

void divideIterate(struct Rectangle rect, int pn,int layer, struct treeNode *tn);
void searchTrees(struct treeNode* node, int nLayer, int searchLayer, FILE* fn);
void freeNode(struct treeNode* node);
void freeTrees(struct FourTree * trees);
void findSearchRange(double lat, double lon, 
					 struct treeNode *node, 
					 int pn, 
					 int layer, 
					 struct searchNodes* r_nodes );


#endif
