/* ==================================== JUCER_BINARY_RESOURCE ====================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

namespace BinaryData
{

//================== tests.txt ==================
static const unsigned char temp_binary_data_0[] =
"/*\r\n"
"  ==============================================================================\r\n"
"\r\n"
"    tests.txt\r\n"
"    Created: 29 Oct 2020 2:23:16pm\r\n"
"    Author:  MT\r\n"
"\r\n"
"    List of all tests for modules and if they passed\r\n"
"\r\n"
"  ==============================================================================\r\n"
"*/\r\n"
"\r\n"
"Custom Midi Keyboard\r\n"
"1. [c] Disable the same key(s) per octave\r\n"
"2. White key layout, 12 keys per octave (default)\r\n"
"3. White key layout, Any keys per octave\r\n"
"4. [c] Total 128 notes (default)\r\n"
"5. [c] Total Any notes\r\n"
"6. Piano layout\r\n"
"7. Custom layout\r\n"
"\r\n"
"Custom Midi Keyboard - labels\r\n"
"1. Labels follow Piano layout\r\n"
"2. Labels follow a custom layout\r\n"
"3. Labels skip disabled keys (written on the next value)\r\n"
"\r\n"
"Systems - \r\n"
"// Not exactly sure how to properly incorporate the system map\r\n"
"// Could test both the system map and equal temperament, but that would be messy\r\n"
"// when somwething is set in the layout, it should ";

const char* tests_txt = (const char*) temp_binary_data_0;


const char* getNamedResource (const char* resourceNameUTF8, int& numBytes)
{
    unsigned int hash = 0;

    if (resourceNameUTF8 != nullptr)
        while (*resourceNameUTF8 != 0)
            hash = 31 * hash + (unsigned int) *resourceNameUTF8++;

    switch (hash)
    {
        case 0xbab94752:  numBytes = 920; return tests_txt;
        default: break;
    }

    numBytes = 0;
    return nullptr;
}

const char* namedResourceList[] =
{
    "tests_txt"
};

const char* originalFilenames[] =
{
    "tests.txt"
};

const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8)
{
    for (unsigned int i = 0; i < (sizeof (namedResourceList) / sizeof (namedResourceList[0])); ++i)
    {
        if (namedResourceList[i] == resourceNameUTF8)
            return originalFilenames[i];
    }

    return nullptr;
}

}
