#include <cstdlib>
#include <iostream>
#include "TestHarness.h"

using namespace std;

int main(int argc, char *argv[])
{
    TestResult tr;
    TestRegistry::runAllTests(tr);

    system("PAUSE");
    return EXIT_SUCCESS;
}
