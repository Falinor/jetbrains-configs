/**
** \file stack.hh
** \brief Declaration of Stack.
*/
#ifndef STACK_HH_
# define STACK_HH_

# include <vector>
# include <iostream>
# include <string>

template <class T>
class Stack
{
  public:
    /**
    ** Expose stack iterator type
    */
    using const_iterator = typename std::vector<T>::const_reverse_iterator;
    using iterator = typename std::vector<T>::reverse_iterator;

    /**
    ** Constructor, by default, max_size = 100
    */
    Stack();
    Stack(int max_size);

    /**
    ** Push element item on the stack
    ** and return the stack reference for chaining
    */
    Stack<T>& push(const T& item);
    /*FIXME*/ operator+= /*FIXME*/;
    /*FIXME*/ operator<< /*FIXME*/;

    /**
    ** Pops an element from the stack, return a copy of it
    */
    /*FIXME*/ pop();
    /*FIXME*/ operator--();

    /**
    ** Returns the i-th element of the stack starting from the top of
    ** the stack and following a zero-based indexing
    ** for exemple stack[0] should return the top element value.
    */
    /*FIXME*/ operator[](int i);

    /**
    ** Compares two stacks, returns true if all elements
    ** from each stack have the same value and if the stacks
    ** have the same max sizes
    */
    /*FIXME*/ operator==(/*FIXME*/);

    /**
    ** Prints *this on the stream s
    ** All the elements must be separated by a single space,
    ** the top of the stack being the last displayed element.
    ** Do not add a newline nor space at the end!
    */
    std::ostream& print(std::ostream& s) const;

    /**
    ** begin returns the top of the stack
    ** end returns the bottom
    */
    const_iterator_type begin() const;
    const_iterator_type end() const;

    /**
    ** Setter of the attribute max_size of the stack. If the new
    ** max_size is lower than the current_size pop the stack until the
    ** stack size match the new stack size
    */
    void max_size_set(int t);
    /**
    ** Getter and setter of the max_size of the stack
    */
    int max_size_get() const;
  private:
    /*FIXME*/
};

/**
** Prints a stack on a stream using the stream operator<<
*/
template <class T>
std::ostream& operator<<(std::ostream& ostr, Stack<T>& p);

# include "stack.hxx"

#endif /* !STACK_HH_ */
