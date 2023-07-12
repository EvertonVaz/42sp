#!/bin/sh
ifconfig | grep "ether " | tr -s ' ' '\t' | cut -f 3