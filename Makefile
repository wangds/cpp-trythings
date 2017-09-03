#CXX := g++
#CXX := clang++
CXXFLAGS := -std=c++14 -W -Wall -Wextra

all: hello

obj/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

hello: obj/hello.o
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY: clean
clean:
	$(RM) hello
	$(RM) obj/*.o
