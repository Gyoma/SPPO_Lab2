#include "cs_CodeGenerator.h"

cs_CodeGenerator::cs_CodeGenerator() {}

inline cs_ClassUnit* cs_CodeGenerator::getClassCode(std::string name, uint32_t modifier) const
{
    return new cs_ClassUnit(name, modifier);
}

inline cs_MethodUnit* cs_CodeGenerator::getMethodCode(std::string name, std::string returnType,
    uint32_t flags, const std::vector<std::string>& args) const
{
    return new cs_MethodUnit(name, returnType, flags, args);
}

inline MemberUnit* cs_CodeGenerator::getMemberCode(std::string type, std::string name) const
{
    return new MemberUnit(type, name);
}

inline cs_PrintUnit* cs_CodeGenerator::getPrintOperCode(std::string text) const
{
    return new cs_PrintUnit(text);
}