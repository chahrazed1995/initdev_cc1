#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int nbr_arguments;
char** arguments;
char const * types[] 	= {"-C","-CPP","-C++","-Py","-Latex","-BEAMER"}	    ;int N_TYPES = 6; 
char const * licences[] 	= {"-MIT","-GPL"}								;int N_LICENCES  = 2; 
char const * parmeteters[]  = {"-git", "-help"}								;int N_PARAMS    = 2; 
int   git_projet = 0; // booleen (par defaut) = false
int   help_projet = 0; // booleen (par defaut) = false
char const * msg = ""; // en cas d'erreur
char const * nom_projet = "";
char   language = NOT_SPECIFIED;
char   licence  = NOT_SPECIFIED;



//L'APPLICATIONs
     
 
void Help_projet(){
                  printf("help : ...\n");
                  }
            
            
            //___________________________________________________________________________________________________________
            
            

int paramtrs(){
	if (nbr_arguments < 2) // le nbr minimum d'argument est 2
	{	message = strdup("Expected arguments, please check the help : initdev -help\n");
		return 0; }
		
    if(strcasecmp(arguments[1],"-help") == 0)
    {   help_now = 1; // dans le cas : initdev -help
		return 1; }
		
	else
    {	project_name = arguments[1]; }
	
	for (int i = 2; i < nbr_arguments;i++)
	{ if(!argument_is_language(arguments[i]))
			 { if(!argument_is_license(arguments[i]))
				 { if(!argument_is_parm(arguments[i]))
					{ message = strdup("\nUknown arguments, please check the help : initdev -help\n");
					return 0; } 
                                }
                                  } 
                                    }
			
		if(type == NOT_SPECIFIED && git_projet){ // si l'utilisateur a choisi le git mais qu'il n'a pas préciser le type de projet
		msg = strdup("\nspecify the type, please check the help : initdev -help\n");
		return 0;
	}
	return 1;
}
            //___________________________________________________________________________________________________________
            
            
            
//INITDEV : code du projet
int main(int argc, char * argv[])
{
	nbr_arguments = argc;
	arguments = argv;

    if(paramtrs()){

		if(help_projet){
			HelpNow();
			return 0;
		}

		printf("\nproject name : %s\n", project_name);
		if ()
		printf("license : %s\n", license == NOT_SPECIFIED ? "NOT_SPECIFIED" : licences[license]);
		printf("langage : %s\n", language == NOT_SPECIFIED ? "NOT_SPECIFIED": languages[language]);
		if(git_is_chosen){
			printf("options : create git \n");
		}


	}else{
		printf("%s",message); // msg d'erreur 
		return 1; // erreur
	}
	

	return 0; // tout est parfait
}
