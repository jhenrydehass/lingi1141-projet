#include "real_address.h"

#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>

const char * real_address(const char * address, struct sockaddr_in6 * rval) {
        struct addrinfo hints;
        struct addrinfo * result;
        int s;
    
        if(rval == NULL)
                return("rval can't be NULL.\n");

         /* Initialize hints */
        memset(&hints, 0, sizeof(struct addrinfo));
        hints.ai_family = AF_INET6;
        hints.ai_socktype = SOCK_DGRAM;
        hints.ai_protocol = 17;
        hints.ai_flags = AI_PASSIVE;
        hints.ai_canonname = NULL;
        hints.ai_addr = NULL;
        hints.ai_next = NULL;

        s = getaddrinfo(address, NULL, &hints, &result);
        if(s != 0)
                return(gai_strerror(s));
  
        /*printf("result->ai_family : %d.\n", result->ai_family);
        printf("result->ai_socktype : %d.\n", result->ai_socktype);
        printf("result->ai_protocol : %d.\n", result->ai_protocol);
        printf("result->ai_flags : %d.\n", result->ai_flags);
        printf("result->ai_addr->sa_family : %d.\n\n", result->ai_addr->sa_family);*/
        
        /*
         * FIX : toujours un doute sur ce cast.
         */
        struct sockaddr_in6 * saddr = (struct sockaddr_in6 *) result->ai_addr;  
        memcpy(rval, saddr, sizeof(struct sockaddr_in6));
        
        /* Free result addrinfo */
        freeaddrinfo(result);

	return(NULL);
}