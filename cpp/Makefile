
CXX=g++
FLAGS=-g3
GTFLAGS=-lgtest

OBJDIR := build

build/move-bytes.o: move-bytes.cpp
	$(CXX) $(FLAGS) -c -o $@ $<

OBJS := $(addprefix $(OBJDIR)/, \
	move-bytes.o )

$(OBJS): | $(OBJDIR)
$(OBJDIR):
	mkdir $(OBJDIR)

TESTS := movebytes-test

movebytes-test: $(OBJDIR)/move-bytes.o move-bytes-test.cpp
	$(CXX) -o $(OBJDIR)/$@ $^ $(GTFLAGS) -Wno-write-strings
	./$(OBJDIR)/$@

test: $(TESTS)

all: $(OBJS) test

.PHONY: clean

clean:
	rm -f $(OBJS) build/movebytes-test
	rm -r -f build

