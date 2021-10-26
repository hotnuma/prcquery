#ifndef PRCLIST_H
#define PRCLIST_H

#include <CString.h>
#include <CList.h>

class PrcEntry;

class PrcList
{
public:

    PrcList();
    bool queryAll();
    bool writeTxt(const CString &filepath);

private:

    bool _addEntry(const CString &line);

    CList _entryList;

};

#endif // PRCLIST_H


