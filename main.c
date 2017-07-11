#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct
{
    int harf;
    int adet;
} struct_harf;
void harfAdetBul()
{
    setlocale(LC_ALL, "Turkish");
    FILE *fp;
    if((fp=fopen("metin.txt","r"))==NULL)
    {
        printf("Dosya Acilamadi ");
    }
    struct_harf dizi[29];
    diziyeHarfEkle(dizi);
    int i = 0;
    char c,h;
    int toplam=0;

    for(i=0; i<29; i++)
    {
        dizi[i].adet=0;
    }


    while(1)
    {

                c=fgetc(fp);
                if(c=='ý'){
                    c='I';
                }
                if(c=='i'){
                    c='Ý';
                }
                if(c!='I'||c!='Ý'){
                    h=toupper(c);
                }
                else{
                    h=c;
                }
                for(i=0; i<29; i++)
                    {
                        if(dizi[i].harf==h)
                        dizi[i].adet++;
                        }


        if(feof(fp))
        {
            break;
        }
    }
    fclose(fp);
    sortSiralama(dizi);
    int toplamSayi;
    toplamSayi=toplamHarf(dizi);
    ofsetYazdir(dizi,toplamSayi);
}
void diziyeHarfEkle(struct_harf dizi[])
{

    dizi[0].harf = 'A';
    dizi[1].harf = 'B';
    dizi[2].harf = 'C';
    dizi[3].harf = 'Ç';
    dizi[4].harf = 'D';
    dizi[5].harf = 'E';
    dizi[6].harf = 'F';
    dizi[7].harf = 'G';
    dizi[8].harf = 'Ð';
    dizi[9].harf = 'H';
    dizi[10].harf = 'I';
    dizi[11].harf = 'Ý';
    dizi[12].harf = 'J';
    dizi[13].harf = 'K';
    dizi[14].harf = 'L';
    dizi[15].harf = 'M';
    dizi[16].harf = 'M';
    dizi[17].harf = 'O';
    dizi[18].harf = 'Ö';
    dizi[19].harf = 'P';
    dizi[20].harf = 'R';
    dizi[21].harf = 'S';
    dizi[22].harf = 'Þ';
    dizi[23].harf = 'T';
    dizi[24].harf = 'U';
    dizi[25].harf = 'Ü';
    dizi[26].harf = 'V';
    dizi[27].harf = 'Y';
    dizi[28].harf = 'Z';

}
void sortSiralama(struct_harf dizi[])
{
    int i,j,ob_a;
    char ob_b;
    for(i=0;i<28;i++){
        for(j=1;j<29;j++){
                if(dizi[j-1].adet<dizi[j].adet){
                    ob_a=dizi[j-1].adet;
                    ob_b=dizi[j-1].harf;
                    dizi[j-1].adet=dizi[j].adet;
                    dizi[j-1].harf=dizi[j].harf;
                    dizi[j].adet=ob_a;
                    dizi[j].harf=ob_b;
                }

        }
    }
}
int toplamHarf(struct_harf dizi[]){
    int i,toplam=0;
    for(i=0;i<29;i++){
        if(dizi[i].adet!=0){
            toplam+=dizi[i].adet;
        }
    }
    return toplam;

}

void ofsetYazdir(struct_harf dizi[],int toplam){
    int i;
    for(i=0;i<28;i++){
        if(dizi[i].adet!=0){
            printf("%c ---------> %d \n",*(dizi+i),*(dizi+i));
        }
        else{
            break;
        }
    }
    if(toplam!=0){
        printf("Toplam harf sayisi = %d \n ",toplam);
    }
    getch();
}
int main()
{

    harfAdetBul();
    system("pause");
    return 1;

}


