#pragma once

#include <cassert>
#include <iostream>

#include "Type.hpp"

namespace ootz
{

template<typename Value>
class SinglyNode
{
protected:
    Value value_;
    SinglyNode* after_;

public:
    SinglyNode(const Value& value, SinglyNode* after)
        : value_(value)
        , after_(after)
    {
    }

    void Insert(const Value& value)
    {
        if (after_ == nullptr)
        {
            SinglyNode* node = new SinglyNode(value, nullptr);
            assert(node && "memory is out");
            after_ = node;
            return;
        }
        
        after_->Insert(value);
    }

    void Delete(const Value& value, SinglyNode*& afterPlace)
    {
        if (value_ == value)
        {
            afterPlace = after_;

            delete this;
            return;
        }

        if (after_)
            after_->Delete(value, after_);
    }

    void Print()
    {
        std::cout << value_;

        if (after_ == nullptr)
        {
            std::cout << '\n';
            return;
        }

        std::cout << ' ';
        after_->Print();
    }
};

template<typename Value>
class SinglyLinkedList
{
private:
    SinglyNode<Value>* head_;

public:
    SinglyLinkedList()
        : head_(nullptr)
    {
    }

    void Insert(const Value& value)
    {
        if (head_ == nullptr)
        {
            head_ = new SinglyNode<Value>(value, nullptr);
            assert(head_ && "memory is out");
            return;
        }

        head_->Insert(value);
    }

    void Delete(const Value& value)
    {
        if (head_ == nullptr)
            return;

        head_->Delete(value, head_);
    }

    void Print()
    {
        if (head_ == nullptr)
            return;

        head_->Print();
    }
};

}