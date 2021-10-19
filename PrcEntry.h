#ifndef PRCENTRY_H
#define PRCENTRY_H

#include <CFile.h>

class PrcEntry
{
public:

    PrcEntry();

    bool readLineTxt(const CString &buffer);
    //bool readBufferCsv(const CString &buffer);

    static bool writeHeaderCsv(CFile &outfile);
    bool writeLineCsv(CFile &outfile);

    CString user;
    int pid;
    CString command;

//    CString name;
//    int     count = 1;
//    CString pid;
//    CString type;
//    int     memory;

};

#endif // PRCENTRY_H


