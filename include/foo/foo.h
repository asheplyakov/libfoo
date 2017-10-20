#ifndef LIBFOO_FOO_H
#include <string>

class A {
public:
	virtual void foo(const std::string& s) = 0;
	virtual void bar(int i) = 0;
	virtual ~A();
};

class B {
public:
	virtual ~B() { }
	virtual const std::string& name() const = 0;
};

class C : public B {
public:
	virtual const std::string& name() const override;
};

class X : public B, public A {
	int m_x;
public:
	explicit X(int x): m_x{x} { }
	virtual const std::string& name() const override;
	virtual void foo(const std::string& s) override;
	virtual void bar(int i) override;
};

#endif /* LIBFOO_FOO_H */
