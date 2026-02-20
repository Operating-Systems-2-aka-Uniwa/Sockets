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

# INSTALL

## UNIX-Domain Stream Sockets Communication for Fibonacci Sequence Validation

This guide explains how to set up, build, and run the project on your local machine.

---

## 1. Requirements

- **Operating System:** Linux or Unix-like OS
- **Compiler:** GCC
- **Libraries:** Standard socket programming libraries (`sys/socket.h`, `sys/un.h`, etc.)

---

## 2. Installation & Usage

### 2.1 Clone Repository

```bash
git clone https://github.com/Operating-Systems-2-aka-Uniwa/Sockets.git
cd Sockets
```

### 2.2 Compile Programs

```bash
gcc -o server server.c
gcc -o client client.c
```

### 2.3 Run Programs

Start the server:

```bash
./server
```

In another terminal, run the client:

```bash
./client Fibonacci_socket
```

The client sends sequences and receives validation results from the server.
