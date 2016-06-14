#include "unity.h"
#include "Rcc.h"
#include "Registers.h"
#include <malloc.h>
#include "Host.h"


void setUp(void)
{
   HostRcc= malloc((sizeof(RccType)));
}
void tearDown(void)
{
    free(HostRcc);
    HostRcc = NULL;
}

void test_rcc_AHB1RSTR(void){
  
  rcc->AHB1RSTR = 0x00000001;
  TEST_ASSERT_EQUAL_INT32(0x00000001,rcc->AHB1RSTR);
  
}

