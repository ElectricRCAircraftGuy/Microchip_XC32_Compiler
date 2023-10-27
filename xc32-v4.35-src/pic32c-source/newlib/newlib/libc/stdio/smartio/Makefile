# Makefile for building SmartIO routines with a specified set of supports
# for format conversion characters. 
#
# The variable SMARTIO_SUFFIX may (should) be overridden with a string
# of characters from the set [c d e E f F g G n o p s u x X]. This suffix will
# be applied to all external entry points as well as appended to all object file names.
#
# if SHORT_DOUBLE is set, build all routines with short-double in effect. 
# if INTEGER_IO is set, build all routines with integer-only support.
#

conversions := c d e E f F g G n o p s u x X
empty := 
sp := $(empty) $(empty)
SMARTIO_SUFFIX := $(strip $(subst $(sp),,$(conversions)))

# Define OBJDIR to set the object directory, required for newlib builds.
OBJDIR := .

# stdio/Makefile sets these to the library object prefix and extension.
oext=o
lpfx=lib_a-

# Common dependencies
HEADERS := prefix.h

# Expand SMARTIO_SUFFIX into set of defines controlling specific support
SMARTIO_DEFS := $(foreach c, $(conversions), $(if $(findstring $(c),$(SMARTIO_SUFFIX)),-D__SMARTIO_$(c)__))

# Prefix definitions
ifdef INTEGER_IO
  PFX := _i
  EXTRA_FLAGS := -DINTEGER_IO
else
ifdef SHORT_DOUBLE
  PFX := _s
  EXTRA_FLAGS := -fshort-double
endif
endif

# TODO: figure out if this needs to be supported (no file io)
ifdef STRING_ONLY
  EXTRA_FLAGS += -DSTRING_ONLY
endif

INCLUDES := -I. -I../ -I../../include

WARN := -Wno-builtin-macro-redefined
EXTRA_FLAGS += -mno-smart-io

# Common defines
DEFS := -D__SMARTIOV2__ -D_HOSTED -DPREFIX=_$(PDX) -DSUFFIX=_$(SMARTIO_SUFFIX) $(SMARTIO_DEFS)

SRCS := $(wildcard *print*.c) $(wildcard *scan*.c)
OBJS := $(addprefix $(OBJDIR)/$(lpfx),$(SRCS:.c=.$(SMARTIO_SUFFIX).$(oext)))

default: all
all: $(OBJS)

$(OBJDIR)/$(lpfx)%.$(SMARTIO_SUFFIX).$(oext): %.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) $(WARN) $(EXTRA_FLAGS) $(DEFS) -c $< -o $@

$(OBJDIR)/stmp-smartio: $(SRCS) $(HEADERS)
	@touch $@

clean:
	@rm -f $(OBJDIR)/*.o $(OBJDIR)/stmp-smartio

