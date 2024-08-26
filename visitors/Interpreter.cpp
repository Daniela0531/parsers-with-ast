#pragma once
#include "interpreter.h"

void Interpreter::visit(Program* pr) {
    pr->getMainClass()->accept(this);
}

void Interpreter::visit(MainClass* main_class) {
    main_class->getStatements()->accept(this);
}

void Interpreter::visit(Expression* ex) {}

void Interpreter::visit(AddExpression* add_ex) {
    add_ex->getLeftExpression()->accept(this);
    int lhs = main_tos_value->toInt();
    add_ex->getRightExpression()->accept(this);
    int rhs = main_tos_value->toInt();
    main_tos_value = std::make_shared<IntValue>(lhs + rhs);
}

void Interpreter::visit(BoolExpression* bool_ex) {
    main_tos_value = std::make_shared<BoolValue>(bool_ex->getValue());
}

void Interpreter::visit(DivExpression* div_ex) {
    div_ex->getLeftExpression()->accept(this);
    int lhs = main_tos_value->toInt();
    div_ex->getRightExpression()->accept(this);
    int rhs = main_tos_value->toInt();
    main_tos_value = std::make_shared<IntValue>(lhs / rhs);
}

void Interpreter::visit(IdentExpression* ident_ex) {
    main_tos_value = main_variables[ident_ex->getIdentifier()];
}

void Interpreter::visit(SubstructExpression* sub_ex) {
    sub_ex->getLeftExpression()->accept(this);
    int lhs = main_tos_value->toInt();
    sub_ex->getRightExpression()->accept(this);
    int rhs = main_tos_value->toInt();
    main_tos_value = std::make_shared<IntValue>(lhs - rhs);
}

void Interpreter::visit(VariableDeclaration* variable_declaration) {
    const std::string& variable_name = variable_declaration->getVariableName();
    std::string type_name = variable_declaration->getType()->getIdentifier();
    if (type_name == "int") {
        main_variables[variable_name] = std::make_shared<IntValue>();
    } else if (type_name == "boolean") {
        main_variables[variable_name] = std::make_shared<BoolValue>();
    } else {
        throw std::logic_error("Bad variable type");
    }
}

void Interpreter::visit(Statement* statement) {}

void Interpreter::visit(StatementList* statement_list) {
    if (statement_list->getHead() == nullptr) {
        return;
    }
    statement_list->getHead()->accept(this);
    statement_list->getTail()->accept(this);
}

void Interpreter::visit(AssignmentStatement* assignment_statement) {
    std::string variable_name = assignment_statement->getNamedEntity()->getName();
    if (main_variables.find(variable_name) == main_variables.end()) {
        throw std::logic_error("Variable is not declared");
    }
    assignment_statement->getExpression()->accept(this);
    if (main_variables[variable_name]->getTypeIdentifier() == "int") {
        main_variables[variable_name] = std::make_shared<IntValue>(main_tos_value->toInt());
    } else if (main_variables[variable_name]->getTypeIdentifier() == "boolean") {
        main_variables[variable_name] = std::make_shared<BoolValue>(main_tos_value->toBool());
    }
}

void Interpreter::visit(IfStatement* if_statement) {
    if_statement->getExpression()->accept(this);
    bool ex_result = main_tos_value->toBool();
    if (ex_result) {
        if_statement->getStatement()->accept(this);
    }
}

void Interpreter::visit(PrintStatement* print_statement) {
    print_statement->getExpression()->accept(this);
    int ex_result = main_tos_value->toInt();
    main_out << ex_result << std::endl;
}

void Interpreter::visit(ReturnStatement* return_statement) {
    return_statement->getExpression()->accept(this);
    main_return_value = main_tos_value;
    main_is_returned = true;
}

void Interpreter::visit(VariableDeclarationStatement* variable_declaration_statement) {
    variable_declaration_statement->getVariableDeclaration()->accept(this);
}

void Interpreter::visit(WhileStatement* while_statement) {
    while_statement->getExpression()->accept(this);
    bool ex_result = main_tos_value->toBool();
    while (ex_result) {
        while_statement->getStatement()->accept(this);

        while_statement->getExpression()->accept(this);
        ex_result = main_tos_value->toBool();
    }
}

void Interpreter::visit(AssertStatement* assert_statement) {
    assert_statement->getExpression()->accept(this);
    bool ex_result = main_tos_value->toBool();
    if (!ex_result) {
        throw std::logic_error("Assert failure");
    }
}

void Interpreter::visit(IfElseStatement* if_else_statement) {
    if_else_statement->getExpression()->accept(this);
    bool ex_result = main_tos_value->toBool();
    if (ex_result) {
        if_else_statement->getFirstStatement()->accept(this);
    } else {
        if_else_statement->getSecondStatement()->accept(this);
    }
}

void Interpreter::visit(Type* type) {}

void Interpreter::visit(SimpleType* simple_type) {}

void Interpreter::visit(ArrayType* array_type) {}