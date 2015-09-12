#include <stdint.h>
/**
* \brief  funcion que hace la suma(AND) entre dos registros, suma Rn con Rm y almacena el valor en Rd
* \param Rd operador 1 puntero de 32 bits
* \param Rn operador 2 punetero de 32 bits
* \param Rm operador 3 puntero de 32 
* \return no retorna valor
*/
void ADD(uint32_t *Rd,uint32_t *Rn,uint32_t *Rm)
{
	
	if(*Rn+*Rm>2^32)
	{
       
		printw("\nC: 1\n");
		
    }
    else
    {
       
	   printw("\nC: 0\n");
		
    }
	
    *Rd=(*Rn + *Rm);
}
/**
* \brief  funcion que hace la OR exclusiva bit a bit entre operador 1 y operador 2, almacena el resultado en el operador 1
* \param Rd operador 1 puntero de 32 bits
* \param Rn operador 2 puntero de 32 bits
* \return no retorna valor
*/
void Xor(uint32_t *Rd,uint32_t *Rn)
{
	
	*Rd = *Rd ^*Rn;

}
/**
* \brief  funcion que hace la OR logica bit a bit entre operador 1 y operador 2, almacena el resultado en el operador 1
* \param Rd operador 1 puntero de 32 bits
* \param Rn operador 2 puntero de 32 bits
* \return retorna un entero de 32 bits positivo
*/
uint32_t Or(uint32_t *Rd,uint32_t *Rn)
{
	
	if(*Rd|*Rn>2^32)
	{
        
		printf("\nC: 1\n");
    }
    else
    {
        
		printf("\nC: 0\n");
		
    }


    return (*Rd | *Rn);
}
/**
* \brief  funcion que hace la AND exclusiva bit a bit entre el operador 1 y el operaodr 2
* \param Rd operador 1 puntero de 32 bits
* \param Rn operador 2 puntero de 32 bits
* \return un entero de 32 bits positivos
*/
uint32_t And (uint32_t *Rd,uint32_t *Rn)
{

	return (*Rd & *Rn);
	
}
/**
* \brief  funcion que hace la MOV entre los dos operadores, se escribe el valor en el registro del operador 1
* \param Rd operador 1 puntero de 32 bits
* \param Rn operador 2 puntero de 32 bits
* \return no retorna valor
*/
uint32_t Movs (uint32_t *Rd,uint32_t *Rn)
{
	
	*Rd=*Rn;
	
}
/**
* \brief  funcion que hace la SUB (la resta entre los dos registros) operador 1 y operador 2
* \param Rd operador 1 puntero de 32 bits
* \param Rn operador 2 puntero de 32 bits
* \return un entero de 32 bits positivos
*/
uint32_t Subs (uint32_t *Rd,uint32_t *Rn,uint32_t *Rm,int *x)
{
	*x=*x+4;
    if(*Rn +*Rm==0)
	{
        move(40,8);
        printw("\nZ: 1\n");
        move(44,8);
        printw("\nC: 1\n");
    }
    else
    {
        move(40,8);
        printw("\nZ: 0\n");
        move(44,8);
        printw("\nC: 0\n");

    }
	
    *Rd=*Rn + ((~(*Rm))+1);
}

