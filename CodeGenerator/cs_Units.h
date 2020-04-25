#pragma once
#include "Units.h"

class cs_ClassUnit : public ClassUnit
{
public:

    explicit cs_ClassUnit(const std::string& name, Flags modifier);

    std::string compile(unsigned int level = 0) const;
};

class cs_MethodUnit : public MethodUnit
{
public:

    explicit cs_MethodUnit(const std::string& name,
        const std::string& returnType,
        Flags flags, const std::vector<std::string>& args);

    std::string compile(unsigned int level = 0) const;
};

class cs_PrintUnit : public PrintUnit
{
public:

    explicit cs_PrintUnit(const std::string& text);

    std::string compile(unsigned int level = 0) const;
};

