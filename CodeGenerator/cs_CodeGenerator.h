#pragma once
#include "Code_Generator.h"
#include "cs_Units.h"

class cs_CodeGenerator : public CodeGenerator
{

public:
    explicit cs_CodeGenerator();

    cs_ClassUnit* getClassCode(std::string name, uint32_t modifier = ClassUnit::DEFAULT) const;

    cs_MethodUnit* getMethodCode(std::string name, std::string returnType,
        uint32_t flags = MethodUnit::DEFAULT,
        const std::vector<std::string>& args = std::vector<std::string>()) const;

    MemberUnit* getMemberCode(std::string type, std::string name) const;

    cs_PrintUnit* getPrintOperCode(std::string text) const;
};