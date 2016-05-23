MAIN = ../umodule
RLIB_PATH = ../Raph_Library
RAPH_LIB = $(RLIB_PATH)/lib.o
OBJS = main.o $(RAPH_LIB)

RAPHFLAGS = -Wall -Wshadow -mcmodel=large -I$(realpath $(RLIB_PATH)/rlib/) -I$(realpath .) -MMD -MP
RAPHCFLAGS = $(RAPHFLAGS) -std=c99
RAPHCXXFLAGS = $(RAPHFLAGS) -std=c++1y -fno-rtti -fno-use-cxa-atexit -fno-threadsafe-statics
CFLAGS += $(RAPHCFLAGS)
CXXFLAGS += $(RAPHCXXFLAGS) -g

ASFLAGS += -I$(realpath .)

default:
	make $(MAIN)

$(MAIN): $(OBJS)
	g++ -pedantic -pthread -lpthread -o $@ $^

.PHONY: $(RAPH_LIB)
$(RAPH_LIB):
	make -C $(RLIB_PATH) CFLAGS="$(CFLAGS)" CXXFLAGS="$(CXXFLAGS)"

.PHONY: clean
clean:
	make -C $(RLIB_PATH) clean
	-rm -f $(OBJS) $(MAIN) *.s *.ii
