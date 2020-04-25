#include "cpp_Codegenerator.h"

cpp_CodeGenerator::cpp_CodeGenerator() {}

inline cpp_ClassUnit* cpp_CodeGenerator::getClassCode(std::string name, uint32_t modifier) const
{
    //return nullptr;
    return new cpp_ClassUnit(name, ClassUnit::DEFAULT);
}

inline cpp_MethodUnit* cpp_CodeGenerator::getMethodCode(std::string name, std::string returnType,
    uint32_t flags, const std::vector<std::string>& args) const
{
    //return nullptr;
    return new cpp_MethodUnit(name, returnType, flags, args);
}

inline MemberUnit* cpp_CodeGenerator::getMemberCode(std::string type, std::string name) const
{
    //return nullptr;
    return new MemberUnit(type, name);
}

inline cpp_PrintUnit* cpp_CodeGenerator::getPrintOperCode(std::string text) const
{
    //return nullptr;
    return new cpp_PrintUnit(text);
}