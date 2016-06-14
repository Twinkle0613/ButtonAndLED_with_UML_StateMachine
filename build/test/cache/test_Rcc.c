#include "Host.h"
#include "Registers.h"
#include "Rcc.h"
#include "unity.h"








void setUp(void)

{

   HostRcc= malloc((sizeof(RccType)));

}

void tearDown(void)

{

    free(HostRcc);

    HostRcc = ((void *)0);

}



void test_rcc_AHB1RSTR(void){



  ( (RccType*)((uint32_t)HostRcc) )->AHB1RSTR = 0x00000001;

  UnityAssertEqualNumber((_U_SINT)(_US32)((0x00000001)), (_U_SINT)(_US32)((( (RccType*)((uint32_t)HostRcc) )->AHB1RSTR)), (((void *)0)), (_U_UINT)21, UNITY_DISPLAY_STYLE_INT32);



}
