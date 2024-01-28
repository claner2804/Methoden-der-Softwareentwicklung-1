#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>

typedef struct {
    char marke[64];
    char modell[64];
    float verbrauch_pro_100km;
    int volumen_tank;
    char farbe[3][64];
    float reichweite;

}Cars_t;


Cars_t cars[40];

int main(int argc, char* argv[]) {


    // Überprüfung der Eingabeanzahl
    if (argc != 3) {
        fprintf(stderr, "Eingabefehler: \n");
        exit(1);
    }


    // Öffnen der Studentendatei
    FILE *file = fopen("cars.csv", "r");
    if (file == NULL) {
        fprintf(stderr, "Lesefehler\n");
        exit(1);
    }

    char buffer[1024];
    int count = 0;

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        memset(&cars[count], 0, sizeof(Cars_t));
        int retval = sscanf(buffer, "%63[^:]:%63[^:]:%f:%d:%63[^,],%63[^,],%63[^,\n\r]",
                            cars[count].marke,
                            cars[count].modell,
                            &cars[count].verbrauch_pro_100km,
                            &cars[count].volumen_tank,
                            cars[count].farbe[0],
                            cars[count].farbe[1],
                            cars[count].farbe[2]);

        // Überprüfung der Zeilen
        if (retval != 7) {
            continue;
        } else {
            cars[count].reichweite = cars[count].volumen_tank / cars[count].verbrauch_pro_100km * 100;
            count++;
        }

        // Wenn mehr als 40 Autos eingelesen wurden, wird die Schleife abgebrochen
        if (count == 40) {
            break;
        }


        //while aus
    }


    // Schließen der datei
    fclose(file);



    //LOGIK

    char *strend;
    int reichweite_input = strtol(argv[1], &strend, 10);
    if (strend == argv[1] || *strend != '\0' || reichweite_input <= 0) {
        fprintf(stderr, "Eingabefehler: Zahl %s ungueltig\n", argv[2]);
        exit(1);
    }

    //zweites eingabeargument ist die farbe
    char *farbe_input = argv[2];


    bool parameter_ok = false;
    bool reichweite_ok = false;

//durch alle autos iterieren in umgekehrter Reihenfolge
    for (int i = count - 1; i >= 0; i--) {
        //wenn die reichweite größer ist als die reichweite_input
        if (cars[i].reichweite > reichweite_input) {
            reichweite_ok = true;
            //wenn die farbe des autos mit der farbe_input übereinstimmt
            if (strcmp(cars[i].farbe[0], farbe_input) == 0 || strcmp(cars[i].farbe[1], farbe_input) == 0 ||
                strcmp(cars[i].farbe[2], farbe_input) == 0) {
                //auto ausgeben
                printf("%s %s: %.2f km\n", cars[i].marke, cars[i].modell, cars[i].reichweite);
                parameter_ok = true;
            }
        }
    }

//wenn mindestreichweite und farbe nicht matchen
    if (reichweite_ok == true && parameter_ok == false) {
        fprintf(stderr, "Parameterfehler\n");
        exit(1);


        /*
         * • Aufruf:
    ./carrange 2300 silver.
        • Ausgabe:
    Nissan Rogue: 2352.94 km
    Chevrolet Malibu: 2352.94 km

         *
         */


        return 0;
    }
}