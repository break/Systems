#include "sorter_client.h"
/* ./sorter_client -c food -h grep.cs.rutgers.edu -p 12345 */

int main (int argc, char * argv[]) {

	char * colname = (char *) malloc(100); 
	char * dirname = (char *) malloc(100);
	char * odirname = (char *) malloc(100);

	/* Our socket */ 
	int sockfd; 
	/* Our port # */
	int port; 
	/* Our sockaddr_in struct for creating a server socket */
	struct sockaddr_in address; 
	/* Hostent struct pointer to hold server info from gethostbyname() */
 	struct hostent * server; 
 	/* Buffer for messages */ 
 	char buffer[256];

 	/* Preliminary STDIN check */ 
 	dirname = getcwd(0,0);
 	odirname = getcwd(0,0);

 	int i = 1; 
 	while (argv[i]) {
 		if (i > 10) { 
 			fprintf(stderr, "%s\n", "ERROR: The correct format of input is: ./sorter_client -c <columnname> -h <hostname> -p <portnum> (-d thisdir/thatdir -o anotherdir)");
 			exit(0);
 		}
 		if (strcmp(argv[i]), "-c") { 
 			//Implement check column name (bring in old function)
 			colname = argv[i+1]; 
 		}
 		if (strcmp(argv[i]), "-h") { 
 			server = gethostbyname(arv[i+1]);
 		}
 		if (strcmp(argv[i]), "-p") { 
 			port = htons(argv[i+1]);
 		}
 		if (strcmp(argv[i]), "-d") { 
 			dirname = argv[i+1];
 		}
 		if(strcmp(argv[i]), "-o") { 
 			odirname = argv[i+1];
 		}
 		argv[i+1];
 	}

}