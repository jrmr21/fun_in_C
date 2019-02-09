#include <stdio.h>      //  FIRST
#include <string.h>

#ifdef WIN32    /*sous windows*/

#include <winsock2.h>
WSADATA WSAData;        /*  objet   WSADATA */
#define error -1

#elif defined(linux)

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>     /*  close   */
#include <netdb.h>      /*  get hostbyname  */
#define error -1
#define INVALID_SOCKET -1
#define closesocket(s) close(s)
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;

#else

#error os no defined

#endif // defined

SOCKADDR_IN ssin;       //  structure TCP
SOCKET sock;            //  soccket     ( surement inutil )


int main()
{

    short int check=100;
    int sock;

    system("color a");
    #ifdef WIN32    /*sous windows*/
    check = WSAStartup (MAKEWORD(2,2), &WSAData);   //  conversion 2.2(version librairies) en 1 int; initialisation de librairies socket
    printf("wsastartup verif == %d \n",check);      //  check verif de WSAStartup == 0 tout est ok
    #endif

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if(sock == INVALID_SOCKET)                                  //  error socket
    {
        printf("\n Socket not created %d\n", sock);
    }
    else                                                    //  sinon preparation serveur
    {

        printf("socket create \n");

        ssin.sin_addr.s_addr = htonl(INADDR_ANY);           //  all IP accept
        ssin.sin_family = AF_INET;
        ssin.sin_port = htons(2023);

        check=bind(sock, (SOCKADDR*)&ssin, sizeof(ssin));      //  bind declaration
        if(check == -1 )
        {
            printf("fail bind \n");
            closesocket(sock);                  //  fin socket si fail
        }
        else
        {
            char buffer[15],bufferS[15]="recus coco";
            buffer[10]='\0';
            printf("succes bind \n");
            do
            {
                check=listen(sock, 5);          //  mode ecoute jusqu'a 5 personnes
                int taille;                        //   taille des sockets reçus
                taille = sizeof(ssin);                  //  affectation de la taille
                sock = accept(sock, (SOCKADDR*) &ssin, &taille);        //  on accept la socket du client

                if(sock != -1)                                        //  sock -1 = error ou fin socket
                    printf("la socket est : %d \n",sock);
                    recv (sock, buffer, sizeof(buffer), 0);         //  lecture du msg
                    printf("le msg est %s \n",buffer);
                    send(sock, bufferS, sizeof(bufferS), 0);        //  send confirmation de reception

            }while(check == 0);             //  tant que l'ecoute est ok on attend

            closesocket(sock);      //  fin socket
        }
    }
#ifdef WIN32    /*sous windows*/
WSACleanup();       //  netoie l'initialisation de la librairies
#endif
}
