#!/bin/bash

len=$#
#############################################################################################

#check if the input is empty
if [[ len -eq 0 ]]
then
echo "Error missing the pattern argument"
echo "Usage ./seeker.sh [-c] [-a] pattern [path]"
fi

#############################################################################################

if [[ len -eq 1 ]]
then
#first check if the input is valid
	if [[ $1 == "-c" ]] || [[ $1 == "-a" ]]
	then
	echo "Error missing the pattern argument"
	echo "Usage ./seeker.sh [-c] [-a] pattern [path]"
#check if the number of file in the current directory is 0
	elif [[ `ls | grep -c "$1"` -eq 0 ]]
	then
	echo "Unable to locate any files tat has pattern $1 in its name in "$0""
#if not 0 then it means the file exists
	else
	echo `ls | grep "$1"`
	fi
fi

#############################################################################################

if [[ len -eq 2 ]]
then
#first check if the input is valid
	if [[ $1 == "-c" ]] && [[ $2 == "-a" ]]
	then
	echo "Error missing the pattern argument"
	echo "Usage ./seeker.sh [-c] [-a] pattern [path]"

#check if option starts with "-c" and if the number of file in the current directory is 0
	elif [[ $1 == "-c" ]] && [[ `ls | grep -c "$2"` -eq 0 ]]
		then
		echo "Unable to locate any files that has pattern $2 in its name in `pwd`"
#if not 0 then it exists, proceed to execute "-c"
	elif [[ $1 == "-c" ]]
		then
#make a list with the found filenames and print the content of the first one since no "-a"
		list=($(ls | grep "$2"))
		echo "==== Contents of: `pwd`"/""${list[0]}" ===="
		echo `cat "`pwd`/${list[0]}"`
#check if option starts with "-c" and if the number of file in the current directory is 0
	elif [[ $1 == "-a" ]] && [[ `ls | grep -c "$2"` -eq 0 ]]
		then
		echo "Unable to locate any files that has pattern $2 in its name in `pwd`"
#if not 0 then it exists, proceed to exectute "-a"
	elif [[ $1 == "-a" ]]
		then
#iterate through the list of found file names and print its path
		for i in `ls | grep "$2"`
		do echo "`pwd`/$i"
		done
#goes to situation when one input is pattern and the other one is path
#check if the number of file in the directory is 0
	elif [[ -d "$2" ]] && [[ `ls "$2" | grep -c "$1"` -eq 0 ]]
		then
		echo "Unable to locate any files that has pattern $1 in its name in $2"
#if not 0 then the file exists in the directory
	elif [[ -d "$2" ]]
		then
#iterate through the list of found file names and print only 1
		list=($(ls "$2" | grep "$1"))
		echo "$2/${list[0]}"
	else
#if it is none of the situation above, then the directory should be invalid
		echo "Error "$2" is not a valid directory"
	fi

fi

#############################################################################################

if [[ len -eq 3 ]]
then
#check if the input is in format of [-c] [-a] [pattern]
#check the number of file exists in current direcotry
	if [[ $1 == "-c" ]] && [[ $2 == "-a" ]] && [[ `ls | grep -c "$3"` -eq 0 ]]
		then
		echo "Unable to locate any files that has pattern $3 in its name in `pwd`"

#if not 0 then file exists
	elif [[ $1 == "-c" ]] && [[ $2 == "-a" ]]
		then
#iterate through returned file names and print its content and directory
		for i in $(ls | grep "$3")
		do echo "==== Contents of: `pwd`/"$i" ===="
		echo "`cat `pwd`/"$i"`"
		done

#check if the option "-c" is present and if the file exists in the given directory
	elif [[ $1 == "-c" ]] && [[ -d "$3" ]] && [[ `ls "$3" | grep -c "$2"` -eq 0 ]]
		then
		echo "unable to locate any files that has pattern $2 in its name in "$3""
#if not 0 then exists
	elif [[ $1 == "-c" ]] && [[ -d "$3" ]]
		then
#print the first file in the list with its content
		list=($(ls "$3" | grep "$2"))
		echo "==== Contents of: "$3"/"${list[0]}" ===="
		echo "`cat "$3/${list[0]}"`"

#check if the option "-a" is present and if the file exists in the given direcotry
	elif [[ $1 == "-a" ]] && [[ -d "$3" ]] && [[ `ls "$3" | grep -c "$2"` -eq 0 ]]
		then
		echo "Unable to locate any files that has pattern $2 in its name in $3"

#if not 0 then it must exists
	elif [[ $1 == "-a" ]] && [[ -d "$3" ]]
		then
#print the list of found filenames with its directory
		for i in $(ls "$3" | grep "$2")
		do echo "$3/$i"
		done
#if it is none of the situation above, then the directory should be invalid
	else
		echo "Error "$3" is not a valid directory"
	fi
fi

#############################################################################################

if [[ len -eq 4 ]]
then
#there is only one possibility for the input of length 4
#check if the number of file in the direcotry is 0
	if [[ $1 == "-c" ]] && [[ $2 == "-a" ]] && [[ -d "$4" ]] && [[ `ls "$4" | grep -c "$3"` -eq 0 ]]
		then
		echo "Unable to locate any files that has pattern $3 in its name in $4"
#if not 0 then it exists in the given directory
	elif [[ $1 == "-c" ]] && [[ $2 == "-a" ]] && [[ -d "$4" ]]
		then
#print all in the list of found filenames with its content and directory
		for i in $(ls "$4" | grep "$3")
		do echo "==== Contents of: "$4""/""$i" ===="
		echo "`cat "$4/$i"`"
		done
#if it is none of the situation above, then the directory should be invalid
	else
		echo "Error "$4" is not a valid directory"
	fi
fi












