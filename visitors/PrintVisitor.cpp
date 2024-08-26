#include "PrintVisitor.h"

#include "elements.h"

#include <iostream>

PrintVisitor::PrintVisitor(std::string& file_name) : 
    stream(file_name) {
}

void PrintVisitor::visit(NumberExpression* ex) {
    printTabs();
    stream << "NumExpression " << ex->value << std::endl;
}

void PrintVisitor::visit(AddExpression* ex) {
    printTabs();
    main_stream << "AddExpression is:" << std::endl;

    main_num_tabs++;
    ex->first->accept(this);
    ex->second->accept(this);
    main_num_tabs--;
}

void PrintVisitor::visit(SubstractExpression* ex) {
    printTabs();

    main_stream << "SubExpression: " << std::endl;
    main_num_tabs++;
    ex->first->accept(this);
    ex->second->accept(this);
    main_num_tabs--;
}

void PrintVisitor::visit(MulExpression* ex) {
    printTabs();

    main_stream << "MulExpression: " << std::endl;
    main_num_tabs++;
    ex->first->accept(this);
    ex->second->accept(this);
    main_num_tabs--;
}

void PrintVisitor::visit(DivExpression* ex) {
    printTabs();
    main_stream << "DivExpression: " << std::endl;
    main_num_tabs++;
    ex->first->accept(this);
    ex->second->accept(this);
    main_num_tabs--;
}

void PrintVisitor::visit(IdentExpression* ex) {
    printTabs();

    main_stream << "IdentExpression: " << ex->main_ident << std::endl;
}

void PrintVisitor::visit(assig* assig) {
    printTabs();
    main_stream << "assig: " << assig->main_var << std::endl;
    main_num_tabs++;
    assig->main_ex->accept(this);
    main_num_tabs--;
}

void PrintVisitor::visit(assigList* assig_list) {
    printTabs();
    main_stream << "assigList: " << std::endl;

    main_num_tabs++;
    for (Statement* assig : assig_list->main_assig) {
        assign->accept(this);
    }
    main_num_tabs--;
}

void PrintVisitor::visit(Program* program) {
    main_stream << "Program:" << std::endl;

    main_num_tabs++;

    program->main_assig->accept(this);
    program->main_ex->accept(this);

    main_num_tabs--;
}

void PrintVisitor::printTabs() {
    for (int i = 0; i < main_num_tabs; ++i) {
        main_stream << '\t';
    }
}

PrintVisitor::~PrintVisitor() {
    main_stream.close();
}