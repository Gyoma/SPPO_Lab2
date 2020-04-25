#pragma once
#include "Units.h"

class java_ClassUnit : public ClassUnit
{
public:

    explicit java_ClassUnit(const std::string& name, Flags modifier);

    std::string compile(unsigned int level = 0) const;
};

class java_MethodUnit : public MethodUnit
{
public:

    explicit java_MethodUnit(const std::string& name,
        const std::string& returnType,
        Flags flags, const std::vector<std::string>& args);

    std::string compile(unsigned int level = 0) const;
};

class java_PrintUnit : public PrintUnit
{
public:

    explicit java_PrintUnit(const std::string& text);

    std::string compile(unsigned int level = 0) const;
};

