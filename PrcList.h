#ifndef PRCLIST_H
#define PRCLIST_H

#include "CStringList.h"
#include "CList.h"

class PrcEntry;

class PrcList
{
public:

    PrcList();

    bool queryAll();

    bool write(const CString &filepath);

private:

//    int _parseCsv(const CString &output);

    bool _addEntry(const CString &line);

//    PrcEntry* _find(const CString &name);

//    bool _writeBuffer(const CString &filepath, const CString &buffer);

    CList _entryList;

};

#endif // PRCLIST_H


