#pragma once
#include "Units.h"
#include "Code_Generator.h"


/*
    Компоновщик. 
    Принимает генератор кода языка, далее собирает код, генерируя соответсвующие блоки кода
*/

class CodeLinker
{
public:

    explicit CodeLinker() = delete;

    static std::string compile(const CodeGenerator& generator);
};
