#ifndef ENGINE_HH_
# define ENGINE_HH_

class Engine
{
public:
  Engine(int fuel);
  bool start();
  void use(int consumed);
  void stop() const;
  void fill(int fuel);

private:
  int fuel_;
  int consumed_;
};

#endif /* !ENGINE_HH_ */
