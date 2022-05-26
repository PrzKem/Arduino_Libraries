// Header file
// Make Sure your file name
// should be my_library.h

#ifndef MENU_MENAGER_H
#define MENU_MENAGER_H
#include <Arduino.h>

struct  Page {
    int ID;           //id  counting from 0
    Page* nextPage;
    String name;
    String title;
    float value;
};


class MenuMenager {
private:
    Page* firstPage;
    int numOfPages;
public:
    MenuMenager();
    int postPage(Page*);
    Page* getLastPage();
    Page* getPage(int);
    Page* getPage(String);
    int getPageID(String);
    String getPageName(int);
    int updatePage(int, float);
    int updatePage(int, String);
    int updatePage(String, float);
    int deletePage(int);
};


#endif
