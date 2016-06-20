/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "unity.h"
#include "cmock.h"
#include "mock_MockFunction.h"

typedef struct _CMOCK_readButton_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int ReturnVal;
  int CallOrder;

} CMOCK_readButton_CALL_INSTANCE;

static struct mock_MockFunctionInstance
{
  int readButton_IgnoreBool;
  int readButton_FinalReturn;
  CMOCK_readButton_CALLBACK readButton_CallbackFunctionPointer;
  int readButton_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE readButton_CallInstance;
} Mock;

extern jmp_buf AbortFrame;
extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_MockFunction_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  if (Mock.readButton_IgnoreBool)
    Mock.readButton_CallInstance = CMOCK_GUTS_NONE;
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.readButton_CallInstance, cmock_line, "Function 'readButton' called less times than expected.");
  if (Mock.readButton_CallbackFunctionPointer != NULL)
    Mock.readButton_CallInstance = CMOCK_GUTS_NONE;
}

void mock_MockFunction_Init(void)
{
  mock_MockFunction_Destroy();
}

void mock_MockFunction_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  Mock.readButton_CallbackFunctionPointer = NULL;
  Mock.readButton_CallbackCalls = 0;
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

int readButton(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_readButton_CALL_INSTANCE* cmock_call_instance = (CMOCK_readButton_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.readButton_CallInstance);
  Mock.readButton_CallInstance = CMock_Guts_MemNext(Mock.readButton_CallInstance);
  if (Mock.readButton_IgnoreBool)
  {
    if (cmock_call_instance == NULL)
      return (int)Mock.readButton_FinalReturn;
    Mock.readButton_FinalReturn = cmock_call_instance->ReturnVal;
    return (int)cmock_call_instance->ReturnVal;
  }
  if (Mock.readButton_CallbackFunctionPointer != NULL)
  {
    return Mock.readButton_CallbackFunctionPointer(Mock.readButton_CallbackCalls++);
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'readButton' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'readButton' called earlier than expected.");
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'readButton' called later than expected.");
  return cmock_call_instance->ReturnVal;
}

void readButton_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_readButton_CALL_INSTANCE));
  CMOCK_readButton_CALL_INSTANCE* cmock_call_instance = (CMOCK_readButton_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.readButton_CallInstance = CMock_Guts_MemChain(Mock.readButton_CallInstance, cmock_guts_index);
  Mock.readButton_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.readButton_IgnoreBool = (int)1;
}

void readButton_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_readButton_CALL_INSTANCE));
  CMOCK_readButton_CALL_INSTANCE* cmock_call_instance = (CMOCK_readButton_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.readButton_CallInstance = CMock_Guts_MemChain(Mock.readButton_CallInstance, cmock_guts_index);
  Mock.readButton_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  cmock_call_instance->ReturnVal = cmock_to_return;
}

void readButton_StubWithCallback(CMOCK_readButton_CALLBACK Callback)
{
  Mock.readButton_CallbackFunctionPointer = Callback;
}

