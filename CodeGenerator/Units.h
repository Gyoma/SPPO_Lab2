#pragma once
#include <string>
#include <memory>
#include <vector>

/*
    �������� ���� ��������� ������ ����

    Unit:
        ����� ������� ����������� �����

        string m_name - ��� ������ (��� ����� ������, ������, ����-�������)

    ClassUnit:
        ����������� ����� ����� ������

        vector< Fields > m_fields - ����� ����, ������� ������ ���� ������ ����� �����
        ������: ������, ����-������ ������ ������
        � m_fields ����� 3 ���� ��� ���������� � ���� ������: public, private, protected

    MethodUnit:
        ����������� ����� ����� ������ ������

        string m_returnType - ������������ ���
        Flags m_flags - ������������ ������ (virtual, const, static, e.t.c)
        vector< shared_ptr< Unit > > m_body - ���������� m_fields  � ClassUnit
        vector< string > m_args - ��������� ������

    MemberUnit:
        ����������� ����� ����� ����-������ ������

        type - ��� ����������

    PrintUnit:
        ���������� ����� ������ ������

        m_text - �����
*/


class Unit
{
public:
    using Flags = unsigned int; //��� ������������� �����
public:

    explicit Unit(std::string name = "");
    
    virtual ~Unit() = default;
    
    virtual void add(const std::shared_ptr< Unit >&, Flags);

    virtual std::string compile(unsigned int level = 0) const = 0;

protected:
    virtual std::string generateShift(unsigned int level) const;

    std::string m_name;
};


class ClassUnit : public Unit
{
public:
    enum AccessModifier
    {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        DEFAULT
    };

    explicit ClassUnit(const std::string& name, Flags modifier);
    
    virtual ~ClassUnit() = default;

    void add(const std::shared_ptr< Unit >& unit, Flags flags);



protected:
    Flags m_modifier;
    using Fields = std::vector< std::shared_ptr< Unit > >;
    std::vector< Fields > m_fields;
    static const std::vector< std::string > ACCESS_MODIFIERS;
};

class MethodUnit : public Unit
{
public:
    enum Modifier
    {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2,
        DEFAULT = 0 //��� �������������
    };

    MethodUnit(const std::string& name,
        const std::string& returnType,
        Flags flags, const std::vector<std::string>& args);

    virtual ~MethodUnit() = default;

    void add(const std::shared_ptr< Unit >& unit, Flags = DEFAULT);

protected:
    std::string m_returnType;
    Flags m_flags;
    std::vector< std::shared_ptr< Unit > > m_body;
    std::vector< std::string > m_args;
};

class MemberUnit : public Unit
{
public:

    explicit MemberUnit(std::string Type, std::string Name);

    virtual ~MemberUnit() = default;

    std::string compile(unsigned int level = 0) const;

private:

    std::string type;
};

class PrintUnit : public Unit
{
public:

    explicit PrintUnit(const std::string& Text);

    virtual ~PrintUnit() = default;

protected:
    std::string m_text;
};