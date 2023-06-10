#include<iostream>
#include<fstream>
#include<string>
#include<filesystem>

using namespace std;

void createFile(string fileName)
{
    ofstream file;
    file.open(fileName);
    if(file){
        cout << "File created successfully!" << endl;
        file.close();
    }
    else{
        cout << "Failed to create file!" << endl;
    }
}

void writeFile(string fileName, string data){
    ofstream file;
    file.open(fileName);
    if(file){
        file << data;
        cout << "Successfuly write!" << endl;
        file.close();
    }
    else{
        cout << "File not opend!" << endl;
    }

}

void deleteFile(string fileName)
{
    if(remove(fileName.c_str()) == 0){
        cout << "File deleted Successfully!" << endl;
    }
    else{
        cout << "Failed to delete file!" << endl;
    }
}

void copyFile(string sourceFileName, string destFileName){
    string line;
    ifstream ini_file {sourceFileName};
    ofstream out_file {destFileName};

    if(ini_file && out_file){
        while(getline(ini_file, line)){
            out_file << line << "\n";
        }

        cout << "Successfully copied!" << endl;
    }
    else {
        cout << "Failed to copy file!" << endl;
    }
}

void moveFile(string sourceFileName, string destFileName){
    copyFile(sourceFileName, destFileName);
    deleteFile(sourceFileName);
}

int main()
{
    int flag = 1, c=1;
    string fileName, destFileName, data;
    while(c){
        cout<< "Options: "<< endl;
        cout << "1. Create File" << endl;
        cout << "2. Write File" << endl;
        cout << "3. copy file" << endl;
        cout << "4. Move file" << endl;
        cout << "5. Delete File" << endl;
        cout << "0. Exit" << endl;

        cin >> flag;
        if(flag == 1){
            cout << "Enter a file name to create a file: ";
            cin >> fileName;
            createFile(fileName);
        }
        else if(flag == 2){
            cout << "Enter your file name to write something into file: ";
            cin >> fileName;
            cout << "Enter your string: ";
            cin >> data;
            writeFile(fileName, data);
        }
        else if(flag == 3){
            cout << "Enter your source file name: ";
            cin >> fileName;
            cout << "Enter your destination file name: ";
            cin >> destFileName;
            copyFile(fileName, destFileName);
        }
        else if(flag == 4){
            cout << "Enter your source file name: ";
            cin >> fileName;
            cout << "Enter your destination file name: ";
            cin >> destFileName;
            moveFile(fileName, destFileName);
        }
        else if(flag == 5){
            cout << "Enter your file name to delete file: ";
            cin >> fileName;
            deleteFile(fileName);
        }
        else if(flag == 0){
            cout << "Enter correct option number" << endl;
            c = 0;
        }
    }
    return 0;
}