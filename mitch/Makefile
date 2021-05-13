PROG=not-a-prog
THREADS=1
TESTCASE=default
DL_FILE=$(PROG)/$(PROG).dl
CPP_FILE=$(PROG)/$(PROG).cpp
EXE_FILE=$(PROG)/$(PROG)
OUTPUT_DIR=$(PROG)/out/$(TESTCASE)
FACTS_DIR=facts/$(TESTCASE)
COMPILED_OUTPUT_DIR=$(OUTPUT_DIR)/compiled-$(THREADS)
INTERPETED_OUTPUT_DIR=$(OUTPUT_DIR)/interp-$(THREADS)
COMMON_SF_ARGS=-F $(FACTS_DIR) -j $(THREADS)

$(PROG): $(PROG).cpp
	../src/souffle-compile $<

$(PROG).cpp: $(PROG).dl souffle
	../src/souffle $< -D ./out -g $@

run-both: souffle prof-interp prof-compiled
	@echo "Diff"
	-@diff $(INTERPETED_OUTPUT_DIR) $(COMPILED_OUTPUT_DIR)
	@echo "Diff End"

prof-compiled: souffle
	mkdir -p $(COMPILED_OUTPUT_DIR)
	../src/souffle $(COMMON_SF_ARGS) -D $(COMPILED_OUTPUT_DIR) -g $(CPP_FILE) $(DL_FILE)
	../src/souffle-compile $(CPP_FILE)
	time ./$(EXE_FILE)
	find $(COMPILED_OUTPUT_DIR) -type f -exec sort -o {} {} \;

prof-interp: souffle
	mkdir -p $(INTERPETED_OUTPUT_DIR)
	time ../src/souffle $(COMMON_SF_ARGS) -D $(INTERPETED_OUTPUT_DIR) $(DL_FILE)
	find $(INTERPETED_OUTPUT_DIR) -type f -exec sort -o {} {} \;

.PHONY: souffle run-both prof-compiled prof-interp

souffle:
	make -C ..