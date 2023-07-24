default_target: all
.PHONY: all source

CXXFLAGS = -lm -std=c99 -I./

all: source.c

source:
	@gcc source.c ${CXXFLAGS}  -o comp.unx

