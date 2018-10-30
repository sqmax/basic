#include<cstdio>

struct ComplexListNode{
	int value;
	ComplexListNode* next;
	ComplexListNode* sibling;
}; 

void cloneNodes(ComplexListNode* head){
	ComplexListNode* node=head;
	while(node!=NULL){
		ComplexListNode* cloned=new ComplexListNode;
		cloned->value=node->value;
		cloned->next=node->next;
		cloned->sibling=node->sibling;
		
		node->next=cloned;
		node=cloned->next;
	}
}
void connectSiblingNodes(ComplexListNode* head){
	ComplexListNode* node=head;
	while(node!=NULL){
		ComplexListNode* cloned=node->next;
		if(node->sibling!=NULL){
			cloned->sibling=node->sibling->next;
		}
		node=cloned->next;
	}
}
ComplexListNode* reconnectNodes(ComplexListNode* head){
	ComplexListNode* node=head;
	ComplexListNode* clonedHead=NULL;
	ComplexListNode* clonedNode=NULL;
	
	if(node!=NULL){
		clonedHead=clonedNode=node->next;
		node->next=clonedHead->next;
		node=node->next;
	}
	while(node!=NULL){
		clonedNode->next=node->next;
		clonedNode=clonedNode->next;
		node->next=clonedNode->next;
		node=node->next;
	}
	return clonedHead;
}

int main(){
	
	return 0;
}
