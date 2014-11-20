#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define getbit(by, pos)  ((by >> pos)&0x1)
void byte2bits(char c, char* s) // Essa função converte um byte numa string binária
{
    int i = 7;
    while(i >= 0)
        *s++ = '0' + getbit(c, i--);
    *s = 0;
}
int BinStrToInt(char *str) // Essa função converte uma string binária no seu equivalente integer
{
  int c, n;
  
  for(c = n = 0; c < strlen(str); c++)
  {
    n <<= 1;
    n |= str[c] == '1' ? 1 : 0;
  }
  
  return n;
}
main () {
	char c, bits[9], dg1[4]="", dg2[4]="", op[3]="";
	int i, k=0, l=0, m=0, opi;
	float div;
	printf("Char: \n"); //recebe o char
	scanf("%c",&c);
	//fgets(c,2,stdin);
	//c[2]="\0";
	//printf("%c \n",c);
	byte2bits(c, bits); //aplica a função byte2bits
    fprintf(stdout, "No sistema binario %s\n", bits);
    //dg1 = ''; dg2=''; op='';
    for (i=0; i<8; i++){ //percorre a string binária
		//printf("%c \n",bits[i]);
		if (i<3){ // separa os três dígitos da frente
			dg1[k] = bits[i];
			k++;
		} else if (i>4) { // separa os três dígitos de trás
					dg2[l] = bits[i];
					l++; 
				}
			   else { // separa os dois dígitos do meio
					op[m] = bits[i];
					m++;
				}
		//printf("%c \n",bits[1]);
		//printf("%c \n",bits[2]);
	}
	printf("%s \n",dg1);
	printf("%s \n",dg2);
	printf("%s \n",op);
	opi = atoi(op);// converte o op em numero para o switch
	//printf("%d \n",BinStrToInt(dg1));
	switch (opi){
		case 00:
			printf("Soma:");
			printf("%d + %d = %d \n",BinStrToInt(dg1),BinStrToInt(dg2),BinStrToInt(dg1)+BinStrToInt(dg2));
		break;
		case 01:
			printf("Subtração \n");
			printf("%d - %d = %d \n",BinStrToInt(dg1),BinStrToInt(dg2),BinStrToInt(dg1)-BinStrToInt(dg2));
		break;
		case 10:
			printf("Multiplicação \n");
			printf("%d * %d = %d \n",BinStrToInt(dg1),BinStrToInt(dg2),BinStrToInt(dg1)*BinStrToInt(dg2));
		break;
		case 11:
			printf("Divisão \n");
			div = (float)BinStrToInt(dg1)/BinStrToInt(dg2); // isso foi necessario para evitar erro de ponto flutuante
			printf("%d / %d = %f \n",BinStrToInt(dg1),BinStrToInt(dg2),div);
		break;
	}
	// comando pause multiplataforma
	#ifdef WIN32
	#define PAUSE 1
	#else
	#define PAUSE 0
	#endif
	if(PAUSE==1)
		system("pause");
	else 
		system("read -p \"Pressione enter para sair\" saindo");
}
