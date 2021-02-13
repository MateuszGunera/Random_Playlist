#include <iostream>

using namespace std;

int main()
{
    int size;
    cout << "Enter the number of tracks in the playlist: ";
    cin >> size;

    int *playlist = new int[size];                          // Creation a dynamic arrays.       
    int *random_playlist = new int[size];

    cout << "Playlist of track numbers: " << endl;

    for (int i = 0; i < size; i++)                          // Entering track numbers into the array (playlist).
    {                                               
        playlist[i] = i+1;
        cout << playlist[i];
        cout << " ";
    }

    cout << endl << endl;
    
    srand(time(0));                                     

    cout << "Random playlist: " << endl;

    int drawn_num;
    for (int i = 0; i < size; i++)                        
    {
        drawn_num = playlist[rand() % size];               // Draw track number from the array and assign to a variable.
        bool repeated_track = false;    
        random_playlist[i] = 0;                            
        for (int j = 0; j < size; j++)
        {
            if (random_playlist[j] == drawn_num)           // If the random track number is in the array of random tracks,  
            {                                              // change the bool variable to true.
                repeated_track = true;
            }
        }
        if (repeated_track) i--;                           // If bool is true, decrease the variable i by 1.
        else random_playlist[i] = drawn_num;               // Else, add drawn number to the array (random_playlist).
    }

    for (int i = 0; i < size; i++) {                       // Writing out a random playlist.
        cout << random_playlist[i];
        cout << ' ';
    }

    delete[] playlist;
    delete[] random_playlist;

    cout << endl;
}