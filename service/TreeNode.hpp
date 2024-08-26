#pragma once

#include "visitors/Visitor.hpp"


class TreeNode {
 public:
    virtual void accept(Visitor* v) = 0;
    virtual ~TreeNode() = default;
};
