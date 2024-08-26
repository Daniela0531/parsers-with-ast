#pragma once
#include "include_list.hpp"

#include <fstream>
#include <unordered_map>
#include <memory>
#include <exception>

class Interpreter : public Visitor {
public:
    explicit Interpreter(const std::string& file_name)
            : main_out(file_name),
              main_tos_value(std::make_shared<IntValue>(0)),
              main_is_returned(false),
              main_return_value(std::make_shared<IntValue>(0)) {}

    ~Interpreter() {
        main_out.close();
    }

    void visit(Program* pr);

    void visit(MainClass* main_class);

    void visit(Expression* ex);

    void visit(AddExpression* add_ex);

    void visit(BoolExpression* bool_ex);

    void visit(DivExpression* div_ex);

    void visit(IdentExpression* ident_ex);

    void visit(SubstructExpression* sub_ex);

    void visit(VariableDeclaration* variable_declaration);

    void visit(Statement* statement);

    void visit(StatementList* statement_list);

    void visit(AssignmentStatement* assignment_statement);

    void visit(IfStatement* if_statement);

    void visit(PrintStatement* print_statement);

    void visit(ReturnStatement* return_statement);

    void visit(VariableDeclarationStatement* variable_declaration_statement);

    void visit(WhileStatement* while_statement);

    void visit(AssertStatement* assert_statement);

    void visit(IfElseStatement* if_else_statement);
    
    void visit(Type* type);

    void visit(SimpleType* simple_type);

    void visit(ArrayType* array_type);

private:
    std::unordered_map<std::string, std::shared_ptr<Value>> main_variables;

    std::shared_ptr<Value> main_tos_value;
    std::shared_ptr<Value> main_return_value;
    bool main_is_returned;
    std::ofstream main_out;
};