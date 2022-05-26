#include <MenuMenager.h>

MenuMenager mm;

void setup()
{
  Serial.begin(9600);
  Page p1, p2, p3;
  p1.title = "p1";
  p2.title = "p2";
  p3.title = "p3";

  p1.value = 0.0;
  p2.value = 1.0;
  p3.value = 2.0;

  mm.postPage(&p1);
  mm.postPage(&p2);
  mm.postPage(&p3);

  for(int i=0;i<3;i++)
  {
    Serial.print("Title #");
    Serial.print(i);
    Serial.print(": ");
    //Serial.println((*(mm.getPage(i))).title);
    Serial.println(mm.getPageTitle(i))
  }
}

void loop()
{
  //do nothig
}
