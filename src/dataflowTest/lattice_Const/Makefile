# usage: call "make" to run on test

PROG     = const_prop

.PHONY: all clean

all: 
	./../../souffle $(PROG).dl --fact-dir=. --output-dir=. --debug-report=$(PROG)_report.html
	sort -k1 ./LocalVar.csv > ./sortedLocalVar.csv

generate: 
	./../../souffle -g $(PROG).cpp $(PROG).dl --fact-dir=. --output-dir=. --debug-report=$(PROG)_report.html

compile: 
	./../../souffle -c $(PROG).dl --fact-dir=. --output-dir=. --debug-report=$(PROG)_report.html

help:
	./../../souffle -help
