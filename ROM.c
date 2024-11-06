#include <stdio.h>

int romFunction(unsigned char mem[100]) {
int i=0;
	FILE *fptr=fopen("fibonacci.bin","rb");
    if(fptr==NULL) {
        printf("Could not open the file\n");
    }
    fread(mem,1,15,fptr);
    do{
    i++;
    }while(mem[i]==0x0 || mem[i]== 0x10 || mem[i]== 0x4  || mem[i]== 0x14 || mem[i]== 0x20 || (mem[i]&0xf8)==0x8  || (mem[i]&0xf8)==0x18  || (mem[i]&0xf8)==0x70  || (mem[i]&0xf8)==0xb0);                          
  
    fclose(fptr);
return i;
}

int main() {
    int size=0;
    int i=0;
	unsigned char mem[100];
    size =romFunction(mem);
    for(i=0;i<size;i++)
        printf("%d\n",mem[i]);
	return 0;
}

