#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

int get_ip_by_name(char *name, char *ip)
{
    struct hostent *hent;
    int iplen = 15;                             //XXX.XXX.XXX.XXX
    char *ipaddr = (char *)malloc(iplen + 1);   //XXX.XXX.XXX.XXX + '\0'

    memset(ipaddr, 0, iplen + 1);

    if ((hent = gethostbyname(name)) == NULL)
    {
        perror("Can't get IP");
        return 1;
    }

    if (inet_ntop(AF_INET, hent->h_addr_list[0], ipaddr, iplen+1) == NULL)
    {
        perror("Can't resolve host");
        return 1;
    }

    strcpy(ip, ipaddr);
    free(ipaddr);
    return 0;
}

int main(int argc, char *argv[])
{
    char ip[16];    //XXX.XXX.XXX.XXX + '\0'

    if (argc < 2)
    {
        printf("Please input hostname\n");
        return 1;
    }
    if (get_ip_by_name(argv[1], ip))
    {
        printf("Can't get IP\n");
        return 1;
    }
    printf("%s\n", ip);
    return 0;
}
