#pragma once

#include "service/TreeNode.hpp"


class Expression : public TreeNode {
public:
    virtual ~Expression() = default;
    void accept(Visitor *v) {
        v->visit(this);
    }
};
