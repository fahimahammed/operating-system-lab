// g++ .\1-1-alternative-command.cpp -o 1-1-alternative-command
// .\1-1-alternative-command args
#include<iostream>
#include<fstream>
#include<windows.h>
#include<unistd.h>
#include<dirent.h>


using namespace  std;


int main(int argc, char* argv[])
{
    string command = argv[1];
   
    // cout<<typeof(argv[1]);
    // string ar[] = argv;
    // if(argv[1][0] == 'c' && argv[1][1] == 'r')
    if(command == "create")
    {
        // creating a file
        string fileName = argv[2];
        cout<<fileName;
        ofstream MyFile(fileName.c_str());
        MyFile << " sample test ";
        MyFile.close();
    }
    // else if(argv[1][0] == 'r')
    else if(command == "rename")
    {
        // rename


        string old_name = argv[2];
        string new_name = argv[3];


        bool res = rename(old_name.c_str(),new_name.c_str());
        cout<<old_name<<endl;
        cout<<new_name<<endl;
        if(!res)
        {
            cout<<"rename successfull...!";
        }
        else{
            cout<<"error occure while renaming...!";
        }
    }
    else if(command == "remove")
    {
        // remove a file
        string file_name = argv[2];
        int res = remove(file_name.c_str());
        if(!res)
        {
            cout<<"rename successfull...!";
        }
        else{
            cout<<"error occure while renaming...!";
        }
    }
    else if(command == "copy")
    {
        string oldDir = argv[2];
        // "F:\CSE-3-2\Lab-3-2\operating-system-lab/test.txt";
        string newDir = argv[3];
        int res = CopyFile(oldDir.c_str(),newDir.c_str(),true);
        if(res)
        {
            cout<<"copy successfull...!";
        }
        else{
            cout<<"error occure while copying...!";
        }
    }
    else if(command == "move")
    {
        string source =  argv[2];
        string destination = argv[3];


        int res = MoveFile(source.c_str(),destination.c_str());
        cout<<res<<endl;
        if(res)
        {
            cout<<"move successfull...!";
        }
        else{
            cout<<"error occure while moving...!";
        }
    }
    else if(command == "curdir")
    {
        char buff[PATH_MAX];
        _getcwd( buff, PATH_MAX );
        string current_working_dir(buff);
        cout << current_working_dir << endl;

    }
    else if(command == "showdir")
    {
        string dir = argv[2];
        struct dirent *d;
        DIR *dr;
        dr = opendir(dir.c_str());
        if(dr!=NULL)
        {
            cout<<"List of Files & Folders:-\n";
            for(d=readdir(dr); d!=NULL; d=readdir(dr))
            {
                cout<<d->d_name<<endl;
            }
            closedir(dr);
        }
        else
            cout<<"\nError Occurred!";
        cout<<endl;
    }
}