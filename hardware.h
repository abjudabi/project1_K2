//#include<hardware.h>
#include<stdio.h>
#include<stdbool.h>
int mux2_1(int iA,int iB, bool bSel);
void translate(char inst,bool * j,bool * c,bool * D1, bool * D0, bool* sreg, int* scos);
int counter(int s,bool j, bool c, bool carry);
void instruction_memory(char inst[],bool * j,bool * c,bool * D1, bool * D0, bool * sreg, int* scos,int pc);
int romFunction(unsigned char mem[100]);
void ALU(int RA, int RB, bool D0, bool S, bool *carry, int *sum);
void decoder(bool D0, bool D1, bool *enRA, bool *enRB, bool *enRO);
