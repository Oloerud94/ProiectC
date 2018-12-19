#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <graphics.h>




struct jocuri 
    {
    char nume[10];
    char firma[10];
    int anul;
    int jucat;
    float nota;
    float nota_meta;
    } ;
    jocuri joc[10];

void ordint(jocuri a[],int n)
{
	printf("2.Aranjarea crescatoare dupa nr de jucatori\n");
	int i,j,aux;
	
	int b[n];
	for(i=0;i<n;i++)
	{
	b[i]=a[i].jucat;	
	}
	
	for(i=0;i<(n-1);i++)
	{
		for(j=0;j<(n-i-1);j++)
		{
		if(b[j]>b[j+1])
		  {
		  aux=b[j];
		  b[j]=b[j+1];
		  b[j+1]=aux;		
		  }
			
		}
	}
	
	for(i=0;i<n;i++)
	{
	printf("%d\n",b[i]);	
	}
	system("pause");
	 system("cls");
	
}

void ordfloat(jocuri a[],int n)
{
	printf("1.Aranjarea crescatoare dupa note\n");
	int i,j;
	float aux;
	
	float b[n];
	for(i=0;i<n;i++)
	{
	b[i]=a[i].nota;	
	}
	
	for(i=0;i<(n-1);i++)
	{
		for(j=0;j<(n-i-1);j++)
		{
		if(b[j]>b[j+1])
		  {
		  aux=b[j];
		  b[j]=b[j+1];
		  b[j+1]=aux;		
		  }
			
		}
	}
	
	for(i=0;i<n;i++)
	{
	printf("%g\n",b[i]);	
	}
	system("pause");
	 system("cls");
}

void ordchar(jocuri a[], int n)
{
	printf("3.Aranjare alfabetica\n");
	int i,j;
	char aux[30];
	
	char b[10][10];
	for(i=0;i<n;i++)
	{
	strcpy(b[i],a[i].nume);
	}
	
	for(i=0;i<(n-1);i++)
	{
		for(j=0;j<(n-i-1);j++)
		{
		 if((b[j+1],b[j]) < 0) 
		  {
		  strcpy(aux,b[j]);
		  strcpy(b[j],b[j+1]);
		  strcpy(b[j+1],aux);		
		  }
			
		}
	}
	
	for(i=0;i<n;i++)
	{
	printf("%s\n",b[i]);	
	}
	system("pause");
	 system("cls");
}

void menu ()
{
    printf("Meniu\n");
    printf("1.Aranjarea crescatoare dupa note\n");
    printf("2.Aranjarea crescatoare dupa nr de jucatori\n");
    printf("3.Aranjare alfabetica\n");
    printf("4.Graficul dupa note\n");
    printf("5.Graficul dupa note meta\n");
    printf("6.Iesire\n");
}

void desen(int n)
{   
	printf("Grafic note meta");
    initwindow(800, 600, "First Sample",100,100);
	int a=getmaxx()/n;
	int i;
	for(i=0;i<n;i++)
    {
	bar(10+i*a,getmaxy()/(joc[i].nota_meta/3),60+i*a,getmaxy());
	outtextxy(10+i*a,getmaxy()-15,joc[i].nume);
	}
	
	
	 while (!kbhit( ))
    {
    delay(200);
    } 
    closegraph();
}

void desen1(int n)
{
	 printf("Grafic note meta");
     initwindow(800, 600, "First Sample",100,100);
	int a=getmaxx()/n;
	int i;
	for(i=0;i<n;i++)
    {
	bar(10+i*a,getmaxy()/(joc[i].nota_meta/3),60+i*a,getmaxy());
	outtextxy(10+i*a,getmaxy()-15,joc[i].nume);
	}
	
	 while (!kbhit( ))
    {
    delay(200);
    } 
    closegraph();

}

int main()
{
    int r,i=0,j;
    int n,aux;
    float a;
    char c,t[10];
    printf("Cate jocuri(elemente) sa aiba structura?\n(maxim 10)");
    if(scanf("%d",&n)!=1 || (n>10) || (n<0))  // Verificam
    {
	printf("Date eronate");
	exit(1);	
	}
    printf("Ati selectat %d elemente\n",n);
   printf("Doriti preluarea datelor de la tastatura?\n DN?\n"); // da sau nu
   if( scanf(" %c",&c)!=1)
   {
	printf("DE");
	exit(1);	
  }
   printf("%c\n",c);
   if((c=='d') || (c=='D') )  //alegere tastatura
   {
   for(i=0;i<n;i++)
   {
   printf("Jocul[%d]\n",i);
   for(j=1;j<n;j++);
   printf("Introduceti numele jocului:\n");
   scanf("%s",joc[i].nume);
   printf("Introduceti firma jocului:\n");
   scanf("%s",joc[i].firma);
   printf("Introduceti anul jocului:\n");
   scanf("%d",&joc[i].anul);
   printf("Introduceti numarul de jucatori:\n");
   scanf("%d",&joc[i].jucat);
   printf("Introduceti nota jocului\n");
   scanf("%f",&joc[i].nota);
   printf("Introduceti nota de pe metacritic:\n");
   scanf("%f",&joc[i].nota_meta);
   }
   }
   else if((c=='n')||(c=='N'))              // alegere fisier
   {
   FILE * Text;
   Text=fopen("elem.txt","r");
   for(i=0;i<n;i++)
   {
   fscanf(Text,"%s",&joc[i].nume);
   fscanf(Text,"%s",&joc[i].firma);
   fscanf(Text,"%d",&joc[i].anul);
   fscanf(Text,"%d",&joc[i].jucat);
   fscanf(Text,"%f",&joc[i].nota);
   fscanf(Text,"%f",&joc[i].nota_meta);
   }
   fclose(Text);
   }
   else {printf("Eroare"); exit(1); }

  printf("Nume \tFrima \t anu\t jucat \t nota \tnota_meta\n");
  for(i=0;i<n;i++)
  {
  printf("%s\t %s\t %d\t %d\t %g\t %g\n",joc[i].nume,joc[i].firma,joc[i].anul,joc[i].jucat,joc[i].nota,joc[i].nota_meta);
  }

   while(1)  //meniu
    {

    menu ();
    if(scanf("%d",&r)!=1)
	{
		printf("DE");
		exit(1);
	}           
    switch(r)
    {
    case 1  :
    ordfloat(joc, n);

    break;

    case 2 :
    
	ordint(joc, n );
    break;

    case 3 :
    ordchar(joc,n);

    break;

    case 4 :
    
    desen(n);
    break;

     case 5 :
    desen1(n);
    break;

    case 6 :
    printf("Iesire");
    exit(1);
    }
    }
   return 0;
}
