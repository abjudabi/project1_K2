//#include<hardware.h>
#include<stdio.h>
#include<stdbool.h>
int counter(int s,bool j, bool c, bool carry);
int mux2_1(int iA,int iB, bool bSel);
void translate(char inst,bool * j,bool * c,bool * D1, bool * D0, bool* sreg, int* scos);
