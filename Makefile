# Alternative GNU Make workspace makefile autogenerated by Premake

ifndef config
  config=debug
endif

ifndef verbose
  SILENT = @
endif

ifeq ($(config),debug)
  metrobud_config = debug

else ifeq ($(config),release)
  metrobud_config = release

else
  $(error "invalid configuration $(config)")
endif

PROJECTS := metrobud

.PHONY: all clean help $(PROJECTS) 

all: $(PROJECTS)

metrobud:
ifneq (,$(metrobud_config))
	@echo "==== Building metrobud ($(metrobud_config)) ===="
	@${MAKE} --no-print-directory -C . -f metrobud.make config=$(metrobud_config)
endif

clean:
	@${MAKE} --no-print-directory -C . -f metrobud.make clean

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "  debug"
	@echo "  release"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   metrobud"
	@echo ""
	@echo "For more information, see https://github.com/premake/premake-core/wiki"