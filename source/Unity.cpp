#include "Unity.h"

RawSerial pc(USBTX, USBRX);

static int _total_test_case;
static int _total_test_failed;
static const char* _current_func_name;

void unity_test_run(UnityTestFunction func, const char* func_name) {
    _current_func_name = func_name;
    func();
}

void unity_success(const char* msg, const int line) {
    _total_test_case++;
    // pc.printf("...asserting(line: %04d) - result: PASSED \r\n", line);
}

void unity_fail(const char* msg, const int line) {

    pc.printf("...asserting[line: %04d] failed in function(%s) (%s)\r\n", line, _current_func_name, msg);
    _total_test_case++;
    _total_test_failed++;
}

void unity_test_waiting_to_go() {

    while(pc.getc() != 'g');
    _total_test_case = 0;
    _total_test_failed = 0;
    pc.puts("go...\r\n");
}

void unity_test_start() {
    // Set baud to 9600
    pc.baud(9600);
    pc.format();

    pc.puts("Press g to start testing...\r\n");
    unity_test_waiting_to_go();
}

void unity_test_end() {
    pc.printf("Total%3d testing, %3d failed.\r\n", _total_test_case, _total_test_failed);
}