#include <iostream>
#include "FileEditor.h"

using namespace std;


FileEditor::FileEditor() : line(0), from(0), to(0)
{

}

FileEditor::FileEditor(int line) : line(line), from(0), to(0)
{

}

FileEditor::FileEditor(int line, int from, int to) : line(line), from(from), to(to)
{

}

void FileEditor::makeHeading(FileManager& m)
{
    m.makeHeading(this->line);
    //m.print();
}

void FileEditor::makeItalic(FileManager& m)
{
    m.italic(this->line, this->from, this->to);
    //m.print();
}

void FileEditor::makeBold(FileManager& m)
{
    m.bold(this->line, this->from, this->to);
    //m.print();
}

void FileEditor::makeCombine(FileManager& m)
{
    m.combine(this->line, this->from, this->to);
    //m.print();
}

void FileEditor::addLine(FileManager& m, char* lineContent)
{
    m.addContent(lineContent);
    //m.print();
}

void FileEditor::remove(FileManager& m, int line)
{
    m.removeLine(line);
    //m.print();
}
