
    char*			GetFirstNullCharPointer	(const char* s)
    {
        while (*s != 0) s++;
        return s;
    }


    std::size_t		GetFirstNullCharIndex	(const char* s)
    {
        const char* index = s;
        while (*index != 0) index++;
        return (std::size_t)index-s;
    }
