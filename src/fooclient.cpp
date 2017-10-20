#include <memory>
#include "foo/foo.h"

int main(int argc, char** argv) {
	std::unique_ptr<A> x(new X(1));
	for (int i = 0; i < argc; i++) {
		x->bar(i);
		x->foo(argv[i]);
	}
	return 0;
}

