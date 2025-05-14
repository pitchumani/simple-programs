.DEFAULT_GOAL := all

CXX=g++
FLAGS=-g3 -std=c++17
GTFLAGS=-lgtest

OBJDIR := build

build/move-bytes.o: move-bytes.cpp
	$(CXX) $(FLAGS) -c -o $@ $<

build/anagram.o: anagram.cpp
	$(CXX) $(FLAGS) -c -o $@ $<

OBJS := $(addprefix $(OBJDIR)/, \
	move-bytes.o anagram.o )

$(OBJS): | $(OBJDIR)
$(OBJDIR):
	mkdir $(OBJDIR)

TESTS := movebytes-test \
	anagram-test \
	substr-test

movebytes-test: $(OBJDIR)/move-bytes.o move-bytes-test.cpp
	$(CXX) -o $(OBJDIR)/$@ $^ $(FLAGS) $(GTFLAGS) -Wno-write-strings
	./$(OBJDIR)/$@

anagram-test: $(OBJDIR)/anagram.o anagram-test.cpp
	$(CXX) -o $(OBJDIR)/$@ $^ $(FLAGS) $(GTFLAGS) -Wno-write-strings
	./$(OBJDIR)/$@

substr-test: substr.cpp substr-test.cpp
	$(CXX) -o $(OBJDIR)/$@ $^ $(FLAGS) $(GTFLAGS) -D __UNITTEST__ -Wno-write-strings
	./$(OBJDIR)/$@

test: $(TESTS)

mthread1: mthread-01.cpp
	echo "Build and run mthread-01.cpp"
	$(CXX) -o $(OBJDIR)/$@ $^
	./$(OBJDIR)/$@

nw1: network-01.cpp
	echo "Build and run network-01.cpp"
	$(CXX) -o $(OBJDIR)/$@ $^
	./$(OBJDIR)/$@

echoserver: echo-server.cpp echo-client.cpp
	$(CXX) -o $(OBJDIR)/echo-server echo-server.cpp
	$(CXX) -o $(OBJDIR)/echo-client echo-client.cpp
	echo "run echo-server and echo-client in separate terminal"

elfsummary: elfsummary.cpp
	$(CXX) -o $(OBJDIR)/$@ $^
	./$(OBJDIR)/$@ ./$(OBJDIR)/nw1

substr: substr.cpp
	$(CXX) -o $(OBJDIR)/$@ $^
	echo "substr \"hello world\" should return 6"
	./$(OBJDIR)/$@ "hello world"

programs: $(OBJDIR) mthread1 nw1 echoserver elfsummary substr

all: $(OBJS) test programs

.PHONY: clean

clean:
	rm -r -f $(OBJS) build/*
	rm -r -f build

