#!/bin/sh
set -x
sudo /sbin/ifconfig eth0 down
sudo /sbin/ifconfig eth0 hw ether $1 
sudo /sbin/ifconfig eth0 up

