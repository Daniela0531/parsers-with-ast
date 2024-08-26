#pragma once

#include "forward_decl.h"

class Visitor {
 public:
    virtual void visit(NumberExpression* ex) = 0;
    virtual void visit(AddExpression* ex) = 0;
    virtual void visit(SubstractExpression* ex) = 0;
    virtual void visit(MulExpression* ex) = 0;
    virtual void visit(DivExpression* ex) = 0;
    virtual void visit(IdentExpression* ex) = 0;
    virtual void visit(Assignment* assignment) = 0;
    virtual void visit(PrintStatement* statement) = 0;
    virtual void visit(AssignmentList* assignment_list) = 0;
    virtual void visit(Program* pr) = 0;
    virtual void visit(MainClass* main_class) = 0;
    virtual void visit(IfStatement* if_statement) = 0;
    virtual void visit(PrintStatement* print_statement) = 0;
    virtual void visit(ReturnStatement* return_statement) = 0;
    virtual void visit(VariableDeclarationStatement* variable_declaration_statement) = 0;
    virtual void visit(WhileStatement* while_statement) = 0;
    virtual void visit(AssertStatement* assert_statement) = 0;
    virtual void visit(IfElseStatement* if_else_statement) = 0;
    virtual void visit(Type* type) = 0;
    virtual void visit(SimpleType* simple_type) = 0;
    virtual void visit(ArrayType* array_type) = 0;
}
