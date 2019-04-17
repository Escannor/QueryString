#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct queryString{
    char key[20];
    char value[20];
}typedef queryString;

int main()
{
    char URL[100];
    queryString lista[15];
    bool keyW=false, valueW=false, QueryN=false;
    int i=0,j=0;

    strcpy( lista[0].key, "");
    strcpy( lista[0].value, "");

    printf("Ingresa el URL\n");
    scanf("%s",&URL);
    printf("URL %s",URL);

    while ( URL[i] == '\0'){

        if ( keyW == true)
            strcat( lista[j].key, URL[i] );
        if ( valueW == true)
            strcat( lista[j].value, URL[i] );

        if ( ( URL[i] == '/') || ( URL[i] == '&') ){
            keyW = true;
            valueW = false;
            if (QueryN == true) {
                j++;
                QueryN = false;
                strcpy( lista[j].key, "");
                strcpy( lista[j].value, "");
            }
        }

        if ( URL[i] == '?') {
            strcpy( lista[j].key, "");
        }

        if ( URL[i] == '=') {
            keyW = false;
            valueW = true;
            QueryN = true;
        }

        i++;
    }

    int jp = 0;
    while( jp <= j){
        printf("\n%d\nkey: %s\nvalue: %s", jp, lista[jp].key, lista[jp].value);
        jp++;
    }


    return 0;
}


/*   Vestigios del Caos
    
    while(URL[i]!=NULL){
    printf("\nkey: %s\nvalue: %s", lista[0].key, lista[0].value);
*/
