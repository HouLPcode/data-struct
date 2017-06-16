#ifndef _TREE_H_
#define _TREE_H_

#define elemType int

typedef struct BitNode{
	elemType elem;
	struct BitNode *left,*right;
}BitNode;

void preOrder(BitNode *T);
void inOrder(BitNode *T);
void inOrder2(BitNode *T);//�ǵݹ�
void postOrder(BitNode *T);
void levelOrder(BitNode *T);//��α���
//BitNode* creatTree(BitNode *&T);
BitNode* Insert(int x,BitNode *T);

#endif