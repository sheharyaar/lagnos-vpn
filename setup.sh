#!/bin/bash

IFACE=lagnos-tun
sudo ip tuntap add mode tun dev $IFACE &&\
sudo ip addr add 192.168.100.1/24 dev $IFACE &&\
sudo ip link set up dev $IFACE

