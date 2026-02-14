<p align="center">
  <img src="https://www.especial.gr/wp-content/uploads/2019/03/panepisthmio-dut-attikhs.png" alt="UNIWA" width="150"/>
</p>

<p align="center">
  <strong>UNIVERSITY OF WEST ATTICA</strong><br>
  SCHOOL OF ENGINEERING<br>
  DEPARTMENT OF COMPUTER ENGINEERING AND INFORMATICS
</p>

---

<p align="center">
  <strong>Operating Systems II</strong>
</p>

<h1 align="center">
  UNIX-Domain Stream Sockets Communication for Fibonacci Sequence Validation
</h1>

<p align="center">
  <strong>Vasileios Evangelos Athanasiou</strong><br>
  Student ID: 19390005
</p>

<p align="center">
  <a href="https://github.com/Ath21" target="_blank">GitHub</a> ·
  <a href="https://www.linkedin.com/in/vasilis-athanasiou-7036b53a4/" target="_blank">LinkedIn</a>
</p>

<hr/>

<p align="center">
  <strong>Supervision</strong>
</p>

<p align="center">
  Supervisor: Vasileios Mamalis, Professor
</p>
<p align="center">
  <a href="https://ice.uniwa.gr/en/emd_person/vassilios-mamalis/" target="_blank">UNIWA Profile</a>
</p>

<p align="center">
  Co-supervisor: Nikolaos Psarras, Applications Lecturer
</p>

<p align="center">
  <a href="https://ice.uniwa.gr/en/emd_person/nikolaos-psarras/" target="_blank">UNIWA Profile</a> ·
  <a href="https://www.linkedin.com/in/psarras-nikolas-20234183/" target="_blank">LinkedIn</a>
</p>

</hr>

<p align="center">
  Athens, June 2022
</p>

---

# UNIX-Domain Stream Sockets Communication for Fibonacci Sequence Validation

This repository contains an assignment for **Operating Systems II**, focusing on inter-process communication using **UNIX-domain stream sockets** to validate Fibonacci number sequences exchanged between a client and a server.

---

## Table of Contents

| Section | Folder/File | Description |
|------:|-------------|-------------|
| 1 | `assign/` | Assignment material |
| 1.1 | `assign/ASK-2C-OS-II-LAB-2021-22.png` | Assignment description in English |
| 1.2 | `assign/ΑΣΚ-2Γ-ΛΣ-ΙΙ-ΕΡΓ-2021-22.png` | Assignment description in Greek |
| 2 | `src/` | Source code implementations |
| 2.1 | `src/server.c` | Server program implementation |
| 2.2 | `src/client.c` | Client program implementation |
| 3 | `README.md` | Repository documentation |

---

## Project Overview

The project implements communication between two programs using **UNIX-domain stream sockets**:

- A **server** program listens for client connections.
- A **client** program sends a sequence of integers.
- The server checks whether the received numbers match the **first N values of the Fibonacci sequence**.
- The server returns a response indicating whether the sequence is valid.

This assignment demonstrates inter-process communication techniques in Unix-like systems.

---

## Objectives

- Implement socket-based communication using UNIX-domain sockets.
- Exchange structured data between client and server programs.
- Validate Fibonacci sequences on the server side.
- Return validation results to the client.
- Demonstrate client-server interaction in a local system environment.

---

## Key Features

- **Client–Server Communication**  
  Programs communicate locally using UNIX sockets.

- **Sequence Validation**  
  Server verifies correctness of Fibonacci sequences.

- **Interactive Client**  
  Client allows repeated sequence submission.

- **Local IPC Mechanism**  
  Uses UNIX-domain sockets instead of network sockets.

---

## Program Structure

### Server Program (`server.c`)
1. Create UNIX-domain socket.
2. Bind to a socket path.
3. Listen for client connections.
4. Receive integer sequences.
5. Validate Fibonacci sequence.
6. Send result back to client.

### Client Program (`client.c`)
1. Connect to server socket.
2. Send integer sequences.
3. Receive server response.
4. Allow repeated user input.

---

## Requirements

- **Operating System:** Linux or Unix-like OS
- **Compiler:** GCC
- **Libraries:** Standard socket programming libraries (`sys/socket.h`, `sys/un.h`, etc.)

---

## Installation & Usage

### 1. Clone Repository
```bash
git clone https://github.com/Operating-Systems-2-aka-Uniwa/Sockets.git
cd Sockets
```

### 2. Compile Programs
```bash
gcc -o server server.c
gcc -o client client.c
```

### 3. Run Programs
Start the server:
```bash
./server
```

In another terminal, run the client:
```bash
./client Fibonacci_socket
```

The client sends sequences and receives validation results from the server.