/*
Εργαστήριο ΛΣ 2 / Άσκηση 2 / Ερώτημα 3 / 2021-22
Ονοματεπώνυμο: Αθανασίου Βασίλειος Ευάγγελος
ΑΜ: 19390005
Τρόπος μεταγλώττισης: gcc -o LS2-19390005-Δ4-Β-2-3-client LS2-19390005-Δ4-Β-2-3-client.c 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
    int sock;                                                                                  // Δήλωση του "socket file descriptor".
/********************************************************************************************* Η διεύθυνση του "socket file descriptor" ********************************************************/
    struct sockaddr_un server;                                                                 // Δήλωση μίας μεταβλητής τύπου δομής "sockaddr_un" που εισάγεται από την βιβλιοθήκη "sys/un.h" (γραμμή 12), που θα ορίζει την διεύθυνση του "socket" στο "file system".
/***********************************************************************************************************************************************************************************************/
    int *Seq;                                                                                  // Δήλωση ενός δείκτη τύπου "int *" που θα δείχνει στον πίνακα με τους ακεραίους.
    int N;                                                                                     // Δήλωση του μεγέθους του πίνακα.
    int i;                                                                                     // Δήλωση ενός ακέραιου μετρητή για την εκτέλεση βρόχου (γραμμές 61-65).
    int check;                                                                                 // Δήλωση μιας ακέραιας μεταβλητής που θα περιέχει μία τιμή που θα δηλώνει αν ο "client" επιθυμεί να στείλει στον "server" κι άλλη ακολουθία για έλεγχο ή όχι. 
    char buf[1024];                                                                            // Δήλωση ενός "buffer" χαρακτήρων για την αποθήκευση του μηνύματος που θα στείλει ο "server" στον "client" για την ακολουθία.
    
    if (argc < 2)                                                                              /* Έλεγχος για τα ορίσματα που δίνονται παραμέτρικα κατά την εντολή εκτέλεση τους προγράμματος του "client". */
    {
        printf ("Error! Client needs 1 argument.\n");
        printf ("%s Fibonacci_socket\n", argv[0]);                                             // Τυπώνεται στο κανάλι "stdout" η εντολή που θα πρέπει να εκτελεστεί με την δεύτερη παράμετρο (argv[1]) να είναι η διεύθυνση του "socket" του "server" που είναι στο "File system", ώστε να συνδεθούν οι "clients" με τα "sockets" τους.
        exit(1);                                                                               // Η διεργασία τερματίζεται με "exit value" την τιμή 1.
    }
    sock = socket (AF_UNIX, SOCK_STREAM, 0);                                                   // Κλήση της συνάρτησης "socket ()" που εισάγεται από την βιβλιοθήκη "sys/socket.h" (γραμμή 11), όπου δημιουργεί το "socket" του "client", το οποίο θα βρίσκεται στο "domain" του "AF_UNIX" και θα είναι τύπου "SOCKET_STREAM". Ο "file descriptor" του "client" αποθηκεύεται στην μεταβλητή "sock". 
    if (sock < 0)                                                                              /* Έλεγχος για επιστροφή τιμής σφάλματος από την "socket ()" στη γραμμή 33. */
    {
        perror ("socket () failed to execute");                                                // Τυπώνεται στο κανάλι του "stderr" ένα μήνυμα λάθους για την αποτυχημένη εκτέλεση της "socket ()".
        exit (1);                                                                              // Η διεργασία τερματίζεται με "exit value" την τιμή 1.
    }
    server.sun_family = AF_UNIX;                                                               // Εκχώρηση στο χαρακτηριστικό "sun_family" του αντικειμένου τύπου δομής "sockaddr_un", το "domain" που βρίσκεται το "socket".
    strcpy (server.sun_path, argv[1]);                                                         // Εκχώρηση της διεύθυνση του "socket" του "server" που είναι στο "File system" που δόθηκε παραμετρικά, στο χαρακτηριστικό "sun_path" του αντικειμένου τύπου δομής "sockaddr_un".
    if (connect (sock, (struct sockaddr *) &server, sizeof (struct sockaddr_un)) < 0)          /* Κλήση της συνάρτησης "connect ()" που εισάγεται από την βιβλιοθήκη "sys/socket.h" (γραμμή 11), που επιτυγχάνει την σύνδεση του "socket" του "client" με το "socket" του "server" και έλεγχος για επιστροφή τιμής σφάλματος.  */
    {
        if (close (sock) < 0)                                                                  /* Εφόσον, αποτύχει η σύνδεση, καλείται η "close ()" που εισάγεται από την βιβλιοθήκη "sys/socket.h" (γραμμή 11) και κλείνει το "socket" του "client". Επίσης, γίενται έλεγχος για επιστροφή τιμής σφάλματος. */
        {
            perror ("close () failed to execute");                                             // Τυπώνεται στο κανάλι του "stderr" ένα μήνυμα λάθους για την αποτυχημένη εκτέλεση της "close ()".
            exit (1);                                                                          // Η διεργασία τερματίζεται με "exit value" την τιμή 1.
        }
        perror ("connect () failed to execute");                                               // Τυπώνεται στο κανάλι του "stderr" ένα μήνυμα λάθους για την αποτυχημένη εκτέλεση της "connect ()".
        exit (1);                                                                              // Η διεργασία τερματίζεται με "exit value" την τιμή 1.
    }
    do                                                                                         /* Βρόχος που ελέγχει την επιθυμία του "client" για αποστολή-παραλαβή δεδομένων από τον "server". */
    {
        printf ("Input the size of Matrix : ");
        scanf ("%d", &N);                                                                      // Διαβάζεται από το κανάλι "stdin" και την διεύθυνση της μεταβλητής "N", το μέγεθος της ακολουθίας που θα στείλει στον "server".
        Seq = (int *) malloc (N * sizeof (int));                                               // Δυναμική δέσμευση μνήμης με την χρήση του δείκτη "Seq" τύπου "int *" για την δημιουργία της ακολουθίας των ακεραίων αριθμών.
        if (!Seq)                                                                              /* Έλεγχος για το αν ο δείκτης "Seq" δείχνει στο "NULL". */
        {
            printf ("Error in allocating heap memory\n");                                      // Τυπώνεται στο κανάλι του "stderr" ένα μήνυμα λάθους για την αποτυχημένη δέσμευση μνήμης στη γραμμή 56.
            exit (1);                                                                          // Η διεργασία τερματίζεται με "exit value" την τιμή 1.
        }
        for (i = 0; i < N; i++)                                                                /* Βρόχος για την εισαγωγή των αριθμών στην ακολουθία. */
        {
            printf ("Seq[%d] : ", i + 1); 
            scanf ("%d", Seq + i);                                                             // Διαβάζεται από το κανάλι "stdin" οι ακέραιοι αριθμοί που θα συμπεριληφθούν στην ακολουθία που θα σταλθεί στον "server" για έλεγχο.
        }
        if (write (sock, Seq, N * sizeof (int)) < 0)                                           /* Κλήση της "write ()" που εισάγεται από την βιβλιοθήκη "unistd.h" (γραμμή 13), η οποία γράφει τα "bytes" δεδομένων που θα στείλει ο "client" στον "server", δηλαδή, την ακολουθία με τους ακέραιους αριθμούς και έλεγχος για επιστροφή τιμής σφάλματος. */
        {
            perror ("write () failed to execute");                                             // Τυπώνεται στο κανάλι του "stderr" ένα μήνυμα λάθους για την αποτυχημένη εκτέλεση της "write ()".
            exit (1);                                                                          // Η διεργασία τερματίζεται με "exit value" την τιμή 1.
        }
        if (read (sock, buf, 1024) < 0)                                                        /* Κλήση της "read ()" που εισάγεται από την βιβλιοθήκη "unistd.h" (γραμμή 13), η οποία διαβάζει τα "bytes" δεδομένων που θα παραλάβει ο "client" από τον "server", δηλαδή, το μήνυμα του "server" για το αν η ακολουθία με τους ακέραιους αριθμούς είναι η ακολουθία "Fibonacci" και έλεγχος για επιστροφή τιμής σφάλματος. */
        {
            perror ("read () failed to execute");                                              // Τυπώνεται στο κανάλι του "stderr" ένα μήνυμα λάθους για την αποτυχημένη εκτέλεση της "read ()".
            exit (1);                                                                          // Η διεργασία τερματίζεται με "exit value" την τιμή 1.
        }
        printf ("\n");
        printf ("Server's message for the sequence given : %s\n\n", buf);                      // Τυπώνεται στο κανάλι "stdout" το μήνυμα του "server" για το αν η ακολουθία με τους ακέραιους αριθμούς είναι η ακολουθία "Fibonacci"
        free (Seq);                                                                            // Αποδέσμευση μνήμης με την χρήση του δείκτη τύπου "int *" "Seq" που έδειχνε στην ακολουθία με τους ακέραιους αριθμούς.
        do                                                                                     /* Βρόχος που ελέγχει την επιθυμία του "client" για τερματισμό σύνδεσης με τον "server" ή αποστολής άλλης ακολουθίας για έλεγχο. */
        {
            printf ("Send another sequence of integers to server in order to check if is Fibonacci's sequence?\n");
            printf ("Press 1 for Yes\n");
            printf ("Press 0 for No\n");
            printf ("Yes/No : ");
            scanf ("%d", &check);                                                              // Διαβάζεται από το κανάλι "stdin" ο ακέραιο αριθμός που θα δηλώσει την επιθυμία του χρήστη για τερματισμό σύνδεσης με τον "server" ή αποστολής άλλης ακολουθίας για έλεγχο.
            printf ("\n");
        }
        while (check != 1 && check != 0);                                                       /* Αν ο "client" πληκτρολογήσει την τιμή 1, τότε θα σταλθεί άλλη ακολουθία στον "server" για έλεγχο, ενώ αν πληκτρολογήσει την τιμή 0, τότε τερματίζει τη σύνδεση του με τον "server". Οποιαδήποτε άλλη ακέραια τιμή εισαχθεί, θα αγνοηθεί. */
    }
    while (check == 1);                                                                         /* Έλεγχος για το αν ο "client" επιθυμεί να στείλει άλλη ακολουθία στον "server" για έλεγχο. */
    
    if (close (sock) < 0)                                                                       /* Εφόσον, αποτύχει η σύνδεση, καλείται η "close ()" που εισάγεται από την βιβλιοθήκη "sys/socket.h" (γραμμή 11) και κλείνει το "socket" του "client". Επίσης, γίενται έλεγχος για επιστροφή τιμής σφάλματος. */
    {
        perror ("close () failed to execute");                                                  // Τυπώνεται στο κανάλι του "stderr" ένα μήνυμα λάθους για την αποτυχημένη εκτέλεση της "close ()".
        exit (1);                                                                               // Η διεργασία τερματίζεται με "exit value" την τιμή 1.
    }
    
    return 0;
}

/*  ΕΝΔΕΙΚΤΙΚΑ ΤΡΕΞΙΜΑΤΑ
    
    #1 ./LS2-19390005-Δ4-Β-2-3-client Fibonacci_socket
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
    #2 ./LS2-19390005-Δ4-Β-2-3-client Fibonacci_socket
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
    #3 ./LS2-19390005-Δ4-Β-2-3-client Fibonacci_socket
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
    
    ΣΧΟΛΙΑ
    
    Τα προγράμματα των "clients" εκτελέστηκαν ταυτόχρονα και συνδεθήκανε με τον "server" (όπως και εξυπηρετήθηκαν) κατά αύξουσα σειρά (από τον "client" #1 εώς #3).
*/
