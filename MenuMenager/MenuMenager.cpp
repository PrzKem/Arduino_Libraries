/*
To Do:
3) apply tests
*/

// Include statement to include
// custom header file
#include "MenuMenager.h"


//constructor filled with empty data
MenuMenager::MenuMenager(){
    this -> numOfPages = 0;
    this -> firstPage = nullptr;
}

//function to add page to list
//@arg Page*: pointer to new page to be added
int MenuMenager::postPage(Page* newPage){
    Page* lastPage = this->getLastPage();
    lastPage -> nextPage = newPage;
    newPage -> nextPage = nullptr;
    newPage -> ID = numOfPages;
    numOfPages++;
    return 0;
}

//function to get last page from list
//@return: last page from list
Page* MenuMenager::getLastPage(){
               return this->getPage(this->numOfPages);
}

//function to get page
//@arg ID: page order number
//@return: pointer to page or null pointer if ID is too big
Page* MenuMenager::getPage(int ID){
    Page* actualPage = this -> firstPage;
    if(ID > numOfPages)
                   return nullptr;

    for(int i=0;i<ID;i++)
    {
                   actualPage = actualPage->nextPage;
                   if (actualPage->ID == ID)
                       break;
    }
    return actualPage;
}

//function to get page
//@arg name: page name
//@return: pointer to page
Page* MenuMenager::getPage(String name)
{
    Page* actualPage = this -> firstPage;
    int i=0;
    for(i=0;i<this->numOfPages;i++)
    {
                   if(name == actualPage->name)
                       break;

                   actualPage = actualPage->nextPage;
    }

    if(name == actualPage->name)
                   return actualPage;
    else
                   return nullptr;
}

//function to get page id based on page name
//@arg name: page name
//@return: id of founded page, -1 if cannot found
int MenuMenager::getPageID(String name){
    Page* pageToGet = this->getPage(name);
    int idToReturn = -1;

    if (pageToGet != nullptr){
                   idToReturn = pageToGet->ID;
    }
    return idToReturn;
}

//function to get page name connected to ID
//@arg ID: page ID
//@return: name of founded page, empty if page cannot be found
String MenuMenager::getPageName(int ID){
    Page* pageToGet = this->getPage(ID);
    String nameToReturn = "";

    if (pageToGet != nullptr){
                   nameToReturn = pageToGet->name;
    }
    return nameToReturn;
}

//function to update page value with setted ID
//@arg ID: id of page to apply change
//@arg newValue: new value to be setted
//@return: error code
int MenuMenager::updatePage(int ID, float newValue){
    Page* pageToModify;
    if(ID > numOfPages)
                   return -1;

    pageToModify = this->getPage(ID);
    pageToModify->value = newValue;
    return 0;
}

//function to update page value with setted ID
//@arg ID: id of page to apply change
//@arg newTitle: new title to be setted
//@return: error code
int MenuMenager::updatePage(int ID, String newTitle){
    Page* pageToModify;
    if(ID > numOfPages)
                   return -1;

    pageToModify = this->getPage(ID);
    pageToModify->title = newTitle;
    return 0;
}

//function to update page with setted name
//@arg pageName: name of page to apply changes
//@arg newValue: new value to be setted
//@return: error code
int MenuMenager::updatePage(String pageName, float newValue){
    int pageID = this->getPageID(pageName);
    return this->updatePage(pageID, newValue);
}

//function to update page with setted name
//@arg pageName: name of page to apply changes
//@arg newTitle: new title to be setted
//@return: error code
int MenuMenager::updatePage(String pageName, String newTitle) {
    int pageID = this->getPageID(pageName);
    return this->updatePage(pageID, newTitle);
}

//function to delete page
//@arg ID: ID of page to be deleted
//@return: error code
int MenuMenager::deletePage(int ID) {
    Page* pageToBeDeleted = this->getPage(ID);
    Page* pageAfter = (ID>=this->numOfPages) ? nullptr : this->getPage(ID+1);
    Page* pageBefore = (ID>0) ? this->getPage(ID-1) : nullptr;
    if(ID > this->numOfPages)
                   return -1;
    if(ID < 0)
                   return -2;

    pageBefore->nextPage = pageAfter;
    pageToBeDeleted = nullptr;
    return 0;
}
