#!/bin/bash
cmd="./../../src/souffle const_prop.dl --fact-dir=facts --output-dir=."

ts=$(date +%s%N)
$cmd
duration=$((($(date +%s%N) - $ts)/1000000))
echo $duration
