#!/bin/bash
declare -a StringArray=("generator" "correctcode" "checkcode")
for val in ${StringArray[@]}; do
   g++ -DONLINE_JUDGE $val.cpp -o $val
done
#g++ generator.cpp -o generator
#g++ correctcode.cpp -o "correctcode"
#g++ checkcode.cpp -o "checkcode"

# ./generator > ./input.txt
(./correctcode < ./input.txt) > ./outputcorrect.txt
(./checkcode < ./input.txt) > ./outputcheck.txt
FILE1="./outputcorrect.txt"
FILE2="./outputcheck.txt"
eof1=0
eof2=0
count1=0
count2=0
exec 3<"$FILE1"
exec 4<"$FILE2"
while [[ $eof1 -eq 0 || $eof2 -eq 0 ]]
do
  if read a <&3; then
    let count1++
    # printf "%s, line %d: %s\n" $FILE1 $count1 "$a"
  else
    eof1=1
  fi
  if read b <&4; then
    let count2++
    # printf "%s, line %d: %s\n" $FILE2 $count2 "$b"
  else
    eof2=1
  fi
  if [ "$a" != "$b" ]
  then
    echo " File $FILE1 and $FILE2 differ at lines $count1, $count2:"
    # exit 1
  fi
done
