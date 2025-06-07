
    char*			GetFirstNullCharPointer	(const char* s)
    {
        return strchr(s, '\0');;
    }


    std::size_t		GetFirstNullCharIndex	(const char* s)
    {
        return strlen(s);
    }
