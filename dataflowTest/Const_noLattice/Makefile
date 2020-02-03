# usage: call "make" to run on test

PROG     = const_prop

.PHONY: all clean

all: 
	./../../src/souffle $(PROG).dl --fact-dir=facts --output-dir=. --debug-report=$(PROG)_report.html
	sort -k1 ./varEntry.csv > ./sortedVarEntry.csv
	sort -k1 ./varExit.csv > ./sortedVarExit.csv

generate: 
	./../../src/souffle -g $(PROG).cpp $(PROG).dl --fact-dir=. --output-dir=. --debug-report=$(PROG)_report.html

compile: 
	./../../src/souffle -c $(PROG).dl --fact-dir=. --output-dir=. --debug-report=$(PROG)_report.html

help:
	./../../src/souffle -help
