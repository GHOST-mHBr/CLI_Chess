# CLI Chess

This project is a CLI chess game that you can play over LAN or simply with your friend with one computer.
I wrote this to learn modern C++, linux's socket API and CMake.
The project will not get updated (at least for now). It was just a practice.
BTW I'm thinking about creating a simple GUI using Qt but not quite sure.

## Installing

>:warning:
Since the code uses Linux's socket API, it can be built only under Linux.

To build the project, you will need CMake, so make sure you have it then enter the following commands in the project's root directory:

```sh
> cmake . -B build
> cd build
> make
```

There are different make targets you can choose, by default all is selected:

* all: builds offline and online binaries
* offline_chess: builds only offline_chess
* server_chess: builds server chess
* client_chess: builds client chess

## Playing

After building, you can play your desired game, placed in build folder. There are three different binaries:

* server_chess
* client_chess
* offline_chess

As name indicates, to play the offline_game, you should run corresponding binary and for playing over LAN, you should run server_chess and client_chess binaries.

## :warning: No TCP encryption

There is no encryption for the TCP data and it passed in raw bytes. So if you are on a public LAN or in a untrusted LAN, the game can be easily hacked and tcp data can be altered.