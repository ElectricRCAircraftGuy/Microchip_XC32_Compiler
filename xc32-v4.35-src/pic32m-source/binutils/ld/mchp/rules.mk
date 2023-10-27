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


# Include the dependency files for the new source files, if they
# exist.  This is what the entries starting with @AMDEP_TRUE@ in
# Makefile.in do, but those have to be compatible with many versions
# of Make.  We only care about GNU Make so we don't have to resort to
# such hacks.
$(foreach f,$(mchp-sources),\
   $(eval -include ./$(DEPDIR)/$(addsuffix .Po,$(basename $(f)))))

# Add libstdc++ to the list of libraries when linking ld.
ld-new$(EXEEXT): LIBS += -lmchp -lstdc++

# Needed for the license manager
ldlang.o: CPPFLAGS += -imacros host-lm.h
pic32-license-manager.o: CPPFLAGS += -imacros host-lm.h

# Create a pattern rule for C++ files.  It only supports creating the
# dependency files, but that's fine since that's the only build option
# we use.
%.o: %.cc
	$(AM_V_CC)$(CXXCOMPILE) -MT $@ -MD -MP -MF $(DEPDIR)/$*.Tpo -c -o $@ $<
	$(AM_V_at)$(am__mv) $(DEPDIR)/$*.Tpo $(DEPDIR)/$*.Po

# Targets to help with debugging the Makefile itself.
print-%:
	@echo $* = $($*)

.PHONY: printvars
printvars:
	@$(foreach V,$(sort $(.VARIABLES)),\
	   $(if \
	     $(filter-out environ% default automatic,$(origin $V)),\
	       $(info $V=$($V) ($(value $V)))))
	@true
