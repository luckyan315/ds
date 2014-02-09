#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
using namespace std;

#define OK 0
#define ERROR -1

/* huffman tree node */
typedef struct _HTNode {
	int weight;
	int parent;
	int lChild;
	int rChild;
}HTNode, *HuffmanTree;

typedef char** HuffmanCode;

/**
 * Encoding huffman tree
 * @param {HuffmanTree*} pHT pointer of huffman tree
 * @param {HuffmanCode*} pHC pointer of huffman code
 * @param {int*} arrW save the weight value of every node
 * @param {int} n the number of the chars to be encoded
 * @return {void}
 */
bool huffmanCoding(HuffmanTree * pHT, HuffmanCode * pHC, const int *arrW, const int n);

void selectMins(HuffmanTree * pHT, int iRange, int& s1, int& s2);

void print(const char * pIn, const int n);
void printHuffmanTree(const HuffmanTree *pTree, const int n);
int compare(const void * a, const void * b);

int main(int argc, char* argv[])
{
	freopen("./input.txt", "r", stdin);

	int n = 0;
	char * pIn = NULL;
	int * arrW = NULL; /* save the weight of nodes */
	HuffmanTree ht;
	HuffmanCode hc;
	
	std::cin>>n;
	pIn = new char[n+1];
	pIn[n] = '\0';
	
	for (int i = 0; i < n; ++i)
	{
		std::cin>>pIn[i];
	}

	arrW = new int[n+1];
	arrW[n] = 0;
	for (int i = 0; i < n; ++i)
	{
		std::cin>>arrW[i];
	}

	std::cout<<"Creating Huffman tree:"<<std::endl;
	if(-1 == huffmanCoding(&ht, &hc, arrW, n))
	{
		std::cout<<"Encoding huffman tree occur error!"<<std::endl;
		delete [] pIn;
		delete [] arrW;

	return 0;
		
	}

	printHuffmanTree(&ht, n);

	std::cout<<"Result of huffman encoding:"<<std::endl;
	for (int i = 0; i < n; ++i)
	{
		std::cout<<"["<<pIn[i]<<"]:";
		char * pCh = hc[i];
		while(*pCh){
			std::cout<<*pCh++;
		}
		std::cout<<std::endl;
	}
	
	delete [] pIn;
	delete [] arrW;

	return 0;
}

bool huffmanCoding(HuffmanTree* pHT, HuffmanCode * pHC, const int * arrW, const int n)
{
	/* leaf numbers */
	int nHT = 2 * n - 1;
	int iStart = n;
	int s1 = 0;
	int s2 = 0;
	char * pCode = NULL;
	
	*pHT = new HTNode[nHT];
	*pHC = (char**) new char* [n];
	
	//set the huffman tree nodes
	for(int i = 0; i < n; ++i)
	{
		(*pHT)[i].weight = arrW[i];
		(*pHT)[i].parent = -1;
		(*pHT)[i].lChild = -1;
		(*pHT)[i].rChild = -1;
	}

	
	//set the extra leaf nodes
	for (int i = n; i < nHT; ++i)
	{
		(*pHT)[i].weight = 0;
		(*pHT)[i].parent = -1;
		(*pHT)[i].lChild = -1;
		(*pHT)[i].rChild = -1;
		
	}

	for (int i = iStart; i < nHT; ++i)
	{
		selectMins(pHT, i, s1, s2);
		// std::cout<<"i="<<i<<" "<<"s1="<<s1<<" "<<"s2="<<s2<<std::endl;
		
		(*pHT)[s1].parent = i;
		(*pHT)[s2].parent = i;
		(*pHT)[i].lChild = s1;
		(*pHT)[i].rChild = s2;
		(*pHT)[i].weight = (*pHT)[s1].weight + (*pHT)[s2].weight;
	}

	//TODO: huffman encoding...
	
	for (int i = 0; i < n; ++i)
	{
		int iParent = (*pHT)[i].parent;
		int iEnc = i; // index of encoding char
		int iCode = n - 1; //index of pCode
		
		pCode = new char[n];
		pCode[n-1] = '\0';
		
		//recursive visit until met the root node
		while(iParent != -1)
		{
			if((*pHT)[iParent].lChild == iEnc)
			{
				pCode[iCode--] = '0';
			}
			else if ((*pHT)[iParent].rChild == iEnc)
			{
				pCode[iCode--] = '1';
			}
			else
			{
				return ERROR;
			}

			iEnc = iParent;
			iParent = (*pHT)[iParent].parent;
		}

		// print(pCode, n);

		int nEncWidth = n - iCode - 1;
		(*pHC)[i] = new char[nEncWidth + 1];
		(*pHC)[i][nEncWidth] = '\0';
		strncpy((*pHC)[i], pCode + n - nEncWidth, nEncWidth * sizeof(char));
		// print((*pHC)[i], nEncWidth);
		delete [] pCode;
	}

	return OK;
}

void selectMins(HuffmanTree* pHT, int iRange, int& s1, int& s2)
{
	s1 = iRange - 1;
	s2 = iRange - 1;

	for (int i = 0; i < iRange ; ++i)
	{
		if ((*pHT)[i].parent == -1)
		{
			if ((*pHT)[i].weight < (*pHT)[s1].weight)
			{
				s1 = i;
			}
			else if ((*pHT)[i].weight < (*pHT)[s2].weight)
			{
				s2 = i;
			}

		}
	}
}

int compare(const void * a, const void * b)
{
	return ((HTNode*)a)->weight - ((HTNode*)b)->weight;
}

void print(const char * pIn, const int n)
{
	for (int i = 0; i < n; ++i)
	{
		std::cout<<*pIn++<<" ";
	}
	std::cout<<std::endl;
}

void printHuffmanTree(const HuffmanTree *pTree, const int n)
{
	for (int i = 0; i < 2 * n - 1; ++i)
	{
		std::cout<<"["<<i<<"]:"<<
			" weight: "<<(*pTree)[i].weight<<" "<<
			"parent: "<<(*pTree)[i].parent<<" "<<
			"lChild: "<<(*pTree)[i].lChild<<" "<<
			"rChild: "<<(*pTree)[i].rChild<<std::endl;
	}
	std::cout<<std::endl;
}
