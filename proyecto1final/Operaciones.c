#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "Operaciones.h"

int c,s,o,n,Pc=0,LR=0;//Variables globales banderas

void RPC(int *P)//Un puntero apuntado a la variable PC DEL MAIN la modifica con el valor del PC
{
    *P=Pc; //modifica el PC del (Main)
}
void ADC(uint32_t *Rd,uint32_t Rn,uint32_t Rm)
{
    Rm=Rm+c; //le suma la bandera de carry
    *Rd=Rn + Rm;//Este puntero Modifica elregistro de destino con el resultado de la suma de Rn y Rm
    Pc+=2;//Aumenta el PC para saltar a la siguiente direccion  cuando termine esta funcion
	if(((((Rn>>31)&1)==1) &&((Rm>>31)&1==1)&&((*Rd>>31)==0))||((((Rn>>31)&1)==1) &&((Rm>>31)==0)&&((*Rd>>31)==0))||((((Rn>>31))==0) &&((Rm>>31)&1==1)&&((*Rd>>31)==0))||((((Rn>>31)&1)==1) &&((Rm>>31)&1==1)&&((*Rd>>31)&1==1)))
	{
       c=1; //Bandera de carry se activa si el ultimo bit de los dos numeros es uno y el de el Rd da 0 o 1
    }
		else
		{
			c=0;//No se activa el carry
		}
	if((Rn>>31==0 && Rm>>31==0 && (*Rd>>31)&1==1 )||(((Rn>>31)&1==1)&&((Rm>>31)&1==1)&&(*Rd>>31==0)))
	{
		o=1; //Se activa si el ultimo bit de los dos registros son iguales y cambia  esto quiere decir que de la suma de dos nuemros de mismo signo da uno de diferente signo
	}
		else
		{
			o=0;//No se activa Bandera sobreflujo
		}
	if((*Rd>>31)&1==1)
	{
		n=1; //si el ultimo bit es 1 es negativo
	}
		else
		{
			n=0;// de lo contrario es positivo
		}
	if (*Rd==0)
    {
		s=1;//Si el registro de destino da 0 se activa
    }
		else
		{
			s=0;//De lo contrario no se activa la bandera
		}

}
void ADD(uint32_t *Rd,uint32_t Rn,uint32_t Rm)
    {
    *Rd=Rn + Rm;// modifica en el destino por el resultado de la suma
    Pc+=2;//Aumenta el PC para saltar a la siguiente direccion  cuando termine esta funcion
	if(((((Rn>>31)&1)==1) &&((Rm>>31)&1==1)&&((*Rd>>31)==0))||((((Rn>>31)&1)==1) &&((Rm>>31)==0)&&((*Rd>>31)==0))||((((Rn>>31))==0) &&((Rm>>31)&1==1)&&((*Rd>>31)==0))||((((Rn>>31)&1)==1) &&((Rm>>31)&1==1)&&((*Rd>>31)&1==1)))
	{
		c=1; //Bandera de carry se activa si el ultimo bit de los dos numeros es uno y el de el Rd da 0 o 1
    }
		else
    {
       c=0; //No se activa el carry
    }
	if((Rn>>31==0 && Rm>>31==0 && (*Rd>>31)&1==1 )||(((Rn>>31)&1==1)&&((Rm>>31)&1==1)&&(*Rd>>31==0)))
	{
		o=1; //Se activa si el ultimo bit de los dos registros son iguales y cambia  esto quiere decir que de la suma de dos nuemros de mismo signo da uno de diferente signo
	}
		else
		{
			o=0; //No se activa Bandera sobreflujo
		}
	if((*Rd>>31)&1==1)
	{
		n=1; //si el ultimo bit es 1, es negativo
	}
		else
		{
			n=0; // de lo contrario es positivo
		}
	if (*Rd==0)
	{
		s=1;//Si el registro de destino da 0 se activa
	}
		else
		{
			s=0; //De lo contrario no se activa la bandera
		}

}
void EOR(uint32_t *Rd,uint32_t Rn,uint32_t Rm)
{
	*Rd = Rn ^Rm; //modifica en el Destino el resultado de la EOR
	Pc+=2; //Aumenta el PC para saltar a la siguiente direccion  cuando termine esta funcion
	if (*Rd==0)
	{
		s=1; //Si el registro de destino da 0 se activa
	}
		else
		{
			s=0; //De lo contrario no se activa la bandera
		}
	if((*Rd>>31)&1==1 )
	{
		n=1; //si el ultimo bit es 1, es negativo
	}
		else
		{
			n=0; //de lo contrario es positivo
		}


 }
uint32_t OR(uint32_t *Rd,uint32_t Rn,uint32_t Rm)
{
	*Rd=Rn|Rm; //Modifica en el registro de destino el resultado de la OR
    Pc+=2; //Aumenta el PC para saltar a la siguiente direccion  cuando termine esta funcion
    if (*Rd==0)
	{
		s=1; //Si el registro de destino da 0 se activa
	}
		else
		{
			s=0; //De lo contrario no se activa la bandera
		}
	if((*Rd>>31)&1==1 )
	{
		n=1; //si el ultimo bit es 1, es negativo
	}
		else
		{
			n=0; //de lo contrario es positivo
		}
		
}

uint32_t AND (uint32_t *Rd,uint32_t Rn,uint32_t Rm)
{
	*Rd=Rn & Rm; //Modifica en el registro el resultado de la AND
	Pc+=2; //Aumenta el PC para saltar a la siguiente direccion  cuando termine esta funcion
	if (*Rd==0)
	{
		s=1; //si el registro de destino da 0 se activa
	}
		else
		{
			s=0; //De lo contrario no se activa la bandera
		}
	if((*Rd>>31)&1==1 )
	{
		n=1; //si el ultimo bit es 1, es negativo
	}
		else
		{
			n=0; //de lo contrario es positivo
		}
	printf("\nCARRY: %d\n",c); //imprime la bandera de Carry
    printf("ZERO: %d\n",s);   //imprime la bandera de Zero
    printf("OVERFLOW: %d\n",o); //imprime la bandera de Sobreflujo
    printf("NEGATIVO: %d",n);   //imprime la bandera de NEGATIVO
}
uint32_t MOV (uint32_t *Rd,uint32_t Rn)
{
	*Rd=Rn;//Mueve el valor del registro que se desea copiar al registro de destino
    Pc+=2; //Aumenta el PC para saltar a la siguiente direccion  cuando termine esta funcion
	if (*Rd==0)
	{
		s=1; //Aumenta el PC para saltar a la siguiente direccion  cuando termine esta funcion
	}
		else
		{
			s=0; ////De lo contrario no se activa la bandera
		}
	if((*Rd>>31)&1==1 )
	{
		n=1; //si el ultimo bit es 1, es negativo
	}
		else
		{
			n=0; //de lo contrario es positivo
		}

}


uint32_t SUB (uint32_t *Rd,uint32_t Rn,uint32_t Rm)
{
	Pc+=2; //Aumenta el PC para saltar a la siguiente direccion  cuando termine esta funcion
	Rm=~Rm+1; // complemento a dos
	*Rd=Rn+Rm; // Resta los dos registros
	if(((((Rn>>31)&1)==1) &&((Rm>>31)&1==1)&&((*Rd>>31)==0))||((((Rn>>31)&1)==1) &&((Rm>>31)==0)&&((*Rd>>31)==0))||((((Rn>>31))==0) &&((Rm>>31)&1==1)&&((*Rd>>31)==0))||((((Rn>>31)&1)==1) &&((Rm>>31)&1==1)&&((*Rd>>31)&1==1)))
	{
       c=1; //Bandera de carry se activa si el ultimo bit de los dos numeros es uno y el de el Rd da 0 o 1
    }
		else
    {
       c=0; //No se activa el carry
    }
	if((Rn>>31==0 && Rm>>31==0 && (*Rd>>31)&1==1 )||(((Rn>>31)&1==1)&&((Rm>>31)&1==1)&&(*Rd>>31==0)))
	{
		o=1; //Se activa si el ultimo bit de los dos registros son iguales y cambia  esto quiere decir que de la suma de dos nuemros de mismo signo da uno de diferente signo
	}
		else
		{
			o=0; //No se activa Bandera sobreflujo
		}
	if((*Rd>>31)&1==1)
	{
		n=1; //si el ultimo bit es 1, es negativo
	}
		else
		{
			n=0; //de lo contrario es positivo
		}
	if (*Rd==0)
	{
		s=1; //Aumenta el PC para saltar a la siguiente direccion  cuando termine esta funcion
	}
		else
		{
			s=0; ////De lo contrario no se activa la bandera
		}

}
void CMP(uint32_t Rn,uint32_t Rm)
{
	uint32_t Rd; //Registro de 32 bits
    Pc+=2; //Aumenta el PC para saltar a la siguiente direccion  cuando termine esta funcion
	Rm=~Rm+1; // complemento a dos
	*Rd=Rn+Rm; // Resta los dos registros
	if(((((Rn>>31)&1)==1) &&((Rm>>31)&1==1)&&((Rd>>31)==0))||((((Rn>>31)&1)==1) &&((Rm>>31)==0)&&((Rd>>31)==0))||((((Rn>>31))==0) &&((Rm>>31)&1==1)&&((Rd>>31)==0))||((((Rn>>31)&1)==1) &&((Rm>>31)&1==1)&&((Rd>>31)&1==1)))
	{
       c=1; //Bandera de carry se activa si el ultimo bit de los dos numeros es uno y el de el Rd da 0 o 1
    }
		else
    {
       c=0; //No se activa el carry
    }
	if((Rn>>31==0 && Rm>>31==0 && (*Rd>>31)&1==1 )||(((Rn>>31)&1==1)&&((Rm>>31)&1==1)&&(*Rd>>31==0)))
	{
		o=1; //Se activa si el ultimo bit de los dos registros son iguales y cambia  esto quiere decir que de la suma de dos nuemros de mismo signo da uno de diferente signo
	}
		else
		{
			o=0; //No se activa Bandera sobreflujo
		}
	if((*Rd>>31)&1==1)
	{
		n=1; //si el ultimo bit es 1, es negativo
	}
		else
		{
			n=0; //de lo contrario es positivo
		}
	if (*Rd==0)
	{
		s=1; //Aumenta el PC para saltar a la siguiente direccion  cuando termine esta funcion
	}
		else
		{
			s=0; ////De lo contrario no se activa la bandera
		}

}
uint32_t CMN (uint32_t Rn,uint32_t Rm)
{
    uint32_t Rd; //Registro de 32 bits
    Rd=Rn+Rm; //Resta los dos registro
    Pc+=2; //Aumenta el PC para saltar a la siguiente direccion  cuando termine esta funcion

	if(((((Rn>>31)&1)==1) &&((Rm>>31)&1==1)&&((Rd>>31)==0))||((((Rn>>31)&1)==1) &&((Rm>>31)==0)&&((Rd>>31)==0))||((((Rn>>31))==0) &&((Rm>>31)&1==1)&&((Rd>>31)==0))||((((Rn>>31)&1)==1) &&((Rm>>31)&1==1)&&((Rd>>31)&1==1)))
	{
       c=1; //Bandera de carry se activa si el ultimo bit de los dos numeros es uno y el de el Rd da 0 o 1
    }
		else
    {
       c=0; //No se activa el carry
    }
	if((Rn>>31==0 && Rm>>31==0 && (*Rd>>31)&1==1 )||(((Rn>>31)&1==1)&&((Rm>>31)&1==1)&&(*Rd>>31==0)))
	{
		o=1; //Se activa si el ultimo bit de los dos registros son iguales y cambia  esto quiere decir que de la suma de dos nuemros de mismo signo da uno de diferente signo
	}
		else
		{
			o=0; //No se activa Bandera sobreflujo
		}
	if((*Rd>>31)&1==1)
	{
		n=1; //si el ultimo bit es 1, es negativo
	}
		else
		{
			n=0; //de lo contrario es positivo
		}
	if (*Rd==0)
	{
		s=1; //Aumenta el PC para saltar a la siguiente direccion  cuando termine esta funcion
	}
		else
		{
			s=0; ////De lo contrario no se activa la bandera
		}

}
void MUL (uint32_t *Rd,uint32_t Rn,uint32_t Rm)
{
	Pc+=2; //Aumenta el PC para saltar a la siguiente direccion  cuando termine esta funcion
	*Rd=(Rn * Rm); // Multiplicacion entre los dos registro
	if((*Rd>>31)&1==1)
	{
		n=1; //si el ultimo bit es 1, es negativo
	}
		else
		{
			n=0; //de lo contrario es positivo
		}
	if (*Rd==0)
	{
		s=1; //Aumenta el PC para saltar a la siguiente direccion  cuando termine esta funcion
	}
		else
		{
			s=0; ////De lo contrario no se activa la bandera
		}
}
void TST (uint32_t Rn,uint32_t Rm)
{
    Pc+=2;  //Aumenta el PC para saltar a la siguiente direccion  cuando termine esta funcion
	if (Rn&Rm==0)
	{
		s=1; //Aumenta el PC para saltar a la siguiente direccion  cuando termine esta funcion
	}
		else
		{
			s=0; ////De lo contrario no se activa la bandera
		}
	if(((Rn&Rm)>>31)&1==1 )
	n=1; //si el ultimo bit es 1, es negativo
	}
		else
		{
			n=0; //de lo contrario es positivo
		}
}
void LSL(uint32_t *Rd,uint32_t Rn,uint32_t y)
{
    Pc+=2;//Aumenta el PC para saltar a la siguiente direccion  cuando termine esta funcion 
	*Rd=Rn<<y; // Desplazamiento logico a la izquierda
	Rn=Rn>>(32-y); //Desplazamiento a la derecha 

  if((Rn&1)==1)
  {
    c=1; //Bandera de carry se activa si el ultimo bit de los dos numeros es uno y el de el Rd da 0 o 1
    }
		else
    {
       c=0; //No se activa el carry
    }
	if((*Rd>>31)&1==1)
	{
		n=1; //si el ultimo bit es 1, es negativo
	}
		else
		{
			n=0; //de lo contrario es positivo
		}
	if (*Rd==0)
	{
		s=1; //Aumenta el PC para saltar a la siguiente direccion  cuando termine esta funcion
	}
		else
		{
			s=0; ////De lo contrario no se activa la bandera
		}
}
void LSR (uint32_t *Rd,uint32_t Rn,int y)
{
    Pc+=2; //Aumenta el PC para saltar a la siguiente direccion  cuando termine esta funcion
   *Rd=Rn>>y; //Desplazamiento logico a la derecha
   if((Rn&1)==1)
    {
		c=1; //Bandera de carry se activa si el ultimo bit de los dos numeros es uno y el de el Rd da 0 o 1
    }
		else
    {
       c=0; //No se activa el carry
    }
	if((*Rd>>31)&1==1)
	{
		n=1; //si el ultimo bit es 1, es negativo
	}
		else
		{
			n=0; //de lo contrario es positivo
		}
	if (*Rd==0)
	{
		s=1; //Aumenta el PC para saltar a la siguiente direccion  cuando termine esta funcion
	}
		else
		{
			s=0; ////De lo contrario no se activa la bandera
		}
}
void ROR (uint32_t *Rd,uint32_t Rn,int y)
{
    Pc+=2;//Aumenta el PC para saltar a la siguiente direccion  cuando termine esta funcion
	uint32_t s; //Registro de 32 bits
    s=(Rn>>(32-y))&2147483647; //Rotacion a la derecha
	*Rd=Rn<<y; //Desplazamiento a la izquierda
	*Rd=*Rd|s; //Agrgar el bloque de bits al Rd
	*Rd=*Rd&4294967295; //Garntiza que no haya desbordamiento
	printf("%d",Rd); //Imprime el bloque de bits de Rd
	if((*Rd>>31)&1==1)
	{
    n=1; //si el ultimo bit es 1, es negativo
	}
		else
		{
			n=0; //de lo contrario es positivo
		}
	if (*Rd==0)
	{
		s=1; //Aumenta el PC para saltar a la siguiente direccion  cuando termine esta funcion
	}
		else
		{
			s=0; ////De lo contrario no se activa la bandera
		}
}

void ASR (uint32_t *Rd,uint32_t Rn,int y)
{
	Pc+=2; //Aumenta el PC para saltar a la siguiente direccion  cuando termine esta funcion
	uint32_t s; //Registro de 32 bits
	s=~0<<(32-y); // Desplazamiento de un cero complemento
	*Rd=Rn>>y; //Desplazamiento aritmetico a la derecha
	*Rd=*Rd|s; //Agrgar el bloque de bits al Rd
	if((*Rd>>31)&1==1)
	{
		n=1; //si el ultimo bit es 1, es negativo
	}
		else
		{
			n=0; //de lo contrario es positivo
		}
	if (*Rd==0)
	{
		s=1; //Aumenta el PC para saltar a la siguiente direccion  cuando termine esta funcion
	}
		else
		{
			s=0; ////De lo contrario no se activa la bandera
		}
}


void REV (uint32_t *Rd,uint32_t Rn)
{
	Pc+=2; //Aumenta el PC para saltar a la siguiente direccion  cuando termine esta funcion
	uint32_t x=255,y,p,r; // Registro de 32 bits
	*Rd=(Rn&x)<<24; //Hacen bloques de ocho bits
	y= (Rn>>24)&x; //Corrimientro de la primera posicion a la ultima posicion
	*Rd=*Rd|((Rn&(x<<8))<<8); // Desplaza los primeros ocho bits y los demas los convierte en cero
	*Rd=*Rd|((Rn&(x<<16))>>8); // Desplaza los primeros 16 bits y los demas los convierte en cero

}

void BIC (uint32_t *Rd,uint32_t Rn,uint32_t Rm)
{
	Pc+=2; //Aumenta el PC para saltar a la siguiente direccion  cuando termine esta funcion
	*Rd=Rn & ~Rm; //AND entre un registro y el complemento del otro
	if((*Rd>>31)&1==1)
   {
    n=1; //si el ultimo bit es 1, es negativo
	}
		else
		{
			n=0; //de lo contrario es positivo
		}
	if (*Rd==0)
	{
		s=1; //Aumenta el PC para saltar a la siguiente direccion  cuando termine esta funcion
	}
		else
		{
			s=0; ////De lo contrario no se activa la bandera
		}
}

void MVN(uint32_t *Rd,uint32_t Rn)
{
    Pc+=2; //Aumenta el PC para saltar a la siguiente direccion  cuando termine esta funcion
	*Rd=~Rn; //Guarda el complemento del registro
	if((*Rd>>31)&1==1)
	{
    n=1; //si el ultimo bit es 1, es negativo
	}
		else
		{
			n=0; //de lo contrario es positivo
		}
	if (*Rd==0)
	{
		s=1; //Aumenta el PC para saltar a la siguiente direccion  cuando termine esta funcion
	}
		else
		{
			s=0; ////De lo contrario no se activa la bandera
		}
}
void NOP()
{
	//No hace nada
}
void RSB (uint32_t *Rd,uint32_t Rn)
{
	Pc+=2; //Aumenta el PC para saltar a la siguiente direccion  cuando termine esta funcion
	*Rd=~Rn+1; //Obtiene el complemento a dos
	if((*Rd>>31)&1==1)
	{
    n=1; //si el ultimo bit es 1, es negativo
	}
		else
		{
			n=0; //de lo contrario es positivo
		}
	if (*Rd==0)
	{
		s=1; //Aumenta el PC para saltar a la siguiente direccion  cuando termine esta funcion
	}
		else
		{
			s=0; ////De lo contrario no se activa la bandera
		}
}
void SBC (uint32_t *Rd,uint32_t Rn,uint32_t Rm)
{
	Pc+=2; //Aumenta el PC para saltar a la siguiente direccion  cuando termine esta funcion
	Rm=~Rm+1;// Resta el carry al menos -1
	Rm=Rm-c;// Resta con carry
	*Rd=Rn+Rm; //Resta el carry
 if(((((Rn>>31)&1)==1) &&((Rm>>31)&1==1)&&((*Rd>>31)==0))||((((Rn>>31)&1)==1) &&((Rm>>31)==0)&&((*Rd>>31)==0))||((((Rn>>31))==0) &&((Rm>>31)&1==1)&&((*Rd>>31)==0))||((((Rn>>31)&1)==1) &&((Rm>>31)&1==1)&&((*Rd>>31)&1==1)))
	{
       c=1; //Bandera de carry se activa si el ultimo bit de los dos numeros es uno y el de el Rd da 0 o 1
    }
		else
    {
       c=0; //No se activa el carry
    }
	if((Rn>>31==0 && Rm>>31==0 && (*Rd>>31)&1==1 )||(((Rn>>31)&1==1)&&((Rm>>31)&1==1)&&(*Rd>>31==0)))
	{
		o=1; //Se activa si el ultimo bit de los dos registros son iguales y cambia  esto quiere decir que de la suma de dos nuemros de mismo signo da uno de diferente signo
	}
		else
		{
			o=0; //No se activa Bandera sobreflujo
		}
	if((*Rd>>31)&1==1)
	{
		n=1; //si el ultimo bit es 1, es negativo
	}
		else
		{
			n=0; //de lo contrario es positivo
		}
	if (*Rd==0)
	{
		s=1; //Aumenta el PC para saltar a la siguiente direccion  cuando termine esta funcion
	}
		else
		{
			s=0; ////De lo contrario no se activa la bandera
		}
}

void BEQ(int Sal)
{
    if(s==1)
	{
		Pc+=Sal*2; // Un salto cuando si se condicion del if
    }
		else
		{
			Pc+=2; //Aumenta el PC para saltar a la siguiente direccion  cuando termine esta funcion
		}
}
void BNE(int Sal)
{
    if(s==0)
	{
		Pc+=Sal*2; // Un salto si se cumple la condicion
    }
    else
	{
		Pc+=2; // De lo contrario se aumenta el PC para saltar a la siguiente direccion
    }
}
void BCS(int Sal)
{
    if(c==1)
	{
        Pc+=Sal*2; // Un salto si se cumple la condicion
    }
		else
		{
			Pc+=2; // De lo contrario se aumenta el PC para saltar a la siguiente direccion
		}
}
void BCC(int Sal)
{
    if(c==0)
	{
        Pc+=Sal*2; // Un salto si se cumple la condicion
    }
		else
		{
			Pc+=2; // De lo contrario se aumenta el PC para saltar a la siguiente direccion
		}
}
void BMI(int Sal)
{
    if(n==1)
	{
        Pc+=Sal*2; // Un salto si se cumple la condicion
    }
		else
		{
			Pc+=2; // De lo contrario se aumenta el PC para saltar a la siguiente direccion
		}
}
void BPL(int Sal)
{
    if(n==o)
	{
        Pc+=Sal*2; // Un salto si se cumple la condicion
    }
		else
		{
			Pc+=2; // De lo contrario se aumenta el PC para saltar a la siguiente direccion
		}
}
void BVS(int Sal)
{
    if(o==1)
	{
        Pc+=Sal*2; // Un salto si se cumple la condicion
    }
		else
		{
			Pc+=2; // De lo contrario se aumenta el PC para saltar a la siguiente direccion
		}
}
void BVL(int Sal)
{
    if(o==0)
	{
        Pc+=Sal*2; // Un salto si se cumple la condicion
    }
		else
		{
			Pc+=2; // De lo contrario se aumenta el PC para saltar a la siguiente direccion
		}
}
void BHI(int Sal)
{
    if(c==1&&s==0)
	{
        Pc+=Sal*2; // Un salto si se cumple la condicion
    }
		else
		{
			Pc+=2; // De lo contrario se aumenta el PC para saltar a la siguiente direccion
		}
}

void BLS(int Sal)
{
    if(c==0||s==1)
	{
        Pc+=Sal*2; // Un salto si se cumple la condicion
    }
		else
		{
			Pc+=2; // De lo contrario se aumenta el PC para saltar a la siguiente direccion
		}
}
void BGE(int Sal){
    if(n==o)
	{
        Pc+=Sal*2; // Un salto si se cumple la condicion
    }
    else
	{
		Pc+=2; // De lo contrario se aumenta el PC para saltar a la siguiente direccion
    }
}
void BLT(int Sal)
{
    if(n!=o)
	{
        Pc+=Sal*2; // Un salto si se cumple la condicion
    }
		else
		{
			Pc+=2; // De lo contrario se aumenta el PC para saltar a la siguiente direccion
		}

}
void BGT(int Sal)
{
    if(s==0&&n==o)
	{
        Pc+=Sal*2; // Un salto si se cumple la condicion
    }
		else
		{
			Pc+=2; // De lo contrario se aumenta el PC para saltar a la siguiente direccion
		}
}
void BLE(int Sal)
{
    if(s==1||n!=o)
	{
        Pc+=Sal*2; // Un salto si se cumple la condicion
    }
		else
		{
			Pc+=2; // De lo contrario se aumenta el PC para saltar a la siguiente direccion
		}
}
void B(int Sal)
{
	Pc+=Sal*2+; // Un salto de dos
}
void BL(int Sal)
{
	LR=Pc+2; // Un salto de dos
	Pc+=Sal*2; //c+Un salto de dos
}
void BX(int Sal)
{
	Pc=Sal; //Un salto a la linea siguiente
}

void PBanderas ()
{
    printf("CARRY:----- %d\n",c); //Imprime la bandera de Carry
    printf("ZERO:------ %d\n",s); //Imprime la bandera de Zero
    printf("OVERFLOW:-- %d\n",o); //Imprime la bandera de Sobreflujo
    printf("NEGATIVO:-- %d\n",n); //Imprime la bandera de Negativo
}





