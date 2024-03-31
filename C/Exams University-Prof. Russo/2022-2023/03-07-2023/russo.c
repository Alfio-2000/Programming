#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#define STRLEN  1024
#define NP      401
#define FILE_X  "x.txt"
#define FILE_Y0 "y0.txt"
#define FILE_Y1 "y1.txt"
#define INV_N   (1.0/100)

typedef float*  pfloat;
typedef char*   pchar;
typedef FILE*   pfile;

pfloat get_array_from_txt(pchar nf,unsigned n)
 {pfile    pf;
  pfloat   parr;
  unsigned i;
  char     s[STRLEN];
  
  if ((pf=fopen(nf,"r"))==NULL) return (pfloat)pf;
  printf("Leggo il file %s\n",nf);
  if ((parr=(pfloat)malloc(sizeof(float)*n))!=NULL) 
   for(i=0;i<NP;i++) {fscanf(pf,"%s",s); parr[i]=atof(s);}
  printf("Primo valore=%6.2f Ultimo=%6.2f\n",parr[0],parr[n-1]);
  fclose(pf);
  return parr;
 }
 
float get_value(pchar msg)
 {char     s[STRLEN]; printf("%s: ",msg); scanf("%s",s); return atof(s);}
 
int main(void)
 {pfloat   px,py0,py1;
  float    m_mn,m_mx,q_mn,q_mx,m0,m1,q0,q1,e0mn,e1mn,diff0,diff1,y,x,dm,dq,m,q,e0,e1;
  unsigned i;
  
  if ((px= get_array_from_txt(FILE_X ,NP))==NULL) goto get_array_from_txt_err;
  if ((py0=get_array_from_txt(FILE_Y0,NP))==NULL) goto get_array_from_txt_err;
  if ((py1=get_array_from_txt(FILE_Y1,NP))==NULL) goto get_array_from_txt_err;
    
  do
   {m_mn=get_value("m minimo" );
    m_mx=get_value("m massimo");
   }
  while (m_mx<=m_mn); dm=(m_mx-m_mn)*INV_N;
  do
   {q_mn=get_value("q minimo" );
    q_mx=get_value("q massimo");
   }
  while (q_mx<=q_mn); dq=(q_mx-q_mn)*INV_N;
  
  for(e0mn=e1mn=FLT_MAX,m=m_mn;m<=m_mx;m+=dm)
   for(                 q=q_mn;q<=q_mx;q+=dq)
    {for(e0=e1=0.0,i=0;i<NP;i++)
      {y=m*px[i]+q; diff0=y-py0[i]; diff1=y-py1[i]; e0+=diff0*diff0; e1+=diff1*diff1;}
     if (e0<e0mn) {e0mn=e0; m0=m; q0=q;}
     if (e1<e1mn) {e1mn=e1; m1=m; q1=q;}
    }
  
  printf("Le due rette trovate sono:\ny=%.2fx+%.2f\ny=%.2fx+%.2f\n",m0,q0,m1,q1);
  x=(q1-q0)/(m0-m1); y=m0*x+q0; 
  printf("Il loro punto d'intersezione e' (%.2f,%.2f)\n",x,y);
  
  free(px);free(py0);free(py1);
  
  return EXIT_SUCCESS;
  
  get_array_from_txt_err: printf("ERRORE: non posso caricare uno degli array!\n"); return EXIT_FAILURE;
  
 }
