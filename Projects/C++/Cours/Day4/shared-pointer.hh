#ifndef SHARED_POINTER_HH
# define SHARED_POINTER_HH

template <typename T>
class SharedPointer
{
  public:
    // The type pointed to.
    typedef T element_type;

    /**
    ** \brief Constructs a new smart pointer to the value pointed to by \a other.
    ** The new reference shares the property of the object with \a other.
    */
    template <typename U>
    SharedPointer(const SharedPointer<U>& other);

    /**
    ** \brief Copy constructor.
    ** Although the implementation is subsumed by the previous, more
    ** generic one, the C++ standard still mandates this specific
    ** signature.  Otherwise, the compiler will provide a default
    ** implementation, which is of course wrong.  Note that the
    ** same applies for the assignment operator.
    */
    SharedPointer(const SharedPointer<T>& other);

    /**
    ** \brief Constructs a counted reference to a newly allocated object.
    ** The new reference takes the property of the object pointed to
    ** by \a p.  If \a p is nullptr, then the reference is invalid and
    ** must be \c reset() before use.
    */
    SharedPointer(T* p = nullptr);

    /**
    ** \brief Destroy a smptr.
    ** The object pointed to is destroyed if it is not referenced anymore.
    */
    ~SharedPointer();

    /**
    ** \brief Reference assignment.
    ** Before assignment, the object pointer to is destroyed if this
    ** is the last reference to it. After assignment, the reference
    ** shares property with the object pointed to by \a other. This
    ** is a no-op if the two references initially point to the same
    ** object.
    */
    template <typename U>
    /*FIXME*/ operator=(const SharedPointer<U>& other);

    /**
    ** \brief Reference assignment (special case)
    ** This method performs like the other, more general, version. It
    ** exists only because the more general version is not used for
    ** copy assignment by compliant compilers.
    */
    /*FIXME*/ operator=(/*FIXME*/ other);

    /**
    ** \brief Force the reference.
    ** The two following lines of code are equivalent:
    ** \code
    **     r.reset(p);
    **
    **     r = SharedPointer<T>(p);
    ** \endcode
    */
    void reset(T* p);

    // Access via a reference.
    /*FIXME*/ operator*() const;
    // Access via a pointer.
    /*FIXME*/ operator->() const;

    /**
    ** \brief Reference comparison.
    ** Returns true if the two references point to the same object.
    */
    template <typename U> bool operator==(const SharedPointer<U>& rhs) const;

    /**
    ** \brief Reference comparison.
    ** Returns false if the two references point to the same object.
    */
    template <typename U> bool operator!=(const SharedPointer<U>& rhs) const;

    /**
    ** \brief Reference comparison.
    ** Returns true if this points to \a p.
    */
    bool operator==(const T* p) const;

    /**
    ** \brief Reference comparison.
    ** Returns false if this points to \a p.
    */
    bool operator!=(const T* p) const;

    /**
    ** \brief Test for validity
    ** Returns true if the reference is valid, i.e. it points to an object.
    ** This conversion operator allows users to write:
    **
    ** \code
    ** smptr<int> p1;
    ** if (p1)
    **   ...
    ** \endcode
    */
    operator bool() const;

    /**
    ** \brief Cast the smptr.
    ** Returns a new smptr, possibly throwing an exception if the
    ** dynamic_cast is invalid. Use method @c is_a to check the validity of
    ** the operation beforehand.
    */
    template <typename U> SharedPointer<U> cast() const;

    /**
    ** \brief Cast the smptr (unsafe).
    ** Returns a new smptr, possibly a nullptr reference if the
    ** dynamic_cast is invalid.
    */
    template <typename U> SharedPointer<U> unsafe_cast() const;

    /**
    ** \brief Test fellowship.
    ** Returns true if the smptr points to an object which is
    ** really of the specified type.
    */
    template <typename U> bool is_a() const;

  public:
    template <typename U>
    friend class SharedPointer;

    // The piece of data to reference.
    /*FIXME*/

    // A counter shared between all ref pointers to \a data_.
    /*FIXME*/
};

# include "shared-pointer.hxx"

#endif /* !SHARED_POINTER_HH */
