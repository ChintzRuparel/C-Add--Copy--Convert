#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>
#include <sstream>

#pragma warning(disable : 4996)

using namespace std;


int main()
{

    const std::string fileName = "file name.txt"; //add extension like ->  (C:\\Users\\Administrator\\Desktop\\rms_copy\\chintan.txt)
    std::fstream processedFile(fileName.c_str());
    std::stringstream fileData;

    fileData << "Your TEXT";

    fileData << processedFile.rdbuf();
    processedFile.close();

    processedFile.open(fileName.c_str(), std::fstream::out | std::fstream::trunc);
    processedFile << fileData.rdbuf();




    char ch;  //copy code starts 
    FILE* fs, * ft;
    int day = 6;


    fs = fopen("file name.txt", "r");  // where the file is    ;    add extension like ->  (C:\\Users\\Administrator\\Desktop\\rms_copy\\chintan.txt)
    if (fs == NULL)
    {
        cout << "\nError Occurred!";
        return 0;
    }
    ft = fopen("file name.txt", "w");     // where the file will be shifted     ;    add extension like ->  (C:\\Users\\Administrator\\Desktop\\rms_copy\\chintan.txt) 
    if (ft == NULL)
    {
        cout << "\nError Occurred!";
        return 0;
    }
    ch = fgetc(fs);
    while (ch != EOF)
    {
        fputc(ch, ft);
        ch = fgetc(fs);
    }
    cout << "\n File copied successfully.";
    fclose(fs);
    fclose(ft);
    cout << endl; //copy code ends



    std::ifstream ascfile;  //csv conversion on
    std::ofstream csvFile;
    ascfile.open("C:\\Users\\Administrator\\Desktop\\rms_copy\\chintan.txt");        // .txt file with extension & path
    csvFile.open("C:\\Users\\Administrator\\Desktop\\rms_copy\\chintan.csv");        //.csv file with extension & path

    if (ascfile.is_open())
    {
        std::string line;
        while (std::getline(ascfile, line))
        {
            line.begin(), line.end(), ' ', ',';
            csvFile << line << std::endl;
        }
        cout << " \n CSV Generated ";

    }
    else
    {
        std::cout << "Sorry, the file could not be openend." << std::endl;
        return -1;
    }
    ascfile.close();
    csvFile.close();
    return 0; //csv conversion finished 
}
