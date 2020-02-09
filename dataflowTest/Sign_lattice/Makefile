# usage: call "make" to run on test

PROG     = sign

.PHONY: all clean

#  -p $(PROG)_profile.log
all: 
	./../../src/souffle $(PROG).dl --fact-dir=facts --output-dir=. --debug-report=$(PROG)_report.html
	sort -k1 ./varEntry.csv > ./sortedVarEntry.csv
	sort -k1 ./varExit.csv > ./sortedVarExit.csv

generate: 
	./../../souffle -g $(PROG).cpp $(PROG).dl --fact-dir=. --output-dir=. --debug-report=$(PROG)_report.html

compile: 
	./../../souffle -c $(PROG).dl --fact-dir=. --output-dir=. --debug-report=$(PROG)_report.html

help:
	./../../souffle -help

profile:
	./../../souffle-profile $(PROG)_profile.log -j
