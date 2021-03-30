//trie data structure

#include<stdio.h>
#include<stdlib.h>
#define CHAR_SIZE 26

//structure
struct Trie{
	int isLeaf;
	struct Trie *character[CHAR_SIZE];
};

//new node
struct Trie * GetNewNode(){
	struct Trie *node=(struct Trie *)malloc(sizeof(struct Trie));
	node->isLeaf=0;
	
	for(int i=0;i<CHAR_SIZE;i++)
	node->character[i]=nullptr;
}

//insertion in trie data structure
void Insert(struct Trie *head,char *str){
	struct Trie *curr=head;
	while(*str){
		if(curr->character[*str-'a']==nullptr){
			curr->character[*str-'a']=GetNewNode();
		}
		curr=curr->character[*str-'a'];
		str++;
	}
	curr->isLeaf=1;
}

//search function
int Search(struct Trie *head,char *str){
	if(head==nullptr){
		return 0;
	}
	struct Trie *curr=head;
	while(*str){
		if(curr->character[*str-'a']==nullptr){
			return 0;
		}
		curr=curr->character[*str-'a'];
		str++;
	}
	return curr->isLeaf;
}

//function to find children 
int HaveChildren(struct Trie *curr){
	for(int i=0;i<CHAR_SIZE;i++){
		if(curr->character[i]){
			return 1;
		}
	}
	return  0;
}

//Deletion in Trie data structure
int Deletion(struct Trie **curr,const char *str){
	if(*curr==nullptr)
		return 0;
	if(*str){
		if(*curr!=nullptr && (*curr)->character[*str-'a'] && Deletion(&(*curr)->character[*str-'a'],str+1) && (*curr)->isLeaf==0){
			if(!HaveChildren(*curr)){
				free(*curr);
				(*curr)=nullptr;
				return 1;
			}
			else{
				return 0;
			}
		}
	}
	if(*str=='\0' && (*curr)->isLeaf){
		if(!HaveChildren(*curr)){
			free(*curr);
			(*curr)=nullptr;
			return 1;
		}
		else{
			(*curr)->isLeaf=0;
			return 0;
		}
	}
	return 0;
}

//main body
int main(){
	struct Trie *head=GetNewNode();
	Insert(head,"hello");
	printf("%d",Search(head,"hell"));
	printf("%d",Deletion(&head,"hello"));
	printf("%d",Search(head,"hello"));
}
