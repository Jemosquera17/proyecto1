#include <stdint.h>

/*! 
 *  \brief     Esta función hace el desplazamiento lógico a la izquierda entre el operador 2 y el operador 3, el resultdo lo guarda en el operador 1.
 *  \param     Rd operador 1 tipo puntero de 32 bits.
 *  \param 	   Rn operador 2 tipo entero de 32 bits.
 *  \param 	   y operador 3 tipo entero de 32 bits.
 *  \return    No retorna valor
 *  \details   Esta funcion se utiliza para realizar el desplazamiento lógico a la izquierda. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void LSLS(uint32_t *Rd,uint32_t Rn,uint32_t y)
{

	*Rd=Rn<<y;
	
}

 /*!
 *  \brief     Esta función realiza el desplazamiento logico a la derecha entre el operador 2 y el operador 3, el resultdo lo guarda en el operador 1. 
 *  \param     Rd operador 1 tipo puntero de 32 bits.
 *  \param     Rn operador 2 tipo enetrode 32 bits.
 *  \param     y operador 3 tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para realizar el desplazamiento logico a la derecha. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void LSRS (uint32_t *Rd,uint32_t Rn,int y)
{
   
	*Rd=Rn>>y;
   
}

 /**
 *  \brief     Esta función hace la rotación a la derecha entre el operador 2 y el operador 3, el resultdo lo guarda en el operador 1. 
 *  \param     Rd operador 1 tipo puntero de 32 bits.
 *  \param     Rn operador 2 tipo entero de 32 bits.
 *  \param     y operador 3 tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para realizar la rotación a la derecha. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void ROR (uint32_t *Rd,uint32_t Rn,int y)
{

	uint32_t s;
	s=Rn>>(32−y);
	*Rd=Rn<<y;
	*Rd=*Rd|s;
	
}

 /**
 *  \brief     Esta función hace el desplazamieento aritmetico a la derecha entre el operador 2 y el operador 3, el resultdo lo guarda en el operador 1.
 *  \param     Rd operador 1 tipo puntero de 32 bits.
 *  \param     Rn operador 2 tipo entero de 32 bits.
 *  \param     y operador 3 tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para realizar el desplazamiento aritmetico a la derecha. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void ASR (uint32_t *Rd,uint32_t Rn,int y)
{

	uint32_t s;
	s=~0<<(32−y);
	*Rd=Rn>>y;
	*Rd=*Rd|s;

}

 /**
 *  \brief     Esta función realiza la AND entre el operador 2 y el complemento del operador 3, el resultdo lo guarda en el operador 1.
 *  \param     Rd operador 1 tipo puntero de 32 bits.
 *  \param     Rn operador 2 tipo entero de 32 bits.
 *  \param     Rm operador 3 tipo entero de 32 bits.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para realizar la AND. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void BIC (uint32_t *Rd,uint32_t Rn,uint32_t Rm)
{
	Pc+=2;
	*Rd=Rn & ~Rm;

}

 /**
 *  \brief     Esta función guarda el complemento del registro del operador 2 en operador 1.
 *  \param     Rd operador 1 tipo puntero de 32 bits
 *  \param     Rn operador 2 tipo entero de 32 bits
 *  \return    no retorna valor
 *  \details   Esta función se utiliza para guardar el complemento del registro. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void MVN (uint32_t *Rd,uint32_t Rn)
{

	*Rd=~Rn;
	
}

 /**
 *  \brief     Esta función cambia el orden de los bytes entre el operador 1 y el operador 2.
 *  \param     Rd operador 1 tipo puntero de 32 bits.
 *  \param     Rn operador 2 tipo entero de 32 bits.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para cambiar el orden de los bytes. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
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
 *  \brief     Esta función no realiza niguna operación.
 *  \param     No recive ningún parametros (variables)
 *  \return    Por esta razón no retorna ningun valor.
 *  \details   Esta función no hace nada. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void NOP()
{

}

 /**
 *  \brief     Esta función obtiene el complemento a dos de un numero, entre el operador 1 y el operador 2.
 *  \param     Rd operador 1 tipo puntero de 32 bits.
 *  \param     Rn operador 2 tipo entero de 32 bits.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para obtener el complemento a dos de un número. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void RSB (uint32_t *Rd,uint32_t Rn)
{
	
	*Rd=~Rn+1;

}

 /**
 *  \brief     Esta función obtiene la resta con carry, entre el operador 2 y el operador 3, almacena el resultado en el operador 1.
 *  \param     Rd operador 1 tipo puntero de 32 bits.
 *  \param     Rn operador 2 tipo entero de 32 bits.
 *  \param     Rm operador 3 tipo entero de 32 bits.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para obtener la resta con carry. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void SBC (uint32_t *Rd,uint32_t Rn,uint32_t Rm)
{

	Pc+=2;
	Rm=~Rm+1;
	Rm=Rm-c;
	*Rd=Rn+Rm;
	
}

/**
 *  \brief     Esta función realiza un salto cuando la bandera de Zero sea igual a 1.
 *  \param     Sal operador 1 tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para obtener un salto cuando se active la bandera de Zero. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void BEQ(int Sal)
{
	
	
}

/**
 *  \brief     Esta función realiza un salto cuando la bandera de Zero sea igual a 0.
 *  \param     Sal operador 1 tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para obtener un salto cuando este en 0 la bandera de Zero. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void BNE(int Sal)
{
	
	
}

/**
 *  \brief     Esta función realiza un salto cuando haya un carry (sea igual a 1).
 *  \param     Sal operador 1 tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para obtener un salto cuando se active la bandera de carry. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void BCS(int Sal)
{
	
	
}

/**
 *  \brief     Esta función realiza un salto cuando la bandera de carry sea igual a 0.
 *  \param     Sal operador 1 tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para obtener un salto cuando este en 0 la bandera de carry. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void BCC(int Sal)
{
	
	
}

/**
 *  \brief     Esta función realiza un salto cuando la bandera de negativo sea igual a 1.
 *  \param     Sal operador 1 tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para obtener un salto cuando se active la bandera de negativo. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void BMI(int Sal)
{
	
	
}

/**
 *  \brief     Esta función realiza un salto cuando la bandera de negativo sea igual a 0.
 *  \param     Sal operador 1 tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para obtener un salto cuando este en 0 la bandera de negativo. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void BPL(int Sal)
{
	
	
}

/**
 *  \brief     Esta función realiza un salto cuando la bandera de overflow sea igual a 1.
 *  \param     Sal operador 1 tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para obtener un salto cuando se active la bandera de overflow. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void BVS(int Sal)
{
	
	
}

/**
 *  \brief     Esta función realiza un salto cuando la bandera de overflow sea igual a 0.
 *  \param     Sal operador 1 tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para obtener un salto cuando este en 0 la bandera de overflow. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void BVL(int Sal)
{
	
	
}

/**
 *  \brief     Esta función realiza un salto cuando la bandera de carry sea igual a 1 y la bandera de Zero sea igual a 0.
 *  \param     Sal operador 1 tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para obtener un salto cuando este en 1 el carry y en 0 el zero. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void BHI(int Sal)
{
	
	
}

/**
 *  \brief     Esta función realiza un salto cuando la bandera de carry sea igual a 0 ó la bandera de Zero sea igual a 1.
 *  \param     Sal operador 1 tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para obtener un salto cuando este en 0 el carry ó en 1 el zero. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void BLS(int Sal)
{
	
	
}

/**
 *  \brief     Esta función realiza un salto cuando la bandera de negativo sea igual a la bandera de overflow.
 *  \param     Sal operador 1 tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para obtener un salto cuando sean iguales las banderas de negativo y overflow.
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void BGE(int Sal)
{
	
	
}

/**
 *  \brief     Esta función realiza un salto cuando la bandera de negativo sea diferente a la bandera de overflow.
 *  \param     Sal operador 1 tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para obtener un salto cuando las banderas de negativo y overflow sean diferentes. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void BLT(int Sal)
{
	
	
}

/**
 *  \brief     Esta función realiza un salto cuando la bandera de negativo sea igual a overflow y la bandera de Zero sea igual a 0.
 *  \param     Sal operador 1 tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para obtener un salto cuando esten igualeslas banderas negativo y overflow y en 0 el zero. 
 *  \author    Juan Manuel Quintero Polania- Leader
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void BGT(int Sal)
{
	
	
}

/**
 *  \brief     Esta función realiza un salto cuando la bandera de Zero sea igual a 1 o la bandera de negativo sea diferente al overflow. 
 *  \param     Sal operador 1 tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para obtener un salto cuando este en 1 el zero o sean diferentes las banderas de negativo y de overflow en 0 el zero.
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void BLE(int Sal)
{
	
	
}

/**
 *  \brief     Esta función realiza un salto de lo que haya acumulado en pc hasta un número. 
 *  \param     Sal operador 1 tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para obtener un salto cuando desde el valor de pc hasta otro número especifico.
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void B(int Sal)
{
	
	
} 

/**
 *  \brief     Esta función realiza un salto de lo que haya acumulado en pc hasta un número. 
 *  \param     Sal operador 1 tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para obtener un salto cuando desde el valor de pc hasta otro número especifico.
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void BL(int Sal)
{
	
	
} 

/**
 *  \brief     Esta función realiza un salto de lo que haya acumulado en pc. 
 *  \param     Sal operador 1 tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para obtener un salto cuando desde el valor de pc.
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void BX(int Sal)
{
	
	
} 

/**
 *  \brief     Esta función realiza instruciones. 
 *  \param     P operador 1 tipo entero.
 *  \return    No retorna valor.
 *  \details   Esta función se utiliza para obtener instruciones.
 *  \author    Julio Edgar Mosquera Angulo - Documenting
 *  \version   4.1a
 *  \date      19/09/2015
 *  \pre       First initialize the system.
 */
void RPC(int Sal)
{
	
	
} 