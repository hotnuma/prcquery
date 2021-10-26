#ifndef PRCENTRY_H
#define PRCENTRY_H

#include <CFile.h>

class PrcEntry
{
public:

    PrcEntry();

    bool readLineTxt(const CString &buffer);

    bool writeLineTxt(CFile &outfile);

    static bool writeHeaderTxt(CFile &outfile);
    bool writeLineCsv(CFile &outfile);

    CString name;
    CString user;
    CString pid;
    CString command;

};

#endif // PRCENTRY_H


