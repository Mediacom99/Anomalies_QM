default_target: all
.PHONY: all source delta

CXXFLAGS = -lm -std=c99 -I./

all: source.c delta.c

source:
	@gcc source.c ${CXXFLAGS}  -o comp.unx
delta:
	@gcc delta.c ${CXXFLAGS}  -o delta.unx

