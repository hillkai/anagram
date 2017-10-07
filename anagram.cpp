#include<iostream>
#include<string>
using namespace std;

void init_arr(string[], string[]);
void comp_num_letters(string[], string[]);
void comp_letters(string, string, string[]);
void put_sorted_arr(string, string, string[]);
void rest_of_words(string[], string[]);

/************************************
 * Function: init_arr
 * Description: Initializes each array with strings
 * Parameters: orig_arr (the original array), sorted_arr (the sorted array)
 * Pre-condions: Arrays must be at least of size 7
 * Post-conditions: The seven slots in the arrays will be filled with strings
 * Return: None
 * ************************************/
void init_arr(string orig_arr[], string sorted_arr[]){
   for(int i=0; i<7; i++){
      cout << "Enter the " << i+1 << " word" << endl;
      cin >> orig_arr[i];
      cin.ignore();
   }
   for(int i=0; i<7; i++){
      sorted_arr[i] = ' ';
   }
}

/**********************************
 * Function: comp_num_letters
 * Description: Compares the size of each string and if they are the same size it sends them to the function comp_letters
 * Parameters: orig_arr (the original array), sorted_arr (the sorted array)
 * Pre-conditions: orig_arr should have string words in it
 * Post-conditions: none
 * Return: none
 * **********************************/
void comp_num_letters(string orig_arr[], string sorted_arr[]){
   for(int i=1; i<7; i++){
      if(orig_arr[0].size() == orig_arr[i].size()){
         comp_letters(orig_arr[0], orig_arr[i], sorted_arr);
      }
   }
   for(int i=2; i<7; i++){
      if(orig_arr[1].size() == orig_arr[i].size()){
         comp_letters(orig_arr[1], orig_arr[i], sorted_arr);
      }
   }
   for(int i=3; i<7; i++){
      if(orig_arr[2].size() == orig_arr[i].size()){
         comp_letters(orig_arr[2], orig_arr[i], sorted_arr);
      }
   }
   for(int i=4; i<7; i++){
      if(orig_arr[3].size() == orig_arr[i].size()){
         comp_letters(orig_arr[3], orig_arr[i], sorted_arr);
      }
   }
   for(int i=5; i<7; i++){
      if(orig_arr[4].size() == orig_arr[i].size()){
         comp_letters(orig_arr[4], orig_arr[i], sorted_arr);
      }
   }
   for(int i=6; i<7; i++){
      if(orig_arr[5].size() == orig_arr[i].size()){
         comp_letters(orig_arr[5], orig_arr[i], sorted_arr);
      }
   }
}

/***********************************
 * Function: comp_letters
 * Description: Counts the number of occurrences of a letter in a string and then compares the amounts of each
 * Parameters: str_1 (the first string we sent in to compare), str_2 (the second string we sent in to compare), sorted_arr (the sorted array)
 * Pre-conditions: str_1 and str_2 should have strings in them
 * Post-conditions: None
 * Return: None
 * **********************************/
void comp_letters(string str_1, string str_2, string sorted_arr[]){
   int counter = 0;
   int counter_2 = 0;
   int letter[26];
   int letter_2[26];
   char k = 97;
   for(int i=0; i<26; i++){
      for(int j=0; j<str_1.size(); j++){
         if(str_1.at(j) == k){
            counter++;
         }
      }
      letter[i] = counter;
      counter = 0;
      k++;
   }
   k = 97;
   for(int i=0; i<26; i++){
      for(int j=0; j<str_2.size(); j++){
         if(str_2.at(j) == k){
	    counter++;
         }
      }
      letter_2[i] = counter;
      k++;
      counter = 0;
   }
   for(int i=0; i<26; i++){
      if(letter[i] == letter_2[i]){
	 counter_2++;
      }
   }
   if(counter_2 == 26){
      put_sorted_arr(str_1, str_2, sorted_arr);
   }
}

/*******************************************
 * Function: put_sorted_arr
 * Description: Puts the anagrams next to each other in the sorted array
 * Parameters: str_1 (the first string we are putting in the array), str_2 (the second string we are putting in the array), sorted_arr (the sorted array)
 * Pre-condition: str_1 and str_2 are anagrams of each other
 * Post-conditions: sorted_arr will have one or two new anagrams in it
 * Return: None
 * *****************************************/
void put_sorted_arr(string str_1, string str_2, string sorted_arr[]){
   int counter = 0;
   int word;
   int where;
   int space;
   for(int i=0; i<7; i++){
     if(str_1 == sorted_arr[i]){
        counter++;
	word = 1;
	where = i;
     }
     if(str_2 == sorted_arr[i]){
        counter++;
	word = 2;
	where = i;
     }
   }
   if(counter == 0){
     for(int i=0; i<7; i++){
        if((sorted_arr[i] == " ") && (i < 6)){
	   sorted_arr[i] = str_1;
	   sorted_arr[i+1] = str_2;
	   break;
	}
     }
   }
   else if(counter == 1){
      for(int i=6; i>=0; i--){
	 if(sorted_arr[i] == " "){
	    space = i;  
	 }
      }
      if(word == 1){
	 for(int i=space; i>0; i--){
	    sorted_arr[i] = sorted_arr[i-1];
	    if(sorted_arr[i] == str_1){
	       sorted_arr[i] = str_2;
	       break;
	    }
	 }
      }
      else if(word == 2){
	 for(int i=space; i>0; i--){
	    sorted_arr[i] = sorted_arr[i-1];
	    if(sorted_arr[i] == str_2){
	       sorted_arr[i] = str_1;
	       break;
	    }
	 }
      }
   }
}

/***************************************
 * Function: rest_of_words
 * Description: puts the remaining non-anagram words at the end of the sorted array
 * Parameters: sorted_arr (the sorted array), orig_arr (the original array)
 * Pre-conditions: orig_arr should have at most seven strings in it
 * Post-conditions: sorted_arr will have all the words in it
 * Return: none
 * **************************************/
void rest_of_words(string sorted_arr[], string orig_arr[]){
   int counter = 0;
   int space;
   for(int i=6; i>=0; i--){
      if(sorted_arr[i] == " "){
	 space = i;  
      }
   }
   for(int i=0; i<7; i++){
      for(int j=0; j<7; j++){
         if(orig_arr[i] == sorted_arr[j]){
	    counter++;
	 }
      }
      if(counter == 0){
         sorted_arr[space] = orig_arr[i];
	 space++;
      }
      counter = 0;
   }
}

/*******************************************
 * Function: main
 * Description: runs program, prints arrays at the end
 * Parameters: none
 * Pre-condtions: none
 * Post-conditions: none
 * Return: 0
 * ******************************************/
int main(){
   string sorted_arr[7];
   string orig_arr[7];
   init_arr(orig_arr, sorted_arr);
   comp_num_letters(orig_arr, sorted_arr);
   rest_of_words(sorted_arr, orig_arr);
   cout << "The original array: " << endl;
   for(int i=0; i<7; i++){
      cout << orig_arr[i] << endl;
   }
   cout << "The sorted array: " << endl;
   for(int i=0; i<7; i++){
      cout << sorted_arr[i] << endl;
   }
   return 0;
}
