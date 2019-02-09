#include <stdio.h>
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

int main()
{
    char buffer[15]="jeremi send";
    short int check=100;
    int sock;

    system("color a");

    printf("buffer == %s \n",&buffer);                //  print buffer

    #ifdef WIN32    /*sous windows*/
    check = WSAStartup (MAKEWORD(2,2), &WSAData);   //  conversion 2.2(version librairies) en 1 int; initialisation de librairies socket
    printf("wsastartup verif == %d \n",check);      //  check verif de WSAStartup == 0 tout est ok
    #endif

    sock = socket(AF_INET, SOCK_DGRAM, 0);        //  creation socket UDP

    if(sock == INVALID_SOCKET)                                  //  error socket
    {
        printf("\n Socket not created %d\n", sock);
    }
    else
    {
        printf("Socket created \n");

        ssin.sin_addr.s_addr = inet_addr("127.0.0.1") ;     //  configuration du socket ( struct )
        ssin.sin_family = AF_INET;
        ssin.sin_port = htons(2023);

        check = 0;

        if(check == 0)                                        //    ERROR connect
        {
            printf("connected  \n");
            check=sendto(sock, buffer, sizeof(buffer), 0,((SOCKADDR*)&ssin), sizeof(ssin));        //  send buffer en UDP

            if(check == error )
            {
               printf(" probleme send \n");
               closesocket(sock);
            }
            else
            {
                printf(" succes send \n");

                char buffe[15];
                buffe[15]='\0';

                short int n = 0;
                int taille=sizeof(ssin);
                do                           // Tant qu'on reçoit quelque chose et que le buffer n'est pas plein
                {
                    printf("read...\n");
                    n += recvfrom(sock,buffe-n, sizeof(buffe) - n, 0,((SOCKADDR*)&ssin), &taille);
                }
                while (n > 0 && n < sizeof(buffer) - 1 );

                printf("buffer = %s \n",buffe);
            }
        }
    }
#ifdef WIN32    /*sous windows*/
WSACleanup();
#endif
closesocket(sock);      //  fin socket

return 0;
}
