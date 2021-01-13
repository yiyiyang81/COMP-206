#!/bin/bash

#first verify if a3config is int he folder
if [[ ! -f a3config ]]
then echo Error cannot find a3config
	exit 1
fi

#run a3config with source command
source a3config

#check if both variables were entered, print error message if does not exist
if [[ -z "$DIRNAME" ]] || [[ -z "$EXTENSION" ]]
then echo Error DIRNAME and EXTENSION must be set
	exit 2

#check if the directory exists, print error message if does not exist
elif [[ ! -d $DIRNAME ]]
then echo Error directory "$DIRNAME" does not exist
	exit 3

#check if the number of file found in the directory is 0, exit if it is
elif [[ `ls "$DIRNAME" | grep -c ".\.$EXTENSION$"` -eq 0 ]]
then echo Unable to locate any files with extension "$EXTENSION" in "$DIRNAME"
	exit 0

#check if the option to show the file content is true, print the location and
# the file content
elif [[ $SHOW == "true" ]]
then 	for i in $(ls "$DIRNAME" | grep ".\.$EXTENSION$")
	do echo "$i"
	   echo `cat "$i"`
	done
	exit 0

#only print the file location if the option is not true
else
	for i in $(ls "$DIRNAME" | grep ".\.$EXTENSION$")
	do echo "$DIRNAME"/"$i"
	done
	exit 0
fi

