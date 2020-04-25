#include "java_Units.h"

java_ClassUnit::java_ClassUnit(const std::string& name, Flags modifier) :
    ClassUnit(name, modifier)
{}

std::string java_ClassUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level);

    switch (m_modifier)
    {
    case ClassUnit::PUBLIC:
        result += "public ";
        break;
    case ClassUnit::PRIVATE:
        result += "private ";
        break;
    case ClassUnit::PROTECTED:
        result += "pprotected ";
        break;
    }

    result += "class " + m_name + " {\n";

    for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i)
    {
        if (m_fields[i].empty())
            continue;

        for (const auto& f : m_fields[i])
        {
            if (f)
                result += generateShift(level + 1) + ACCESS_MODIFIERS[i] + " " + f->compile(0);
        }
        result += "\n";
    }

    result += generateShift(level) + "};\n";

    return result;
}

java_MethodUnit::java_MethodUnit(const std::string& name,
    const std::string& returnType,
    Flags flags, const std::vector<std::string>& args) :
    MethodUnit(name, returnType, flags, args)
{}

std::string java_MethodUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level);

    if (m_flags & STATIC)
    {
        result += "static ";
    }

    result += m_returnType + " ";
    result += m_name + "(";

    {
        size_t size = m_args.size();
        for (size_t i = 0; i < size; ++i)
        {
            result += m_args[i];
            if (i < size - 1)
                result += ", ";
        }
    }

    result += ")";
    result += " {\n";

    for (const auto& b : m_body)
    {
        if (b)
            result += b->compile(level + 2);
    }

    result += generateShift(level + 1) + "}\n";

    return result;
}

java_PrintUnit::java_PrintUnit(const std::string& text) :
    PrintUnit(text)
{}

std::string java_PrintUnit::compile(unsigned int level) const
{
    return generateShift(level) + "System.out.println( \"" + m_text +
        "\" );\n";
}