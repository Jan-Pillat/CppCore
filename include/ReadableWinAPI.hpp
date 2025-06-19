
#ifndef _HPP_ReadableWinAPI_
#define _HPP_ReadableWinAPI_


//g++ nie rozumie tej dyrektywy, ale jest ona tutaj dla przenośności kodu.
#pragma comment(lib, "comdlg32.lib")
#include <windows.h>
#include <tchar.h>

#define  ANSIorUNICODE(txt)             _T(txt)
#define  OpenWindow_OpenFile(settings)  GetOpenFileName( (OPENFILENAME*) settings )
#define  OpenWindow_SaveFile(settings)  GetSaveFileName( (OPENFILENAME*) settings )

typedef struct FileSelectionSettings
{
  DWORD         structSize;             // Rozmiar struktury - na podstawie tego Windows wie z jak¹ wersj¹ ma do czynienia
  HWND          owner;                  // Uchwyt do okna nadrzêdnego – jeœli aplikacja ma GUI. NULL = brak w³aœciciela (np. aplikacja konsolowa)
  HINSTANCE     programInstance;        // Uchwyt do obecnego programu

  LPCSTR        fileFilters;            // Lista par: opis1\0wzorzec1\0opis2\0wzorzec2\0\0 (koñczona podwójnym '\0')
  LPTSTR        customFilter;           // Bufor na niestandardowy filtr (jeœli u¿ytkownik mo¿e zdefiniowaæ w³asny filtr, co wymaga napisania w³asnego okna dialogowego do tego, ogó³em - niepolecane i niepotrzebne)
  DWORD         customFilterSize;       // Rozmiar (w znakach) bufora lpstrCustomFilter
  DWORD         selectedFilterIndex;    // Który z filtrów zawartych w fileFilters ma byæ wybrany od pocz¹tku lub który wybra³ u¿ytkownik

  LPTSTR        pathBuffer;             // WskaŸnik do bufora, do którego zostanie wpisana pe³na œcie¿ka do pliku wybranego przez u¿ytkownika
  DWORD         bufferSize;             // Maksymalna d³ugoœæ œcie¿ki – musi odpowiadaæ rozmiarowi bufora szFile
  LPTSTR        gotFileTitle;           // Bufor na sam¹ nazwê pliku (bez œcie¿ki)
  DWORD         gotFileTitle_MAX;       // Rozmiar bufora gotFileTitle

  LPCSTR        initialPath;            // Œcie¿ka pocz¹tkowa (katalog, który ma byæ domyœlnie otwarty w oknie dialogowym)
  LPCSTR        windowTitle;            // Tytu³ okna dialogowego (np. "Wybierz plik")
  DWORD         flags;                  // Flagi konfiguruj¹ce zachowanie okna (np. OFN_PATHMUSTEXIST, OFN_FILEMUSTEXIST)

  WORD          fileNameOffset;         // Pozycja pierwszego znaku nazwy pliku w œcie¿ce (np. po ostatnim '\')
  WORD          fileExtensionOffset;    // Pozycja rozszerzenia w nazwie pliku (np. po ostatniej kropce)

  LPCSTR        defaultExtension;       // Domyœlne rozszerzenie, które zostanie dopisane, jeœli u¿ytkownik poda plik bez rozszerzenia. Ma to zastosowanie wy³¹cznie w GetSaveFileName.

  LPARAM        customFuncParam;        // Parametry przekazywane do customFuncParam
  LPOFNHOOKPROC customFunc;             // WskaŸnik na w³asn¹ funkcjê uruchamian¹ za ka¿dym razem, gdy u¿ytkownik zrobi cokolwiek, umo¿liwia dostosowanie zachowania okna dialogowego. Wymaga flagi OFN_ENABLEHOOK.

  LPCSTR        templateName;           // Nazwa w³asnego niestandardowego okna zdefiniowanego w pliku .rc, dzia³a tylko przy ustawieniu flagi OFN_ENABLETEMPLATE lub OFN_ENABLETEMPLATEHANDLE

//(Typ LPEDITMENU nie istnieje, to relikt starych wersji Windows!)
//  LPEDITMENU    lpEditInfo;             // Nie u¿ywane – zarezerwowane dla przysz³ych wersji (lub niektórych wewnêtrznych zastosowañ)
//(W najnowszym commdlg.h nie jest definiowane (stan na 05.2025))
//  LPCSTR        requestInfo;            // Tekst wyœwietlany jako prompt (g³ównie dla dialogów zapisu). Czêœciej wykorzystywane w bardzo starych aplikacjach Windows (Win3.1–98) i trzeba by³o pokazaæ u¿ytkownikowi proœbê np. o w³o¿enie dyskietki

  void*         pvReserved;             // Zarezerwowane – musi byæ ustawione na NULL
  DWORD         dwReserved;             // Zarezerwowane – musi byæ ustawione na 0

  DWORD         extensionFlags;         // Rozszerzone flagi – np. OFN_EX_NOPLACESBAR (ukrywa pasek szybkiego dostêpu)
};

class FileSelector
{
	char gotPath[MAX_PATH]    {0};
	FileSelectionSettings     settings{};
	
	FileSelector ()
	{
		settings.structSize  =   sizeof(FileSelectionSettings);
		settings.fileFilters =   ANSIorUNICODE("All files\0*.*\0");
		settings.pathBuffer  =   gotPath;
		settings.bufferSize  =   sizeof(gotPath);
		settings.flags       =   OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
	}
	
	GetPath_OpenFile ()
	{
		OpenWindow_OpenFile (&settings)
	}
	
	GetPath_SaveFile ()
	{
		OpenWindow_SaveFile (&settings)
	}
}

#endif
