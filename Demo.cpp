/**
 * Demo file for the exercise on iterators
 *
 * @author Tal Zichlinsky
 * @since 2022-02
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "OrgChart.hpp"
using namespace ariel;

int main() {
  OrgChart organization;
  organization.add_root("CEO")
      .add_sub("CEO", "CTO")         // Now the CTO is subordinate to the CEO
      .add_sub("CEO", "CFO")         // Now the CFO is subordinate to the CEO
      .add_sub("CEO", "COO")         // Now the COO is subordinate to the CEO
      .add_sub("CTO", "VP_SW") // Now the VP Software is subordinate to the CTO
      .add_sub("COO", "VP_BI")
      .add_sub("VP_SW", "dvir")
      .add_sub("VP_BI", "biton");

  cout << "cout:\n"<<  organization << endl; /* Prints the org chart in a reasonable format. For example:
//        CEO
//        |--------|--------|
//        CTO      CFO      COO
//        |                 |
//        VP_SW             VP_BI
//        |                 |
//        dvir              biton
//  */
  cout << "level order:" << endl;
  for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
  {
    cout << (*it) << " " ;
  } // prints: CEO CTO CFO COO VP_SW VP_BI dvir biton
  cout << "\nreverse order:" << endl;
  for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
  {
    cout << (*it) << " " ;
  } // prints: dvir biton VP_SW VP_BI CTO CFO COO CEO
  cout <<"\npreorder:" << endl;
  for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it) {
    cout << (*it) << " " ;
  }  // prints: CEO CTO VP_SW dvir CFO COO VP_BI biton
  cout << "\nfor each:" << endl;

  for (auto element : organization)
  { // this should work like level order
    cout << element << " " ;
  } // prints: CEO CTO CFO COO VP_SW VP_BI dvir biton
  cout << "\nsize of the string in the iterator:" << endl;

  // demonstrate the arrow operator:
  for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
  {
    cout << it->size() << " " ;
  } // prints: 3 3 3 3 5 5 4 5
  cout << endl;
}