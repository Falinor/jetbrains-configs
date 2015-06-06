#ifndef IPARSER_HH_
# define IPARSER_HH_

# include <istream>

class IExpr;

class IParser
{
public:
  virtual ~IParser() = default;
  virtual IExpr* parse(std::istream&) = 0;
};

#endif /* !IPARSER_HH_ */
