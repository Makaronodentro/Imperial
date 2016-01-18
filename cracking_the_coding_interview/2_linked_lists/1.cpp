/* 2.1 | Remove Dupes
 * -----------------------------------------------------------------------------
 * Desc  : remove duplicates from unsorted list
 *
 * Notes : Do we care about running time or memory?
 *         Hash table: O(N) running time | Progressively iterate O(N^2)
 */

#include <forward_list>
#include <iostream>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){

  forward_list<int> list(100);

  for(auto it = list.begin(); it != list.end(); ++it){
    *it = rand() % 5;
  }

  list.unique();

  for(auto it = list.begin(); it != list.end(); ++it){
    cout<<*it<<endl;
  }

  int count = 0;

  for(auto it = list.begin(); it != list.end(); ++it) count++;

  cout<<"count "<<count<<endl;

  return 0;
}
