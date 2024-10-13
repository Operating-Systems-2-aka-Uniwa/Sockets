/*
Laboratory OS 2 / Exercise 2 / Question 3 / 2021-22
Name: Athanasiou Vasileios Evangelos
Student ID: 19390005
Compilation Command: gcc -o server server.c 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>

#define BIND "Fibonacci_socket"
#define MSG_TRUE "Sequence Ok"
#define MSG_FALSE "Check Failed"

void Sort_Sequence (int [], int);
void Print_Sequence (int [], int);
int Check_Fibonacci (int [], int);

int main (int argc, char *argv[])
{
    int sock, accept_sock, read_seq;
    struct sockaddr_un server;
    int is_fibo;
    int N;
    int cnt_client = 0;
    int cnt_seq;
    int seq[100];
    
    sock = socket (AF_UNIX, SOCK_STREAM, 0);                                                      /* Call to the "socket()" function imported from the "sys/socket.h" library (line 11), which creates the "socket" of the "client", which will be in the "AF_UNIX" domain and will be of type "SOCK_STREAM". The file descriptor of the "server" is stored in the variable "sock". */
    if (sock < 0)                                                                                               
    {
        perror ("socket () failed to execute");
        exit (1);
    }
    server.sun_family = AF_UNIX;
    strcpy (server.sun_path, BIND);
    if (bind (sock, (struct sockaddr *) &server, sizeof (struct sockaddr_un)) < 0)                 /* Bind the "server's socket" to an address located in the "file system" so it can be accessed for connecting "clients' sockets". */
    {
        perror ("bind () failed to execute");
        exit (1);
    }
    printf ("Waiting for connection...\n\n");
    if (listen (sock, 5) < 0)                                                                       /* Wait for the "server" to connect to a "client". */
    {
        perror ("listen () failed to execute");
        exit (1);
    }
    while (1)
    {
        accept_sock = accept (sock, NULL, NULL);                                                    /* Accept connection from the "server" to a "client" and create a new socket for communication between them. */
        if (accept_sock < 0)
        {
            perror ("accept () failed to execute");
            exit (1);
        }
        cnt_client++;
        cnt_seq = 0;
        printf ("Hello from client #%d\n\n", cnt_client);
        do
        {
            read_seq = read (accept_sock, seq, 100 * sizeof (int));                                /* The "server" reads the sequence of integers sent by the connected "client" for checking. */
            N = read_seq / 4;                                                                      // The size of the sequence sent by the "client" and read by the "server".  
            if (read_seq < 0)
            {
                perror ("read () failed to execute");
                exit (1);
            }
            else
            {
                if (read_seq == 0)                                                                  /* If it does not receive more "bytes" from the "client" to read, it terminates the connection. */
                {
                    printf ("Ending connection with client #%d\n", cnt_client);
                    printf ("-------------------------------------------------------------------\n");
                    printf ("Waiting for connection...\n\n");
                }
                else
                {
                    cnt_seq++;
                    printf ("Sequence #%d\n\n", cnt_seq);
                    Print_Sequence (seq, N);                                                        // Print the sequence (lines 132-137).
                    Sort_Sequence (seq, N);                                                         // Sort the sequence in ascending order (lines 140-152).
                    printf ("Sequence #%d is being sorted...\n\n", cnt_seq);
                    Print_Sequence (seq, N);                                                        // Print the now sorted sequence in ascending order (lines 132-137).
                    is_fibo = Check_Fibonacci (seq, N);                                             // Check if the sequence is a "Fibonacci" sequence (lines 155-167).
                    printf ("Server is sending a message about sequence #%d to client #%d...\n\n", cnt_seq, cnt_client);
                    if (is_fibo)
                    {
                        if (write (accept_sock, MSG_TRUE, strlen (MSG_TRUE) + 1) < 0)               /* Send a message to the "client" if the sequence is a "Fibonacci" sequence. */
                        {
                            perror ("write () failed to execute");
                            exit (1);
                        }
                    }
                    else
                    {
                        if (write (accept_sock, MSG_FALSE, strlen (MSG_FALSE) + 1) < 0)             /* Send a message to the "client" if the sequence is not a "Fibonacci" sequence. */
                        {
                            perror ("write () failed to execute");
                            exit (1);
                        }
                    }
                }
            }
        }
        while (read_seq > 0);
        if (close (accept_sock) != 0)                                                               /* Close the communication socket after the connection between "client" and "server" is established. */
        {
            perror ("close () failed to execute");
            exit (1);
        }
    }
    if (close (sock) != 0)                                                                          /* Close the "server's socket". */
    {
        perror ("close () failed to execute");
        exit (1);
    }
    if (unlink (BIND) != 0)                                                                         /* Unlink the "server's socket" from the address located in the "file system" so it can be accessible for connecting "clients' sockets". */
    {
        perror ("unlink () failed to execute");
        exit (1);
    }
            
    return 0;
}

void Print_Sequence (int Seq[], int N)
{
    int i;
    for (i = 0; i < N; i++)
        printf ("Seq[%d] : %d\n", i, Seq[i]);
    printf ("\n");
}

void Sort_Sequence (int Seq[], int N)
{
    int i, j, tmp;
    for (i = 0; i < N - 1; i++)
        for (j = i + 1; j < N; j++)
        {
            if (Seq[i] > Seq[j])
            {
                tmp = Seq[i];
                Seq[i] = Seq[j];
                Seq[j] = tmp;
            }
        }
}

int Check_Fibonacci (int Seq[], int N)
{
    int i, j;
    if (Seq[0] != 0)
        return 0;
    if (Seq[1] != 1)
        return 0;
    for (i = 2; i < N; i++)
    {
        if (Seq[i] != Seq[i - 1] + Seq[i - 2])
            return 0;
    }
    return 1;
}


/*  SAMPLE RUNS
    
    #1 ./server
    Waiting for connection...

    Hello from client #1

    Sequence #1

    Seq[0] : 1
    Seq[1] : 2
    Seq[2] : 0
    Seq[3] : 1
    Seq[4] : 21
    Seq[5] : 34
    Seq[6] : 8
    Seq[7] : 5
    Seq[8] : 3
    Seq[9] : 13

    Sequence #1 is being sorted...
    
    Seq[0] : 0
    Seq[1] : 1
    Seq[2] : 1
    Seq[3] : 2
    Seq[4] : 3
    Seq[5] : 5
    Seq[6] : 8
    Seq[7] : 13
    Seq[8] : 21
    Seq[9] : 34

    Server is sending a message about sequence #1 to client #1...

    Sequence #2

    Seq[0] : 5
    Seq[1] : 6
    Seq[2] : 5

    Sequence #2 is being sorted...

    Seq[0] : 5
    Seq[1] : 5
    Seq[2] : 6

    Server is sending a message about sequence #2 to client #1...

    Ending connection with client #1
    -------------------------------------------------------------------
    Waiting for connection...

    Hello from client #2

    Sequence #1

    Seq[0] : 34
    Seq[1] : 5
    Seq[2] : 67
    Seq[3] : 31
    Seq[4] : 2
    Seq[5] : 0
    Seq[6] : 1
    Seq[7] : 1
    Seq[8] : 23
    Seq[9] : 4
    Seq[10] : 3
    Seq[11] : 45
    Seq[12] : 67
    Seq[13] : 89
    Seq[14] : 4
    Seq[15] : 23
    Seq[16] : 4
    Seq[17] : 5
    Seq[18] : 6
    Seq[19] : 7

    Sequence #1 is being sorted...

    Seq[0] : 0
    Seq[1] : 1
    Seq[2] : 1
    Seq[3] : 2
    Seq[4] : 3
    Seq[5] : 4
    Seq[6] : 4
    Seq[7] : 4
    Seq[8] : 5
    Seq[9] : 5
    Seq[10] : 6
    Seq[11] : 7
    Seq[12] : 23
    Seq[13] : 23
    Seq[14] : 31
    Seq[15] : 34
    Seq[16] : 45
    Seq[17] : 67
    Seq[18] : 67
    Seq[19] : 89

    Server is sending a message about sequence #1 to client #2...

    Sequence #2

    Seq[0] : 0
    Seq[1] : 1

    Sequence #2 is being sorted...

    Seq[0] : 0
    Seq[1] : 1

    Server is sending a message about sequence #2 to client #2...

    Sequence #3

    Seq[0] : 4
    Seq[1] : 3
    Seq[2] : 6

    Sequence #3 is being sorted...

    Seq[0] : 3
    Seq[1] : 4
    Seq[2] : 6

    Server is sending a message about sequence #3 to client #2...

    Ending connection with client #2
    -------------------------------------------------------------------
    Waiting for connection...

    Hello from client #3

    Sequence #1

    Seq[0] : 1
    Seq[1] : 1
    Seq[2] : 2
    Seq[3] : 3
    Seq[4] : 0

    Sequence #1 is being sorted...

    Seq[0] : 0
    Seq[1] : 1
    Seq[2] : 1
    Seq[3] : 2
    Seq[4] : 3

    Server is sending a message about sequence #1 to client #3...

    Sequence #2

    Seq[0] : 1
    Seq[1] : 0
    Seq[2] : 1
    Seq[3] : 3
    Seq[4] : 5  
    Seq[5] : 8
    Seq[6] : 144
    Seq[7] : 21
    Seq[8] : 13
    Seq[9] : 34
    Seq[10] : 2
    Seq[11] : 89
    Seq[12] : 55

    Sequence #2 is being sorted...

    Seq[0] : 0  
    Seq[1] : 1
    Seq[2] : 1
    Seq[3] : 2
    Seq[4] : 3
    Seq[5] : 5
    Seq[6] : 8
    Seq[7] : 13
    Seq[8] : 21
    Seq[9] : 34
    Seq[10] : 55
    Seq[11] : 89
    Seq[12] : 144

    Server is sending a message about sequence #2 to client #3...

    Sequence #3

    Seq[0] : 33
    Seq[1] : 32
    Seq[2] : 12
    Seq[3] : 34

    Sequence #3 is being sorted...

    Seq[0] : 12
    Seq[1] : 32
    Seq[2] : 33
    Seq[3] : 34

    Server is sending a message about sequence #3 to client #3...

    Ending connection with client #3
    -------------------------------------------------------------------
    Waiting for connection...
*/

