#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class listNode{
///Friend Class A friend class can access private and protected members of other class in which it is declared as friend. 

	friend class LLSTACK;
	friend class LLQ;
	public:
	int data;
	listNode * next;
	listNode( int d){
		data = d;	
		next=NULL;
	}

	
	
};
class LLSTACK{
	public:
	listNode * top;
	 LLSTACK(){
	 	top =NULL;
	 }
	 void push(listNode * newNode){
	 	listNode * temp  = newNode;
	 	if(isEmpty()){
	 		top = temp;
		 }
		 else {
	 	   temp->next = top;
	 	   top=temp;
		 }
		 
	 }
	 int pop(){
	 	if(isEmpty()){
	 		return 0;
		 }else{
		  int temp = top->data;
;		 listNode * tempNode = top->next;
		 top= tempNode;
		 
		 return temp;
		 }
	 }
	 
	 bool isEmpty(){
	 	return top==NULL;
	 }
	 
	 void print(){
	 	listNode * temp = top;
	 	cout<<"Elements in the stack: ";
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp = temp->next;
	}
	cout<<"Null"<<endl;
  cout<<endl;
    
    }
	
};
class LLQ{
	public:
		listNode* head;
		listNode* tail;
		LLQ(){
			listNode* dummy = new listNode(9999);
			head=dummy;
			tail=dummy;
			head=tail;
		}
		void addQ(listNode* newNode){
		     	tail->next=newNode;
		     	tail = newNode;
			 }
		
		int deleteQ(){
			if(isEmpty()){
				cout<<"no more element in the queue. except dummy ndoe"<<endl;
				return 0;
			}else{
			
			listNode *tempNode =head->next;
		  int temp = tempNode->data;
			head->next=head->next->next;
		
		 return temp;
	}
		}
		
		bool isEmpty(){
		 return head->next==NULL;
		}
		 void print(){
	 	listNode * temp = head;
	 	cout<<"Elements in the queue: ";
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp = temp->next;
	}
	cout<<"Null"<<endl;
  cout<<endl;
    
    }



};
int main(int argc, char** argv) {
	  char classType;
	  char stopflag;
	  int inputdata;
	  	char methodType;
	  	LLSTACK * s = new LLSTACK();
	  	LLQ * q = new LLQ();
    cout<<"select class types: S for stack and  Q for queue"<<endl;
    cin>> classType;
    if(classType=='S'){ 
    	cout<<" Stack operation has been choose"<<endl;	
	}else if ( classType =='Q'){
		cout<<" Queue operation has been choose"<<endl;
	} else{
	cout<<" invaild input option"<<endl;
	exit(0);
	}
	
	
	do{
	cout<<"select methods:  I - for insertion or D - for deletion"<<endl;
	cin>>methodType;
	if(methodType=='I'){
		cout<<"you selected insertion"<<endl;
		cout<<"enter any integer input"<<endl;
	cin>>inputdata;
	cout<<"you have entered "<<inputdata<<endl;
	listNode * newNode = new listNode(inputdata);
	if(classType =='S'){
		s->push(newNode);
		s->print();
	}
	else if(classType=='Q'){
		q->addQ(newNode);
		q->print();
	}
	
	}else if(methodType=='D'){
		cout<<"you select Deletion"<<endl;
		
		if(classType =='S'){
		cout<<"pop item "<<s->pop()<<endl;
		cout<<"remaining stack ";
		s->print();
		}else if(classType=='Q'){
			cout<<"delete Q"<<q->deleteQ()<<endl;
			cout<<" remaining  Q";
			q->print();
		}
		
	}else{
		cout<<" invaild input"<<endl;
		exit(0);
	}
		 cout<<"continue enter Y else enter N"<<endl;
	 cin>>stopflag;
	
}while(stopflag=='Y');
	return 0;
}
