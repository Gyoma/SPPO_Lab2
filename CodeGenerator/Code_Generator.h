#pragma once
#include "Units.h"

/*
    абстрактный генератор кода (интерфейс)
*/

class CodeGenerator
{
public:

    virtual ClassUnit* getClassCode(std::string name, uint32_t modifier = ClassUnit::DEFAULT) const = 0;

    virtual MethodUnit* getMethodCode(std::string name, std::string returnType,
        uint32_t flags = MethodUnit::DEFAULT,
        const std::vector<std::string>& args = std::vector<std::string>()) const = 0;

    virtual MemberUnit* getMemberCode(std::string type, std::string name) const = 0;

    virtual PrintUnit* getPrintOperCode(std::string text) const = 0;

    virtual ~CodeGenerator() = default;
};

