/*
    compare_spy.h
    02/01/14
    Chris Lacher

    Defining and implementing the predicate class
    LessThanSpy<T> and and GreaterThanSpy

    Copyright 2014, R.C. Lacher
*/

#ifndef _COMPARE_SPY_H
#define _COMPARE_SPY_H

namespace fsu
{

  template < typename T >
  class LessThanSpy;

  template < typename T >
  class GreaterThanSpy;

  template < typename T >
  class LessThanSpy
  {
  public:
    LessThanSpy() : count_(0) {}
    bool    operator() (const T& t1, const T& t2) { ++count_; return t1 < t2; }
    void    Reset      ()                         { count_ = 0; }
    size_t  Count      () const                   { return count_; }
  private:
    size_t  count_;
  };

  template < typename T >
  class GreaterThanSpy
  {
  public:
    GreaterThanSpy() : count_(0) {}
    bool    operator() (const T& t1, const T& t2) { ++count_; return t1 > t2; }
    void    Reset      ()                         { count_ = 0; }
    size_t  Count      () const                   { return count_; }
  private:
    size_t  count_;
  };

  template < typename T >
  bool operator == ( const LessThanSpy<T>& p1, const LessThanSpy<T>& p2)
  {
    if (p1.Count() == p2.Count()) return 1;
    return 0;
  }

  template < typename T >
  bool operator != ( const LessThanSpy<T>& p1, const LessThanSpy<T>& p2)
  {
    return !(p1 == p2);
  }

  template < typename T >
  bool operator == ( const GreaterThanSpy<T>& p1, const GreaterThanSpy<T>& p2)
  {
    if (p1.Count() == p2.Count()) return 1;
    return 0;
  }

  template < typename T >
  bool operator != ( const GreaterThanSpy<T>& p1, const GreaterThanSpy<T>& p2)
  {
    return !(p1 == p2);
  }

} // namespace fsu
#endif
