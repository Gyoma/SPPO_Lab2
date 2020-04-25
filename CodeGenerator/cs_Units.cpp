#include "cs_Units.h"

cs_ClassUnit::cs_ClassUnit(const std::string& name, Flags modifier) :
    ClassUnit(name, modifier)
{}

std::string cs_ClassUnit::compile(unsigned int level) const
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
            result += generateShift(level + 1) + ACCESS_MODIFIERS[i] + " " + f->compile();
        }
        result += "\n";
    }

    result += generateShift(level) + "};\n";

    return result;
}

cs_MethodUnit::cs_MethodUnit(const std::string& name,
    const std::string& returnType,
    Flags flags, const std::vector<std::string>& args) :
    MethodUnit(name, returnType, flags, args)
{}

std::string cs_MethodUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level);

    if (m_flags & STATIC)
        result += "static ";
    else if (m_flags & VIRTUAL)
        result += "virtual ";

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
        result += b->compile(level + 2);
    }

    result += generateShift(level + 1) + "}\n";

    return result;
}

cs_PrintUnit::cs_PrintUnit(const std::string& text) :
    PrintUnit(text)
{}

std::string cs_PrintUnit::compile(unsigned int level) const
{
    return generateShift(level) + "Console.WriteLine( \"" + m_text +
        "\" );\n";
}