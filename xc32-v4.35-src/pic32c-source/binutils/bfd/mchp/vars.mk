# Add or adjust variables from Makefile.in here.  This file is
# included after all the other variable definitions and before rules,
# which means that variables used in rule prerequisites can still be
# affected.

VPATH += $(top_srcdir)/mchp

# Files added to mchp-sources will be put in libbfd.a.  If you add a
# new file, the easiest thing to do is clean the build directory to
# ensure is shows up in the library.
ifeq ($(target_triplet),pic32c-mchp-elf)
mchp-target-sources = 
endif

ifeq ($(target_triplet),pic32mz-mchp-elf)
mchp-target-sources = 
endif

mchp-common-sources = 

mchp-sources = $(mchp-target-sources) $(mchp-common-sources)

EXTRA_libbfd_la_SOURCES += $(mchp-sources)
OFILES += $(addsuffix .lo,$(basename $(mchp-sources)))
