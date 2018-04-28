#ifndef __FILEMANAGER_H__
#define __FILEMANAGER_H__

class FileManager
{

    public:

        FileManager();
        FileManager(const FileManager&);
        ~FileManager();
        FileManager& operator=(const FileManager&);

        void readFile(char* fileName);

        void print() const;
        const char* getLineAt( int index) const;

        void saveMdFile(char* fileName);

        void makeHeading(int line);
        void combine(int currentLine, int fromWord, int toWord);
        void bold(int currentLine, int fromWord, int toWord);
        void italic(int currentLine, int fromWord, int toWord);
        void addContent(char* lineContent);
        void removeLine(int line);

    private:

        char** content;
        int numberOfLines;

        void copyHelp(const FileManager&);
        void deleteHelp();

        void helper(int currentLine, int fromWord, int toWord, int count);
};

#endif
