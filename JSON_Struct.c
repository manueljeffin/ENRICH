/* ==========================================================================
 JSON_Struct.c
 Aparna Lavanya K
 
 C Stucture for given JSON format
 ========================================================================== */
 
 struct person{
    int personID;
    char* firstName;
    char* lastName;
    char* email;
};

struct contact{
    int contactID;
    char* name;
    char* street;
    char* area;
    char* city;
    struct person *p;
}*c;

