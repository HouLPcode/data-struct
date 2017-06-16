#ifndef _TREE_H_
#define _TREE_H_

#define elemType int

typedef struct BitNode{
	elemType elem;
	struct BitNode *left,*right;
}BitNode;

void preOrder(BitNode *T);
void inOrder(BitNode *T);
void inOrder2(BitNode *T);//·ÇµÝ¹é
void postOrder(BitNode *T);
void levelOrder(BitNode *T);//²ã´Î±éÀú
//BitNode* creatTree(BitNode *&T);
BitNode* Insert(int x,BitNode *T);

#endif