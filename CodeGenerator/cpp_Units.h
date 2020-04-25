#pragma once
#include "Units.h"

class cpp_ClassUnit : public ClassUnit
{
public:

    explicit cpp_ClassUnit(const std::string& name, Flags modifier);

    std::string compile(unsigned int level = 0) const;
};

class cpp_MethodUnit : public MethodUnit
{
public:

    explicit cpp_MethodUnit(const std::string& name, 
        const std::string& returnType, Flags flags, 
        const std::vector<std::string>& args);

    std::string compile(unsigned int level = 0) const;
};

class cpp_PrintUnit : public PrintUnit
{
public:

    explicit cpp_PrintUnit(const std::string& text);

    std::string compile(unsigned int level = 0) const;
};
