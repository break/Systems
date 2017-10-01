#ifndef SORTER_H
#define SORTER_H

typedef struct row {
    char * color;
    char * director_name;
    int num_critic_for_reviews;
    int duration;
    int director_facebook_likes;
    int actor_3_facebook_likes;
    char * actor_2_name;
    int actor_1_facebook_likes;
    int gross;
    char * genres;
    char * actor_1_name;
    char * movie_title;
    int num_voted_users;
    int cast_total_facebook_likes;
    char * actor_3_name;
    int facenumber_in_poster;
    char * plot_keywords;
    char * movie_imdb_link;
    int num_user_for_reviews;
    char * language;
    char * country;
    char * content_rating;
    long budget;
    int title_year;
    int actor_2_facebook_likes;
    double imdb_score;
    double aspect_ratio;
    int movie_facebook_likes;
} record; 

const char * movieColumns[] = { 
	"color", "director_name", "num_critic_for_reviews", "duration",
    "director_facebook_likes","actor_3_facebook_likes", "actor_2_name",
    "actor_1_facebook_likes", "gross", "genres", "actor_1_name",
    "movie_title", "num_voted_users", "cast_total_facebook_likes",
    "actor_3_name", "facenumber_in_poster", "plot_keywords",
    "movie_imdb_link", "num_user_for_reviews", "language",
    "country", "content_rating", "budget", "title_year",
    "actor_2_facebook_likes", "imdb_score", "aspect_ratio",
    "movie_facebook_likes"
}; 

char * strtokenizer (char * str, char const * delims); 

#endif