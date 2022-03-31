/* Input: ??a vào 1 m?ng các ph?n t?. Và giá tr? x
Output: ??a ra k?t lu?n x có n?m trong m?ng. Và ??a ra m?ng ?ã s?p x?p.
Yêu c?u: Dùng BST */
#include<stdio.h>
#include<stdlib.h>
typedef int x;
struct Tnode { 
	char word[20];
	struct Tnode *Left;// con tro trai
	struct Tnode *Right;// con tro phai
	};
typedef struct Tnode* treeNode;//cay nhi phan

treeNode* makeTreeNode(char *word){
	treeNode* newNode = NULL;
	newNode = (treeNode *)malloc(sizeof(treeNode));// cap bo nho cho cay
	if(newNode == NULL){
		printf("Out of memory");
		exit(1);
		}
	else{
		newNode->Left = NULL;
		newNode-> Right = NULL;
		strcpy(newNode->word, word);
	}return newNode;
}
treeNode* createTree(treeNode *p, x){
	print("Node: ");
	scanf("%d",&x);
	if( x==0)return NULL;
		p=makeTreeNode(p,x);
		printf("Enter Left node %d: ",x);
		p->Left= createTree(p->Left,x);
		printf("Enter Right node %d: ",x);
		p->Right= createTree(p->Right,x);
	return p;
}
void printfInorder(treeNode *tree){
	if(tree != NULL){
		printfInorder(tree->Left);
		printf("%s\n",tree->word);
		printInorder(tree->Right);
	}
}
treeNode* searchKey(treeNode *T, float x){
	treeNode p;
	if (T->key==x) return T;
	if (T==NULL)return NULL;
	p=searchKey(T->Left,x);
	if(p==NULL) searchKey(T->Right,x);
}
treeNode* delete(treeNode *T, float x){
	treeNode tmp;
	if(T==null)
		printf("Not found x!");
	else if (x < T->key)// duyet ben trai 
		T->Left = delete(T->Left,x);
	else if (x>T->key)// duyet ben phai
		T->Right = delete(T->Right,x);
	else //tim duoc phan tu can xoa
		if(T->Left && T->Right){//phan tu the cho la phan tu min o cay con phai
			tmp = find_min(T->Right);
			T->key = tmp->key;
			T->Right = delete(T->Right);
		}	
	else {
		//co 1 hoac ko co con
		tmp = T;
		if(T->Left == NULL)//chi co con phai hoac khong co con
			T = T->Right;
		else 
			if(T->Right ==NULL)// chi co con trai hoac ko co con
				T =T->Left;
		free(tmp);
	}	
	return (T);		
}
int main(){
	treeNode T;
	T==NULL;//Tao cay rong
	treeNode *p=NULL;x;
	printf("Enter 0 to switch to another node or exit.");
	T=createTree(p,x);//Nhap cay
	printf("Sort array:\n");
	printInorder(T);
	treeNode *P;
	printf("Enter key to search:");
	scanf("%d",&x);
	P= searchKey(T,x);
	if(P!= NULL) printf("Found Key!\n");
	else printf("Not found Key!\n");
	
	if(delete (T,x)) printf ("Delete successful!\n");
	else{ printf("Not found key to delete!\n");
	printf("Sort array:\n");
	printInorder(T);	
}
return 0;
}

