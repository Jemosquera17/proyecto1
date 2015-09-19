#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "mregistros.h"
#include "Operaciones.h"

int main()
{
int h;

   int a,b,c;  // se declaran las variables 
   uint32_t rd[13]; // registro de 32 bits
   Mregistro(rd,13); 
	switch(a)
	{
     case 1:
         Xor(rd[b],rd[c]); // realiza la or exclusiva bit a bit
         break;
     case 2:
         Or(rd[b],rd); // realiza la or logica bit a bit
         break;
     case 3:
        And(rd[b],rd[c]); // realiza la AND bit a bit
         break;
     case 4:
          Movs(rd,b,c); // escribe un valor en un registro
          break;
     case 5:
          Subs (rd[b],rd[c]); // realiza la resta aritmetica
          break;

	}

	printf("\n%d\n",rd[a]); //Imprime el resultado del registro rd


}
