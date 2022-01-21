# Routing Tables

## Without VPN

```console
Kernel IP routing table
Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
0.0.0.0         10.117.10.2     0.0.0.0         UG    100    0        0 eno2
10.117.10.0     0.0.0.0         255.255.255.0   U     100    0        0 eno2


default via 10.117.10.2 dev eno2 proto dhcp metric 100 
10.117.10.0/24 dev eno2 proto kernel scope link src 10.117.10.115 metric 100 
```

## Using OpenVPN ec2

```console
Kernel IP routing table
Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
0.0.0.0         10.8.0.1        0.0.0.0         UG    50     0        0 tun0
0.0.0.0         10.117.10.2     0.0.0.0         UG    100    0        0 eno2
3.111.98.137    10.117.10.2     255.255.255.255 UGH   100    0        0 eno2
10.8.0.0        0.0.0.0         255.255.255.0   U     50     0        0 tun0
10.117.10.0     0.0.0.0         255.255.255.0   U     100    0        0 eno2
10.117.10.2     0.0.0.0         255.255.255.255 UH    100    0        0 eno2
169.254.0.0     0.0.0.0         255.255.0.0     U     1000   0        0 tun0


default via 10.8.0.1 dev tun0 proto static metric 50 
default via 10.117.10.2 dev eno2 proto dhcp metric 100 
3.111.98.137 via 10.117.10.2 dev eno2 proto static metric 100 
10.8.0.0/24 dev tun0 proto kernel scope link src 10.8.0.2 metric 50 
10.117.10.0/24 dev eno2 proto kernel scope link src 10.117.10.115 metric 100 
10.117.10.2 dev eno2 proto static scope link metric 100 
169.254.0.0/16 dev tun0 scope link metric 1000 
```

## Using OpenVPN DigitalOcean

```console
Kernel IP routing table
Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
0.0.0.0         10.8.0.1        0.0.0.0         UG    50     0        0 tun0
0.0.0.0         10.117.10.2     0.0.0.0         UG    100    0        0 eno2
10.8.0.0        0.0.0.0         255.255.255.0   U     50     0        0 tun0
10.117.10.0     0.0.0.0         255.255.255.0   U     100    0        0 eno2
10.117.10.2     0.0.0.0         255.255.255.255 UH    100    0        0 eno2
64.227.168.10   10.117.10.2     255.255.255.255 UGH   100    0        0 eno2
169.254.0.0     0.0.0.0         255.255.0.0     U     1000   0        0 tun0


default via 10.8.0.1 dev tun0 proto static metric 50 
default via 10.117.10.2 dev eno2 proto dhcp metric 100 
10.8.0.0/24 dev tun0 proto kernel scope link src 10.8.0.2 metric 50 
10.117.10.0/24 dev eno2 proto kernel scope link src 10.117.10.115 metric 100 
10.117.10.2 dev eno2 proto static scope link metric 100 
64.227.168.10 via 10.117.10.2 dev eno2 proto static metric 100 
169.254.0.0/16 dev tun0 scope link metric 1000 
```

## ExpressVPN

```console
# Network Information

IP Address : 10.117.10.115
Broadcast Address : 10.117.10.255
Subnet Mask : 255.255.255.0
Default Route : 10.117.10.2
Primary DNS : 172.16.1.164
Secondary DNS : 172.16.1.180

# IP address config

## Without VPN

1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
    inet6 ::1/128 scope host 
       valid_lft forever preferred_lft forever
2: eno2: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc fq_codel state UP group default qlen 1000
    link/ether 24:4b:fe:6f:4f:b4 brd ff:ff:ff:ff:ff:ff
    altname enp3s0
    inet 10.117.10.115/24 brd 10.117.10.255 scope global dynamic noprefixroute eno2
       valid_lft 82621sec preferred_lft 82621sec
    inet6 fe80::314c:5c97:4435:76c4/64 scope link noprefixroute 
       valid_lft forever preferred_lft forever
3: wlo1: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc noqueue state DOWN group default qlen 1000
    link/ether 3c:58:c2:da:d9:69 brd ff:ff:ff:ff:ff:ff
    altname wlp0s20f3
```

## OpenVPN ec2

```console
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
    inet6 ::1/128 scope host 
       valid_lft forever preferred_lft forever
2: eno2: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc fq_codel state UP group default qlen 1000
    link/ether 24:4b:fe:6f:4f:b4 brd ff:ff:ff:ff:ff:ff
    altname enp3s0
    inet 10.117.10.115/24 brd 10.117.10.255 scope global dynamic noprefixroute eno2
       valid_lft 82597sec preferred_lft 82597sec
    inet6 fe80::314c:5c97:4435:76c4/64 scope link noprefixroute 
       valid_lft forever preferred_lft forever
3: wlo1: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc noqueue state DOWN group default qlen 1000
    link/ether 3c:58:c2:da:d9:69 brd ff:ff:ff:ff:ff:ff
    altname wlp0s20f3
14: tun0: <POINTOPOINT,MULTICAST,NOARP,UP,LOWER_UP> mtu 1500 qdisc fq_codel state UNKNOWN group default qlen 500
    link/none 
    inet 10.8.0.2/24 brd 10.8.0.255 scope global noprefixroute tun0
       valid_lft forever preferred_lft forever
    inet6 fe80::5ff:d1ec:3a5:f3e4/64 scope link stable-privacy 
       valid_lft forever preferred_lft forever
```

## OpenVPN DigitalOcean

```console
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
    inet6 ::1/128 scope host 
       valid_lft forever preferred_lft forever
2: eno2: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc fq_codel state UP group default qlen 1000
    link/ether 24:4b:fe:6f:4f:b4 brd ff:ff:ff:ff:ff:ff
    altname enp3s0
    inet 10.117.10.115/24 brd 10.117.10.255 scope global dynamic noprefixroute eno2
       valid_lft 82552sec preferred_lft 82552sec
    inet6 fe80::314c:5c97:4435:76c4/64 scope link noprefixroute 
       valid_lft forever preferred_lft forever
3: wlo1: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc noqueue state DOWN group default qlen 1000
    link/ether 3c:58:c2:da:d9:69 brd ff:ff:ff:ff:ff:ff
    altname wlp0s20f3
15: tun0: <POINTOPOINT,MULTICAST,NOARP,UP,LOWER_UP> mtu 1500 qdisc fq_codel state UNKNOWN group default qlen 500
    link/none 
    inet 10.8.0.2/24 brd 10.8.0.255 scope global noprefixroute tun0
       valid_lft forever preferred_lft forever
    inet6 fe80::e928:5e24:1d9f:8a90/64 scope link stable-privacy 
       valid_lft forever preferred_lft forever
```

## ExpressVPN
