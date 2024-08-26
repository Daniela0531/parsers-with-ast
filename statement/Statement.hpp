#pragma once

#include "TreeNode.hpp"

class Statement : public TreeNode {
 public:
    virtual ~Statement() = default;

    void Accept(Visitor* visitor) override {
        visitor->Visit(this);
    }
};
