#pragma once

#include <fstream>
#include <string>
#include "Visitor.h"

class PrintVisitor: public Visitor {
 public:
    PrintVisitor(const std::string& file_name);
    ~PrintVisitor();
    void visit(NumberExpression* ex);
    void visit(AddExpression* ex);
    void visit(SubstractExpression* ex);
    void visit(MulExpression* ex);
    void visit(DivExpression* ex);
    void visit(IdentExpression* ex);
    void visit(Assignment* assignment);
    void visit(PrintStatement* statement);
    void visit(AssignmentList* assignment_list);
    void visit(Program* pr);
 private:

    void printTabs();
    std::ofstream main_stream;
    int main_num_tabs = 0;

};
