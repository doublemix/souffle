#!/bin/bash

PROG=const_prop
echo "Job Started at $(date)"

for Line in 75 #25 50 75
do
	for Var in 5
	do
		echo "Var: $Var, Line: $Line"
		for i in 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
		do
			printf "%d\t" $i
			fact_dir="../../../LatticeFactsFolder/Vars_${Var}/Lines_${Line}/$i"			
			outdir="./LatticeTestOutput/Vars_${Var}/Lines_${Line}/$i"
			mkdir -p $outdir
			cmd="./../../src/souffle ${PROG}.dl --fact-dir=${fact_dir} --output-dir=$outdir -p $outdir/${PROG}_profile.log"

			ts=$(date +%s%N)
			$cmd
			duration=$((($(date +%s%N) - $ts)/1000000))
			echo $duration

			sort -k1 $outdir/varEntry.csv > $outdir/sortedVarEntry.csv
			sort -k1 $outdir/varExit.csv > $outdir/sortedVarExit.csv

			sort -k1 $outdir/varEntry_num.csv > $outdir/sorted_varEntry_num.csv
			sort -k1 $outdir/varExit_num.csv > $outdir/sorted_varExit_num.csv
		done
	done
done

echo "Job ended at $(date)"
