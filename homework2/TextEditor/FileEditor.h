#include "FileManager.h"
#ifndef __FILEEDITOR_H__
#define __FILEEDITOR_H__

class FileEditor
{

    public:

        FileEditor();
        FileEditor(int line);
        FileEditor(int line, int from, int to);

        void makeHeading(FileManager& m);

        //makeItalic line from to
        void makeItalic(FileManager& m);
        //makeBold line from to
        void makeBold(FileManager& m);
        //makeCombine  line from to
        void makeCombine(FileManager& m);

        //addLine lineContent
        void addLine(FileManager& m, char* lineContent);
        //remove line
        void remove(FileManager& m, int line);

    private:

        int line;
        int from;
        int to;
};

#endif
