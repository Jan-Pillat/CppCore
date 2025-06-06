# CppCore
A collection of reusable C++ modules designed to support multiple personal projects.  
This repository is intended to be used as a Git submodule.

## Modules

### FileData
Provides simple loading of file contents either as binary data or null-terminated text.  
Includes automatic buffer allocation and optional text conversion (`\0` → `\n` + final `\0`).

### BinaryData
A lightweight binary buffer structure with utility functions for raw data manipulation.

### ReadableWinAPI
A simplified, more readable interface to selected WinAPI functions.  
Improves code clarity when working with Windows-specific features.
