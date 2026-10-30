# Technical Coursework 📁

A few more technical assignments from my degree. They're not the heart of my marketing and business focus, but I like keeping them here as they show how I work through a problem when it gets technical.

*Reports and code comments are in Greek; the notes below are in English.*

---

### security: cryptography & security

*Course: Protection & Security of Computing and Telecommunication Systems*

**`Cryptography-AES-Integrity-Caesar.pdf`** walked through the AES block cipher modes (ECB, CBC, CFB, CTR) with hands-on tools, verified a downloaded file's integrity against its published SHA-256 hash, and wrote a small Python brute-force that cracked a Caesar cipher across all 25 shifts.

**`Cryptography-RSA-DiffieHellman.pdf`** decrypted an RSA message by factoring the modulus and finding the private key with the extended Euclidean algorithm, recovered a private key from a public one, and solved a Diffie–Hellman key-exchange problem (shared secret and primitive-root proof included).

*Shows:* cryptography basics, modular arithmetic, security tooling, a bit of scripting.

---

### c-programs string operations in C

**`string-operations.c`** a little menu-driven program that searches for a character in a string, replaces one character with another, and checks whether a string is a palindrome.

> I cleaned this one up from the original coursework: fixed the palindrome check (it used to return the opposite result), set the length correctly, and swapped the unsafe `gets()` for `fgets()`. It now compiles cleanly with `gcc -Wall`.

```bash
gcc -Wall -o string-operations string-operations.c
./string-operations
```

---

### systems-programming: TCP client–server

*Course: Systems Programming*

A small client–server system over TCP sockets that models a producer/consumer inventory. The `server.c` listens on a port and keeps a quantity table per product; `producer.c` and `consumer.c` connect and send a message that adds or removes stock. `common.h` holds the shared message struct, with a `Makefile` to build and an `execute` script that runs the whole demo.

```bash
make          # builds server, producer, consumer
./execute     # runs the demo: server + 2 producers + 2 consumers
```

*Shows:* C, TCP sockets, a simple client–server design, Makefiles and shell scripting.
