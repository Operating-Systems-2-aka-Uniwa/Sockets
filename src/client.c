/*
Laboratory OS 2 / Exercise 2 / Question 3 / 2021-22
Name: Athanasiou Vasileios Evangelos
Student ID: 19390005
Compilation Command: gcc -o client client.c 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
    int sock;                                                                                  // Declaration of the "socket file descriptor".
/********************************************************************************************* The address of the "socket file descriptor" ********************************************************/
    struct sockaddr_un server;                                                                 // Declaration of a variable of type "sockaddr_un" structure imported from the "sys/un.h" library (line 12), which will define the address of the "socket" in the "file system".
/***********************************************************************************************************************************************************************************************/

    int *Seq;                                                                                  // Declaration of a pointer of type "int *" that will point to the array of integers.
    int N;                                                                                     // Declaration of the size of the array.
    int i;                                                                                     // Declaration of an integer counter for the execution loop (lines 61-65).
    int check;                                                                                 // Declaration of an integer variable that will contain a value indicating whether the "client" wants to send another sequence for checking to the "server" or not.
    char buf[1024];                                                                            // Declaration of a character "buffer" for storing the message that will be sent by the "server" to the "client" for the sequence.
    
    if (argc < 2)                                                                              /* Check for the parameters passed when executing the "client" program. */
    {
        printf ("Error! Client needs 1 argument.\n");
        printf ("%s Fibonacci_socket\n", argv[0]);                                             // Prints to the "stdout" the command that should be executed with the second parameter (argv[1]) being the address of the "socket" of the "server" that is in the "File system", so that the "clients" can connect with their "sockets".
        exit(1);                                                                               // The process terminates with "exit value" 1.
    }
    sock = socket (AF_UNIX, SOCK_STREAM, 0);                                                   // Call of the "socket ()" function imported from the "sys/socket.h" library (line 11), which creates the "socket" of the "client", which will be in the "domain" of "AF_UNIX" and will be of type "SOCKET_STREAM". The "file descriptor" of the "client" is stored in the variable "sock". 
    if (sock < 0)                                                                              /* Check for error return from the "socket ()" at line 33. */
    {
        perror ("socket () failed to execute");                                                // Prints an error message to the "stderr" for the failure of "socket ()".
        exit (1);                                                                              // The process terminates with "exit value" 1.
    }
    server.sun_family = AF_UNIX;                                                               // Assign the "sun_family" attribute of the "sockaddr_un" structure object to the domain in which the "socket" resides.
    strcpy (server.sun_path, argv[1]);                                                         // Assign the address of the "server's socket" that is in the "File system" provided as a parameter to the "sun_path" attribute of the "sockaddr_un" structure object.
    if (connect (sock, (struct sockaddr *) &server, sizeof (struct sockaddr_un)) < 0)          /* Call of the "connect ()" function imported from the "sys/socket.h" library (line 11), which achieves the connection of the "client's socket" with the "server's socket" and check for error return.  */
    {
        if (close (sock) < 0)                                                                  /* If the connection fails, call "close ()" which is imported from the "sys/socket.h" library (line 11) and close the "client's socket". Also, check for error return. */
        {
            perror ("close () failed to execute");                                             // Prints an error message to the "stderr" for the failure of "close ()".
            exit (1);                                                                          // The process terminates with "exit value" 1.
        }
        perror ("connect () failed to execute");                                               // Prints an error message to the "stderr" for the failure of "connect ()".
        exit (1);                                                                              // The process terminates with "exit value" 1.
    }
    do                                                                                         /* Loop that checks the "client's" desire to send-receive data from the "server". */
    {
        printf ("Input the size of Matrix : ");
        scanf ("%d", &N);                                                                      // Reads from the "stdin" and the address of the variable "N", the size of the sequence to be sent to the "server".
        Seq = (int *) malloc (N * sizeof (int));                                               // Dynamic memory allocation using the pointer "Seq" of type "int *" for the creation of the sequence of integer numbers.
        if (!Seq)                                                                              /* Check if the pointer "Seq" points to "NULL". */
        {
            printf ("Error in allocating heap memory\n");                                      // Prints an error message to the "stderr" for the failed memory allocation at line 56.
            exit (1);                                                                          // The process terminates with "exit value" 1.
        }
        for (i = 0; i < N; i++)                                                                /* Loop for inputting numbers into the sequence. */
        {
            printf ("Seq[%d] : ", i + 1); 
            scanf ("%d", Seq + i);                                                             // Reads from the "stdin" the integer numbers that will be included in the sequence to be sent to the "server" for checking.
        }
        if (write (sock, Seq, N * sizeof (int)) < 0)                                           /* Call of "write ()" imported from the "unistd.h" library (line 13), which writes the "bytes" of data that the "client" will send to the "server", i.e., the sequence with the integers and check for error return. */
        {
            perror ("write () failed to execute");                                             // Prints an error message to the "stderr" for the failure of "write ()".
            exit (1);                                                                          // The process terminates with "exit value" 1.
        }
        if (read (sock, buf, 1024) < 0)                                                        /* Call of "read ()" imported from the "unistd.h" library (line 13), which reads the "bytes" of data that the "client" will receive from the "server", i.e., the message from the "server" about whether the sequence with integers is the "Fibonacci" sequence and check for error return. */
        {
            perror ("read () failed to execute");                                              // Prints an error message to the "stderr" for the failure of "read ()".
            exit (1);                                                                          // The process terminates with "exit value" 1.
        }
        printf ("\n");
        printf ("Server's message for the sequence given : %s\n\n", buf);                      // Prints to the "stdout" the message from the "server" about whether the sequence with integers is the "Fibonacci" sequence.
        free (Seq);                                                                            // Memory deallocation using the pointer type "int *" "Seq" which pointed to the sequence of integers.
        do                                                                                     /* Loop that checks the "client's" desire to terminate the connection with the "server" or send another sequence for checking. */
        {
            printf ("Send another sequence of integers to server in order to check if is Fibonacci's sequence?\n");
            printf ("Press 1 for Yes\n");
            printf ("Press 0 for No\n");
            printf ("Yes/No : ");
            scanf ("%d", &check);                                                              // Reads from the "stdin" the integer number that will indicate the user's desire to terminate the connection with the "server" or send another sequence for checking.
            printf ("\n");
        }
        while (check != 1 && check != 0);                                                       /* If the "client" types the value 1, then another sequence will be sent to the "server" for checking, while if they type the value 0, then the connection will be terminated. Any other integer value entered will be ignored. */
    }
    while (check == 1);                                                                         /* Check if the "client" wishes to send another sequence to the "server" for checking. */
    
    if (close (sock) < 0)                                                                       /* If the connection fails, call "close ()" imported from the "sys/socket.h" library (line 11) and close the "client's socket". Also, check for error return. */
    {
        perror ("close () failed to execute");                                                  // Prints an error message to the "stderr" for the failure of "close ()".
        exit (1);                                                                               // The process terminates with "exit value" 1.
    }
    
    return 0;
}


/*  SAMPLE RUNS
    
    #1 ./client Fibonacci_socket
    Input the size of Matrix : 10
    Seq[1] : 1
    Seq[2] : 2
    Seq[3] : 0
    Seq[4] : 1
    Seq[5] : 21
    Seq[6] : 34
    Seq[7] : 8
    Seq[8] : 5
    Seq[9] : 3
    Seq[10] : 13

    Server's message for the sequence given : Sequence Ok

    Send another sequence of integers to server in order to check if is Fibonacci's sequence?
    Press 1 for Yes
    Press 0 for No
    Yes/No : 1

    Input the size of Matrix : 3    
    Seq[1] : 5
    Seq[2] : 6
    Seq[3] : 5

    Server's message for the sequence given : Check Failed

    Send another sequence of integers to server in order to check if is Fibonacci's sequence?
    Press 1 for Yes
    Press 0 for No
    Yes/No : 0
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||    
    #2 ./client Fibonacci_socket
    Input the size of Matrix : 20
    Seq[1] : 34
    Seq[2] : 5
    Seq[3] : 67
    Seq[4] : 31
    Seq[5] : 2
    Seq[6] : 0
    Seq[7] : 1
    Seq[8] : 1
    Seq[9] : 23
    Seq[10] : 4
    Seq[11] : 3
    Seq[12] : 45
    Seq[13] : 67
    Seq[14] : 89
    Seq[15] : 4
    Seq[16] : 23
    Seq[17] : 4
    Seq[18] : 5
    Seq[19] : 6
    Seq[20] : 7

    Server's message for the sequence given : Check Failed

    Send another sequence of integers to server in order to check if is Fibonacci's sequence?
    Press 1 for Yes
    Press 0 for No
    Yes/No : 1

    Input the size of Matrix : 2
    Seq[1] : 0
    Seq[2] : 1

    Server's message for the sequence given : Sequence Ok
    
    Send another sequence of integers to server in order to check if is Fibonacci's sequence?
    Press 1 for Yes
    Press 0 for No
    Yes/No : 1

    Input the size of Matrix : 3
    Seq[1] : 4
    Seq[2] : 3
    Seq[3] : 6

    Server's message for the sequence given : Check Failed

    Send another sequence of integers to server in order to check if is Fibonacci's sequence?
    Press 1 for Yes
    Press 0 for No
    Yes/No : 0
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||    
    #3 ./client Fibonacci_socket
    Input the size of Matrix : 10
    Seq[1] : 1
    Seq[2] : 2
    Seq[3] : 0
    Seq[4] : 1
    Seq[5] : 21
    Seq[6] : 34
    Seq[7] : 8
    Seq[8] : 5
    Seq[9] : 3
    Seq[10] : 13

    Server's message for the sequence given : Sequence Ok

    Send another sequence of integers to server in order to check if is Fibonacci's sequence?
    Press 1 for Yes
    Press 0 for No
    Yes/No : 1

    Input the size of Matrix : 3 
    Seq[1] : 5
    Seq[2] : 6
    Seq[3] : 5

    Server's message for the sequence given : Check Failed

    Send another sequence of integers to server in order to check if is Fibonacci's sequence?
    Press 1 for Yes
    Press 0 for No
    Yes/No : 0
    
    COMMENTS
    
    The "client" programs were executed simultaneously and connected to the "server" (as well as served) in increasing order (from "client" #1 to #3).
*/

