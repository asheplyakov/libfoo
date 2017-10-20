#include <iostream>
#include "foo/foo.h"

A::~A() { }

void X::foo(const std::string& s) {
	std::cout << "B::foo() s: " << s << std::endl;
}

void X::bar(int x) {
	m_x += x;
}

