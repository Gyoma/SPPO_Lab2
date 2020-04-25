#pragma once
#include "Code_Generator.h"
#include "cpp_Units.h"

class cpp_CodeGenerator : public CodeGenerator
{

public:

    explicit cpp_CodeGenerator();

    cpp_ClassUnit* getClassCode(std::string name, uint32_t modifier = ClassUnit::DEFAULT) const;

    cpp_MethodUnit* getMethodCode(std::string name, std::string returnType,
        uint32_t flags = MethodUnit::DEFAULT,
        const std::vector<std::string>& args = std::vector<std::string>()) const;

    MemberUnit* getMemberCode(std::string type, std::string name) const;

    cpp_PrintUnit* getPrintOperCode(std::string text) const;
};