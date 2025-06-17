# CppCore
A collection of reusable C++ modules designed to support multiple personal projects.  
This repository is intended to be used as a Git submodule.

## Modules

### ConsoleInterface
A modular and reusable console menu system.
Provides a structured interface for console applications, eliminating the need for primitive 1,2,3-style text menus.
Supports navigation with arrow keys, multi-line descriptions, custom coloring, spacing configuration, and more. Designed to bring interactive, visually organized menus to CLI tools.

### ConsoleUtils
A comprehensive utility module that simplifies low-level WinAPI console operations.
It includes functions for cursor control, text positioning, color management, and output.
Notably, output functions are robust against character rendering failures in WriteConsoleW, ensuring graceful fallback for special wchar_t symbols.

### FileData
Provides simple loading of file contents either as binary data or null-terminated text.  
Includes automatic buffer allocation and optional text conversion (`\0` → `\n` + final `\0`).

### BinaryData
A lightweight binary buffer structure with utility functions for raw data manipulation.

### ReadableWinAPI
A simplified, more readable interface to selected WinAPI functions.  
Improves code clarity when working with Windows-specific features.

### StringUtils
Helper functions for clear, intention-revealing string manipulation.
