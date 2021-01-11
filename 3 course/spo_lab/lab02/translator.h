#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include "types.h"
#include "operatorparser.h"
#include <vector>
#include <string>
#include <map>

class Translator
{
    using Operator  = ASM_types::Operator;
    using Operation = ASM_types::Operation;
    using LabelValue = decltype(VM_types::data_t::u);
// поля
    // символ счетчика размещения, он будет в таблице имен
    static constexpr char LC_Symbol[] = "$";
    // операторы ассемблерной программы: [метка:] операция [аргументы]
    std::vector<Operator> program;
    // таблица имен (меток)
    std::map<std::string, LabelValue> TableNames;
    // таблица операций (команда ВМ или директива)
    std::map<std::string_view, ASM_types::Operation> TableOperations;
    // Конечный автомат - разбор оператора
    OperatorParser OperParser;
// методы
    // заполнение таблиц транслятора
    void initTables() noexcept;
    // обработка метки из оператора
    void LabelDo(Operator &oper);
    // первый проход - чтение строк и разбор операторов из строк
    void firstPass(std::ifstream &source);
    // первый проход - вычисление LC, занесение метки в таблицу имен, выполнение директивы
    void firstPass_handleOper(Operator& oper);
    static void HandleFunc(Operator &oper);
public:
    explicit Translator(const std::string_view filename);
};

#endif // TRANSLATOR_H