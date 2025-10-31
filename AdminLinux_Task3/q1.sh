#!/bin/bash

if [[ -f ~/.bashrc  ]]; then
	export HELLO=$HOSTNAME
	echo $HELLO
	LOCAL=$(whoami)
	echo $LOCAL
fi

gnome-terminal
