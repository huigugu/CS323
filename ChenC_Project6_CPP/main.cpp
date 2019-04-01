#include <iostream>
#include<fstream>
#include<String>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class runLengthEncode{
	public:
	 int startRow,startCol,pixelVal,length, currentRow, currentCol,methodNum,currentVal, maxRow,maxCol,nextVal,count,numberRun;
	 runLengthEncode(int maxR,int maxC){
	 	maxRow=maxR;
	 	maxCol=maxC;
	 	startRow=0;
	 	startCol=0;
	 	pixelVal=0;
	 	length=0;
	 	currentRow=0;
	 	currentCol=0;
	 	currentVal=0;
	 	nextVal=0;
	 	count=0;
	 	numberRun=0;
	 
	 }

	 void method1(ifstream & image,ofstream& out1,ofstream &encodeFile){
	 	numberRun=0;
	 	//Method 1) with zero and not wrap-around.
	 	while(image.good()&&startRow<maxRow){
	 		count=0; 
	 		image>>currentVal;
	 		count++;
	 		startCol=0;
		 cout<<" "<<startRow<<" "<<startCol<<" "<<currentVal;
		 encodeFile<<" "<<startRow<<" "<<startCol<<" "<<currentVal;
		 	numberRun++;
	 	    while(startCol<maxCol-1){
	 	    	image>>nextVal;
	 	    	startCol++;
	 	    if(nextVal==currentVal){
	 	    	count++;
	 	    	if(startCol==maxCol-1){
	 	    		encodeFile<<" "<<count<<endl;
	 	    		cout<<" "<<count<<endl;
				 }
			 }else{
			 	cout<<" "<<count<<endl;
			 	encodeFile<<" "<<count<<endl;
			 	count=1;
			 	currentVal=nextVal;
			 	cout<<" "<<startRow<<" "<<startCol<<" "<<currentVal;
			 	encodeFile<<" "<<startRow<<" "<<startCol<<" "<<currentVal;
			 		numberRun++;
		
			 }
			 
			 }
			 
	 	    startRow++;
	 	   	
		 }
		 out1<<numberRun<<" runs produced in Run-Length encoding"<<endl;
		 out1<<numberRun*4*4<<" bytes used without counting the image header"<<endl;
	 }
	 void method2(ifstream & image,ofstream& out1,ofstream &encodeFile){
	 	//"Method 2) Not zero and not wrap-around
	 	numberRun=0;
	 	while(image.good()&&startRow<maxRow){
	 	    count=0;
	 		startCol=0;
	 		image>>currentVal;
	 		while(currentVal==0&&startCol<maxCol-1){
	 			image>>currentVal;
	 			startCol++;
		}
			if(currentVal!=0){
			 count++;
			 	cout<<" "<<startRow<<" "<<startCol<<" "<<currentVal;
			 	encodeFile<<" "<<startRow<<" "<<startCol<<" "<<currentVal;
			 		numberRun++;
			 }
			  while(startCol<maxCol-1){
	 	    	image>>nextVal;
	 	    	startCol++;
	 	
	 	    if(nextVal==currentVal){
	 	    	count++;
	 	    	if(startCol==maxCol-1){
	 	    		cout<<" "<<count<<endl;
	 	    		encodeFile<<" "<<count<<endl;
				 }
			 }else{
			 	cout<<" "<<count<<endl;
			 	encodeFile<<" "<<count<<endl;
			 		while(nextVal==0&&startCol<maxCol-1){
	 	    		image>>nextVal;
	 	    		startCol++;
				 }
			 	count=1;
			 	currentVal=nextVal;
			 	if(nextVal!=0){
			 	cout<<" "<<startRow<<" "<<startCol<<" "<<currentVal;
			 	encodeFile<<" "<<startRow<<" "<<startCol<<" "<<currentVal;
			 	numberRun++;
	}
			 }		 
			 }			 
	 	    startRow++;		  	
}
out1<<numberRun<<" runs produced in Run-Length encoding"<<endl;
		 out1<<numberRun*4*4<<" bytes used without counting the image header"<<endl;
}
	 void method3(ifstream & image,ofstream& out1,ofstream &encodeFile){
	 //Method 3) with zero and wrap-around. 
	 numberRun=0;
	 	  nextVal =-1;
	        while(image.good()){
	        	startCol=0;
	           image>>currentVal;
	           if(image.eof()){	
	encodeFile<<" "<<count<<endl;	   	
	cout<<" "<<count<<endl;
			  }	
	           if(currentVal!=nextVal){
	           	 if(nextVal>=0){
				encodeFile<<" "<<count<<endl;
	           	cout<<" "<<count<<endl;
	           }
	           	 count=1;
	           	 encodeFile<<" "<<startRow<<" "<<startCol<<" "<<currentVal;
	            cout<<" "<<startRow<<" "<<startCol<<" "<<currentVal;
	            numberRun++;
	}else
		{
			count++;
		}
	      
			  while(startCol<maxCol-1){
				image>>nextVal;
				startCol++;
				if(nextVal==currentVal){
					count++;	
		
				}else{
					encodeFile<<" "<<count<<endl;
					cout<<" "<<count<<endl;
				
					count=1;
					currentVal=nextVal;
					 cout<<" "<<startRow<<" "<<startCol<<" "<<currentVal;
					 encodeFile<<" "<<startRow<<" "<<startCol<<" "<<currentVal;
					 numberRun++;
					
					
				}
			}
			startRow++;
		}
		out1<<numberRun<<" runs produced in Run-Length encoding"<<endl;
		 out1<<numberRun*4*4<<" bytes used without counting the image header"<<endl;
	 }
	 void method4(ifstream & image,ofstream& out1,ofstream &encodeFile){
	 	//"Method 4) Not  zero and wrap-around.
	 	nextVal=0;
	 	count=0;
	 	numberRun=0;
	  	while(image.good()){
	  		startCol=0;
	  		image>>currentVal;
	  		while(currentVal==0&&startCol<maxCol-1){
	  			image>>currentVal;
	  			startCol++;
			  }
			  
			  if(currentVal!=nextVal){
			  	     if(nextVal>0&&currentVal!=0){
			      	encodeFile<<" "<<count<<endl;
			 		cout<<" "<<count<<endl;
			 	}
			 	if(currentVal!=0){
				 
			   	count=1;
	           	 encodeFile<<" "<<startRow<<" "<<startCol<<" "<<currentVal;
	            cout<<" "<<startRow<<" "<<startCol<<" "<<currentVal;
	            numberRun++;
	        }
				}else{
					count++;
				}
				while(startCol<maxCol-1){
					image>>nextVal;
					startCol++;
					if(nextVal==currentVal){
						count++;
					}else{	

				encodeFile<<" "<<count<<endl;
	           	cout<<" "<<count<<endl;
	    
	           while(nextVal==0&&startCol<maxCol-1)
	           {
	           	image>>nextVal;
	           	startCol++;
			   }
			   if(nextVal!=0){
	           	count=1;
	           	currentVal=nextVal;
	           	 encodeFile<<" "<<startRow<<" "<<startCol<<" "<<currentVal;
	            cout<<" "<<startRow<<" "<<startCol<<" "<<currentVal;
	            numberRun++;
					}
					}
					
				}
				startRow++;
	  		
		  }
		
		
			
		
		 out1<<numberRun<<" runs produced in Run-Length encoding"<<endl;
		 out1<<numberRun*4*4<<" bytes used without counting the image header"<<endl;
		 }
	 	 
};
class runLengthDecode{
	public:
	int startRow,startCol,pixelVal,length,numRows, numCols, minVal, maxVal;
	runLengthDecode(){
		startRow=0;
		startCol=0;
		pixelVal=0;
		numRows=0;
		numCols=0;
		length=0;
		minVal=0;
		maxVal=0;
	}
	void decodeMethod1(ifstream &encodeFile, ofstream & decodeFile ){
		//	int count=0;
		if(encodeFile.good()){
			encodeFile>>numRows;
			encodeFile>>numCols;
			encodeFile>>minVal;
			encodeFile>>maxVal;
			cout<<"***decode image header***"<<endl;
			cout<<numRows<<" "<<numCols<<" "<<minVal<<" "<<maxVal<<" "<<endl;
			decodeFile<<"***decode image header***"<<endl;
				decodeFile<<numRows<<" "<<numCols<<" "<<minVal<<" "<<maxVal<<" "<<endl;
		}
		
		 int image[numRows][numCols]={0};
		 for(int i=0;i<numRows;i++){
			for(int j=0;j<numCols;j++){
				image[i][j]=0;			
		}
		}
		while(encodeFile.good()){
			encodeFile>>startRow;
			encodeFile>>startCol;
			encodeFile>>pixelVal;
			encodeFile>>length;
			if(!encodeFile.eof()) {
			
	    for(int i=0;i<length;i++){
	    	image[startRow][startCol++]=pixelVal;
		}
	}
}
	    int count=0;
		for(int i=0;i<numRows;i++){
			for(int j=0;j<numCols;j++){
				cout<<image[i][j]<<" ";
				decodeFile<<image[i][j]<<" ";
		}
		cout<<endl;	
		decodeFile<<endl;	
}
}
	void decodeMethod2(ifstream &encodeFile, ofstream & decodeFile ){
				if(encodeFile.good()){
			encodeFile>>numRows;
			encodeFile>>numCols;
			encodeFile>>minVal;
			encodeFile>>maxVal;
			cout<<"***decode image header***"<<endl;
			cout<<numRows<<" "<<numCols<<" "<<minVal<<" "<<maxVal<<" "<<endl;
			decodeFile<<"***decode image header***"<<endl;
				decodeFile<<numRows<<" "<<numCols<<" "<<minVal<<" "<<maxVal<<" "<<endl;
		}
		
		 int image[numRows][numCols]={0};
		 for(int i=0;i<numRows;i++){
			for(int j=0;j<numCols;j++){
				image[i][j]=0;			
		}
		}
		while(encodeFile.good()){
		
			
			encodeFile>>startRow;
			encodeFile>>startCol;
			encodeFile>>pixelVal;
			encodeFile>>length; 
				if(!encodeFile.eof()){
	    for(int i=0;i<length;i++){
	    	image[startRow][startCol++]=pixelVal;
		}
		}
	}
	
	
		for(int i=0;i<numRows;i++){
			for(int j=0;j<numCols;j++){
				cout<<image[i][j]<<" ";
				decodeFile<<image[i][j]<<" ";
		}
		cout<<endl;	
		decodeFile<<endl;	
}
}
	void decodeMethod3(ifstream &encodeFile, ofstream & decodeFile ){
				if(encodeFile.good()){
			encodeFile>>numRows;
			encodeFile>>numCols;
			encodeFile>>minVal;
			encodeFile>>maxVal;
			cout<<"***decode image header***"<<endl;
			cout<<numRows<<" "<<numCols<<" "<<minVal<<" "<<maxVal<<" "<<endl;
			decodeFile<<"***decode image header***"<<endl;
				decodeFile<<numRows<<" "<<numCols<<" "<<minVal<<" "<<maxVal<<" "<<endl;
		}
			 int image3[numRows][numCols]={0};
		 for(int i=0;i<numRows;i++){
			for(int j=0;j<numCols;j++){
				image3[i][j]=0;			
		}
		}
		
		  while(encodeFile.good()){
	    encodeFile>>startRow;
	    encodeFile>>startCol;
	    encodeFile>>pixelVal;
	    encodeFile>>length;
	    if(!encodeFile.eof()){
	     
	     	for(int i=0; i<length;i++){
	     		if(startCol<numCols){
	     	image3[startRow][startCol++]=pixelVal;
			 }else{
			 	startRow++;
			 	startCol=0;
			 	image3[startRow][startCol++]=pixelVal;
			 }	
}		 
}	    
}
	for(int i=0;i<numRows;i++){
			for(int j=0;j<numCols;j++){
				cout<<image3[i][j]<<" ";
				decodeFile<<image3[i][j]<<" ";
		}
		cout<<endl;	
		decodeFile<<endl;	
}
	
				
		
	}
	void decodeMethod4(ifstream &encodeFile, ofstream & decodeFile ){
			if(encodeFile.good()){
			encodeFile>>numRows;
			encodeFile>>numCols;
			encodeFile>>minVal;
			encodeFile>>maxVal;
			cout<<"***decode image header***"<<endl;
			cout<<numRows<<" "<<numCols<<" "<<minVal<<" "<<maxVal<<" "<<endl;
			decodeFile<<"***decode image header***"<<endl;
				decodeFile<<numRows<<" "<<numCols<<" "<<minVal<<" "<<maxVal<<" "<<endl;
		}
			 int image4[numRows][numCols]={0};
		 for(int i=0;i<numRows;i++){
			for(int j=0;j<numCols;j++){
				image4[i][j]=0;			
		}
		}
		 while(encodeFile.good()){
	    encodeFile>>startRow;
	    encodeFile>>startCol;
	    encodeFile>>pixelVal;
	    encodeFile>>length;
	    if(!encodeFile.eof()){
	     
	     	for(int i=0; i<length;i++){
	     		if(startCol<numCols){
	     	image4[startRow][startCol++]=pixelVal;
			 }else{
			 	startRow++;
			 	startCol=0;
			 	image4[startRow][startCol++]=pixelVal;
			 }	
}		 
}	    
}
	for(int i=0;i<numRows;i++){
			for(int j=0;j<numCols;j++){
				cout<<image4[i][j]<<" ";
				decodeFile<<image4[i][j]<<" ";
		}
		cout<<endl;	
		decodeFile<<endl;	
}
		
		
}
};
int main(int argc, char** argv) {
	ifstream read;
	ofstream out1;
		ofstream encodeFile;
		ofstream decodeFile;
		ifstream encodeFile2;
	 char yesNo='Y';
	int totalRow=0,totalCol=0,min=0,max=0;
	int methodNum;
		while(yesNo=='Y'){
	 	cout<<"there are 4 methods"<<endl;
		cout<<"Method 1) with zero and not wrap-around."<<endl;
		cout<<"Method 2) Not zero and not wrap-around. "<<endl;
		cout<<"Method 3) with zero and wrap-around. "<<endl;
		cout<<"Method 4) Not  zero and wrap-around. "<<endl;
		cout<<"Enter Y to choose methods else to terminate"<<endl;
		cin>>yesNo;
		if(yesNo!='Y'){
			exit(1);
		}else{
			read.open(argv[1]);
			out1.open(argv[2]);
			if(read.good()){
					read>>totalRow;
					read>>totalCol;
					read>>min;
					read>>max;
					cout<<"***Image Header****"<<endl;
					cout<<"Total rows: "<<totalRow<<" Total Colomns: "<<totalCol<<" Minimum pixel value: "<<min<<" Maximum pixel value: "<<max;	
					cout<<endl;
	}
			cout<<"Please enter 1 to 4 to choose the method"<<endl;
				cin>>methodNum;
				cout<<"you choosed method "<<methodNum<<endl;
			while(methodNum==0||methodNum>4){
				cout<<"Please enter again, its invaild method number,the Method need to be  1 to 4"<<endl;
				cin>>methodNum;
			cout<<"you choosed method "<<methodNum<<endl;
			}
			string inputFileName= string(argv[1]);
			string nameEncodeFile=inputFileName+"_EncodeMethod"+to_string(methodNum)+".txt";
			out1<<"method "<<methodNum<<" used to decompress the input image "<<endl;
			string nameDecodeFile=inputFileName+"_EncodeMethod_Decoded"+to_string(methodNum)+".txt";
			encodeFile.open(nameEncodeFile);
			decodeFile.open(nameDecodeFile);
		
		encodeFile<<totalRow<<" "<<totalCol
		<<" "<<min<<" "<<max<<endl;

			runLengthEncode *run = new runLengthEncode(totalRow,totalCol);
			runLengthDecode *run2 = new runLengthDecode();
			switch(methodNum){
				case 1:
					run->method1(read,out1,encodeFile);
					  encodeFile.close();
					  encodeFile2.open(nameEncodeFile);
					  run2->decodeMethod1(encodeFile2,decodeFile);
					  
					  
					break;
				case 2:	
					run->method2(read,out1,encodeFile);
					 encodeFile.close();
					 encodeFile2.open(nameEncodeFile);
					 run2->decodeMethod2(encodeFile2,decodeFile);
					break;
				case 3:
					run->method3(read,out1,encodeFile);
					 encodeFile.close();
					 encodeFile2.open(nameEncodeFile);
					 run2->decodeMethod3(encodeFile2,decodeFile);
					break;
				case 4:
					run->method4(read,out1,encodeFile);
					 encodeFile.close();
					 encodeFile2.open(nameEncodeFile);
					 run2->decodeMethod4(encodeFile2,decodeFile);
					break;
				default:
					cout<<"Invalid method number, theres only four method"<<endl;
			}
		
	
		}
		read.close();
		out1.close();
		encodeFile2.close();
		decodeFile.close();
}
	 
	
	return 0;
}

