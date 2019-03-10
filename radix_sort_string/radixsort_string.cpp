#include <iostream>
#include <fstream>
#include<string>
#include<cmath>
#include<cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class node{
	friend class stack;
	friend class queue;
	friend class radixSort;
	string data;
	node* next;
	node(string d){
		data =d;
		next =NULL;
	}
	string toString(){
		 string s = "";
		 if(next==NULL){
		 	s= s+ "( " + data + " -->NULL )" ;
		 }else{
		 	s= s +"( " + data + " , " + next->data+ " )";
		 }
		 return s;
	}
};

class stack{
	friend class radixSort;
	  node * top ;
     stack(){
     	top =NULL;
	 }
	 void push(node* newNode){
	 	  if(top==NULL){
	 	  	top =newNode;
		   }else{
		   	newNode->next=top;
		   	top=newNode;
		   }
	 }
	node *pop(){
		if(top==NULL){
			cout<<"stack is empty"<<endl;
		}else{
			node* temp = top;
			top = top->next;
			temp->next =NULL;
			return temp;
		}
	}
	bool isEmpty(){
		return (top==NULL);
	}
    void printStack(ofstream &out2){
    	  cout<<"*** Below is the output of the stack***"<<endl;
    	  out2<<"*** Below is the output of the stack***"<<endl;
    	  cout<<"Top";
    	  out2<<"Top";
    	 node* temp = top;
    	 while(temp!=NULL){
    	 	cout<< temp->toString()<<"--->";
    	 	out2<< temp->toString()<<"--->";
    	 	temp=temp->next;
		 }
		 cout<<"-->NULL"<<endl;
		 out2<<"-->NULL"<<endl;
		 cout<<endl;
		 out2<<endl;
	}
};
class queue{
	friend class radixSort;
	node* head,*tail,*dummy;
	 queue(){
	 
	 	head =tail =dummy=NULL;
	 }
	bool isEmpty(){
		return (head==NULL);
	}
	void addTail(node* newNode){
		if(isEmpty()){
			tail =newNode;
			head= tail;
		}else{
		
		tail->next =newNode;
		tail = newNode;
	}
	}
    node* deleteHead(){
	      node* temp = head;
        if(head == tail) 
		{
		head = tail = NULL;
	}
        else {
		head = head->next;
    }
    temp->next=NULL;
    return temp;
	}
   void printQueue(ofstream & out2){
   	    cout<<"Front";
   	    out2<<"Front";
   	    node* temp = head;
   	  	while(temp!=NULL){
			cout<<"--> "<<temp->toString(); 
			out2<<"--> "<<temp->toString(); 
			temp=temp->next;
		}
		cout<<"--> NULL"<<endl;
		out2<<"--> NULL"<<endl;
 		temp =tail;
		cout<<"Tail:";
		out2<<"Tail:";
	  while(temp!=NULL){
        	cout<<" ----> " << temp->toString();
            out2<<" ----> " << temp->toString();
            temp = temp->next;
        }
        cout<< " ----> NULL" << endl;
        out2<< " ----> NULL" << endl;
	}
};
 class radixSort{
 	friend class queue;
 		int tableSize,currentTable,previousTable,longestStringLength,currentPosition;
 		string data;
 		stack *s;
 		queue ** hashTable;
 			public:
 		radixSort(){
 			tableSize =256;
 			data="";
 			currentTable=0;
 			previousTable=1;
 			longestStringLength=0;
 			currentPosition=1;
 			s = new stack();
 			hashTable = new queue*[2];
 			for(int i=0;i<2;i++){
 				hashTable[i]= new queue[tableSize];
			 }
			 for(int i=0;i<2;i++)
			for( int j=0; j<tableSize;j++)
			hashTable[i][j]= queue();

			 
		 }
		 void firstReading(ifstream &in){
		    string s=""; 
		    while(in.good()){
		      in>>s;
		       if(!in.eof()){
		       	 //cout<<s.length()<<endl;
		       	   if(s.length()>longestStringLength)
		       	   {
		       	      longestStringLength =s.length();
					}
			   }
			}
		}
		string paddedData(string s){
			if(s.length()<longestStringLength){
				int difference = longestStringLength -s.length();
				for(int i=0; i<difference;i++){
					s=" "+s;
				}
				} 
				return s;
			}
		
		void loadStack(ifstream & in,ofstream &out2){
	
			while(in.good()){
				in>>data;
				if(!in.eof()){
			   node* n=new node(paddedData(data));
			  s->push(n);
			}
			}
			s->printStack(out2);
		
		}
			char getChar(string ss){
			int dex = longestStringLength -currentPosition;
			char c = ss.at(dex);
			return c;
		}
	
		void dumpStack(ofstream & out2){
			char oneChr; int hashIndex;
			node* temp;
			while(!s->isEmpty()){
			 temp =s->pop();
			 string s = temp->data;
				oneChr = getChar(s);
		 	hashIndex =(int)oneChr;
		 	hashTable[currentTable][hashIndex].addTail(temp); 
		} 
		hashTable[currentTable][hashIndex].printQueue(out2);
		   
}
 void sort(ofstream & out1,ofstream &out2){
 	dumpStack(out2);
     currentPosition++;
 	while(currentPosition<=longestStringLength){
 		  int temp = currentTable;
 		  currentTable = previousTable;
 		  previousTable =temp;
 		  for(int i=0; i<tableSize;i++){
 		  	  while(hashTable[previousTable][i].head!=NULL){
 		  	  	 node * temp =hashTable[previousTable][i].deleteHead();
 		  	  	 string s = temp->data;
 		  	  	 char c =getChar(s);
 		  	  	 int hashIndex =(int)c;
 		  	  	 hashTable[currentTable][hashIndex].addTail(temp);
				 }
		   }
		   printTable(out2);
			currentPosition++;
	 }
	  getSortedData(out1);
 }
 void printTable(ofstream &out){
        out <<"The hash table "<<endl;
        cout<<"The hash table "<<endl;
        for(int i = 0; i< tableSize; i++){
            if(hashTable[currentTable][i].head!=NULL){
                out << "Table index  [" << to_string(currentTable) << "][" << to_string(i) <<"]: ";
                cout<< "Table index [" << to_string(currentTable) << "][" << to_string(i) <<"]: ";
                hashTable[currentTable][i].printQueue(out);
            }
        }
    }

    void getSortedData(ofstream &out){
    	cout<<"The sorted result"<<endl;
    	out<<"The sorted result"<<endl;
        for(int i = 0; i<tableSize; i++){
            while(!hashTable[currentTable][i].isEmpty()){
               node *temp = hashTable[currentTable][i].deleteHead();
                out << temp->data << " >>> ";
                cout<<temp->data<< " >>> ";
            }
        }
    }
 };


int main(int argc, char** argv) {
	
	ifstream inFile;
	ofstream outFile1, outFile2;
	inFile.open(argv[1]);
	outFile1.open(argv[2]);
	outFile2.open(argv[3]);
	radixSort *s = new radixSort();
	s->firstReading(inFile);
	inFile.close();
	inFile.open(argv[1]);
	s->loadStack(inFile,outFile2);
	s->sort(outFile1,outFile2);
	inFile.close();
	outFile1.close();
	outFile2.close();
				return 0;
	}
