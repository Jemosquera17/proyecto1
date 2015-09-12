#include <stdint.h>
/**
* \brief  funcion que imprime el registro del operador 1
* \param ptro operador 1 puntero de 32 bits
* \param n operador 2 entero
* \param x operador 3 puntero de tipo entero
* \return no retorna valor
*/
void Mregistro(uint32_t *ptro,int n,int *x)
{
    char i;
    *x=2;
    move(2, 34);
    printw("REGISTROS:\n");
    refresh();
    for(i=0;i<n;i++)
	{
		
    *x=i+4;
    move(*x,8);
    printw(" registro #%d  : %d \n",i+1,ptro[i]);
	
	}

}
