
////////////////////////////////////////////////////
//  I made this test in a local project           //
//  and I included it using:                      //
//  #include "..\CppCore\tests\test_FileData.cpp" //
////////////////////////////////////////////////////

#include "..\include\FileData.hpp"
//#include "..\src\FileData.cpp"
//#include "..\src\BinaryData.cpp"

using std::cout;
using std::endl;

    // -------------------  LIBRARY  TEST  -------------------


    void FileData_LibraryTest ()
    {
        cout << " ----- JanFile - Library Test ----- \n\n";

        FileData fd1, fd2;

        cout << "Try to open files: fd_test1.txt and fd_test2.txt\n\n";
        fd1.LoadTextFile("fd_test1.txt");
        fd2.LoadTextFile("fd_test2.txt");


        // -------------------- OPEN FILES --------------------
        if (!fd1.IsGood())
        {
            cout << "fd_test1.txt  load  failed \n";
            return;
        }
        else
            cout << "fd_test1.txt  load  success \n";

        if (!fd2.IsGood())
        {
            cout << "fd_test2.txt  load  failed \n";
            return;
        }
        else
            cout << "fd_test2.txt  load  success \n";


        // -------------------- INFO --------------------
        cout << "Operator tests:\n\n";


        // -------------------- PRINT DATA --------------------

        cout << "operator []\n";
        cout << "fd_test1.txt  &data[0]:" << &fd1[0] << endl;
        cout << "fd_test2.txt  &data[0]:" << &fd2[0] << endl;
        cout << "fd_test1.txt  data[10]:" << fd1[10] << endl;
        cout << "fd_test2.txt  data[10]:" << fd2[10] << endl;


        // -------------------- COMPARE FILES --------------------
        cout << "\n operator == \n";
        if (fd1 == fd2)
            cout << "They are the same.\n";
        else
            cout << "They AREN't the same.\n";


        // --------------------  --------------------

        cout << "\n operators =  +=  + \n";

        cout << endl;
        FileData  previous_fd1 = fd1;
        fd1 += fd2;
        cout << "File1 += File2:" << &fd1[0] << endl << endl;
        fd1 = fd2;
        cout << "File1 = File2:" << &fd1[0] << endl << endl;
        fd1 = fd2 + previous_fd1 + fd2;
        cout << "File1 = File2 + previous File1 + File2:" << &fd1[0] << endl << endl;


        // -------------------- SECOND TEST COMPARE --------------------
        cout << "\n operator == \n";
        cout << "File2 == File2; result:\n";
        if (fd2 == fd2)
            cout << "They are the same.\n";
        else
            cout << "They AREN't the same.\n";
    }
