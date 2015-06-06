#ifndef WEAK_POINTER_HH
# define WEAK_POINTER_HH
# include "shared-pointer.hh"

template <class T>
class WeakPointer
{
  public:
    /**
    ** \brief Constructs a new empty weak pointer.
    ** \a shared_ must be set to nullptr.
    */
    WeakPointer();

    // \brief Constructs a new weak pointer wich stocks the address of \a other.
    WeakPointer(SharedPointer<T> const& other);

    /**
    ** \brief Constructs a new weak pointer and shares the SharedPointer of
    ** other.
    */
    WeakPointer(WeakPointer<T> const& other);

    /**
    ** \brief Reference assignment.
    ** The reference shares property with the object pointed to by \a other.
    ** This is a no-op if the two references initially point to the same
    ** object.
    */
    WeakPointer<T>& operator=(WeakPointer<T> const& other);

    /**
    ** \brief Reference assignment.
    ** Before assignment, the object pointed to is destroyed if this
    ** is the last reference to it. After assignment, the reference
    ** shares property with the object pointed to by \a other. This
    ** is a no-op if the two references initially point to the same
    ** object.
    */
    WeakPointer<T>& operator=(SharedPointer<T> const& other);

    /**
    ** \brief Reference assignment.
    ** Returns a valid SharedPointer, if shared_ is nullptr,
    ** the function still has to return a valid SharedPointer.
    */
    SharedPointer<T> lock() const;

  protected:

    /**
    ** \brief A pointer on a SharedPointer, in the way to create a
    ** new SharedPointer from it.
    */
    const SharedPointer<T>* shared_;
};

# include "weak-pointer.hxx"

#endif /* !WEAK_POINTER_HH */
