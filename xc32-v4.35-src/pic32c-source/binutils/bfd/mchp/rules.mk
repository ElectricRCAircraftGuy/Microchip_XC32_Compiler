# Include the dependency files for the new source files, if they
# exist.  This is what the entries starting with @AMDEP_TRUE@ in
# Makefile.in do, but those have to be compatible with many versions
# of Make.  We only care about GNU Make so we don't have to resort to
# such hacks.
$(foreach f,$(mchp-sources),\
   $(eval -include ./$(DEPDIR)/$(addsuffix .Po,$(basename $(f)))))

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
