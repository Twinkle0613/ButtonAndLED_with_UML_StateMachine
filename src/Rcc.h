#ifndef Rcc_H
#define Rcc_H

#include <stdint.h>
#include "Host.h"
#include "Registers.h"


typedef struct RCC_t RccType;

struct RCC_t{
 uint32_t CR;
 uint32_t PLLCFGR;
 uint32_t CFGR;
 uint32_t CIR;
 uint32_t AHB1RSTR;
 uint32_t AHB2RSTR;
 uint32_t AHB3RSTR;
 uint32_t Reserved0x1C;
 uint32_t APB1RSTR;
 uint32_t APB2RSTR;
 uint32_t Reserved0x20;
 uint32_t Reserved0x2C;
 uint32_t AHB1ENR;
 uint32_t AHB2ENR;
 uint32_t AHB3ENR;
 uint32_t Reserved0x3C;
 uint32_t APB1ENR;
 uint32_t APB2ENR;
 uint32_t Reserved0x48;
 uint32_t Reserved0x4C;
 uint32_t AHB1LPENR;
 uint32_t AHB2LPENR;
 uint32_t AHB3LPENR;
 uint32_t Reserved0x5C;
 uint32_t APB1LPENR;
 uint32_t APB2LPENR;
 uint32_t Reserved0x68;
 uint32_t Reserved0x6C;
 uint32_t BDCR;
 uint32_t CSR;
 uint32_t Reserved0x78;
 uint32_t Reserved0x7C;
 uint32_t SSCGR;
 uint32_t PLLI2SCFGR;
};

#define rcc	( (RccType*)RCC_BASE_ADDRESS )

#endif // Rcc_H
