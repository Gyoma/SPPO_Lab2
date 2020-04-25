#include "cpp_Units.h"

cpp_ClassUnit::cpp_ClassUnit(const std::string& name, Flags modifier = ClassUnit::DEFAULT) :
    ClassUnit(name, ClassUnit::DEFAULT)
{}

std::string cpp_ClassUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level) + "class " + m_name + " {\n";

    for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i)
    {
        if (m_fields[i].empty())
            continue;

        result += ACCESS_MODIFIERS[i] + ":\n";
        for (const auto& f : m_fields[i])
        {
            result += f->compile(level + 1);
        }
        result += "\n";
    }

    result += generateShift(level) + "};\n";

    return result;
}

cpp_MethodUnit::cpp_MethodUnit(const std::string& name, 
    const std::string& returnType, Flags flags, 
    const std::vector<std::string>& args) :
    MethodUnit(name, returnType, flags, args)
{}

std::string cpp_MethodUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level);

    if (m_flags & STATIC)
    {
        result += "static ";
    }
    else if (m_flags & VIRTUAL)
    {
        result += "virtual ";
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

    if (m_flags & CONST)
    {
        result += " const";
    }

    result += " {\n";

    for (const auto& b : m_body)
    {
        result += b->compile(level + 1);
    }

    result += generateShift(level) + "}\n";

    return result;
}

cpp_PrintUnit::cpp_PrintUnit(const std::string& text) :
    PrintUnit(text)
{}

std::string cpp_PrintUnit::compile(unsigned int level) const
{
    return generateShift(level) + "printf( \"" + m_text +
        "\" );\n";
}
