#!/bin/bash
echo -----------------------------------------------------------
echo Tests pour le binome : B3130
echo -----------------------------------------------------------

nTestCount=0
nSuccesfulTests=0
nStrResult="$1 "

echo ADD1
let "nTestCount=$nTestCount+1"
./$1 < add1.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB add1.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo LOAD1
let "nTestCount=$nTestCount+1"
./$1 < load1.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB load1.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo SAVE1
let "nTestCount=$nTestCount+1"
./$1 < save1.in > temp1.txt
grep -v '^#' temp.txt > temp2.txt
diff -wB save1.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo MOVE1
let "nTestCount=$nTestCount+1"
./$1 < move1.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB move1.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo SELECT1
let "nTestCount=$nTestCount+1"
./$1 < select1.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB select1.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo DELETE1
let "nTestCount=$nTestCount+1"
./$1 < delete1.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB delete1.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo COUNT1
let "nTestCount=$nTestCount+1"
./$1 < count1.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB count1.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo UNDO1
let "nTestCount=$nTestCount+1"
./$1 < undo1.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB undo1.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo REDO1
let "nTestCount=$nTestCount+1"
./$1 < redo1.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB redo1.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo -----------------------------------------------------------
echo RESULTS
echo -----------------------------------------------------------
echo Results: $nSuccesfulTests/$nTestCount
echo CSVLine: $nStrResult
echo $nStrResult >> results.txt
