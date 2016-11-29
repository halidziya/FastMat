CC = g++
LIBSRC = osm.cpp
LIBOBJ=$(LIBSRC:.cpp=.o)
FASTMAT = fastmat.a
$(FASTMAT): $(LIBSRC)

CFLAGS = -Wall
LOADLIBES = -L./

CPP_FILES = $(wildcard src/*.cpp)
OBJ_FILES = $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
LD_FLAGS  = 
CC_FLAGS  = -03

TARGETS = $(FASTMAT)

all: $(OBJ_FILES)
    ar rcs $(FASTMAT) $(OBJ_FILES)
    ranlib $(FASTMAT)
	
obj/%.o: src/%.cpp
   $(CC) $(CC_FLAGS) -c -o $@ $<
   
clean:
    rm fastmat.o $(TARGETS) $(FASTMAT) $(OBJ_FILES)

depend:
    makedepend -- $(CFLAGS) -- $(SRC) $(LIBSRC)
	
	
