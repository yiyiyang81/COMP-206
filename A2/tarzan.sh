#!/bin/bash

numberArgs=$#
#first check if there are two arguments
if [[ numberArgs -ne 2 ]] || [[ -z $@ ]] 
then
	echo "Usage ./tarza.sh filename tarfile"

#then check if the tarfile exists in the first place
elif [[ -f "$2" ]]
then
#if the tarfile does exist, check if the file is in tarfile
	if [[ `tar -tvf "$2" | grep -c "$1"` -eq 0 ]]
	then
	echo "$1 does not exist in $2"
	else
	echo "$1 exists in $2"	
	fi
else
echo "Error cannot find tar file $2"
exit 1
fi
