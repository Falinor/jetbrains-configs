#ifndef IEXPR_HH_
# define IEXPR_HH_

class IExpr
{
public:
  virtual ~IExpr() = default;
  virtual void print() const = 0;
  virtual long eval() const = 0;
};

#endif /* !IEXPR_HH_ */
