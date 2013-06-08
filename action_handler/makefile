
SRCS=$(wildcard *.cpp)
BIN_SRCS=$(shell grep "int main" -l *.cpp) 
LIB_SRCS=$(patsubst $(BIN_SRCS),,$(SRCS))

DEPS=$(SRCS:.cpp=.d) 
OBJS=$(SRCS:.cpp=.o) 

LIB_OBJS=$(patsubst %.cpp,%.o,$(LIB_SRCS)) 
BINS=$(patsubst %.cpp,%,$(BIN_SRCS))
#BINS=gate_application
DEP_LIBS=  
LDFLAGS=
LIB_NAME=
SO_LIB=$(patsubst %,lib%.so,$(LIB_NAME))
STATIC_LIB=$(patsubst %,lib%.a,$(LIB_NAME))


CC=g++
CFLAGS= -Wall -D_REENTRANT -D_GNU_SOURCE -fPIC
#INC= -I${THRIFT_DIR} -I${BOOST_DIR}  -I. -I../public 
INC= -I. 

ifeq ($(release), 1)
CFLAGS += -O2 -DNDEBUG 
else
CFLAGS += -g -DDEBUG 
endif

all: $(BINS) $(SO_LIB) $(STATIC_LIB) 

$(BINS): % : %.o $(LIB_OBJS) $(DEP_LIBS)
	$(CC) -o $@ $^ $(LDFLAGS) 
$(SO_LIB): $(LIB_OBJS) 
	$(CC) $(CFLAGS) -shared -o $@ $^ 
$(STATIC_LIB): $(LIB_OBJS) 
	ar -rcs -o $@ $^ 
dist :
	rm -f $(DEPS)
clean:
	rm -f $(BINS) $(OBJS) $(DEPS) $(SO_LIB) $(STATIC_LIB)
release: clean
	@make release=1

%.d : %.cpp
	$(CC) -MM $(INC)  $< >$@
%.o : %.cpp
	$(CC) $(CFLAGS) $(INC) -c  $< 

-include  $(DEPS)

