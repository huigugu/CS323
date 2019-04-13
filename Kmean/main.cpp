#include <iostream>
#include<string>
#include<fstream>
#include<typeinfo>
#include<cmath>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Point{
	public:
		int Xcoord,Ycoord,Label,Distance;
		Point(int x, int y){
			Xcoord=x;
			Ycoord=y;
			Label=0;
			Distance=0;
		}
		Point(){
			Xcoord=0;
			Ycoord=0;
			Label=0;
			Distance=0;
		}
	};
class Kmean{
	public:
	 int k, numberPts,numRows,numCols,minVal,maxVal,change;
	 Point **pointSet;
	 int ** image;
	 Point**Kcentroids;
	 Kmean(string inputk,int nR,int nC,int minV, int maxV, int numpts){
         k=stoi(inputk);
	 	numRows=nR;
	 	numCols=nC;
	 	minVal=minV;
	 	maxVal=maxV;
	 	change=0;
	 	numberPts=numpts;//199
	   pointSet = new Point*[numberPts];
	   for(int i=0;i<numberPts;i++)
	   pointSet[i]=new Point();
	    image = new int*[numRows];
	    for(int i=0;i<numRows;i++){
	    	image[i]= new int[numCols];
	    	for(int j=0;j<numCols;j++){
	    		image[i][j]=0;
			}
		}
		Kcentroids =new Point*[k+1];
		for(int i=0;i<k+1;i++)
		Kcentroids[i] = new Point();
	 }
	 void loadPointset(ifstream& out1){
	 	 int x=0, y=0;
	 	 	for(int i=0;i<numberPts;i++){
	 	 			out1>>x;
	 	   	 		out1>>y;
	 	   	 	
	 	   	 	pointSet[i] = new Point(x,y);
	 	 		pointSet[i]->Distance=9999;
		  }	 
	 }
	 void assignLabel(){
	 	int front=0, back=numberPts-1, label=1;
	 	while(front<=back){
	 	pointSet[front]->Label=label;
	 	front++;
	 	label++;
	 	pointSet[back]->Label=label;
	 	back--;
	 	label++;
	 	if(label>=k){
	 		label=1;
		 }
	 }
	 }
	 
	 void computeCent(){
	 	int *sumX= new int[k+1];
	 	int *sumY= new int[k+1];
	 	int *totalPt=new int[k+1];
	 	for(int i=0;i<k+1;i++){
	 		sumX[i]=0;
	 		sumY[i]=0;
	 		totalPt[i]=0;
	 		
		 }
		 int index =0;
		 int label=0;
		 while(index<numberPts){
		 	label=pointSet[index]->Label;
		 	sumX[label]+=pointSet[index]->Xcoord;
		 	sumY[label]+=pointSet[index]->Ycoord;
		 	totalPt[label]++;
		 	index++;
		 }
	for(label=1;label<=k;label++){
			if(totalPt[label]>0){
			Kcentroids[label]->Xcoord = (sumX[label]) / (totalPt[label]);
			Kcentroids[label]->Ycoord = (sumY[label]) / (totalPt[label]);
		}
		} 
}
double computeDist(Point *p, Point* c){
	double Distance = (pow(p->Xcoord - c->Xcoord, 2)) + (pow(p->Ycoord - c->Ycoord, 2));
		return sqrt(Distance);
	}
	
	 void  DistanceMinLabel(Point* p,Point ** Kcen){
	 	int minDist=99999,minLabel=0,dist=0;
	 	for(int label=1;label<=k;label++){
			dist = computeDist(p,Kcen[label]);
			if(dist < minDist){
				minLabel = label;
				minDist = dist;
			}
		}
		if(p->Label!=minLabel){
			p->Distance = minDist;
			p->Label = minLabel;
			change++;
		}
	 }
	 
	 void kcluster(ofstream &out2){
	 	 int iteration = 0, index;
		change = 1;
		assignLabel();
	 	 while(!change<=0){
	 	 	point2Image();
	 	 	prettyPrint(out2,iteration);
	 	 	change=0;
	 	 	computeCent();
	 	 	index=0;
	 	 while(index<numberPts){
	 	 	DistanceMinLabel(pointSet[index],Kcentroids);
	 	 	index++;
	 	 }
	 	 iteration++;
		  } 	 
	 }
	 void point2Image(){
	 	 int x=0, y=0,label=0;
	 	 for(int i=0;i<numberPts;i++){
	 	 	x=pointSet[i]->Xcoord;
	 	 	y=pointSet[i]->Ycoord;
	 	 	label =pointSet[i]->Label;
	 	 	image[x][y]=label;
		  }
	 }
	 void prettyPrint(ofstream & o2,int iterations){
	 	o2 << "****************************************************\n";
	 o2<<"Result of Iteration# "<<iterations<<endl;

	 	for(int i=0;i<numRows;i++){
	 		for(int j=0; j<numCols;j++)
	 			if(image[i][j]>0){
	 				o2<<image[i][j];
	 				//cout<<image[i][j]<<endl;
				 }else{
				 	o2<<" ";
				 }
				 o2<<endl;
			 }	 
	 }
	 void writeSet(ofstream & o3){
	 	int x=0,y=0,label=0;
	 	o3<<"Number of points "<<numberPts<<endl;
	 	o3<<"Number of Rows "<<numRows;
	 	o3<<" Number of Cols "<<numCols<<endl;
	 	for(int i=0;i<numberPts;i++){
	 		x=pointSet[i]->Xcoord;
	 		y=pointSet[i]->Ycoord;
	 		label=pointSet[i]->Label;
	 		o3<<x<<" "<<y<<" "<<label<<endl;
		 }
}
};


 int extractPts(ifstream & in1,ofstream & out1,int Nr,int Nc){
 	int count =0;
 	int temp =0;
 	for(int i=0;i<Nr;i++){
 		for(int j=0;j<Nc;j++){
 			in1>>temp;
 			if(temp>0){
 				out1<<i<<" "<<j<<endl;
 				count++;
			 }
		 }
	 }
	 return count;	
 }
int main(int argc, char** argv) {
	ifstream in;
	ifstream read_out1;
	int numRows=0,numCols=0,minVal=0,maxVal=0;
	ofstream out1,out2,out3;
	int numPts=0;
	in.open(argv[1]);
	string k=argv[2];
	out1.open(argv[3]);
	out2.open(argv[4]);
	out3.open(argv[5]);
	in>>numRows>>numCols>>minVal>>maxVal;
	numPts =extractPts(in,out1,numRows,numCols);
	out1.close();
	read_out1.open(argv[3]);
	Kmean * kmean = new Kmean(k,numRows,numCols,minVal,maxVal,numPts);
	kmean->loadPointset(read_out1);
	read_out1.close();
	kmean->kcluster(out2);
	kmean->writeSet(out3);
	in.close();
	out2.close();
	out3.close();
	
}
