# usage: call "make TEST=<test>" to run on test

PROG = liveness
TESTS_ROOT = ../tests
TEST = test1

.PHONY: all clean

all: 
	@if [ ! -d "$(TEST)" ];then echo "creating the output dir..."; mkdir $(TEST); fi
	./../../souffle --fact-dir=$(TESTS_ROOT)/$(TEST) --output-dir=$(TEST) --include-dir=../shared --include-dir=. $(PROG).dl --debug-report=liveness_report.html
	sort -k1 $(TEST)/liveEntry.csv > $(TEST)/sortedLVEntry.csv
	sort -k1 $(TEST)/liveExit.csv > $(TEST)/sortedLVExit.csv

clean:
	rm -rf $(TEST)

