# usage: call "make TEST=<test>" to run on test

PROG = reachingDef
TESTS_ROOT = ../tests
TEST = test1

.PHONY: all clean

all: 
	@if [ ! -d "$(TEST)" ];then echo "creating the output dir..."; mkdir $(TEST); fi
	souffle --fact-dir=$(TESTS_ROOT)/$(TEST) --output-dir=$(TEST) --include-dir=../shared --include-dir=.  --debug-report=rd_report.html $(PROG).dl
	sort -k1 $(TEST)/rdEntry.csv > $(TEST)/sortedRDEntry.csv
	sort -k1 $(TEST)/rdExit.csv > $(TEST)/sortedRDExit.csv

generate: 
	./../../souffle -g $(PROG).cpp --fact-dir=$(TESTS_ROOT)/$(TEST) --output-dir=$(TEST) --include-dir=../shared --debug-report=$(PROG)_report.html $(PROG).dl

compile: 
	./../../souffle -o $(PROG) --fact-dir=$(TESTS_ROOT)/$(TEST) --output-dir=$(TEST) --include-dir=../shared --debug-report=$(PROG)_report.html $(PROG).dl
clean:
	rm -rf $(TEST)

