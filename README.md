<img src="./wip.svg">

# Lagnos VPN

This is a fresh start towards building by SSL based VPN. This is solely-worked on by me, I am not accepting contributions at this time. 

Deadline : ~31 December 2023 for a POC~ Due to other high priority tasks, this project is suspended for now. Maybe I will pick this up in April, 2024.

#### TODO

- [X] Overall design of the VPN and the platform agnostic functions
- [X] Bash script to setup tunnel
- [X] Checkpoint 1 : Open a tunnel and inspect the packet
- [ ] Bash script to setup routes
- [ ] Checkpoint 2 : Send packets without SSL to the client and back
- [ ] Checkpoint 3 : Send packets with SSL to the client and back
- [ ] Checkpoint 4 : Setup authentication and session management
<<<<<<< Updated upstream
- [ ] Optional : Userspace and kernel optimisations if needed
=======
- [ ] Checkpoint 5 : Add support for config files
- [ ] Checkpoint 6 : Add support for multiple peers
- [ ] Optional : Userspace and kernel optimisations if needed

# Building and running

Building:
```
make
```

Running:
```
chmod +x ./setup-tun.sh
sudo ./setup-tun.sh

sudo ./bin/lagnos-vpn ./peer.conf
```

Stopping:
```
chmod +x ./cleanup-tun.sh
sudo ./cleanup-tun.sh

# TODO: Stopping the VPN
```
>>>>>>> Stashed changes
