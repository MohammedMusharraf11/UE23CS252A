#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { head, data } TYPEFIELD;

struct entryNode {
    int docID;
    int patID;
    char time[10];
    struct entryNode *docNext;
    struct entryNode *patNext;
};

typedef struct multiList {
    struct entryNode *doctorHead;
    struct entryNode *patientHead;
} MULTILIST;


MULTILIST* init(TYPEFIELD tag) {
    MULTILIST *newList = (MULTILIST *)malloc(sizeof(MULTILIST));
    newList->doctorHead = NULL;
    newList->patientHead = NULL;
    // SRN: @PES2UG23CS915
    return newList;
}


int addDoctor(MULTILIST *p) {
    static int doctorID = 0;
    doctorID++;
    return doctorID;
}


int addPatient(MULTILIST *p) {
    static int patientID = 0;
    patientID++;
    return patientID;
}


int addAppointment(MULTILIST *p, int docID, int patID, char *time) {
    struct entryNode *newNode = (struct entryNode *)malloc(sizeof(struct entryNode));
    newNode->docID = docID;
    newNode->patID = patID;
    strcpy(newNode->time, time);
    newNode->docNext = p->doctorHead;
    p->doctorHead = newNode;
    newNode->patNext = p->patientHead;
    p->patientHead = newNode;
    printf("\nAppointment added for Doctor ID %d with Patient ID %d at %s", docID, patID, time);
    return 0;
}


void deleteAppointment(MULTILIST *p, int docID, int patID) {
    struct entryNode *current = p->doctorHead, *prev = NULL;
    while (current != NULL) {
        if (current->docID == docID && current->patID == patID) {
            if (prev == NULL) {
                p->doctorHead = current->docNext;
            } else {
                prev->docNext = current->docNext;
            }
            free(current);
            printf("\nAppointment between Doctor %d and Patient %d deleted", docID, patID);
            return;
        }
        prev = current;
        current = current->docNext;
    }
    printf("\nAppointment not found.");
}


void listAppDoc(MULTILIST *p, int docID) {
    struct entryNode *current = p->doctorHead;
    int found = 0;
    while (current != NULL) {
        if (current->docID == docID) {
            printf("\nAppointment: Patient ID %d at %s", current->patID, current->time);
            found = 1;
        }
        current = current->docNext;
    }
    if (!found) {
        printf("\nNo appointments for Doctor ID %d", docID);
    }
}


void listAppPat(MULTILIST *p, int patID) {
    struct entryNode *current = p->patientHead;
    int found = 0;
    
    if (current == NULL) {  // Check if the patient list is empty
        printf("\nNo appointments for Patient ID %d", patID);
        return;
    }
    
    while (current != NULL) {
        if (current->patID == patID) {
            printf("\nAppointment: Doctor ID %d at %s", current->docID, current->time);
            found = 1;
        }
        current = current->patNext;
    }
    
    if (!found) {
        printf("\nNo appointments for Patient ID %d", patID);
    }
}
// SRN: PES2UG23CS915
int main() {
    int ch, docID, patID, cont;
    char time[10];
    MULTILIST *p;
    p = init(data);
    printf("********************************************\n");
    printf("    HOSPITAL MANAGEMENT SYSTEM              \n");
    printf("********************************************\n");
    do {
        printf("\nEnter your choice:");
        printf("\n1. Add doctor");
        printf("\n2. Add patient");
        printf("\n3. Add Appointment");
        printf("\n4. Delete Appointment");
        printf("\n5. List Appointments for a Doctor");
        printf("\n6. List Appointments for a Patient");
        printf("\n7. Exit");
        printf("\nChoice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                docID = addDoctor(p);
                printf("\nDoctor inserted with doctor ID: %d", docID);
                break;
            case 2:
                patID = addPatient(p);
                printf("\nPatient inserted with patient ID: %d", patID);
                break;
            case 3:
                printf("\nEnter the doctor ID: ");
                scanf("%d", &docID);
                printf("\nEnter the patient ID: ");
                scanf("%d", &patID);
                printf("\nEnter the appointment time (HH:MM): ");
                scanf("%s", time);
                addAppointment(p, docID, patID, time);
                break;
            case 4:
                printf("\nEnter the doctor ID: ");
                scanf("%d", &docID);
                printf("\nEnter the patient ID: ");
                scanf("%d", &patID);
                deleteAppointment(p, docID, patID);
                break;
            case 5:
                printf("\nEnter the doctor ID: ");
                scanf("%d", &docID);
                listAppDoc(p, docID);
                break;
            case 6:
                printf("\nEnter the patient ID: ");
                scanf("%d", &patID);
                listAppPat(p, patID);
                break;
            case 7:
                exit(0);
            default:
                printf("\nInvalid choice");
        }
        printf("\nDo you want to continue? Press 1 for Yes, 0 for No: ");
        scanf("%d", &cont);
    } while (cont);
    return 0;
}
