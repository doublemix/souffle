PROG=not-a-prog
THREADS=1
TESTCASE=default
DL_FILE=$(PROG)/$(PROG).dl
CPP_FILE=$(PROG)/$(PROG).cpp
EXE_FILE=$(PROG)/$(PROG)
OUTPUT_DIR=$(PROG)/out/$(TESTCASE)
FACTS_DIR=facts/$(TESTCASE)
COMPILED_OUTPUT_DIR=$(OUTPUT_DIR)/compiled-$(THREADS)
INTERPRETED_OUTPUT_DIR=$(OUTPUT_DIR)/interpreted
COMMON_SF_ARGS=-F $(FACTS_DIR)
COMPILED_SF_ARGS=-j $(THREADS) -D $(COMPILED_OUTPUT_DIR) -g $(CPP_FILE)
INTERPRETED_SF_ARGS=-D $(INTERPRETED_OUTPUT_DIR)

run-compiled: souffle
	mkdir -p $(COMPILED_OUTPUT_DIR)
	../src/souffle $(COMMON_SF_ARGS) $(COMPILED_SF_ARGS)  $(DL_FILE)
	../src/souffle-compile $(CPP_FILE)
	find $(COMPILED_OUTPUT_DIR) -type f -exec sort -o {} {} \;

run-interpreted: souffle
	mkdir -p $(INTERPRETED_OUTPUT_DIR)
	../src/souffle $(COMMON_SF_ARGS) $(INTERPRETED_SF_ARGS) $(DL_FILE)
	find $(INTERPRETED_OUTPUT_DIR) -type f -exec sort -o {} {} \;

run-both: run-interpreted run-compiled
	echo "Done"

.PHONY: souffle run-both run-compiled run-interpreted

souffle:
	make -C ..