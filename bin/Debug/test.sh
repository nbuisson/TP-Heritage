echo -----------------------------------------------------------
echo Tests pour le binome : $1
echo -----------------------------------------------------------

nTestCount=0
nSuccesfulTests=0
nStrResult="$1 "

echo ADD.1
let "nTestCount=$nTestCount+1"
./$1 < add.1.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB add.1.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo ADD.2
let "nTestCount=$nTestCount+1"
./$1 < add.2.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB add.2.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo LOAD.1
let "nTestCount=$nTestCount+1"
./$1 < load.1.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB load.1.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo SAVE.1
let "nTestCount=$nTestCount+1"
./$1 < save.1.in > temp1.txt
grep -v '^#' temp.txt > temp2.txt
diff -wB save.1.result temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo MOVE.1
let "nTestCount=$nTestCount+1"
./$1 < move.1.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB move.1.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo SELECT.1
let "nTestCount=$nTestCount+1"
./$1 < select.1.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB select.1.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo DELETE.1
let "nTestCount=$nTestCount+1"
./$1 < delete.1.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB delete.1.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo COUNT.1
let "nTestCount=$nTestCount+1"
./$1 < count.1.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB count.1.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo UNDO.1
let "nTestCount=$nTestCount+1"
./$1 < undo.1.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB undo.1.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo UNDO.2
let "nTestCount=$nTestCount+1"
./$1 < undo.2.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB undo.2.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo REDO.1
let "nTestCount=$nTestCount+1"
./$1 < redo.1.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB redo.1.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo DIVERS.1
let "nTestCount=$nTestCount+1"
./$1 < divers.1.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB divers.1.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo DIVERS.2
let "nTestCount=$nTestCount+1"
./$1 < divers.2.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB divers.2.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo DIVERS.3
let "nTestCount=$nTestCount+1"
./$1 < divers.3.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB divers.3.out temp2.txt
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
