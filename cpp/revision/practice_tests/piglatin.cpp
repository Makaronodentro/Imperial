#include "piglatin.h"

int findFirstVowel(const char* str){
    
    int c = 0;
    
    if(tolower(str[0]) == 'y'){
        str++;
        c++;
    }
    
    while(str[0] && !isVowel(str[0])){
        str++;
        c++;
    }
    
    if(str[0] == 'y'){
        str++;
        if(!str[0]){
            c++;
        }
    }
    
    return c;
}

bool isVowel(char c){
    c = tolower(c);
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y'){
        return true;
    }
    
    return false;
}

void translateWord(const char* str, char* out){
    strcpy(out, str);
    
    // if digit, leave as is
    if(isdigit(str[0])) return;
    
    int fv = findFirstVowel(str);
    // if findFirstVowel == 0, add way at the end of the word
    if(fv == 0) strcat(out, "way"); 
    else {
        shiftElements(out, fv);
        strcat(out, "ay");
    }
}

void shiftElements(char* in, int n){
    int l = strlen(in);
    
    char t[l];
    
    for(int i = 0; i < l; i++){
        t[i] = in[(i+n)%l];
    }
    
    strcpy(in, t);
}

void translateStream(istream& in, ostream& out){
    char line[256];
    char word[64] = "";
    char tran[64] = "";
    
    memset(word,0,sizeof(word));
    memset(word,0,sizeof(word));
    
    char c[2];
    c[1] = '\0';
    
    in.get(c[0]);
    
    while(in.getline(line, 256)){
		
	while(get_word(const char *input_line, int word_number, char *output_word))
	    		

            translateWord(word, tran);
            out<<tran;
            out<<c[0];
            
            memset(word,0,sizeof(word));
            memset(word,0,sizeof(word));
        }
        else{
            out<<c[0];
        }
        
        in.get(c[0]);
    }
}

bool get_word(const char *input_line, int word_number, char *output_word) {
  char *output_start = output_word;
  int words = 0;

  if (word_number < 1) {
    *output_word = '\0';
    return false;
  }
  
  do {
    while (*input_line && !isalnum(*input_line))
      input_line++;

    if (*input_line == '\0')
      break;

    output_word = output_start;
    while (*input_line && (isalnum(*input_line) || *input_line=='\'')) {
      *output_word = toupper(*input_line);
      output_word++;
      input_line++;
    }
    *output_word = '\0';

    if (++words == word_number)
      return true;

  } while (*input_line);

  *output_start = '\0';
  return false;
}
