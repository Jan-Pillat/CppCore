
#include <iostream>
#include "../include/StringUtils.hpp"

using std::cout;
using std::endl;

    // -------------------  LIBRARY  TEST  -------------------

    void StringUtils_LibraryTest ()
    {
        cout << "IsHexNum('Z') = " << (IsHexNum('Z')!=0) << endl;
        cout << "IsHexNum('F') = " << (IsHexNum('F')!=0) << endl;
        cout << "IsHexNum('9') = " << (IsHexNum('9')!=0) << endl;
        cout << "IsHexNum('.') = " << (IsHexNum('.')!=0) << endl;
        cout << "IsHexNum('\t')= " << (IsHexNum('\t')!=0)<< endl << endl;

        cout << "IsDecNum('Z') = " << (IsDecNum('Z')!=0) << endl;
        cout << "IsDecNum('F') = " << (IsDecNum('F')!=0) << endl;
        cout << "IsDecNum('9') = " << (IsDecNum('9')!=0) << endl;
        cout << "IsDecNum('.') = " << (IsDecNum('.')!=0) << endl;
        cout << "IsDecNum('\t')= " << (IsDecNum('\t')!=0)<< endl << endl;

        cout << "IsNum('Z') = " << (IsNum('Z')!=0) << endl;
        cout << "IsNum('F') = " << (IsNum('F')!=0) << endl;
        cout << "IsNum('9') = " << (IsNum('9')!=0) << endl;
        cout << "IsNum('.') = " << (IsNum('.')!=0) << endl;
        cout << "IsNum('\t')= " << (IsNum('\t')!=0)<< endl << endl;

        cout << "IsAlOrNum('Z') = " << (IsAlOrNum('Z')!=0) << endl;
        cout << "IsAlOrNum('F') = " << (IsAlOrNum('F')!=0) << endl;
        cout << "IsAlOrNum('9') = " << (IsAlOrNum('9')!=0) << endl;
        cout << "IsAlOrNum('.') = " << (IsAlOrNum('.')!=0) << endl;
        cout << "IsAlOrNum('\t')= " << (IsAlOrNum('\t')!=0)<< endl << endl;

        //===================================================================

        cout << "IsHexDigit('Z') = " << (IsHexDigit('Z')!=0) << endl;
        cout << "IsHexDigit('F') = " << (IsHexDigit('F')!=0) << endl;
        cout << "IsHexDigit('9') = " << (IsHexDigit('9')!=0) << endl;
        cout << "IsHexDigit('.') = " << (IsHexDigit('.')!=0) << endl;
        cout << "IsHexDigit('\t')= " << (IsHexDigit('\t')!=0)<< endl << endl;

        cout << "IsDecDigit('Z') = " << (IsDecDigit('Z')!=0) << endl;
        cout << "IsDecDigit('F') = " << (IsDecDigit('F')!=0) << endl;
        cout << "IsDecDigit('9') = " << (IsDecDigit('9')!=0) << endl;
        cout << "IsDecDigit('.') = " << (IsDecDigit('.')!=0) << endl;
        cout << "IsDecDigit('\t')= " << (IsDecDigit('\t')!=0)<< endl << endl;

        cout << "IsDigit('Z') = " << (IsDigit('Z')!=0) << endl;
        cout << "IsDigit('F') = " << (IsDigit('F')!=0) << endl;
        cout << "IsDigit('9') = " << (IsDigit('9')!=0) << endl;
        cout << "IsDigit('.') = " << (IsDigit('.')!=0) << endl;
        cout << "IsDigit('\t')= " << (IsDigit('\t')!=0)<< endl << endl;

        cout << "IsAlOrDigit('Z') = " << (IsAlOrDigit('Z')!=0) << endl;
        cout << "IsAlOrDigit('F') = " << (IsAlOrDigit('F')!=0) << endl;
        cout << "IsAlOrDigit('9') = " << (IsAlOrDigit('9')!=0) << endl;
        cout << "IsAlOrDigit('.') = " << (IsAlOrDigit('.')!=0) << endl;
        cout << "IsAlOrDigit('\t')= " << (IsAlOrDigit('\t')!=0)<< endl << endl;

        cout << "IsAlOrDig('Z') = " << (IsAlOrDig('Z')!=0) << endl;
        cout << "IsAlOrDig('F') = " << (IsAlOrDig('F')!=0) << endl;
        cout << "IsAlOrDig('9') = " << (IsAlOrDig('9')!=0) << endl;
        cout << "IsAlOrDig('.') = " << (IsAlOrDig('.')!=0) << endl;
        cout << "IsAlOrDig('\t')= " << (IsAlOrDig('\t')!=0)<< endl << endl;

        //===================================================================

        cout << "IsBlank('Z') = " << (IsBlank('Z')!=0) << endl;
        cout << "IsBlank('F') = " << (IsBlank('F')!=0) << endl;
        cout << "IsBlank('9') = " << (IsBlank('9')!=0) << endl;
        cout << "IsBlank('.') = " << (IsBlank('.')!=0) << endl;
        cout << "IsBlank('\t')= " << (IsBlank('\t')!=0)<< endl << endl;

        cout << "IsPunctator('Z') = " << (IsPunctator('Z')!=0) << endl;
        cout << "IsPunctator('F') = " << (IsPunctator('F')!=0) << endl;
        cout << "IsPunctator('9') = " << (IsPunctator('9')!=0) << endl;
        cout << "IsPunctator('.') = " << (IsPunctator('.')!=0) << endl;
        cout << "IsPunctator('\t')= " << (IsPunctator('\t')!=0)<< endl << endl;

        cout << "IsPunct('Z') = " << (IsPunct('Z')!=0) << endl;
        cout << "IsPunct('F') = " << (IsPunct('F')!=0) << endl;
        cout << "IsPunct('9') = " << (IsPunct('9')!=0) << endl;
        cout << "IsPunct('.') = " << (IsPunct('.')!=0) << endl;
        cout << "IsPunct('\t')= " << (IsPunct('\t')!=0)<< endl << endl;

        cout << "IsAlpha('Z') = " << (IsAlpha('Z')!=0) << endl;
        cout << "IsAlpha('F') = " << (IsAlpha('F')!=0) << endl;
        cout << "IsAlpha('9') = " << (IsAlpha('9')!=0) << endl;
        cout << "IsAlpha('.') = " << (IsAlpha('.')!=0) << endl;
        cout << "IsAlpha('\t')= " << (IsAlpha('\t')!=0)<< endl << endl;

        cout << "IsAlphabetic('Z') = " << (IsAlphabetic('Z')!=0) << endl;
        cout << "IsAlphabetic('F') = " << (IsAlphabetic('F')!=0) << endl;
        cout << "IsAlphabetic('9') = " << (IsAlphabetic('9')!=0) << endl;
        cout << "IsAlphabetic('.') = " << (IsAlphabetic('.')!=0) << endl;
        cout << "IsAlphabetic('\t')= " << (IsAlphabetic('\t')!=0)<< endl << endl;
    }
