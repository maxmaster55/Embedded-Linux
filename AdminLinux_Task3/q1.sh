#!/bin/bash

if [[ -f ~/.bashrc  ]]; then
	export HELLO=$HOSTNAME
	echo "export HELLO=$HOSTNAME" >> ~/.bashrc
	echo $HELLO
	LOCAL=$(whoami)
	echo "LOCAL=$(whoami)" >> ~/.bashrc
	echo $LOCAL
fi

gnome-terminal
