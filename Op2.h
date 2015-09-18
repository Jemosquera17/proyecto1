#include <stdint.h>
/**
* \brief  funcion que hace el desplazamioento logico a la izquierda entre el operador 2 y el operador 3, el resultdo lo guarda en el operador 1. 
* \param Rd operador 1 tipo puntero de 32 bits
* \param Rn operador 2 tipo puntero de 32 bits
* \param y operador 3 tipo entero
* \return no retorna valor
*/
void LSLS(uint32_t *Rd,uint32_t Rn,uint32_t y)
{

	*Rd=Rn<<y;
	
}
/**
* \brief  funcion que hace el desplazamioento logico a la derecha entre el operador 2 y el operador 3, el resultdo lo guarda en el operador 1. 
* \param Rd operador 1 tipo puntero de 32 bits
* \param Rn operador 2 tipo0 puntero de 32 bits
* \param y operador 3 tipo entero
* \return no retorna valor
*/
void LSRS (uint32_t *Rd,uint32_t Rn,int y)
{
   
	*Rd=Rn>>y;
   
}
/**
* \brief  funcion que hace la rotacion a la derecha entre el operador 2 y el operador 3, el resultdo lo guarda en el operador 1 
* \param Rd operador 1 tipo puntero de 32 bits
* \param Rn operador 2 tipo puntero de 32 bits
* \param y operador 3 tipo entero
* \return no retorna valor
*/
void ROR (uint32_t *Rd,uint32_t Rn,int y)
{

	uint32_t s;
	s=Rn>>(32−y);
	*Rd=Rn<<y;
	*Rd=*Rd|s;
	
}
/**
* \brief  funcion que hace el desplazamioento aritmetico a la derecha entre el operador 2 y el operador 3, el resultdo lo guarda en el operador 1.
* \param Rd operador 1 tipo puntero de 32 bits
* \param Rn operador 2 tipo puntero de 32 bits
* \param y operador 3 tipo entero
* \return no retorna valor
*/
void ASR (uint32_t *Rd,uint32_t Rn,int y)
{

	uint32_t s;
	s=~0<<(32−y);
	*Rd=Rn>>y;
	*Rd=*Rd|s;

}
/**
* \brief  funcion que hace la AND entre el operador 1 y el complemento del operador 2, el resultdo lo guarda en el operador 1.
* \param Rd operador 1 tipo puntero de 32 bits
* \param Rn operador 2 tipo puntero de 32 bits
* \return no retorna valor
*/
void Bic(uint32_t *Rd,uint32_t Rn)
{

	*Rd&=~Rn;

}
/**
* \brief  funcion que guarda el complemento del registro del operador 2 en operador 1
* \param Rd operador 1 tipo puntero de 32 bits
* \param Rn operador 2 tipo puntero de 32 bits
* \return no retorna valor
*/
void Mvn (uint32_t *Rd,uint32_t Rn)
{

	*Rd=~Rn;
	
}
/**
* \brief  funcion que cambia el orden de los bytes entre el operador 1 y el operador 2.
* \param Rd operador 1 tipo puntero de 32 bits
* \param Rn operador 2 tipo puntero de 32 bits
* \return no retorna valor
*/
void REV (uint32_t *Rd,uint32_t Rn)
{

	uint32_t x=255;
	*Rd=Rn<<24;
	*Rd= *Rd|(Rn>>24);
	*Rd=*Rd|((Rn&(x<<8))<<8);
	*Rd=*Rd|((Rn&(x<<16))>>8);

}
/**
* \brief  funcion que hace el desplazamioento aritmetico a la derecha entre el operador 2 y el operador 3, el resultdo lo guarda en el operador 1.
* \param Rd operador 1 tipo puntero de 32 bits
* \param Rn operador 2 tipo puntero de 32 bits
* \param y operador 3 tipo entero
* \return no retorna valor
*/
void ASR (uint32_t *Rd,uint32_t Rn,int y)
{
	
   *Rd=Rn>>y;

}
/**
* \brief  funcion que hace la AND entre el operador 1 y el complemento del operador 2, el resultdo lo guarda en el operador 1.
* \param Rd operador 1 tipo puntero de 32 bits
* \param Rn operador 2 tipo puntero de 32 bits
* \return no retorna valor
*/
void BIC (uint32_t *Rd,uint32_t Rn)
{

	*Rd=*Rd & ~Rn;
	
}
/**
* \brief  funcion que hace el desplazamioento logico a la derecha entre el operador 2 y el operador 3, el resultdo lo guarda en el operador 1. 
* \param Rd operador 1 tipo puntero de 32 bits
* \param Rn operador 2 tipo0 puntero de 32 bits
* \param y operador 3 tipo entero
* \return no retorna valor
*/
void LSRS (uint32_t *Rd,uint32_t Rn,int y)
{
   
   *Rd=Rn>>y;
   
{
/**
* \brief  funcion que guarda el complemento del registro del operador 2 en operador 1
* \param Rd operador 1 tipo puntero de 32 bits
* \param Rn operador 2 tipo puntero de 32 bits
* \return no retorna valor
*/
void MVN(uint32_t *Rd,uint32_t Rn)
{

	*Rd=~Rn;

}
/**
* \brief funcion que no hace nada (no realiza niguna funcion)
* \param no tiene parametros (variables)
* \return por lo tanto no retorna ningun valor
*/
void NOP()
{

}
/**
* \brief  funcion que obtiene el complemento a dos de un numero, entre operador 1 y el operador 2.
* \param Rd operador 1 tipo puntero de 32 bits
* \param Rn operador 2 tipo puntero de 32 bits
* \return no retorna valor
*/
void RSB (uint32_t *Rd,uint32_t Rn)
{
	
	*Rd=~Rn+1;

}
}


