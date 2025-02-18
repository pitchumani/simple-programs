
CXX=g++
FLAGS=-g3
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
	anagram-test

movebytes-test: $(OBJDIR)/move-bytes.o move-bytes-test.cpp
	$(CXX) -o $(OBJDIR)/$@ $^ $(GTFLAGS) -Wno-write-strings
	./$(OBJDIR)/$@

anagram-test: $(OBJDIR)/anagram.o anagram-test.cpp
	$(CXX) -o $(OBJDIR)/$@ $^ $(GTFLAGS) -Wno-write-strings
	./$(OBJDIR)/$@

test: $(TESTS)

all: $(OBJS) test

.PHONY: clean

clean:
	rm -f $(OBJS) build/*
	rm -r -f build

