#ifndef CADENA_H_INCLUDED
#define CADENA_H_INCLUDED

void cargarCadena(char *pal, int tam);

void cargarCadena(char *pal, int tam){
  int i;
  fflush(stdin);
  for(i = 0; i < tam; i++){
      pal[i] = cin.get();
	  if(pal[i] == '\n') break;
	  }
  pal[i] = '\0';
  fflush(stdin);
}

#endif // CADENA_H_INCLUDED