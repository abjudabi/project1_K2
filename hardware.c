//#include<hardware.h>
#include<stdio.h>
#include<stdbool.h>

void translate(char inst,bool * j,bool * c,bool * D1, bool * D0, bool * sreg, int* scos);

int counter(int s,bool j, bool c, bool carry);

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



void instruction_memory(char inst[],bool * j,bool * c,bool * D1, bool * D0, bool * sreg, int* scos,int pc){
	bool ji,ci,D1i,D0i;
	bool sregi;
	int scosi;

	translate(inst[pc],&ji,&ci,&D1i,&D0i,&sregi,&scosi);

	*j=ji;
	*c=ci;
	*D1=D1i;
	*D0=D0i;
	*sreg=sregi;
	*scos=scosi;
}
