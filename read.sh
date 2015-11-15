#!/bin/bash

read -p "input name: " -t 30 name
echo $name

read -p "passwd:" -s passwd
echo -e "\n"
echo $passwd

read -p "choose sex [M/F]: " -n 1 sex
echo $sex
