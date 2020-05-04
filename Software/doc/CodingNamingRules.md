# Coding Naming Rules

These rules only apply to the hand written source code (../src/User/), 

no impact on the generated source codes or imported source codes (../src/Core/, ../src/Driver/).

## 1. File names:= < package/layer/level name > + < Module Name >

A software unit usually consists of 1 C file and 1 H file, with the same name.

Examples: mcuUartDriver, ecuCanDriver, appCanSimulator

A software unit have a abbr of its name as the prefix for the items inside.

Examples: mud_, ecd_, acs_

## 2. Including header files

This is not a naming rule, but a guideline:

**DO NOT** include header files which is not used by the C file.

**ONLY** include the header file when you use the declarations from that header file.

## 3. MACROs := PREFIX_MACRO_NAME

## 4. enum

enum type name: e_prefix_enumTypeName

enum type value: E_PREFIX_ENUM_TYPE_VALUE

## 5. struct

struct type name: t_prefix_structTypeName

struct member variables: memberVariableName

## 6. function

normal: prefix_functionName

hook: prefixHook_functionName

event: prefix_EventFunctionName

# examples

[exampleModuleName.h](exampleModuleName.h)


