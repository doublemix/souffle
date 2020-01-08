# usage: call "make TEST=<test>" to run on test

PROG     = veryBusyExp
TESTS_ROOT  = ../tests
TEST	 = test3

.PHONY: all clean

all: 
	@if [ ! -d "$(TEST)" ];then mkdir $(TEST); fi
	souffle --fact-dir=$(TESTS_ROOT)/$(TEST) --output-dir=$(TEST) --include-dir=../shared $(PROG).dl
	sort -k1 $(TEST)/veryBusyExpEntry.csv > $(TEST)/sortedVeryBusyExpEntry.csv
	sort -k1 $(TEST)/veryBusyExpExit.csv > $(TEST)/sortedVeryBusyExpExit.csv

clean:
	rm -rf $(TEST)
