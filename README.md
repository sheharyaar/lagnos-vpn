# ToDo

Milestone #1 :

- [ ] Helium server setup with config
- [ ] Helium client setup with config
- [ ] Tunnel setup for server and client
  
- [ ] Testing on mobile network

Milestone #2 :

- [ ] SNI spoofing
- [ ] Testing on LAN network

Milestone #3 :

- [ ] Kernel based offloading and routing research

# Theory

libhelium is a library by ExpressVPN that abstracts away the process of wrapping and unwrappin ssl packed data. This is just one step of the entire process. The user needs to handle the creation and routing of `tun` interface. The user also needs to handle the transport service between the server and the client.

Here is the complete packet flow in the communication :

```mermaid
sequenceDiagram
    Client->>+ClientTunnel: Packet for the internet
    ClientTunnel->>+VPNClient: Reads packet from tunnel
    VPNClient->>+HeliumClient: Wrap the packet
    HeliumClient->>-VPNClient: SSL Wrapped packet
    VPNClient->>+VPNServer: Packet over UDP/TCP
    VPNServer->>+HeliumServer: Wrapped packet
    HeliumServer->>-VPNServer: Unwrapped Paclet
    VPNServer->>+Internet: Internet (masquerade)
    Internet->>-VPNServer: Response (masquerade)
    VPNServer->>+HeliumServer: Wrap response
    HeliumServer->>-VPNServer: Wrapped response
    VPNServer->>-VPNClient: response over UDP
    VPNClient->>+HeliumClient: Wrap the Packet
    HeliumClient->>-VPNClient: Unwrapped Packet
    VPNClient->>-ClientTunnel: Response packet
    ClientTunnel->>-Client: Response from Internet
```