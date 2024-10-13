![Alt text](https://upload.wikimedia.org/wikipedia/commons/thumb/a/a5/Flag_of_the_United_Kingdom_%281-2%29.svg/255px-Flag_of_the_United_Kingdom_%281-2%29.svg.png)

# UNIX-Domain Stream Sockets Communication for Fibonacci Sequence Validation

For the requested Assignment, click the link:
[Assignment](Assignment/)

For the detailed Source Codes, click the link:
[Code](Code/)

## Assignment Overview

This project involves creating two programs: a **server** program and a **client** program that can communicate using UNIX-domain stream sockets. The client will send a sequence of integers to the server, which will check if the sequence corresponds to the first N numbers of the Fibonacci sequence. The server will then send a response back to the client, indicating whether the sequence is valid or not.

## Course Information

- **Course**: [Operating Systems II](https://ice.uniwa.gr/education/undergraduate/courses/operating-systems-ii/)
- **Semester**: 4
- **Program of Study**: [UNIWA](https://www.uniwa.gr/)
- **Department**: [Informatics and Computer Engineering](https://ice.uniwa.gr/)
- **Lab Instructor**: [Psarras Nikolaos](https://ice.uniwa.gr/emd_person/20879/)
- **Academic Season**: 2021-2022

## Student Information

- **Name**: Athanasiou Vasileios Evangelos
- **Student ID**: 19390005
- **Status**: Undergraduate

## Programs

### 1. Server Program

- **File**: `server.c`
- **Functionality**: Listens for incoming connections from clients, receives a sequence of integers, checks if they match the Fibonacci sequence, and sends a response back to the client.

### 2. Client Program

- **File**: `client.c`
- **Functionality**: Connects to the server, sends sequences of integers, and displays the server's response. It prompts the user for another sequence until the user decides to stop.

## Requirements

- **Operating System**: Linux-based OS or any Unix-like system that supports UNIX-domain sockets.
- **Compiler**: GCC (GNU Compiler Collection).
- **Libraries**: Standard libraries for socket programming (`sys/socket.h`, `sys/un.h`, etc.).

## Installation and Usage

### 1. Clone the Repository
Download the repository to your local machine:
```
git clone https://github.com/Operating-Systems-2-aka-Uniwa/Sockets.git
```
### 2. Compile the Source Code
Compile the server and client programs using the GCC compiler:
```
gcc -o server server.c
gcc -o client client.c
```
### 3. Run the Programs

1. **Start the Server**:
   
   Open a terminal and run the server program:
   ```
   ./server
   ```
2. **Start the client**:
    
    Open a terminal and run the client program with the right `socket path`:
   ```
   ./client Fibonacci_socket
   ```


![Alt text](https://upload.wikimedia.org/wikipedia/commons/thumb/5/5c/Flag_of_Greece.svg/255px-Flag_of_Greece.svg.png)

# Επικοινωνία μέσω Sockets Stream UNIX για Έλεγχο Ακολουθίας Fibonacci

Για την απαιτούμενη Άσκηση, κάντε κλικ στον σύνδεσμο:
[Άσκηση](Assignment/)

Για τον λεπτομερή Κώδικα, κάντε κλικ στον σύνδεσμο:
[Κώδικας](Code/)

## Επισκόπηση Άσκησης

Αυτό το έργο περιλαμβάνει τη δημιουργία δύο προγραμμάτων: ενός προγράμματος **server** και ενός προγράμματος **client** που μπορούν να επικοινωνούν χρησιμοποιώντας sockets stream UNIX. Ο client θα στείλει μια ακολουθία ακέραιων αριθμών στον server, ο οποίος θα ελέγξει αν η ακολουθία αντιστοιχεί στους πρώτους N αριθμούς της ακολουθίας Fibonacci. Στη συνέχεια, ο server θα στείλει μια απάντηση πίσω στον client, υποδεικνύοντας αν η ακολουθία είναι έγκυρη ή όχι.

## Πληροφορίες Μαθήματος

- **Μάθημα**: [Λειτουργικά Συστήματα II](https://ice.uniwa.gr/education/undergraduate/courses/operating-systems-ii/)
- **Εξάμηνο**: 4
- **Πρόγραμμα Σπουδών**: [UNIWA](https://www.uniwa.gr/)
- **Τμήμα**: [Πληροφορική και Μηχανική Υπολογιστών](https://ice.uniwa.gr/)
- **Εκπαιδευτής Εργαστηρίου**: [Ψαράς Νικόλαος](https://ice.uniwa.gr/emd_person/20879/)
- **Ακαδημαϊκή Χρονιά**: 2021-2022

## Πληροφορίες Φοιτητή

- **Όνομα**: Αθανασίου Βασίλειος Ευάγγελος
- **ΑΜ**: 19390005
- **Κατάσταση**: Προπτυχιακός

## Προγράμματα

### 1. Πρόγραμμα Server

- **Αρχείο**: `server.c`
- **Λειτουργικότητα**: Ακούει για εισερχόμενες συνδέσεις από clients, δέχεται μια ακολουθία ακέραιων αριθμών, ελέγχει αν ταιριάζουν με την ακολουθία Fibonacci και στέλνει μια απάντηση πίσω στον client.

### 2. Πρόγραμμα Client

- **Αρχείο**: `client.c`
- **Λειτουργικότητα**: Συνδέεται με τον server, στέλνει ακολουθίες ακέραιων αριθμών και εμφανίζει την απάντηση του server. Προτρέπει τον χρήστη για άλλη ακολουθία μέχρι ο χρήστης να αποφασίσει να σταματήσει.

## Απαιτήσεις

- **Λειτουργικό Σύστημα**: Λειτουργικό σύστημα βασισμένο σε Linux ή οποιοδήποτε Unix-like σύστημα που υποστηρίζει sockets stream UNIX.
- **Μεταγλωττιστής**: GCC (GNU Compiler Collection).
- **Βιβλιοθήκες**: Βασικές βιβλιοθήκες για προγραμματισμό sockets (`sys/socket.h`, `sys/un.h`, κ.λπ.).

## Εγκατάσταση και Χρήση

### 1. Κλωνοποίηση του Αποθετηρίου
Κατεβάστε το αποθετήριο στον τοπικό υπολογιστή σας:
```
git clone https://github.com/Operating-Systems-2-aka-Uniwa/Sockets.git
```
### 2. Μεταγλώττιση του Κώδικα
Μεταγλωττίστε τα προγράμματα server και client χρησιμοποιώντας τον μεταγλωττιστή GCC:
```
gcc -o server server.c 
gcc -o client client.c
```
### 3. Εκτέλεση των Προγραμμάτων

1. **Ξεκινήστε τον Server**:
   
   Ανοίξτε ένα τερματικό και εκτελέστε το πρόγραμμα server:
    ```
    ./server
    ```
    
2. **Ξεκινήστε τον Client**:
 
    Ανοίξτε ένα τερματικό και εκτελέστε το πρόγραμμα client με τη σωστή `διεύθυνση socket`:
    ```
   ./client Fibonacci_socket
   ``` 




