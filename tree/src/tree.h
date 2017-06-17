#ifndef _TREE_H_
#define _TREE_H_

#define elemType int

typedef struct BitNode{
	elemType elem;
	struct BitNode *left,*right;
}BitNode;

void preOrder(BitNode *T);
void preOrder2(BitNode *T);
void inOrder(BitNode *T);
void inOrder2(BitNode *T);//�ǵݹ�
void postOrder(BitNode *T);
void postOrder2(BitNode *T);
void levelOrder(BitNode *T);//��α���
//BitNode* creatTree(BitNode *&T);
int get_hight(BitNode *T);

//����������
BitNode* BST_insert(BitNode *T, elemType x);
BitNode* BST_delete(BitNode *T, elemType x);
BitNode* BST_find(BitNode *T, elemType x);
BitNode* BST_find2(BitNode *T, elemType x);
BitNode* BST_findMin(BitNode *T);

#endif