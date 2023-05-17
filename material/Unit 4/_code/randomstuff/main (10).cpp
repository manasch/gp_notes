#include<iostream>
#include<memory>
#include<utility>

int Object1() { return 1; }
int Object2() { return 2; }
int GetId() { return 3; }

struct ObjectWrapper
{
  template <typename T>
  ObjectWrapper(T&& obj) :
    wrappedObject(std::make_shared<Wrapper<T>>(std::forward<T>(obj))) { }
  
  struct ObjectBase
  {
    virtual int operator()() const = 0;
    virtual ~ObjectBase() {}
  };
  
  template<typename T>
  struct Wrapper : public ObjectBase
  {
    Wrapper(const T& t) :
      wrappedObject(t) {}
    
    int operator()() const override
    {
      return wrappedObject();
    }
    T wrappedObject;
  };
  
  int operator()() const
  {
    return (*wrappedObject)();
  }
  
  std::shared_ptr<ObjectBase> wrappedObject;
};

void PrintId(const ObjectWrapper& obj)
{
  std::cout << obj() << "\n";
}

int main()
{
  PrintId(ObjectWrapper(Object1));
  PrintId(ObjectWrapper(Object2));
  PrintId(ObjectWrapper(GetId));
  PrintId(ObjectWrapper(+[](){ return 4;}));
  PrintId(ObjectWrapper([i=1](){ return 4+i;}));
}
