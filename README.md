This is Cosmos, a source-based UNIX Package Manager, written in C. Now don't expect this to be a drop-in replacement to your OS's package manager, its not even nearly completed. It is also extremely simple (not yet do we have garbage collection, dependency handling, etc.)



To compile, run these commands:

git clone https://github.com/Mortem-Metallum/cosmos.git

cd cosmos

chmod +x autobuild

./autobuild build

sudo ./autobuild install

This will compile and install in the build folder





Usage: cosmos [ OPERAND ] [ PACKAGE ]

Operands:

install: Install the specified package
--help: Display this help and exit
