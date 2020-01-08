# usage: call "make TEST=<test>" to run on test

PROG     = availableExp
TESTS_ROOT  = ../tests
TEST	 = test3

.PHONY: all clean

all: 
	@if [ ! -d "$(TEST)" ];then mkdir $(TEST); fi
	./../../souffle --fact-dir=$(TESTS_ROOT)/$(TEST) --output-dir=$(TEST) --include-dir=../shared $(PROG).dl --debug-report=ae_report.html
	sort -k1 $(TEST)/availableExpExit.csv > $(TEST)/sortedAvailableExpExit.csv

clean:
	rm -rf $(TEST)
