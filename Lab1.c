#include <stdio.h>
#include <math.h>
#include <conio.h>
double someMathOperations(int a,int b,double c,int Xbegin,int Xend){
	double preRes;
	if((Xbegin+10<0)&&(b!=0)){
		preRes=a*pow(Xbegin,2)-c*Xbegin+b;
	}else if((Xbegin+10>0)&&(b==0)){
		preRes=(Xbegin-a)/(Xbegin-c);
	}else{
		preRes=-Xbegin/(a-c);
	}
	return preRes;
}
int main() {
	int a,b,c,Xbegin,Xend,dX,intRes;
	double res;
	printf("Enter:");
	printf("\ta=");scanf("%d",&a);
	printf("\tb=");scanf("%d",&b);
	printf("\tc=");scanf("%f",&c);
	printf("\tXbegin:");scanf("%d",&Xbegin);
	printf("\tXend:");scanf("%d",&Xend);
	printf("\tdX:");scanf("%d",&dX);
	for(Xbegin;Xbegin<=Xend;Xbegin+=dX){
		res=someMathOperations(a,b,c,Xbegin,Xend);
			if(((long)floor(a)||(long)floor(b))&(!((long)floor(a)||(long)floor(c)))){
				printf("x=%d\tF=%.2f\n",Xbegin,res);
			}else{
				intRes=(int)res;
				printf("x=%d\tF=%d\n",Xbegin,intRes);
			}
		}
	getch();
	return 0;
}
