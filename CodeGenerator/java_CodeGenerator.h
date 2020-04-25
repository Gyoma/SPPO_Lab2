#pragma once
#include "Code_Generator.h"
#include "java_Units.h"

class java_CodeGenerator : public CodeGenerator
{

public:

    explicit java_CodeGenerator();

    java_ClassUnit* getClassCode(std::string name, uint32_t modifier = ClassUnit::DEFAULT) const;

    java_MethodUnit* getMethodCode(std::string name, std::string returnType,
        uint32_t flags = MethodUnit::DEFAULT,
        const std::vector<std::string>& args = std::vector<std::string>()) const;

    MemberUnit* getMemberCode(std::string type, std::string name) const;

    java_PrintUnit* getPrintOperCode(std::string text) const;
};
