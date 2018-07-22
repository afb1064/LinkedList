#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct liste{
	char isim[20];
	char soyisim[20];
	char numara[11];
	int yas;
	liste*sonraki;
}Liste;
Liste *ilk=NULL,*son=NULL,*yeni,*gecici,*temp;

 void ekle(Liste*);
 void bastir();
 void sil(int);
 void dosyayaYaz();
 void dosyadanOku();

 FILE *fp;
 FILE *fc;

int main(){

  int secim=0;

   while(secim!=6){
	puts("1-EKLE\n2-LISTELE\n3-SIL\n4-DOSYAYA YAZ\n5-DOSYADAN EKLE\n6-CIKIS");

	scanf("%d",&secim);
	system("CLS");

	 switch(secim){

		case 1:

		yeni=(Liste*)malloc(sizeof(Liste));

		puts("Isim Gir\n");
	    scanf("%s",&yeni->isim);

	    puts("Soyisim Gir");
	    scanf("%s",&yeni->soyisim);

	    puts("Tel No");
	    scanf("%s",&yeni->numara);

	    puts("Yas");
	    scanf("%d",&yeni->yas);

		yeni->sonraki=NULL;
	    ekle(yeni);
	    getch();

		break;

		case 2:
		bastir();
		getch();
		break;

		case 3:
		int no;
		puts("Silinecek Indis Numarasini Giriniz");
		scanf("%d",&no);
		sil(no);
		getch();
		break;

		case 4:
		fp=fopen("Liste.txt","w");
		dosyayaYaz();
		fclose(fp);
	    getch();
	    break;

		case 5:
		fc=fopen("Liste.txt","r");
	    dosyadanOku();
	    fclose(fc);
	    getch();
	    break;
	}
      system("CLS");
 }
 return 0;
}
void ekle(Liste*yeni)
{
	if(ilk==NULL)
	{
		ilk=yeni;
		son=yeni;
	}
	else
	{
		son->sonraki=yeni;
		son=son->sonraki;
	}
}

void bastir()
{
	gecici=ilk;

    while(gecici!=NULL)
    {

	printf("Isim: %s\n",gecici->isim);
	printf("Soyisim: %s\n",gecici->soyisim);
	printf("Numara: %s\n",gecici->numara);
	printf("Yas: %d\n",gecici->yas);
	printf("\n");
    gecici=gecici->sonraki;

    }
}
void sil(int indis){
	int i=0;
	gecici=ilk;

	while(gecici!=NULL)
	{
	 gecici=gecici->sonraki;
	 i++;
    }

	printf("%d",i);

	if(indis==1)
	{
    	gecici=ilk;
    	ilk=ilk->sonraki;
    	free(gecici);
	}

    if(indis==i)
    {
	gecici=ilk;

	for(int j=0;j<(i-2);j++)
	   {
       gecici=gecici->sonraki;
	   }

       temp=gecici->sonraki;
       son=gecici;
       son->sonraki=NULL;
       free(temp);
    }

    else{
    gecici=ilk;

	for(int s=0;s<(indis-2);s++)
    {
    gecici=gecici->sonraki;
	}

	temp=gecici->sonraki;
	gecici->sonraki=temp->sonraki;
	free(temp);
	}

}

void dosyayaYaz(){

  gecici=ilk;
  while(gecici!=NULL)
  {
	fprintf(fp,"%s\t%s\t%s\t%d\n",gecici->isim,gecici->soyisim,gecici->numara,gecici->yas);
    gecici=gecici->sonraki;
  }
}

void dosyadanOku(){

  while(!feof(fc))
    {
	yeni=(Liste*)malloc(sizeof(Liste));
	fscanf(fc,"%s\t%s\t%s\t%d\n",&yeni->isim,&yeni->soyisim,&yeni->numara,&yeni->yas);
	yeni->sonraki=NULL;
    ekle(yeni);
	}
}
