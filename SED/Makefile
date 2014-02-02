CC=gcc
CXX=g++
LINKER=$(CXX) -o
TARGET=psp-sed
CFLAGS=-Wall -I Kirk
CXXFLAGS=-Wall
RM = rm -f

CSOURCES  := $(wildcard Kirk/*.c)
CPPSOURCES  := $(wildcard *.cpp)

COBJECTS := $(CSOURCES:Kirk/%.c=Kirk/%.o)
CPPOBJECTS := $(CPPSOURCES:%.cpp=%.o)

ifeq ($(DOGE), 1)
CXXFLAGS+=-DDOGE
endif

$(TARGET): $(COBJECTS) $(CPPOBJECTS)
	$(LINKER) $@ $(LFLAGS) $(COBJECTS) $(CPPOBJECTS)
	@echo "Linking complete!"

$(COBJECTS): Kirk/%.o : Kirk/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(CPPOBJECTS): %.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONEY: clean
clean:
	@$(RM) $(COBJECTS) $(CPPOBJECTS) $(TARGET)
	@echo "Cleanup complete!"
