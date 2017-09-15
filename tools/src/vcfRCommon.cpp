#include <Rcpp.h>
#include "vcfRCommon.h"
#include <string>


// From:
// https://github.com/RcppCore/Rcpp/issues/636#issuecomment-280985661
/*
void R_init_vcfR(DllInfo* info) {
	R_registerRoutines(info, NULL, NULL, NULL, NULL);
	R_useDynamicSymbols(info, TRUE);
}
*/


//static 
//static 
void vcfRCommon::strsplit(std::string& mystring, std::vector<std::string>& vec_o_strings, char& split){
//void strsplit(std::string& mystring, std::vector<std::string>& vec_o_strings, char& split){
  // mystring is a string to be split on the character 'split'.
  // vec_o_strings is empty and will be pushed on to.

  int start = 0;
  unsigned int i=0;

  for(i = 1; i < mystring.size(); i++){
    if( mystring[i] == split){
      std::string temp = mystring.substr(start, i - start);
      vec_o_strings.push_back(temp);
      start = i+1;
      i = i+1;
    }
  }

  // Handle the last element.
  std::string temp = mystring.substr(start, i - start);
  vec_o_strings.push_back(temp);
  
}








