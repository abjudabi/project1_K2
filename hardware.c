//#include<hardware.h>
#include<stdio.h>
#include<stdbool.h>

void translate(char inst,bool * j,bool * c,bool * D1, bool * D0, bool * sreg, int* scos);

int counter(int s,bool j, bool c, bool carry);
int main(){
char x=0b10110101;
bool j,c,D1,D0,sreg;
int scos;
int count;
bool carry =0;
translate(x,&j,&c,&D1,&D0,&sreg,&scos);
printf("%c : %d,%d,%d,%d,%d,%d\n",x,j,c,D1,D0,sreg,scos);
count=counter(scos,j,c,carry);

count=counter(scos,j,c,carry);
x=0b10110111;
translate(x,&j,&c,&D1,&D0,&sreg,&scos);
carry=1;
count=counter(scos,j,c,carry);
count=counter(scos,j,c,carry);
x=0b0;
translate(x,&j,&c,&D1,&D0,&sreg,&scos);
count=counter(scos,j,c,carry);
while(1){
count=counter(scos,j,c,carry);
}
return 0;
}


int mux2_1(int iA,int iB, bool bSel){

	if (bSel==0)
		return iA;
	else
		return iB;


}

void translate(char inst,bool * j,bool * c,bool * D1, bool * D0, bool* sreg, int* scos){

	*j =(inst>>7)& 1;
	*c=(inst>>6) &1;
	*D1=(inst>>5)&1;
	*D0=(inst>>4)&1;
	*sreg=(inst>>3)&1;
	*scos=inst& 7;


}

int counter(int s,bool j, bool c, bool carry){
	bool load = (carry & c) || j;
	static int count =0;
	
	if (count>14)
		count=0;

	if (load ==1)
		count=s;
	else 
		count+=1;
	printf("\n the count value is %d\n",count);
	return count;


}
