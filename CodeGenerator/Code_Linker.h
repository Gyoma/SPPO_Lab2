#pragma once
#include "Units.h"
#include "Code_Generator.h"


/*
    �����������. 
    ��������� ��������� ���� �����, ����� �������� ���, ��������� �������������� ����� ����
*/

class CodeLinker
{
public:

    explicit CodeLinker() = delete;

    static std::string compile(const CodeGenerator& generator);
};
