#include "MenuMenager.h"

MenuMenager mm;
Page p1,p2,p3,p4,p5;
Page pages[] = {p1,p2,p3,p4,p5};
int numOfPages = sizeof(pages)/sizeof(pages[0]);

void setup()
{
  int i=0;
  Serial.begin(9600);
  String p = "p";
  randomSeed(analogRead(0));

  for(i=0;i<numOfPages;i++)
  {
    pages[i].title = p+(i+1);
    pages[i].name = pages[i].title;
    pages[i].value = random(10, 100)/10.0;
    mm.postPage(&pages[i]);
  }

  for(i=0;i<mm.getNumOfPages();i++)
  {
    Serial.print("Title #");
    Serial.print(i);
    Serial.print(": ");
    Serial.print(mm.getPageTitle(i));

    Serial.print("\t\tValue: ");
    Serial.println(mm.getPageValue(i));
  }

  while(mm.getNumOfPages()>0)
  {
    mm.deletePage(mm.getNumOfPages());
    Serial.print("Remaining pages: ");
    Serial.println(mm.getNumOfPages());
  }
  Serial.println("\nDeleted all pages");\
  Serial.print("Num of pages: ");
  Serial.println(mm.getNumOfPages());

}

void loop()
{

}
