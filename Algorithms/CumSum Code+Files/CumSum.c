//RAM 8GB
//CUM-SUM ALGORITHM

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define N 1000
#define M 10000
#define K 50000
#define L 100000

void cumsum(int *array, int index);
/* GENERATE RANDOM NUMBERS,SAVE TO FILE,READ FROM FILE*/
void generate_and_save_to_file(int number,FILE *fp); //number= plithos stoixeiwn kathe fora
void load_from_file(int a[],int *counter,FILE *fp,char fileName[]);
void display_int(int a[],int len);

int main(void) {
    FILE *timer=fopen("times_2114041_2114077.txt","w"); //pointer arxeiou pou apothikeuontai oi xronoi
    FILE *fp=NULL; //pointer arxeiwn pou periexoun tous arithmous, poy kanoume load gia to test
    double time_spent;
    clock_t begin,end;
    int counter;
    char fname[30];

    //create files and generate the random numbers
    //Tis trexw mono 1 fora gia na dimiourgithoun ta arxeia k meta tis vazw se sxolio
    //an xreiastei na ksanakanw nea arxeia, tis trexw pali

    //generate_and_save_to_file(N,fp);
    //generate_and_save_to_file(M,fp);
    //generate_and_save_to_file(K,fp);
    //generate_and_save_to_file(L,fp);

    fprintf(timer,"-CumSum runtime test with: \n");
    printf("CumSum runtime\n");
    //1.000 numbers
    counter = 0;
    strcpy(fname,"numbers_1000.txt"); //anoigoume kathe fora to arxeio pou theloume gia test
    int *a = malloc(N*sizeof(int));   //desmeusi mnimis gia na fortwthei to arxeio se array
    load_from_file(a,&counter,fp,fname);

    begin = clock(); //start of timer
        cumsum(a,N-1); //call with the index of the last element (size-1)
    end = clock(); //end of timer
    //display_int(a,N);

    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    fprintf(timer,"     1.000 elements: %.5lf secs\n",time_spent);

   //10.000 numbers
    counter = 0;
    strcpy(fname,"numbers_10000.txt");
    int *b = malloc(M*sizeof(int));
    load_from_file(b,&counter,fp,fname);

    begin = clock(); //start of timer
        cumsum(b,M-1); //call with the index of the last element (size-1)
    end = clock(); //end of timer
    //display_int(b,M);

    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    fprintf(timer,"     10.000 elements: %.5lf secs\n",time_spent);

    //50.000 numbers
    counter = 0;
    strcpy(fname,"numbers_50000.txt");
    int *c = malloc(K*sizeof(int));
    load_from_file(c,&counter,fp,fname);

    begin = clock(); //start of timer
        cumsum(c,K-1); //call with the index of the last element (size-1)
    end = clock(); //end of timer
    //display_int(c,K);

    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    fprintf(timer,"     50.000 elements: %.5lf secs\n",time_spent);

    /* ---------------------Sta 100.000 stoixeia skaei o kwdikas
    //100.000 numbers
    counter = 0;
    strcpy(fname,"numbers_100000.txt");
    int *d = malloc(L*sizeof(int));
    load_from_file(d,&counter,fp,fname);

    begin = clock(); //start of timer
        cumsum(d,L-1); //call with the index of the last element (size-1)
    end = clock(); //end of timer
    //display_int(c,K);

    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    fprintf(timer,"     100.000 elements: %.5lf secs\n",time_spent);
    */

    /*---------                END                  --------------*/
    printf("\n****************************");
    printf("\nVIGLAS PANAGIWTHS 2114041 - GIWRGOS PAPADOPOULOS 2114077"
        "\nTested with:\n"
        "HDD \n"
       );

    return 0;
}

void cumsum(int *array, int index){
    if(index <= 0) return;
    cumsum(array, index -1);
    array[index] += array[index - 1];
}

/*------ EXTRA FUNCTIONS ------*/
//DISPLAY ARRAY
void display_int(int a[],int len){
    int i;

    for(i=0; i<len; i++) printf("%d, ",a[i]);
}

//GENERATE RANDOM NUMBERS AND SAVE TO FILE
void generate_and_save_to_file(int number,FILE *fp){
    char fileName[30];
    int a,i;
    srand(time(NULL));

    sprintf(fileName, "numbers_%d.txt",number); //orismos onomatwn analogws to plithos arithmwn
    fp = fopen(fileName,"w");

    fprintf(fp,"%d \n",number); //1h thesi arxeiou = plithos stoixeiwn

    for(i = 0; i < number; i++){
        a = rand()% 1000;
        fprintf(fp,"%d ",a);
    }
}

//LOAD NUMBERS FROM FILE TO ARRAY
void load_from_file(int a[],int *counter,FILE *fp,char fileName[]){
	int i,numb;
    int x;

	fp=fopen(fileName,"r");

	fscanf(fp,"%d",&numb); //arithmos groups - vasi autou kanw to for
    //printf("%d",numb);

	for(i=0; i<numb; i++){
        fscanf(fp,"%d",&x);
        a[i] = x;
	}

    printf("\n-There were %d numbers loaded from %s \n",numb,fileName);
    *counter = numb;
}

