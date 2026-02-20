<p align="center">
  <img src="https://www.especial.gr/wp-content/uploads/2019/03/panepisthmio-dut-attikhs.png" alt="UNIWA" width="150"/>
</p>

<p align="center">
  <strong>UNIVERSITY OF WEST ATTICA</strong><br>
  SCHOOL OF ENGINEERING<br>
  DEPARTMENT OF COMPUTER ENGINEERING AND INFORMATICS
</p>

<p align="center">
  <a href="https://www.uniwa.gr" target="_blank">University of West Attica</a> ·
  <a href="https://ice.uniwa.gr" target="_blank">Department of Computer Engineering and Informatics</a>
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

---

<p align="center">
  Athens, June 2022
</p>

---

<p align="center">
  <img src="https://i.ytimg.com/vi/KEiur5aZnIM/hq720.jpg?sqp=-oaymwEhCK4FEIIDSFryq4qpAxMIARUAAAAAGAElAADIQj0AgKJD&rs=AOn4CLD2L48A0icVeJNFTNeMEs92nvOvXA" width="250"/>
</p>

---

# README

## UNIX-Domain Stream Sockets Communication for Fibonacci Sequence Validation

This repository contains an assignment for **Operating Systems II**, focusing on inter-process communication using **UNIX-domain stream sockets** to validate Fibonacci number sequences exchanged between a client and a server.

---

## Table of Contents

| Section | Folder/File                           | Description                       |
| ------: | ------------------------------------- | --------------------------------- |
|       1 | `assign/`                             | Assignment material               |
|     1.1 | `assign/ASK-2C-OS-II-LAB-2021-22.png` | Assignment description in English |
|     1.2 | `assign/ΑΣΚ-2Γ-ΛΣ-ΙΙ-ΕΡΓ-2021-22.png` | Assignment description in Greek   |
|       2 | `src/`                                | Source code implementations       |
|     2.1 | `src/server.c`                        | Server program implementation     |
|     2.2 | `src/client.c`                        | Client program implementation     |
|       3 | `README.md`                           | Project documentation             |
|       4 | `INSTALL.md`                          | Usage instructions                |

---

## 1. Project Overview

The project implements communication between two programs using **UNIX-domain stream sockets**:

- A **server** program listens for client connections.
- A **client** program sends a sequence of integers.
- The server checks whether the received numbers match the **first N values of the Fibonacci sequence**.
- The server returns a response indicating whether the sequence is valid.

This assignment demonstrates inter-process communication techniques in Unix-like systems.

---

## 2. Objectives

- Implement socket-based communication using UNIX-domain sockets.
- Exchange structured data between client and server programs.
- Validate Fibonacci sequences on the server side.
- Return validation results to the client.
- Demonstrate client-server interaction in a local system environment.

---

## 3. Key Features

- **Client–Server Communication**  
  Programs communicate locally using UNIX sockets.

- **Sequence Validation**  
  Server verifies correctness of Fibonacci sequences.

- **Interactive Client**  
  Client allows repeated sequence submission.

- **Local IPC Mechanism**  
  Uses UNIX-domain sockets instead of network sockets.

---

## 4. Program Structure

### 4.1 Server Program (`server.c`)

1. Create UNIX-domain socket.
2. Bind to a socket path.
3. Listen for client connections.
4. Receive integer sequences.
5. Validate Fibonacci sequence.
6. Send result back to client.

### 4.2 Client Program (`client.c`)

1. Connect to server socket.
2. Send integer sequences.
3. Receive server response.
4. Allow repeated user input.
