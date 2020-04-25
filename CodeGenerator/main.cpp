#include <iostream>
#include "Code_Linker.h"
#include "cpp_CodeGenerator.h"
#include "java_CodeGenerator.h"
#include "cs_CodeGenerator.h"

using namespace std;

int main()
{
    cout << CodeLinker::compile(cpp_CodeGenerator()) << endl;
    cout << CodeLinker::compile(java_CodeGenerator()) << endl;
    cout << CodeLinker::compile(cs_CodeGenerator()) << endl;

    getchar();
    return 0;
}