#include <cstdio>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

#define OK 0
#define ERROR -1

typedef char TElemType;
typedef struct BiTreeNode {
	TElemType           data;
	struct BiTreeNode   *parent; /* pointer of parent */
	struct BiTreeNode   *lChild; /* pointer of left child */
	struct BiTreeNode   *rChild; /* pointer of right child */
}BiTreeNode, *PBiTreeNode;

const int MAX_NODE = 10;

int initBiTree(PBiTreeNode* pTree);
int createBiTree(PBiTreeNode* pTree);
int create(PBiTreeNode* pTree);
int deleteBiTree(PBiTreeNode* pTree);
int getBiTreeDepth(const PBiTreeNode pRoot);

int preOrder(const PBiTreeNode* pTree, void (* visit)(const PBiTreeNode /*pNode*/));
int inOrder(const PBiTreeNode* pTree, void (* visit)(const PBiTreeNode /*pNode*/));
int postOrder(const PBiTreeNode* pTree, void (* visit)(const PBiTreeNode /*pNode*/));

void visit(const PBiTreeNode pNode);

int main(int argc, char *argv[])
{
	std::cout<<"BiTree Demo App for console"<<std::endl;

	freopen("./input.txt", "r", stdin);
	
	PBiTreeNode pBiTree[MAX_NODE];
	initBiTree(pBiTree);
	createBiTree(pBiTree);

	std::cout<<"The depth of the tree: "<<getBiTreeDepth(*pBiTree)<<std::endl;

	std::cout<<"Pre Order sequence: ";
	preOrder(pBiTree, visit);
	std::cout<<std::endl;


	std::cout<<"InOrder sequence: ";
	inOrder(pBiTree, visit);
	std::cout<<std::endl;

	//delete bi tree
	deleteBiTree(pBiTree);

	return 0;
}

int initBiTree(PBiTreeNode* pTree)
{
	*pTree = NULL;
	return OK;
}

int createBiTree(PBiTreeNode* pTree)
{
	std::queue<PBiTreeNode> que;
	PBiTreeNode  pTmpNode;

	//create bi tree, but no parent pointer
	int ret = create(pTree);
	if(ret == ERROR)
	{
		std::cout<<"create bitree occur error!"<<std::endl;
		return ERROR;
	}

	//set the parent node
	if(*pTree)
	{
		//enque root node
		que.push(*pTree);

		while(!que.empty())
		{
			pTmpNode = que.front();
			que.pop();

			if (pTmpNode->lChild)
			{
				pTmpNode->lChild->parent = pTmpNode;
				que.push(pTmpNode->lChild);
			}
			if (pTmpNode->rChild)
			{
				pTmpNode->rChild->parent = pTmpNode;
				que.push(pTmpNode->rChild);
			}
		}

	}
	return OK;
}

int create(PBiTreeNode* pTree)
{
	TElemType ch;
	std::cin>>ch;

	//leaf node end with '#'
	if (ch == '#')
	{
		*pTree = NULL;
	}
	else
	{
		*pTree =  new BiTreeNode();
		if(*pTree == NULL)
		{
			std::cout<<"Heap over flow!"<<std::endl;
			return ERROR;
		}
		//set data
		(*pTree)->data = ch;
		
		create(&(*pTree)->lChild);
		create(&(*pTree)->rChild);

	}

	return OK;
}

int deleteBiTree(PBiTreeNode* pTree)
{
	//TODO:
}

int getBiTreeDepth(PBiTreeNode pRoot)
{
	int nLeft = 0;
	int nRight = 0;

	if(!pRoot)
	{
		return 0;
	}

	if(pRoot->lChild)
	{
		nLeft = getBiTreeDepth(pRoot->lChild);
	}

	if(pRoot->rChild)
	{
		nRight = getBiTreeDepth(pRoot->rChild);
	}

	return nLeft > nRight ? nLeft + 1 : nRight + 1;
}

int preOrder(const PBiTreeNode* pTree, void (* visit)(const PBiTreeNode /* pNode */))
{
	if(*pTree)
	{
		visit(*pTree);
		if(preOrder(&(*pTree)->lChild, visit) == OK)
		{
			if(preOrder(&(*pTree)->rChild, visit) == OK)
			{
				return OK;
			}
		}
		return ERROR;
	}
	else
	{
		return OK;
	}
}

int inOrder(const PBiTreeNode* pTree, void (* visit)(const PBiTreeNode /* pNode */))
{
	//TODO:
	if(*pTree)
	{
		if(inOrder(&(*pTree)->lChild, visit) == OK)
		{
			visit(*pTree);
			if(inOrder(&(*pTree)->rChild, visit) == OK)
			{
				return OK;
			}
		}
		return ERROR;
	}
	else
	{
		return OK;
	}
}

int postOrder(const PBiTreeNode* pTree, void (* visit)(const PBiTreeNode /* pNode */))
{
	//TODO:
	
}

void visit(const PBiTreeNode pNode)
{
	//TODO:
	std::cout<<pNode->data<<" ";
}
