#include "Code_Linker.h"

std::string CodeLinker::compile(const CodeGenerator& generator)
{
    /*
        Получаем приставку того языка, генератор которого передан
        Например: сpp_ , java_ , cs_
    */
    std::string prefix = typeid(generator).name();
    int start = prefix.find(' ') + 1, end = prefix.find('_') + 1;
    prefix = prefix.substr(start, end - start);

    std::string class_name = "MyClass";

    std::unique_ptr<ClassUnit> Class(generator.getClassCode(prefix + class_name, ClassUnit::PUBLIC));

    if (Class)
    {
        Class->add(std::shared_ptr< MethodUnit >(generator.getMethodCode("testFunc1", "void")),
            ClassUnit::PUBLIC);

        Class->add(std::shared_ptr<MethodUnit>(generator.getMethodCode("testFunc2", "void",
            MethodUnit::STATIC)), ClassUnit::PRIVATE);

        /*
            В модификаторы блока (в данном случае функции) можно передавать любые флаги (virtual, const, static)
            даже если в языке такой модификатор использовать неывозможно.
            Какие модификаторы будут учтены уже зависит от конкретной реализации метода MethodUnit::compile
        */
        Class->add(std::shared_ptr< MethodUnit >(generator.getMethodCode("testFunc3", "void",
            MethodUnit::VIRTUAL | MethodUnit::CONST, std::vector<std::string>{ "int", "double", "UserType" })),
            ClassUnit::PUBLIC);

        std::shared_ptr< MethodUnit > method(generator.getMethodCode("testFunc4",
            "void", MethodUnit::STATIC));

        if (method)
        {
            //добавляем в метод функцию вывода
            method->add(std::shared_ptr< PrintUnit >(generator.getPrintOperCode("Hello, world!")));
            Class->add(method, ClassUnit::PROTECTED);
        }

        Class->add(std::shared_ptr<MemberUnit>(generator.getMemberCode("int", "a")), ClassUnit::PRIVATE);
        Class->add(std::shared_ptr<MemberUnit>(generator.getMemberCode("double", "b")), ClassUnit::PRIVATE);

        return Class->compile();
    }

    return "";
}