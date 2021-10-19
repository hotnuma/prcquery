#if 0

    CString buffer;

    if (_parseCsv(buffer) < 1)
        return false;


int PrcList::_parseCsv(const CString &output)
{
    CStringList allLines = output.split("\r\n", false);

    int numLines = allLines.size();
    if (numLines < 2)
    {
        print("*** PrcList::_parseCsv: empty or invalid file.");
        return -1;
    }

    for (int i = 1; i < numLines; ++i)
    {
        const CString &line = allLines.at(i);

        if (!_addEntry(unquote(line)))
        {
            return -1;
        }
    }

    return _entryList.size();
}


#endif


