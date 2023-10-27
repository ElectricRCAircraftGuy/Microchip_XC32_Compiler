# This file is part of the GNU Binutils.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston,
# MA 02110-1301, USA.


# Add or adjust variables from Makefile.in here.  This file is
# included after all the other variable definitions and before rules,
# which means that variables used in rule prerequisites can still be
# affected.

VPATH += $(top_srcdir)/mchp

# Add new source files to these variables.
ifeq ($(target_triplet),pic32c-mchp-elf)
mchp-target-sources = pic32c-allocate.c \
	pic32c-options.c \
	pic32c-emul.c
endif

ifeq ($(target_triplet),pic32mx-mchp-elf)
mchp-target-sources = pic32m-allocate.c \
	pic32m-options.c \
	pic32m-emul.c
endif

mchp-common-sources = smartio.c \
	pic32-su-callstack.c \
	pic32-su-common.c \
	pic32-license-manager.c \
	memory-report-by-module.c \
	pic32-common-emul.c \
	pic32-debug.c

mchp-sources = $(mchp-target-sources) $(mchp-common-sources)

# Add them to the variables used to define the ld build.
EXTRA_ld_new_SOURCES += $(mchp-sources)
ld_new_OBJECTS += $(addsuffix .$(OBJEXT),$(basename $(mchp-sources)))

# This is based on COMPILE, but changed to use CXX.  AM_CPPFLAGS has
# had the CFLAGS removed and not replaced since CXXFLAGS is already
# present.  AM_CFLAGS has the warnings specific to C removed.  CFLAGS
# has been changed to use CXXFLAGS.
CXXCOMPILE = $(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) \
	$(subst $(CFLAGS) ,,$(AM_CPPFLAGS)) \
	$(CPPFLAGS) \
	$(subst -Wstrict-prototypes -Wmissing-prototypes ,,$(AM_CFLAGS)) \
	$(CXXFLAGS)
