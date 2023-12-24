#!/bin/bash

IFACE=lagnos-tun
sudo ip link set $IFACE down && \
sudo ip link delete $IFACE
