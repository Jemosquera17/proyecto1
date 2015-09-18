#include <stdint.h>

/**
* \brief  funcion que hace la suma(AND) entre dos registros, suma Rd con Rn y almacena el valor en Rd
* \param Rd operador 1 tipo puntero de 32 bits
* \param Rn operador 2 tipo tpunetero de 32 bits
* \param n variable de tipo entero
* \return no retorna valor
*/
void ADD(uint32_t *Rd,uint32_t Rn)
{
	
	printf("\nCARRY: %d\n",c);
	printf("ZERO: %d\n",s);
	printf("OVERFLOW: %d\n",o);
	printf("NEGATIVO: %d",n);
	*Rd=*Rd + Rn;

}
/**
* \brief  funcion que hace la OR exclusiva bit a bit entre operador 1 y operador 2, almacena el resultado en el operador 1
* \param Rd operador 1 tipo puntero de 32 bits
* \param Rn operador 2 tipo puntero de 32 bits
* \return no retorna valor
*/
void EOR(uint32_t *Rd,uint32_t Rn)
{
	
	*Rd = *Rd ^Rn;

}
/**
* \brief  funcion que hace la OR logica bit a bit entre operador 1 y operador 2, almacena el resultado en el operador 1
* \param Rd operador 1 tipo puntero de 32 bits
* \param Rn operador 2 tipo puntero de 32 bits
* \return retorna un entero de 32 bits positivo
*/
uint32_t OR(uint32_t *Rd,uint32_t Rn)
{
	
	*Rd=*Rd|Rn;

}
/**
* \brief  funcion que hace la AND exclusiva bit a bit entre el operador 1 y el operaodr 2
* \param Rd operador 1 tipo puntero de 32 bits
* \param Rn operador 2 tipo puntero de 32 bits
* \return retorna un entero de 32 bits positivo
*/
uint32_t AND (uint32_t *Rd,uint32_t Rn)
{

	*Rd=*Rd & Rn;

}
/**
* \brief  funcion que hace la MOV entre los dos operadores, se escribe el valor en el registro del operador 1
* \param Rd operador 1 tipo puntero de 32 bits
* \param Rn operador 2 tipo puntero de 32 bits
* \return retornar un entero de 32 bits positivo
*/
uint32_t MOV (uint32_t *Rd,uint32_t Rn)
{

	*Rd=Rn;

}

/**
* \brief  funcion que hace la SUB (la resta entre los dos registros) operador 1 y operador 2
* \param Rd operador 1 tipo puntero de 32 bits
* \param Rn operador 2 tipo puntero de 32 bits
* \return un entero de 32 bits positivo
*/
uint32_t SUB (uint32_t *Rd,uint32_t Rn)
{

	*Rd=*Rd+(~Rn+1);
	printf("ZERO: %d\n",s);

	printf("NEGATIVO: %d",n);
	
}
/**
* \brief  funcion que suma los dos registros pero no guarda el resultado en ninguno de los dos, sin embargo modifica las banderas. (compara negativo)
* \param Rd operador 1 tipo puntero de 32 bits
* \param Rn operador 2 tipo puntero de 32 bits
* \return no retorna valor
*/
void CMN(uint32_t *Rd,uint32_t Rn)
{

	printf("\nCARRY: %d\n",c);
    printf("ZERO: %d\n",s);
    printf("OVERFLOW: %d\n",o);
    printf("NEGATIVO: %d",n);

}
/**
* \brief  funcion que resta los dos registros pero no guarda el resultado en ninguno de los dos, sin embargo modifica las banderas. (solo compara)
* \param Rd operador 1 tipo puntero de 32 bits
* \param Rn operador 2 tipo puntero de 32 bits
* \return retorna un entero de 32 bits positivo
*/
uint32_t CMP (uint32_t *Rd,uint32_t Rn)
{

	printf("ZERO: %d\n",s);
	
	printf("NEGATIVO: %d",n);

}
/**
* \brief  funcion que multiplica los dos registros; pero solo guarda los 32 bits menos significativos.
* \param Rd operador 1 tipo puntero de 32 bits
* \param Rn operador 2 tipo puntero de 32 bits
* \return no retorna valor
*/
void MUL (uint32_t *Rd,uint32_t Rn)
{

	*Rd=(*Rd * Rn)& 4294967295;

}
/**
* \brief  funcion que hace la AND bit a bit pero no guarda resultado, solo modifica las banderas.
* \param Rd operador 1 tipo puntero de 32 bits
* \param Rn operador 2 tipo puntero de 32 bits
* \return no retorna valor
*/
void TST (uint32_t *Rd,uint32_t Rn)
{
 
	
}
