#include "java_CodeGenerator.h"

java_CodeGenerator::java_CodeGenerator() {}

inline java_ClassUnit* java_CodeGenerator::getClassCode(std::string name, uint32_t modifier) const
{
    return new java_ClassUnit(name, modifier);
}

inline java_MethodUnit* java_CodeGenerator::getMethodCode(std::string name, std::string returnType,
    uint32_t flags, const std::vector<std::string>& args) const
{
    return new java_MethodUnit(name, returnType, flags, args);
}

inline MemberUnit* java_CodeGenerator::getMemberCode(std::string type, std::string name) const
{
    return new MemberUnit(type, name);
}

inline java_PrintUnit* java_CodeGenerator::getPrintOperCode(std::string text) const
{
    return new java_PrintUnit(text);
}