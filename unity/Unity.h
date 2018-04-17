#ifndef TEST_UNITY_H
#define TEST_UNITY_H

#include "mbed.h"

#ifdef __cplusplus
extern "C"
{
#endif

void unity_test_start();
void unity_test_end();

void unity_fail(const char* msg, const int line);
void unity_success(const char* msg, const int line);


#define UNITY_TEST_FAIL(line, message)      unity_fail((message), (line))
#define UNITY_TEST_SUCCESS(line, message)   unity_success((message), (line))
#define UNITY_TEST_ASSERT(condition, line, message)   \
  if (condition) {UNITY_TEST_SUCCESS((line), "");} else {UNITY_TEST_FAIL((line), (message));}

#define TEST_ASSERT(condition) \
  UNITY_TEST_ASSERT((condition), __LINE__, "")

#define TEST_ASSERT_MESSAGE(condition, message) \
  UNITY_TEST_ASSERT((condition), __LINE__, (message))


typedef void (*UnityTestFunction)(void);
void unity_test_run(UnityTestFunction func, const char* func_name);
#define RUN_TEST(func) unity_test_run(func, #func)


#ifdef __cplusplus
}
#endif


#endif