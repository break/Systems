#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "sorter.h"

record* movies; 


char * strtok_try (char * str, char const * delims) {
  static char  * src = NULL;
  char  *  p,  * ret = 0;

  if (str != NULL)
    src = str;

  if (src == NULL)
    return NULL;

  if ((p = strpbrk (src, delims)) != NULL) {
    *p  = 0;
    ret = src;
    src = ++p;

  } else if (*src) {
    ret = src;
    src = NULL;
  }

  return ret;
}

int columnCheck(char * column){
	for(int i=0;i<28;i++){
		if(strcmp(column,movieColumns[i])==0){
			return 1;

		}
	}return 0;

}

int main(int argc, char ** argv){
	/*if (argc!=3 || (strcmp(argv[1],"-c"))!=0){
		fprintf(stderr, "Improper entry in arguments. Please use '-h' for help.\n");
		return 0;
	}

	int sortColumn;
	sortColumn=columnCheck(argv[2]);
	if(sortColumn!=1){
		fprintf(stderr, "Invalid column to sort has been entered, please list valid column title\n");
	}*/

	char * line=NULL;
	size_t size;
	int counter=0;
	printf("start\n");

	getline(&line, &size, stdin);


	//printf("%s, %s , %s , %d \n ", argv[0], argv[1], argv[2], argc);

	while (getline(&line, &size, stdin) != -1){
		//printf("%s\n", line);

		if(counter == 0){
			movies = (record*)calloc(sizeof(record),1);
		}
		else {
			movies = (record*)(realloc(movies,sizeof(record) * (counter+1)));
			//printf("%d\n", counter);
		}

		char* tokenizer=strtok_try(line,",");
		char* temp1= strdup(tokenizer);

		movies[counter].color = (char*)malloc(sizeof(char) * strlen(temp1)+1);
		movies[counter].color = strcpy(movies[counter].color, temp1);
		free(temp1);


		//printf("%s\n", movies[counter].color);
		//printf("%s ,",tokenizer);

		tokenizer=strtok_try(NULL,",");
		temp1=strdup(tokenizer);
		movies[counter].director_name = (char*)malloc(sizeof(char) * strlen(temp1)+1);
		movies[counter].director_name = strcpy(movies[counter].director_name, temp1);
		free(temp1);
		//printf("%s\n",movies[counter].director_name );

		//printf("%s ,",tokenizer);


		tokenizer=strtok_try(NULL,",");
		movies[counter].num_critic_for_reviews = atoi(tokenizer);
		//printf("%s ,",tokenizer);

		tokenizer=strtok_try(NULL,",");
		movies[counter].duration=atoi(tokenizer);
		//printf("%s ,",tokenizer);

		tokenizer=strtok_try(NULL,",");
		movies[counter].director_facebook_likes=atoi(tokenizer);
		//printf("%s ,",tokenizer);

		tokenizer=strtok_try(NULL,",");
		movies[counter].actor_3_facebook_likes=atoi(tokenizer);
		//printf("%s ,\n",tokenizer);
		//printf("%d\n", movies[counter].actor_3_facebook_likes);

		tokenizer=strtok_try(NULL,",");
		temp1=strdup(tokenizer);
		movies[counter].actor_2_name = (char*)malloc(sizeof(char) * strlen(temp1)+1);
		movies[counter].actor_2_name = strcpy(movies[counter].actor_2_name, temp1);
		free(temp1);


		tokenizer=strtok_try(NULL,",");
		movies[counter].actor_1_facebook_likes=atoi(tokenizer);

		tokenizer=strtok_try(NULL,",");
		movies[counter].gross=atoi(tokenizer);

		tokenizer=strtok_try(NULL,",");
		temp1=strdup(tokenizer);
		movies[counter].genres=(char*)malloc(sizeof(char) * strlen(temp1)+1);
		movies[counter].genres=strcpy(movies[counter].genres, temp1);
		free(temp1);
		//printf("genres %s \n",movies[counter].genres);


		tokenizer=strtok_try(NULL,",");
		temp1 = strdup(tokenizer);
		movies[counter].actor_1_name = (char*)malloc(sizeof(char) * strlen(temp1)+1);
		movies[counter].actor_1_name = strcpy(movies[counter].actor_1_name, temp1);
		free(temp1);
		//printf(" actor 1 %s\n", temp1);

		tokenizer=strtok_try(NULL,",");
		temp1=strdup(tokenizer);
		char* temporary = (char*)(malloc(sizeof(char)*strlen(temp1)));
		temporary = strcpy(temporary,temp1);
		//printf("here %s\n",temporary );
		free(temp1);

		tokenizer=strtok_try(NULL,",");
		temp1 = strdup(tokenizer);
		//printf("token is %s\n",tokenizer );

		int check = 0;
		if(!isdigit(*tokenizer)){
			//printf("working if\n"); cazy,lds,sdfs
			while(!isdigit(*tokenizer)){


				//printf("%d\n", strlen(temporary) + 2);

				temporary = (char*)realloc(temporary,sizeof(char) * (strlen(temporary) +2));
				//printf("%s\n", "???");
				temporary = strcat(temporary,", ");

				//printf("%s\n", "h33ere");

				temporary = (char*)realloc(temporary,sizeof(char) * (strlen(temp1) + strlen(temporary))+1);
				temporary = strcat(temporary,temp1);

				free(temp1);
				///temp_movie=strdup(temporary);
				tokenizer = strtok_try(NULL,",");
				temp1 = strdup(tokenizer);
				//printf("tokenizer in while loop is : %s \n ", tokenTemp);

			}

			movies[counter].movie_title=(char*)malloc(sizeof(char) * strlen(temporary)+1);
			movies[counter].movie_title=strcpy(movies[counter].movie_title, temporary);
			movies[counter].num_voted_users=atoi(temp1);
			free(temp1);
			free(temporary);
		}else{
			movies[counter].movie_title=(char*)malloc(sizeof(char) * strlen(temp1)+1);
			movies[counter].movie_title=strcpy(movies[counter].movie_title, temp1);
			movies[counter].num_voted_users=atoi(tokenizer);
			free(temp1);

		}

		
		//printf("aad\n");

		tokenizer=strtok_try(NULL,",");
		movies[counter].cast_total_facebook_likes=atoi(tokenizer);
		//printf(" likes %s\n",tokenizer );

		tokenizer=strtok_try(NULL,",");
		temp1=strdup(tokenizer);
		movies[counter].actor_3_name=(char*)(malloc(sizeof(char)*strlen(temp1)+1));
		movies[counter].actor_3_name=strcpy(movies[counter].actor_3_name, temp1);
		free(temp1);
		//printf("actor 3 name %s\n", movies[counter].actor_3_name);


		tokenizer=strtok_try(NULL,",");
		movies[counter].facenumber_in_poster=atoi(tokenizer);

		tokenizer=strtok_try(NULL,",");
		temp1=strdup(tokenizer);
		movies[counter].plot_keywords = (char*)(malloc(sizeof(char)*strlen(temp1)+1));
		movies[counter].plot_keywords = strcpy(movies[counter].plot_keywords,temp1);
		free(temp1);

		tokenizer=strtok_try(NULL,",");
		temp1=strdup(tokenizer);
		movies[counter].movie_imdb_link=(char*)(malloc(sizeof(char)*strlen(temp1)+1));
		movies[counter].movie_imdb_link = strcpy(movies[counter].movie_imdb_link,temp1);
		free(temp1);

		tokenizer=strtok_try(NULL,",");
		movies[counter].num_user_for_reviews=atoi(tokenizer);

		tokenizer=strtok_try(NULL,",");
		temp1=strdup(tokenizer);
		movies[counter].language = (char*)(malloc(sizeof(char)*strlen(temp1)+1));
		movies[counter].language = strcpy(movies[counter].language, temp1);
		free(temp1);

		tokenizer=strtok_try(NULL,",");
		temp1=strdup(tokenizer);
		movies[counter].country = (char*)(malloc(sizeof(char)*strlen(temp1)+1));
		movies[counter].country = strcpy(movies[counter].country,temp1);
		free(temp1);
		//printf("hcountry %s\n",movies[counter].country );

		tokenizer = strtok_try(NULL,",");
		temp1=strdup(tokenizer);
		movies[counter].content_rating = (char*)(malloc(sizeof(char)*strlen(temp1)+1));
		movies[counter].content_rating = strcpy(movies[counter].content_rating, temp1);
		free(temp1);

		tokenizer=strtok_try(NULL,",");
		movies[counter].budget=atoi(tokenizer);

		tokenizer=strtok_try(NULL,",");
		movies[counter].title_year=atoi(tokenizer);

		tokenizer=strtok_try(NULL,",");
		movies[counter].actor_2_facebook_likes=atoi(tokenizer);

		tokenizer=strtok_try(NULL,",");
		movies[counter].imdb_score=atof(tokenizer);

		tokenizer=strtok_try(NULL,",");
		movies[counter].aspect_ratio=atof(tokenizer);

		tokenizer=strtok_try(NULL,",");
		movies[counter].movie_facebook_likes=atoi(tokenizer);

		counter++;

		//printf("%s\n", "loop");

	}
	//printf("Counter is : %d\n", counter);
	int i;
	for (int i=0;i<counter;i++){
		//printf("%d \t ",i );
		printf("%s, ",movies[i].color);
		printf("%s, ",movies[i].director_name);
		printf("%d, ",movies[i].num_critic_for_reviews);
		printf("%d, ",movies[i].duration);
		printf("%d, ",movies[i].director_facebook_likes);
		printf("%d, ",movies[i].actor_3_facebook_likes);
		printf("%s, ",movies[i].actor_2_name);
		printf("%d, ",movies[i].actor_1_facebook_likes);
		printf("%d, ",movies[i].gross);
		printf("%s, ",movies[i].genres); 
		printf("%s, ",movies[i].actor_1_name);
		printf("%s, ",movies[i].movie_title);
		printf("%d, ",movies[i].num_voted_users);
		printf("%d, ",movies[i].cast_total_facebook_likes);
		printf("%s, ",movies[i].actor_3_name);
		printf("%d, ",movies[i].facenumber_in_poster );
		printf("%s, ",movies[i].plot_keywords);
		printf("%s, ",movies[i].movie_imdb_link);
		printf("%d, ",movies[i].num_user_for_reviews);
		printf("%s, ",movies[i].language);
		printf("%s, ",movies[i].country);
		printf("%s, ",movies[i].content_rating);
		printf("%ld, ",movies[i].budget);
		printf("%d, ",movies[i].title_year);
		printf("%d, ",movies[i].actor_2_facebook_likes);
		printf("%f, ",movies[i].imdb_score);
		printf("%f, ",movies[i].aspect_ratio);
		printf("%d\n",movies[i].movie_facebook_likes);

	}

	return 0;
}