touch results
echo "" > results
set THREADS=1 2
echo "50 lines" >> results
for seed in 3000 3001
do
	time ../src/souffle -F facts/prog-50L-$seed -D const_prop/out/prog-50L-$seed const_prop/const_prop.dl
    for t in $THREADS
    do
        make compiled PROG=const_prop TESTCASE=prog-50L-$seed THREADS=$t > /dev/null
        time ./const_prop/const_prop
        echo "----------------------" >> results
    done
done
