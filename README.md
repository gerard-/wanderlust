# Wanderlust
Wanderlust - A Worldwide Network with Distributed Routing through Location Swapping

The centralized nature of the current Internet allows for easy censoring and invasion of privacy. Current technical solutions are not sufficient. Wanderlust is a decentralized mesh/overlay network compatible with existing IPv6 aware applications that aims to fix this. Nodes have an IPv6 addresses which is created from their public key. A node connects to a number of peers over the normal Internet or through private links. The connections between nodes are assumed to form a small world network and location swapping is used to assign every node a location that is close to its directly connected peers. Using the location gradient packets can then be routed to nodes. A DHT provides a global location lookup for any address. Encryption is used throughout the network to provide privacy and prevent attacks on the network.

Wanderlust is inspired by [Freenet][] and [Cjdns][]. It's not related to the [Emacs mail/news reader Wanderlust][emacs-wanderlust].

## Goals
The goal of Wanderlust is to deliver the same connectivity as the classical Internet but with less centralization and more privacy.

Subgoals are:

- A routing algorithm that allows for efficient and robust decentralized routing.
- A protocol that allows for the communication needed for the implementation of the algorithm and for the transfer of the information itself, safely and securely.
- The design and implementation of an application that implements the routing algorithm and the protocol.
- A global network of nodes that can communicate without fear of censorship or privacy violations.

## Status
The algorithm is ready to be reviewed. Protocol design is taking shape. No code has yet been written, and it is unclear whether Wanderlust could best be implemented as:

- a new routing engine for Cjdns
- a new mode of operation for Freenet
- a completely separate project

These are the steps needed to reach the project goal and their status:

1. Routing algorithm design - looking for feedback
2. Simulation
3. Protocol design - in progress
4. Software design
5. Software implementation
6. Promote and grow the network

## Contributing
Currently its most important to get the design clearly documented and to find any flaws. You can help by asking questions if things are unclear. Also, if you can think of situations in which the system might not function optimally or of possible attacks please let us know. You can either use the Github bug tracker or post to the mailing list.

To subscribe to the mailing list send an email to wanderlust-request@freelists.org with 'subscribe' in the Subject field OR by visiting the list page at http://www.freelists.org/list/wanderlust To post on the list, simply send email to wanderlust@freelists.org Please introduce yourself if you are interested in the project. The list is suitable for questions, remarks and information relevant to Wanderlust. There will also be periodic updates about the status of the project.

You are encouraged to fork this repository and make any changes that you think are improvements. Please send a pull request if you think your work is ready for inclusion. Corrections of spelling and grammar definitely count as improvements.

## Read more
Please read the following if you want to know more about the design or implementation of Wanderlust.

- [Why the need for Wanderlust?](doc/why-wanderlust.md)
- [Routing](doc/routing.md)
- [Protocol](doc/protocol.md)
- [Attacks](doc/attacks.md)
- [FAQ](doc/faq.md)

[freenet]: https://freenetproject.org/ "Freenet, the free network"
[cjdns]: http://cjdns.info/ "CJDNS"
[emacs-wanderlust]: http://www.emacswiki.org/emacs/WanderLust "Wanderlust for Emacs"

