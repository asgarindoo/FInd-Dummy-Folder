#include <iostream>
#include <string>

using namespace std;

struct Folder {
    string name;
    Folder* subfolders[10];  // Maksimal 10 subfolder

    Folder(const string& n) : name(n) {
        for (int i = 0; i < 10; i++) {
            subfolders[i] = NULL;
        }
    }
};

// Fungsi untuk mencari folder target dengan IDS
bool depthLimitedSearch(Folder* currentFolder, const string& target, int depth, string path[100]) {
    if (depth <= 0) {
        return false;
    }
    path[depth] = currentFolder->name; // Simpan nama folder saat ini di path
    if (currentFolder->name == target) {
        return true; // Folder target ditemukan
    }
    for (int i = 0; i < 10; i++) {
        if (currentFolder->subfolders[i] != NULL) {
            if (depthLimitedSearch(currentFolder->subfolders[i], target, depth - 1, path)) {
                return true; // Folder target ditemukan dalam subfolder
            }
        }
    }
    path[depth] = ""; // Hapus nama folder saat ini jika tidak ada yang cocok
    return false;
}

/*
void printFolderStructure(Folder* folder, int level) {
    for (int i = 0; i < level; i++) {
        cout << "  "; // Spasi untuk tampilan indentasi
    }
    cout << folder->name << endl;
    for (int i = 0; i < 10; i++) {
        if (folder->subfolders[i] != NULL) {
            printFolderStructure(folder->subfolders[i], level + 1);
        }
    }
}

*/

// Fungsi IDS
string* iterativeDeepeningSearch(Folder* root, const string& target) {
    int depth = 0;
    string* path = new string[100];
    for (int i = 0; i < 100; i++) {
        path[i] = "";
    }

    while (true) {
        for (int i = 0; i < 100; i++) {
            path[i] = "";
        }
        if (depthLimitedSearch(root, target, depth, path)) {
            return path;
        }
        depth++;
        if (depth > 10) {
            return NULL; // Jika kedalaman melebihi 10, hentikan pencarian dan kembalikan NULL
        }
    }
}

int main() {
    // Membuat struktur folder dummy
    Folder* root = new Folder("root");
    Folder* SSD = new Folder("SSD");
    Folder* driveC = new Folder("C"); 
    Folder* driveD = new Folder("D");
    Folder* driveE = new Folder("E");
    Folder* driveF = new Folder("F");
     //Folder di drive C
    Folder* programFiles = new Folder("Program Files");
    Folder* windows = new Folder("Windows");
    Folder* users = new Folder("Users");
    Folder* BocahKosong = new Folder("Bocah Kosong");
    Folder* documents = new Folder("Documents");
    Folder* pictures = new Folder("Pictures");
    Folder* music = new Folder("Music");
    Folder* download = new Folder("Download");
    Folder* programData = new Folder("ProgramData");
    //Folder di drive D
    Folder* visualStudio = new Folder("Visual Studio");
    Folder* delphi = new Folder("Delphi");
    Folder* photoshop = new Folder("Photoshop");
    Folder* figma = new Folder("Figma");
    //Folder di drive E
    Folder* game = new Folder("Game");
    Folder* dota = new Folder("Dota");
    Folder* minecraft = new Folder("Minecraft");
    Folder* stumble = new Folder("Stumble Guys");
    Folder* work = new Folder("Work");
    Folder* projects = new Folder("Projects");
    //Folder di drive F
    Folder* backup = new Folder("Backup");
    Folder* photos = new Folder("Photos");
    Folder* videos = new Folder("Videos");

    root->subfolders[0] = SSD;
    
    SSD->subfolders[0] = driveC;
    SSD->subfolders[1] = driveD;
    SSD->subfolders[2] = driveE;
    SSD->subfolders[3] = driveF;

    //struktur folder dummy di drive C
    driveC->subfolders[0] = programFiles;
    driveC->subfolders[1] = windows;
    driveC->subfolders[2] = users;
        users->subfolders[0] = BocahKosong;
            BocahKosong->subfolders[0] = documents;
            BocahKosong->subfolders[1] = pictures;
            BocahKosong->subfolders[2] = music;
            BocahKosong->subfolders[3] = download;
    driveC->subfolders[3] = programData;

    //struktur folder dummy di drive D

    driveD->subfolders[0] = visualStudio;
    driveD->subfolders[1] = delphi;
    driveD->subfolders[2] = photoshop;
    driveD->subfolders[3] = figma;

    //struktur folder dummy di drive E

    driveE->subfolders[0] = game;
        game->subfolders[0]= dota;
        game->subfolders[1]= minecraft;
        game->subfolders[2]= stumble;
    driveE->subfolders[1] = work;
        work->subfolders[0] = projects;

    //struktur folder dummy di drive F

    driveF->subfolders[0] = backup;
    backup->subfolders[0] = photos;
    backup->subfolders[1] = videos;

    /*cout << "Struktur folder di drive SSD:" << endl;
    printFolderStructure(SSD, 0);*/

    string targetFolderName;
    cout << "Masukkan nama folder target: ";
    cin >> targetFolderName;

    string* result = iterativeDeepeningSearch(SSD, targetFolderName);

    if (result != NULL) {
        for (int i = 99; i >= 0; i--) {
            if (result[i] != "") {
                cout << result[i] << "\\"; // Tambahkan karakter backslash untuk representasi path
            }
        }
    } else {
        cout << "Folder tidak ditemukan." << endl;
    }

    return 0;
}
